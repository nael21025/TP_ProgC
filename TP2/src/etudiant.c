#include <stdio.h>

int main()
{
    char noms[5][50] = {
        "Dupont Marie",
        "Martin Pierre",
        "Durand Sarah",
        "Bernard Lucas",
        "Petit Emma"
    };

    char adresses[5][100] = {
        "Lyon",
        "Paris",
        "Lille",
        "Nantes",
        "Bordeaux"
    };

    float noteC[5] = {16.5, 14.0, 12.5, 18.0, 15.5};
    float noteSysteme[5] = {12.1, 14.1, 13.0, 17.0, 16.0};

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Etudiant %d\n", i + 1);
        printf("Nom et prenom : %s\n", noms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note C : %.1f\n", noteC[i]);
        printf("Note systeme : %.1f\n\n", noteSysteme[i]);
    }

    return 0;
}
