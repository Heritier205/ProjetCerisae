/*
============================================================
 Projet        : Cerisae v2
 Fichier       : TypeEmplacement.c
 Description   : Gestion des types d’emplacement à l’aide d’un fichier séquentiel.
 Auteurs       : Héritier ADAKANOU et KUDAWOO kate
 But           : Le but du projet est de mettre en oeuvre une gestion complete par des fichiers sequentielle.
 Date          : 12/20/2025
============================================================

 Ce module implémente les opérations suivantes :
  - Vérification de l’existence d’un identifiant
  - Ajout d’un type d’emplacement
  - Modification d’un type qui existe deja
  - Suppression d’un type qui existe aussi bien sur
  - Affichage d’un ou de plusieurs types

 Les données sont stockées sous forme textuelle dans un fichier séquentiel, avec une ligne par type.
 Les opérations de mise à jour utilisent un fichier, temporaire afin de préserver l’intégrité des données.
============================================================
*/



#include <stdio.h>
#include "TypeEmplacement.h"

#include <stdlib.h>
#include <string.h>

const char fileName[] = "typeEmplacement.txt";


FILE * openFile(const char *nomFichier, const char *mode)
/* cette fonction s'occupe de l'ouverture du fichier donc le nom es renseigné
 * et affiche le message en cas d'erreur (ça nous permettra de ne pas repeter
 * la meme instruction un peu plus
 */
{
    FILE *f = fopen(nomFichier, mode);
    if (!f) {
        printf("Erreur l'ors de l'ouverture du fichier !\n");
    }
    return f;
}

int saisirIdType()
/* cette procedure nous permet recuperer uniquement l'identifiant d'un type
 * de la part de l'utilisateur
 * L'Objectif est de demander l'id à l'utilisateur une seule fois
 */
{
    int id;
    printf("Entrez l'identifiant du type : ");
    scanf("%d", &id);
    return id;
}


void saisirInfoType(TypeEmplacement *t)
/* Cette methode nous permet de recuperer le reste des infos d'un type
 * de la part de l'utilisateur
 */
{
    printf("Entrez le nom de l'emplacement : ");
    scanf("%s", t->nom);

    getchar();

    printf("Entrez le Prix par personne : ");
    scanf("%f", &t->prix_jour_personne);

    getchar();
}

bool findIdType(int id)
/* Cette fonction verifie dans le fichier si l'identifiant fournis en parametre
 * existe ou pas (si oui, il renvoie (true) sinon (false)
 */
{
    TypeEmplacement t;
    FILE *f = openFile(fileName, "r");
    if (!f) return 0;

    char ligne[ligneMax];
    int idLigne;

    while (fgets(ligne, sizeof(ligne), f)) {
        ligne[strcspn(ligne, "\n")] = '\0';

        if (sscanf(ligne, "%d", &idLigne) && idLigne == id) {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

void enregistrerType(TypeEmplacement *t, FILE *f)
/*
 * Cette procedure permet juste d'écrire ou d'enregistrer un type dans le fichier
 * un type par ligne.
 */
{
    fprintf(f, "%d:%s:%.2f\n", t->numero_type, t->nom, t->prix_jour_personne);
}

void updateFile(const char *oldFile, const char *newFile)
/*
 * Nous avons creé cette methodes pour simplifier les instructions de mise à jour
 * (suppression de l'ancien fichier et le renommage du nouveau en l'ancien).
 */
{
    remove(oldFile); // suppression du fichier original
    rename(newFile, oldFile); // renommage du nouveau fichier en l'ancien

}


void ajouterTypeEmplacement()
/*
 * Evidement cette methode permet d'ajouter un type au fichier sequentiel
 * elle fait donc appel au methodes (saisirIdType, findIdType openFile, saisirInfoType, enregistrerType).
 */
{
    TypeEmplacement t;
    const int id = saisirIdType(); // Recuperation de l'Id

    if (findIdType(id))
        // Au cas ou le type exsite déja on informe l'utilisateur
        {
        printf("Un type avec ce meme identifiant existe deja !\n");
        return;
    }

    // On vérifie, si l'id n'existe pas deja dans le fichier alors, on continue l'enregistrement
    FILE *file = openFile(fileName, "a");
    if (!file) return;
    t.numero_type = id;
    saisirInfoType(&t);enregistrerType(&t, file);
    fclose(file);
}



void modifierType()
/*
 * Cette methode permet de modifier un type donc l'id es fourni par l'user
 * Elle utilise presque toutes les autres methodes citées recement pour faire des vérifications
 * et des opérations.
 */

{
    TypeEmplacement t;
    const int id = saisirIdType();
    if (findIdType(id)) {
        FILE *file = openFile(fileName, "r");
        FILE *tmp = openFile("tmp", "w");
        if (!file || !tmp)
            /* On vérifie bien que les deux fichiers ont été sans erreurs avant de continuer
             * Si une ouverture s'est mal passée, on referme l'autre et on arrête le processus
             * pour eviter certaines imprévues.
             */
            {
            if (file) fclose(file);
            if (tmp) fclose(tmp);
            return;
        }

        char ligne[ligneMax];
        int idLigne;

        while (fgets(ligne, sizeof(ligne), file))
            /*
             * Lecture du fichier ligne par ligne
             */
            {
            ligne[strcspn(ligne, "\n")] = '\0'; // Suppression des retours a la ligne.

            if (sscanf(ligne, "%d", &idLigne) == 1 && idLigne == id)
                /*
                 * On essaye de convertir la chaine de caractère lue en int.
                 * Apres avoir verifier que la conversion s'est bien passé, on passe
                 * à la verification d'égalité entre l'id lue et celui entré par l'user
                 */
                {
                t.numero_type = id; // Attribution de l'id a un typeEmplacement a enregistrer
                saisirInfoType(&t); // Recuperation des autres infos du type
                enregistrerType(&t, tmp);
            }else
                /*
                 * Tant que les deux id ne sont pas les meme, on recopie dans le nouveau fichier
                 * toutes les lignes lues sans modification.
                 */
                {
                fprintf(tmp, "%s\n", ligne);
            }
        }
        fclose(file); // Fermeture du fichier original
        fclose(tmp); // Fermeture du nouveau fichier
        updateFile(fileName, "tmp"); // mise à jour de l'ancien fichier avec le nouveau
    }else
        /*
         * Si l'id entré par l'user n'existe pas alors, on l'informe
         */
        {
        printf("Type introuvable !\n");
    }
}

void supprimerType()
/*
 * Cette methode permet de supprimer un type dont l'id est fournis par l'user
 * cette methode fait pratiquement les memes instruction que la methode de modification.
 * Sauf qu'au lieu de modifier, elle n'écrit simplement pas
 */
{
    const int id = saisirIdType();
    if (findIdType(id)) {
        FILE *file = openFile(fileName, "r");
        FILE *tmp = openFile("tmp", "w");

        if (!file || !tmp) {
            if (file) fclose(file);
            if (tmp) fclose(tmp);
            return;
        }

        char ligne[ligneMax];
        int idLigne;

        while (fgets(ligne, sizeof(ligne), file)) {
            ligne[strcspn(ligne, "\n")] = '\0';

            if (sscanf(ligne, "%d", &idLigne) == 1 && idLigne == id) {
                continue;
            }
            fprintf(tmp, "%s\n", ligne);
        }

        fclose(file);
        fclose(tmp);
        updateFile(fileName, "tmp");

        printf("Suppression effectuée !");
    }else {
        printf("Type introuvable !\n");
    }
}


void listerType(const char *idStr) {
    FILE *file = openFile(fileName, "r");
    if (!file) return;

    char ligne[ligneMax];
    int idLigne;
    float prix;

    while (fgets(ligne, sizeof(ligne), file)) {
        char nom[50];
        ligne[strcspn(ligne, "\n")] = '\0';

        if (sscanf(ligne, "%d:%[^:]:%f", &idLigne, nom, &prix) == 3) {
            if (strcmp(idStr, "all") == 0)
                {
                // afficher tous
                printf("[%d]\t\t%s\t\t\t\t%.2f Euros/personne\n", idLigne, nom, prix);
                }
            else
                {
                // afficher un seul ID
                const int idRecherche = atoi(idStr); // Conversion en int de l'id entré
                if (idLigne == idRecherche) {
                    printf("[%d] \t %s \t %.2f Euros/personne\n", idLigne, nom, prix);
                }
            }

        }
    }
}