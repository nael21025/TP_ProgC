#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tableau[100];
    int i;
    int j;
    int temp;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 100; i++)
        tableau[i] = rand() % 1000;

    printf("Tableau non trie :\n");
    for (i = 0; i < 100; i++)
        printf("%d ", tableau[i]);

    for (i = 0; i < 99; i++)
    {
        for (j = 0; j < 99 - i; j++)
        {
            if (tableau[j] > tableau[j + 1])
            {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("\n\nTableau trie :\n");
    for (i = 0; i < 100; i++)
        printf("%d ", tableau[i]);

    printf("\n");
    return 0;
}