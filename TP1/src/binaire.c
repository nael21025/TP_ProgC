#include <stdio.h>

int main()
{
    int nombres[5] = {0, 4096, 65536, 65535, 1024};
    int binaire[32];
    int i;
    int j;
    int nombre;
    int taille;

    for (i = 0; i < 5; i++)
    {
        nombre = nombres[i];
        taille = 0;

        if (nombre == 0)
        {
            printf("0\n");
            continue;
        }

        while (nombre > 0)
        {
            binaire[taille] = nombre % 2;
            nombre = nombre / 2;
            taille++;
        }

        for (j = taille - 1; j >= 0; j--)
            printf("%d", binaire[j]);

        printf("\n");
    }

    return 0;
}
