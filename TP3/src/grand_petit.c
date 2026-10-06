#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tableau[100];
    int i;
    int grand;
    int petit;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 100; i++)
        tableau[i] = rand() % 1000 + 1;

    grand = tableau[0];
    petit = tableau[0];

    for (i = 1; i < 100; i++)
    {
        if (tableau[i] > grand)
            grand = tableau[i];

        if (tableau[i] < petit)
            petit = tableau[i];
    }

    printf("Le numero le plus grand est : %d\n", grand);
    printf("Le numero le plus petit est : %d\n", petit);

    return 0;
}