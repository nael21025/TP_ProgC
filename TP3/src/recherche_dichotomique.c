#include <stdio.h>

int main()
{
    int tableau[100];
    int recherche;
    int gauche = 0;
    int droite = 99;
    int milieu;
    int trouve = 0;
    int i;

    for (i = 0; i < 100; i++)
        tableau[i] = i + 1;

    printf("Tableau trie :\n");
    for (i = 0; i < 100; i++)
        printf("%d ", tableau[i]);

    printf("\nEntier a chercher : ");
    scanf("%d", &recherche);

    while (gauche <= droite)
    {
        milieu = (gauche + droite) / 2;

        if (tableau[milieu] == recherche)
        {
            trouve = 1;
            break;
        }

        if (tableau[milieu] < recherche)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }

    if (trouve)
        printf("entier present\n");
    else
        printf("entier absent\n");

    return 0;
}