#include <stdio.h>

struct Etudiant
{
    char nom[30];
    char prenom[30];
    char adresse[100];
    float note1;
    float note2;
};

int main()
{
    struct Etudiant etudiants[5];
    FILE *fichier;
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Etudiant %d\n", i + 1);

        printf("Nom : ");
        scanf("%29s", etudiants[i].nom);

        printf("Prenom : ");
        scanf("%29s", etudiants[i].prenom);

        printf("Adresse : ");
        scanf(" %99[^\n]", etudiants[i].adresse);

        printf("Note 1 : ");
        scanf("%f", &etudiants[i].note1);

        printf("Note 2 : ");
        scanf("%f", &etudiants[i].note2);
    }

    fichier = fopen("etudiant.txt", "w");

    if (fichier == NULL)
    {
        printf("Impossible de creer etudiant.txt\n");
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        fprintf(fichier, "%s;%s;%s;%.2f;%.2f\n",
                etudiants[i].nom,
                etudiants[i].prenom,
                etudiants[i].adresse,
                etudiants[i].note1,
                etudiants[i].note2);
    }

    fclose(fichier);

    printf("Donnees enregistrees dans etudiant.txt\n");
    return 0;
}