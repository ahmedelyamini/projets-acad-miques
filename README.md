# Système de Sécurité et d'Alarme basé sur Arduino

Ce dépôt contient l'ensemble du projet de fin d'études pour la réalisation d'un système de sécurité et d'alarme utilisant une carte Arduino Uno. Le projet a été réalisé dans le cadre de la formation en électronique à la Faculté des Sciences d’El Jadida.
## Introduction

Le projet consiste à concevoir et réaliser un système de sécurité et d'alarme qui permet de surveiller un domicile ou un établissement. Le système détecte les intrusions grâce à un capteur de mouvement (PIR) et active une alarme sonore via un buzzer. L'activation et la désactivation du système se font à l'aide d'un clavier numérique, et un écran LCD affiche l'état du système ainsi que les messages d'alerte.

## Fonctionnalités

- **Détection de mouvement :** Utilisation d'un capteur PIR pour détecter les intrusions.
- **Alarme sonore :** Activation d'un buzzer en cas de détection d'un mouvement suspect.
- **Interface utilisateur :** Clavier numérique pour entrer le code d'activation/désactivation et écran LCD pour l'affichage des informations.
- **Sécurité :** Possibilité de changer le mot de passe pour renforcer la sécurité.
- **Simulation :** Simulation du système réalisée avec Proteus ISIS avant la mise en œuvre pratique.

## Matériel Utilisé

- **Arduino Uno** – Microcontrôleur utilisé comme cœur du système.
- **Capteur PIR** – Détecteur de mouvement infrarouge passif.
- **Clavier numérique 4x4** – Pour la saisie du code d'accès.
- **Écran LCD 16x2** – Pour l'affichage des messages et de l'état du système.
- **Buzzer** – Pour émettre une alarme sonore.
- **Plaque d'essai (Breadboard) et divers câbles** – Pour réaliser les connexions.
- **Potentiomètre** – Pour le réglage du contraste de l'écran LCD.

## Schéma et Connexions

Le dépôt contient également des schémas de câblage illustrant :
- Le raccordement du capteur PIR à l’Arduino.
- La connexion du clavier numérique et de l’écran LCD.
- Le montage du buzzer pour l’activation de l’alarme.

Ces schémas ont été réalisés et vérifiés à l'aide du logiciel Proteus ISIS.

## Installation et Utilisation

1. **Téléversement du Code sur Arduino :**
   - Ouvrez l'IDE Arduino.
   - Chargez le fichier source (par exemple, `main.ino`).
   - Connectez votre Arduino Uno via USB.
   - Sélectionnez la carte et le port appropriés dans l'IDE.
   - Téléversez le code sur la carte.

2. **Simulation :**
   - Consultez les fichiers de simulation (Proteus) inclus pour tester le circuit virtuellement avant de le réaliser en pratique.

3. **Utilisation du Système :**
   - Pour activer le système, entrez le code d'activation via le clavier numérique.
   - Après une courte temporisation, l'alarme sera activée.
   - En cas de détection de mouvement, le buzzer se déclenchera et l'écran affichera un message d'alerte.
   - Pour désactiver l’alarme, entrez le code d’accès actuel et, si nécessaire, modifiez-le.
