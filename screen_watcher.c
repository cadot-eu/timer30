#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <time.h>

// Vérifie si l'écran est allumé via xset (X11)
bool is_screen_on() {
    FILE *fp = popen("xset q | grep 'Monitor is'", "r");
    if (!fp) return false;
    char buf[128];
    bool on = false;
    while (fgets(buf, sizeof(buf), fp)) {
        if (strstr(buf, "Monitor is On")) {
            on = true;
            break;
        }
    }
    pclose(fp);
    return on;
}

// Retourne le temps d'inactivité clavier/souris en ms (nécessite xprintidle)
unsigned long get_idle_ms() {
    FILE *fp = popen("xprintidle", "r");
    if (!fp) return 0;
    unsigned long ms = 0;
    fscanf(fp, "%lu", &ms);
    pclose(fp);
    return ms;
}

void show_ok_window() {
    system("zenity --info --title='Notification' --width=400 --height=200 --timeout=3 --no-wrap --text='✅  OK !'");
}

// Lit le temps d'inactivité en minutes depuis ~/.config/timer30.conf
unsigned long read_idle_minutes() {
    const char *config_dir = getenv("HOME");
    char config_path[256];
    snprintf(config_path, sizeof(config_path), "%s/.config/timer30.conf", config_dir ? config_dir : ".");
    FILE *fp = fopen(config_path, "r");
    unsigned long minutes = 1;
    if (!fp) {
        // Crée le dossier ~/.config si besoin
        char config_folder[256];
        snprintf(config_folder, sizeof(config_folder), "%s/.config", config_dir ? config_dir : ".");
        mkdir(config_folder, 0755);
        // Crée le fichier avec la valeur par défaut
        fp = fopen(config_path, "w");
        if (fp) {
            fprintf(fp, "idle_minutes=1\n");
            fclose(fp);
        }
        return minutes;
    }
    char line[64];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "idle_minutes=%lu", &minutes) == 1) {
            break;
        }
    }
    fclose(fp);
    return minutes;
}

int main() {
    bool was_idle = false;
    unsigned long idle_minutes = read_idle_minutes();
    unsigned long idle_threshold = idle_minutes * 60 * 1000; // en ms
    while (1) {
        unsigned long idle = get_idle_ms();
        if (idle > idle_threshold) {
            was_idle = true;
        } else if (was_idle) {
            // L'utilisateur vient de "réveiller" l'écran
            printf("ok\n");
            fflush(stdout);
            show_ok_window();
            was_idle = false;
        }
        sleep(1);
    }
    return 0;
}
