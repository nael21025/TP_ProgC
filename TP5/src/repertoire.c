#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "repertoire.h"

int est_dossier(const char *chemin)
{
    struct stat infos;

    if (stat(chemin, &infos) != 0)
        return 0;

    return S_ISDIR(infos.st_mode);
}

void construire_chemin(char *destination, size_t taille,
                       const char *dossier, const char *nom)
{
    snprintf(destination, taille, "%s/%s", dossier, nom);
}

void lire_dossier(const char *nom)
{
    DIR *dossier = opendir(nom);
    struct dirent *entree;

    if (dossier == NULL)
    {
        printf("Impossible d'ouvrir %s\n", nom);
        return;
    }

    while ((entree = readdir(dossier)) != NULL)
    {
        if (strcmp(entree->d_name, ".") != 0 &&
            strcmp(entree->d_name, "..") != 0)
        {
            printf("%s\n", entree->d_name);
        }
    }

    closedir(dossier);
}

void lire_dossier_recursif(const char *nom)
{
    DIR *dossier = opendir(nom);
    struct dirent *entree;

    if (dossier == NULL)
        return;

    while ((entree = readdir(dossier)) != NULL)
    {
        char chemin[1024];

        if (strcmp(entree->d_name, ".") == 0 ||
            strcmp(entree->d_name, "..") == 0)
            continue;

        construire_chemin(chemin, sizeof(chemin), nom, entree->d_name);
        printf("%s\n", chemin);

        if (est_dossier(chemin))
            lire_dossier_recursif(chemin);
    }

    closedir(dossier);
}

void lire_dossier_iteratif(const char *nom)
{
    char file[500][1024];
    int debut = 0;
    int fin = 0;

    snprintf(file[fin++], sizeof(file[0]), "%s", nom);

    while (debut < fin)
    {
        char dossierActuel[1024];
        DIR *dossier;
        struct dirent *entree;

        snprintf(dossierActuel, sizeof(dossierActuel), "%s", file[debut++]);
        dossier = opendir(dossierActuel);

        if (dossier == NULL)
            continue;

        while ((entree = readdir(dossier)) != NULL)
        {
            char chemin[1024];

            if (strcmp(entree->d_name, ".") == 0 ||
                strcmp(entree->d_name, "..") == 0)
                continue;

            construire_chemin(chemin, sizeof(chemin),
                              dossierActuel, entree->d_name);

            printf("%s\n", chemin);

            if (est_dossier(chemin) && fin < 500)
                snprintf(file[fin++], sizeof(file[0]), "%s", chemin);
        }

        closedir(dossier);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        lire_dossier(argv[1]);
        return 0;
    }

    if (argc == 3 && strcmp(argv[1], "-r") == 0)
    {
        lire_dossier_recursif(argv[2]);
        return 0;
    }

    if (argc == 3 && strcmp(argv[1], "-i") == 0)
    {
        lire_dossier_iteratif(argv[2]);
        return 0;
    }

    printf("Utilisation :\n");
    printf("%s dossier\n", argv[0]);
    printf("%s -r dossier\n", argv[0]);
    printf("%s -i dossier\n", argv[0]);

    return 1;
}