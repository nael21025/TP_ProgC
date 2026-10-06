#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int entiers[10];
    float reels[10];

    int *pe = entiers;
    float *pr = reels;

    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 10; i++)
    {
        *(pe + i) = rand() % 100;
        *(pr + i) = (float)(rand() % 1000) / 10;
    }

    printf("Avant\n");

    for (i = 0; i < 10; i++)
        printf("%d %.1f\n", *(pe + i), *(pr + i));

    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            *(pe + i) = *(pe + i) * 3;
            *(pr + i) = *(pr + i) * 3;
        }
    }

    printf("Apres\n");

    for (i = 0; i < 10; i++)
        printf("%d %.1f\n", *(pe + i), *(pr + i));

    return 0;
}
