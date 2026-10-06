#include <stdio.h>

int main()
{
    int a = 2;
    int b = 3;
    int resultat = 1;
    int i;

    for (i = 0; i < b; i++)
        resultat = resultat * a;

    printf("%d\n", resultat);

    return 0;
}
