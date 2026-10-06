#include <stdio.h>

int main()
{
    char chaine1[100] = "Hello";
    char chaine2[100] = " World!";
    char copie[100];

    int longueur = 0;
    int i = 0;
    int j = 0;

    while (chaine1[longueur] != '\0')
        longueur++;

    while (chaine1[i] != '\0')
    {
        copie[i] = chaine1[i];
        i++;
    }

    copie[i] = '\0';

    i = longueur;

    while (chaine2[j] != '\0')
    {
        chaine1[i] = chaine2[j];
        i++;
        j++;
    }

    chaine1[i] = '\0';

    printf("Longueur : %d\n", longueur);
    printf("Copie : %s\n", copie);
    printf("Concatenation : %s\n", chaine1);

    return 0;
}
