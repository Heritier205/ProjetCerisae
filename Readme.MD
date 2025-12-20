Ce module implémente la gestion complète des types d’emplacement à l’aide d’un fichier séquentiel en langage C.
Il fournit des fonctionnalités de création, lecture, modification et suppression (CRUD) des types d’emplacement, en assurant la persistance des données dans un fichier texte structuré.

Le programme repose sur une séparation claire des responsabilités :
la saisie utilisateur, la validation des identifiants, l’accès au fichier et la logique métier sont traitées par des fonctions distinctes.

Les opérations de modification et de suppression sont réalisées via un fichier temporaire afin de garantir l’intégrité des données.
Une attention particulière est portée à la gestion des erreurs (ouverture de fichiers, validation des entrées) ainsi qu’à la lisibilité et à la modularité du code.