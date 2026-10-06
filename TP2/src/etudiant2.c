#include <stdio.h>
#include <string.h>

struct Etudiant
{
    char nom[30];
    char prenom[30];
    char adresse[100];
    float noteC;
    float noteSysteme;
};

int main()
{
    struct Etudiant etudiants[5];
    int i;

    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "Lyon");
    etudiants[0].noteC = 16.5;
    etudiants[0].noteSysteme = 12.1;

    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "Paris");
    etudiants[1].noteC = 14.0;
    etudiants[1].noteSysteme = 14.1;

    strcpy(etudiants[2].nom, "Durand");
    strcpy(etudiants[2].prenom, "Sarah");
    strcpy(etudiants[2].adresse, "Lille");
    etudiants[2].noteC = 12.5;
    etudiants[2].noteSysteme = 13.0;

    strcpy(etudiants[3].nom, "Bernard");
    strcpy(etudiants[3].prenom, "Lucas");
    strcpy(etudiants[3].adresse, "Nantes");
    etudiants[3].noteC = 18.0;
    etudiants[3].noteSysteme = 17.0;

    strcpy(etudiants[4].nom, "Petit");
    strcpy(etudiants[4].prenom, "Emma");
    strcpy(etudiants[4].adresse, "Bordeaux");
    etudiants[4].noteC = 15.5;
    etudiants[4].noteSysteme = 16.0;

    for (i = 0; i < 5; i++)
    {
        printf("Etudiant %d\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note C : %.1f\n", etudiants[i].noteC);
        printf("Note systeme : %.1f\n\n", etudiants[i].noteSysteme);
    }

    return 0;
}
