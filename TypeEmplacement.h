/*
============================================================
 Projet        : Cerisae v2
 Fichier       : TypeEmplacement.h
 Description   : Gestion des types d’emplacement à l’aide d’un fichier séquentiel.
 But           : Le but du projet est de mettre en oeuvre une gestion complete par des fichiers sequentielle.
 Auteurs       : Héritier ADAKANOU et KUDAWOO kate
 Date          : 12/20/2025
============================================================
*/



#ifndef CERISAE_TYPEEMPLACEMENT_H
#define CERISAE_TYPEEMPLACEMENT_H

#endif //CERISAE_TYPEEMPLACEMENT_H

#include<stdbool.h>
#define nomMax 50
#define ligneMax 255
typedef struct{
    int numero_type;                    /* Numero unique du type */
    char nom[nomMax];                   /* Nom du type ( Ex : "Tente", "Caravane")  */
    float prix_jour_personne;           /* Prix par jour et par personne en Euros */
} TypeEmplacement;


FILE * openFile(const char *nomFichier, const char *mode);

int saisirIdType();

void saisirInfoType(TypeEmplacement *t);

bool findIdType(int id);

void enregistrerType(TypeEmplacement *t, FILE *f);

void updateFile(const char *oldFile, const char *newFile);

void ajouterTypeEmplacement();

void modifierType();

void supprimerType();

void listerType(const char *idStr);
