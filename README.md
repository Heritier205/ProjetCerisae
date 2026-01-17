# 📍 ProjetCerisae - Gestion des Types d'Emplacement

![Langage C](https://img.shields.io/badge/Language-C-blue.svg)
![Build](https://img.shields.io/badge/Build-CMake-green.svg)

## 📝 Description
**ProjetCerisae** est un module de gestion de données développé en langage C. Il permet de gérer un catalogue de "types d'emplacement" de manière persistante en utilisant un système de fichiers séquentiels.

L'accent est mis sur la fiabilité et la séparation des responsabilités pour garantir un code maintenable et des données sécurisées.

---

## ✨ Fonctionnalités principales
* **Gestion CRUD complète** : Création, Lecture, Mise à jour et Suppression des types d'emplacement.
* **Persistance des données** : Sauvegarde automatique dans un fichier texte structuré.
* **Intégrité garantie** : Les modifications et suppressions utilisent un fichier temporaire pour éviter toute corruption de données en cas d'erreur système.
* **Architecture modulaire** : Séparation stricte entre la logique métier, l'accès aux fichiers et l'interface utilisateur.
* **Validation des saisies** : Contrôle rigoureux des identifiants et des entrées utilisateur.

---

## 🛠 Structure du projet
* `main.c` : Point d'entrée, gestion de l'interface et du menu utilisateur.
* `TypeEmplacement.c / .h` : Logique de manipulation des données et gestion du fichier séquentiel.
* `CMakeLists.txt` : Script de configuration pour une compilation facile.

---

## 🚀 Installation et Compilation

### 1. Prérequis
Assurez-vous d'avoir installé :
* Un compilateur C (GCC, Clang ou MSVC)
* [CMake](https://cmake.org/download/) (version 3.10+)

### 2. Compilation
Clonez le dépôt et utilisez CMake pour générer l'exécutable :


# Cloner le projet
git clone [https://github.com/Heritier205/ProjetCerisae.git](https://github.com/Heritier205/ProjetCerisae.git)
cd ProjetCerisae

# Créer un dossier de build
mkdir build && cd build

# Compiler
cmake ..
make

3. Utilisation

Lancez simplement le programme généré :
Bash

./ProjetCerisae

👥 Auteurs

Développé avec passion par :

[ADAKANOU Koffi Heritier](https://github.com/Heritier205/)

[KUDAWOO Kate Bertrande Ya](https://github.com/katekudawoo/)

Projet réalisé dans le cadre d'un apprentissage de la gestion de fichiers et de la rigueur algorithmique en langage C.