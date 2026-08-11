# 🛡️ Cyber-Sentinel

## A Portable ESP32-Based Rogue Access Point Detector and Lightweight Honeypot

Cyber-Sentinel is a portable, battery-powered wireless security monitoring system developed using an ESP32. The system scans nearby Wi-Fi networks and identifies potential Rogue Access Points (Rogue APs) and Evil Twin conditions by comparing observed wireless characteristics with a trusted Access Point baseline.

The system collects information such as SSID, BSSID, RSSI, channel, and encryption information and provides real-time alerts through an OLED display, red/green LEDs, and an active buzzer.

The project also presents a conceptual extension toward a lightweight honeypot architecture using the ESP32 together with a companion single-board computer.

> ⚠️ **Disclaimer:** This project is intended for cybersecurity education, research, and authorized wireless security testing only. Do not use it to monitor or interfere with networks without proper authorization.

---

## 🎯 Project Objectives

The main objectives of Cyber-Sentinel are:

- Design and implement a portable ESP32-based Wi-Fi scanning device.
- Detect potential Rogue Access Points and Evil Twin conditions.
- Compare BSSID, RSSI, and channel information against a trusted AP baseline.
- Provide real-time alerts through OLED, LED, and buzzer.
- Support local logging of Wi-Fi scan results.
- Explore a lightweight honeypot architecture using a companion computer.

These objectives are based on the project report. :contentReference[oaicite:1]{index=1}

---

## 🔍 How It Works

Cyber-Sentinel follows this basic workflow:

```text
              Nearby Wi-Fi Networks
                       │
                       ▼
                ┌─────────────┐
                │    ESP32    │
                │ Wi-Fi Scan  │
                └──────┬──────┘
                       │
                       ▼
             Collect Wi-Fi Information
          ┌────────┬────────┬─────────┐
          │ SSID   │ BSSID  │ RSSI    │
          │        │        │ Channel │
          └────────┴────────┴─────────┘
                       │
                       ▼
             Trusted AP Comparison
                       │
                       ▼
                Suspicious AP?
                  /          \
                NO            YES
                │              │
                ▼              ▼
              SAFE           ALERT
                │              │
          Green LED       Red LED + Buzzer
                │              │
                └──────┬───────┘
                       ▼
                 OLED Display
                       │
                       ▼
                Optional Logging
