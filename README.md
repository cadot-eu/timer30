
# sleep-monitor.service

## English

This project allows you to start a timer or a custom action after waking up (suspend) on a Linux system, using a systemd service and a Python script.

### Main files

- `script_timer.py`: Python script executed after waking up.
- `/etc/systemd/system/sleep-monitor.service`: Example systemd service file (see below).

### Example systemd service file

```ini
[Unit]
Description=Timer after wake from suspend
After=suspend.target

[Service]
Type=simple
ExecStart=/usr/bin/python3 /home/michael/git/timer30/script_timer.py
Restart=on-failure

[Install]
WantedBy=suspend.target
```

### Installation

1. Copy the service file to `/etc/systemd/system/`.

2. Reload systemd configuration:

   ```bash
   sudo systemctl daemon-reload
   ```

3. Enable the service:

   ```bash
   sudo systemctl enable sleep-monitor.service
   ```

4. Check the status:

   ```bash
   systemctl status sleep-monitor.service
   ```

### Customization


### Notifications

To enable desktop notifications from the Python script, install the following packages:

- `libnotify-bin` (for the `notify-send` command)
- Python package: `notify2` (optional, for Python-based notifications)

Install with:

```bash
sudo apt install libnotify-bin
pip install notify2
```

### Customization

Edit the `script_timer.py` script to adapt the timer or action to your needs.

### Author

Michael

---

## Français

Ce projet permet de lancer un timer ou une action personnalisée après la sortie de veille (suspend) sur un système Linux, grâce à un service systemd et un script Python.

### Fichiers principaux

- `script_timer.py` : Script Python exécuté à la sortie de veille.
- `/etc/systemd/system/sleep-monitor.service` : Fichier de service systemd (exemple ci-dessous).

### Exemple de fichier service systemd

```ini
[Unit]
Description=Timer après sortie de veille
After=suspend.target

[Service]
Type=simple
ExecStart=/usr/bin/python3 /home/michael/git/timer30/script_timer.py
Restart=on-failure

[Install]
WantedBy=suspend.target
```

### Installation

1. Copier le fichier de service dans `/etc/systemd/system/`.

2. Recharger la configuration systemd :

   ```bash
   sudo systemctl daemon-reload
   ```

3. Activer le service :

   ```bash
   sudo systemctl enable sleep-monitor.service
   ```

4. Vérifier le statut :

   ```bash
   systemctl status sleep-monitor.service
   ```

### Personnalisation


### Notifications

Pour activer les notifications sur le bureau depuis le script Python, installez :

- `libnotify-bin` (pour la commande `notify-send`)
- Le paquet Python : `notify2` (optionnel, pour les notifications Python)

Installez avec :

```bash
sudo apt install libnotify-bin
pip install notify2
```

### Personnalisation

Modifiez le script `script_timer.py` pour adapter le comportement du timer ou de l'action à vos besoins.

### Auteur
Michael

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Issues

If you encounter any problems, please use the [GitHub Issues](https://github.com/yourusername/timer30/issues) page.

## Repository

Find the source code and updates at: [https://github.com/yourusername/timer30](https://github.com/yourusername/timer30)
Find the source code and updates at: [https://github.com/yourusername/timer30](https://github.com/yourusername/timer30)
