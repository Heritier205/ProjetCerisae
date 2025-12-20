/*
============================================================
 Projet        : Cerisae v2
 Fichier       : main.c
 Description   : Gestion des types d’emplacement à l’aide d’un fichier séquentiel.
 But           : Le but du projet est de mettre en oeuvre une gestion complete par des fichiers sequentielle.
 Auteurs       : Héritier ADAKANOU et KUDAWOO kate
 Date          : 12/20/2025
============================================================
*/

#include <stdio.h>
#include "TypeEmplacement.h"

int main(void) {
    char answer;
    char msg;
    do {
        printf("\nEntrez :\n");
        printf("(1) Ajouter un emplacement\n");
        printf("(2) Modifier un emplacement\n");
        printf("(3) Supprimer un emplacement\n");
        printf("(4) Afficher tous les emplacements\n");
        printf("(0) Quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &answer);
        printf("\n");
        getchar();

        switch (answer) {
            case '1':
                do {
                    ajouterTypeEmplacement();
                    printf("Voulez-vous entrer un autre emplacement (o/N) ? : ");
                    scanf(" %c", &msg);
                    getchar();
                } while (msg == 'o' || msg == 'O');
                break;

            case '2':
                modifierType();
                break;

            case '3':
                supprimerType();
                break;

            case '4':
                char choix[]="";
                printf("Etrez un id pour lister un type precis, (all) pour tout : ");
                scanf("%s", choix);
                listerType(choix);
                break;

            case '0':
                printf("Programme termine.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while(answer != '0');
    return 0;
}