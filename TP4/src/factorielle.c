#include <stdio.h>

unsigned long long factorielle(unsigned int n)
{
    if (n == 0)
        return 1;

    return n * factorielle(n - 1);
}

int main()
{
    unsigned int valeurs[] = {0, 1, 3, 5, 10};
    int i;

    for (i = 0; i < 5; i++)
        printf("%u! = %llu\n", valeurs[i], factorielle(valeurs[i]));

    return 0;
}