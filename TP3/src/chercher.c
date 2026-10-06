#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tableau[100];
    int recherche;
    int trouve = 0;
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 100; i++)
        tableau[i] = rand() % 100 + 1;

    printf("Tableau :\n");
    for (i = 0; i < 100; i++)
        printf("%d ", tableau[i]);

    printf("\nEntier a chercher : ");
    scanf("%d", &recherche);

    for (i = 0; i < 100; i++)
    {
        if (tableau[i] == recherche)
        {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("entier present\n");
    else
        printf("entier absent\n");

    return 0;
}