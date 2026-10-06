#include <stdio.h>

int main()
{
    int n = 7;
    int a = 0;
    int b = 1;
    int suivant;
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a);

        suivant = a + b;
        a = b;
        b = suivant;
    }

    printf("\n");

    return 0;
}
