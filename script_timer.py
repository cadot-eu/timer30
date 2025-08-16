#!/usr/bin/env python3
import os
import time
from datetime import timedelta
import subprocess

def send_notification(message):
    subprocess.run(["notify-send", "--urgency=normal", "Timer Veille", message])

def main():
    start_time = time.time()
    while True:
        elapsed = time.time() - start_time
        elapsed_minutes = int(elapsed // 60)
        
        # Notification toutes les 30 minutes
        if elapsed_minutes > 0 and elapsed_minutes % 30 == 0:
            hours = elapsed_minutes // 60
            remaining_minutes = elapsed_minutes % 60
            if hours == 0:
                message = f"{elapsed_minutes} minutes écoulées"
            else:
                message = f"{hours}h{remaining_minutes:02d} écoulées"
            send_notification(message)
        
        time.sleep(60)  # Vérifie toutes les minutes

if __name__ == "__main__":
    main()
