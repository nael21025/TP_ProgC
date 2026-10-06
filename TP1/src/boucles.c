#include <stdio.h>

int main()
{
    int compteur = 5;
    int i;
    int j;

    for (i = 1; i <= compteur; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (i == compteur || j == 1 || j == i)
                printf("* ");
            else
                printf("# ");
        }

        printf("\n");
    }

    return 0;
}
