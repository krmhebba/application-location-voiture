# Application de Location de Voitures

## Description
Application console développée en langage C pour la gestion complète d'une agence de location de véhicules. Le logiciel permet aux gestionnaires d'administrer le parc automobile (CRUD), de traiter les locations (contrats) et de gérer la disponibilité des véhicules en temps réel via une base de données fichiers.

## Fonctionnalités Principales
* **Gestion du Parc Automobile :** Ajout, modification et suppression de véhicules avec détails techniques (Marque, Modèle, Carburant, Places, Transmission, Prix).
* **Système de Location :**
  * **Louer une voiture :** Création automatique d'un contrat, calcul du coût total en fonction de la durée et mise à jour immédiate de la disponibilité.
  * **Retourner une voiture :** Remise en disponibilité du véhicule après la location.
* **Recherche et Tri :**
  * Recherche de véhicules par marque.
  * Algorithme de tri (Tri à bulles) pour afficher les offres par ordre croissant de prix.
* **Gestion des Incidents :** Module de signalement des pannes rendant un véhicule indisponible à la location.
* **Persistance des Données :** Sauvegarde automatique des données dans des fichiers textes (`Voitures.txt` et `Contrats.txt`) pour conserver les informations après fermeture du programme.

## Architecture Technique
* **Langage :** C Standard.
* **Structures de Données :** Utilisation de structures complexes (`struct Voiture`, `struct Contrat`, `struct Date`) pour modéliser les entités métier.
* **Algorithmique :** Implémentation d'algorithmes de recherche séquentielle et de tri.
* **Gestion de Fichiers :** Manipulation avancée des entrées/sorties pour le stockage durable des données.

## Installation et Exécution
1. Cloner le dépôt.
2. Compiler le code source :
   gcc VOITURE.c -o location_app
3. Lancer l'application :
   ./location_app
   (Sur Windows : location_app.exe)

## Auteur
Projet réalisé par Hiba Karam en collaboration avec Bounya Fayçal, Kamil Mohamed et Sefraoui Hiba.
