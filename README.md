# timer30

## English

**timer30** is a small program to help you stay aware of your computer usage time. It displays a visible notification after a period of inactivity, reminding you to be vigilant about your time spent on the computer.

### Installation

1. Install dependencies:
   - `zenity` (for notifications)
   - `xprintidle` (for inactivity detection)
   - `gcc` (for compilation)
   - `libx11-dev` (for X11 support)

   On Ubuntu/Debian:
   ```bash
   sudo apt install zenity xprintidle gcc libx11-dev
   ```

2. Compile the program:
   ```bash
   gcc -O2 -Wall screen_watcher.c -o screen_watcher $(pkg-config --cflags --libs x11)
   ```

3. Configure the inactivity time:
   - The config file is at `~/.config/timer30.conf`.
   - It is created automatically at first launch with `idle_minutes=1` (1 minute).
   - Edit this file to set your preferred time (in minutes):
     ```
     idle_minutes=30
     ```

### Autostart in XFCE

1. Open XFCE Settings > Session and Startup > Application Autostart.
2. Click "Add" and fill in:
   - Name: `timer30`
   - Command: `/path/to/screen_watcher`
   - Description: `Stay aware of your computer usage time.`
3. Save. The program will start automatically at each session.

---

## Français

**timer30** est un petit programme pour vous aider à rester vigilant sur votre temps passé sur l’ordinateur. Il affiche une notification visible après une période d’inactivité, pour vous rappeler de faire attention à votre temps d’écran.

### Installation

1. Installez les dépendances :
   - `zenity` (pour les notifications)
   - `xprintidle` (pour la détection d’inactivité)
   - `gcc` (pour la compilation)
   - `libx11-dev` (pour le support X11)

   Sur Ubuntu/Debian :
   ```bash
   sudo apt install zenity xprintidle gcc libx11-dev
   ```

2. Compilez le programme :
   ```bash
   gcc -O2 -Wall screen_watcher.c -o screen_watcher $(pkg-config --cflags --libs x11)
   ```

3. Configurez le temps d’inactivité :
   - Le fichier de configuration est `~/.config/timer30.conf`.
   - Il est créé automatiquement au premier lancement avec `idle_minutes=1` (1 minute).
   - Modifiez ce fichier pour définir votre temps préféré (en minutes) :
     ```
     idle_minutes=30
     ```

### Démarrage automatique sous XFCE

1. Ouvrez les Paramètres XFCE > Session et démarrage > Démarrage automatique des applications.
2. Cliquez sur "Ajouter" et remplissez :
   - Nom : `timer30`
   - Commande : `/chemin/vers/screen_watcher`
   - Description : `Restez vigilant sur votre temps d’ordinateur.`
3. Enregistrez. Le programme se lancera automatiquement à chaque session.
