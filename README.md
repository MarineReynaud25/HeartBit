## Description

Ce projet permet de mettre en communication 2 esp32 Mini en utilisant le protocole ESP6NOW. Chaque carte est équipée d'un bouton, d'une LED et d'un moteur à vibration. Lorsqu'un bouton sur l'ESP32 A est pressé, cela déclenche la LED et le moteur à vibration sur l'ESP32 B, et vice versa.

## Composants
- 2 x ESP32 C3 Mini
- 2 x Boutons poussoirs
- 2 x LEDs
- 2 x Moteurs à vibration
- Câbles de connexion
- Résistances (pour les LEDs)
- Breadboard oiu carte à trou

## Configuration du Matériel
1. Connectez les 2 esp32 à une breadboard.
1. Pour chaque carte connectez le bouton poussoir, a led et le moteur à des pins GPIO de l'ESP32, elles seront appelées INTERRUPT_PIN, LedPin et MOTOR dans le code.

## Installation
1.	Installez l'IDE Arduino et les paquets nécessaires pour ESP32.
2. Clonez ce dépôt sur votre machine locale.
3. Ouvrez le fichier de code dans l'IDE Arduino.
4. Téléversez le code sur les deux cartes ESP32.

## Configuration du Logiciel
- Assurez-vous que les adresses MAC dans le code (`broadcastAddress`) sont correctement définies pour chaque ESP32.
- Le code doit être téléversé sur les deux ESP32 avec leurs adresses MAC respectives.

## Utilisation
Après la mise sous tension des deux cartes ESP32, appuyez sur le bouton de l'une des cartes. Cela devrait activer la LED et le moteur à vibration sur l'autre carte.

## Code
Le code fourni établit une communication ESP-NOW entre deux ESP32. Il gère l'envoi et la réception de messages, ainsi que le contrôle des périphériques externes (LED et moteur à vibration) en réponse aux entrées du bouton.

### Fonctions Principales
- `OnDataSent` : Callback appelé après l'envoi d'un message.
- `OnDataRecv` : Callback appelé à la réception d'un message.
- `isr_callback` : Fonction appelée lors de l'interruption par le bouton poussoir.
