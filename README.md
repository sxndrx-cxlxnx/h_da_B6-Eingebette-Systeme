# SS2024 : Embedded Distance Assistent (EDA)

Als Projektziel für das Praktikum dieses Semesters soll ein Distanzassistent programmiert werden, der einem Modellauto im Maßstab 1:10 ermöglicht, in einem definierten Abstand vor einem Hindernis (z. B. einer Wand) zu halten. Dies soll mithilfe verschiedener Sensoren und Aktoren (z. B. Ultraschallsensor und DC-Motor) realisiert werden. Als zentrale Komponente des eingebetteten Systems wird ein Arduino Due (AT91SAM3X8E) verwendet. Im Praktikum werden Sie mit zwei verschiedenen Versuchsaufbauten arbeiten. An jedem Laborplatz befindet sich ein fester Aufbau, auf dem die im Praktikum verwendbaren Peripheriegeräte (LED, Tasten, Ultraschallsensor, Motor, LED-Matrix, Drehimpulsgeber, usw.) verbaut sind, sowie das eigentliche Fahrzeug, welches als Zielplattform am Ende des Praktikums eingesetzt werden soll. Das Fahrzeug wird wenigstens einen Antrieb, einen Ultraschallsensor sowie eine zum Laborplatz kompatible Entwicklungsplattform mit den üblichen Schnittstellen haben.

## Einrichtung

Die intergrierte Entwicklungsumgebung IDE (Integrated Development Environment), die verwendet wird, ist Visual Studio Code. Die aktuellen Aufgabenstellungen und der Quellcode werden in einem Git-Repository verfügbar sein.

Sie können den Projektordner mit den folgenden Befehlen herunterladen und öffnen:

```
git clone https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/ss2024.git ss2024
cd ss2024
code .
```

Wenn Sie Ihr eigenes Git-Repository zum Speichern und Teilen der Daten verwenden möchten, können Sie den `.git`-Ordner löschen: `rm -rf .git`.

## Ablauf

Der Ablauf der Praktika lässt sich wie folgt zusammenfassen:

- Termin 0 (Einführung)
  - Laborordnung
  - Einrichtung des Projekts
  - Verbindung mit dem eingebetteten System
    - Debugger
    - Serielle Schnittstelle

- Termin 1 (PIO)
    - Ein- und Ausschalten der verbauten LEDs

- Termin 2 (I2C)
    - Fortschrittsanzeige über LED-Matrix (Duty, Abstand)

- Termin 3 (Timer Capture)
    - Distanzmessung mit Ultraschallsensor

- Termin 4 (Timer Wave)
    - Ansteuern der Motoren

- Termin 5 (Regelkreis, Abnahme)
    - Implementierung des Regelkreises zum Anhalten vor dem Hindernis
    - Abnahme mit dem Fahrzeug auf der Teststrecke
