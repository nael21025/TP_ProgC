#include <stdio.h>
#include <string.h>

int compter_occurrences(const char *ligne, const char *phrase)
{
    int compteur = 0;
    const char *position = ligne;
    size_t longueur = strlen(phrase);

    if (longueur == 0)
        return 0;

    while ((position = strstr(position, phrase)) != NULL)
    {
        compteur++;
        position += longueur;
    }

    return compteur;
}

int main(int argc, char *argv[])
{
    FILE *fichier;
    char phrase[200];
    char ligne[1000];
    int numeroLigne = 0;

    if (argc != 2)
    {
        printf("Utilisation : %s <fichier>\n", argv[0]);
        return 1;
    }

    fichier = fopen(argv[1], "r");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        return 1;
    }

    printf("Phrase a chercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        int occurrences;

        numeroLigne++;
        occurrences = compter_occurrences(ligne, phrase);

        if (occurrences > 0)
            printf("Ligne %d, %d fois\n", numeroLigne, occurrences);
    }

    fclose(fichier);
    return 0;
}