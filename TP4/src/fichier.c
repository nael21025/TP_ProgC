#include <stdio.h>
#include "fichier.h"

void lire_fichier(const char *nom_de_fichier)
{
    FILE *fichier = fopen(nom_de_fichier, "r");
    char ligne[500];

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
        printf("%s", ligne);

    fclose(fichier);
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message)
{
    FILE *fichier = fopen(nom_de_fichier, "a");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    fprintf(fichier, "%s\n", message);
    fclose(fichier);
}