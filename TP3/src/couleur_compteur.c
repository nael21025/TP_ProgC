#include <stdio.h>

struct Couleur
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct CouleurComptee
{
    struct Couleur couleur;
    int compteur;
};

int egales(struct Couleur a, struct Couleur b)
{
    return a.r == b.r &&
           a.g == b.g &&
           a.b == b.b &&
           a.a == b.a;
}

int main()
{
    struct Couleur couleurs[100];
    struct CouleurComptee distinctes[100];
    struct Couleur exemples[5] = {
        {0xff, 0x23, 0x23, 0x45},
        {0xff, 0x00, 0x23, 0x12},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0xff}
    };

    int nombreDistinct = 0;
    int i;
    int j;
    int trouve;

    for (i = 0; i < 100; i++)
        couleurs[i] = exemples[i % 5];

    for (i = 0; i < 100; i++)
    {
        trouve = 0;

        for (j = 0; j < nombreDistinct; j++)
        {
            if (egales(couleurs[i], distinctes[j].couleur))
            {
                distinctes[j].compteur++;
                trouve = 1;
                break;
            }
        }

        if (!trouve)
        {
            distinctes[nombreDistinct].couleur = couleurs[i];
            distinctes[nombreDistinct].compteur = 1;
            nombreDistinct++;
        }
    }

    for (i = 0; i < nombreDistinct; i++)
    {
        printf("%02x %02x %02x %02x : %d\n",
               distinctes[i].couleur.r,
               distinctes[i].couleur.g,
               distinctes[i].couleur.b,
               distinctes[i].couleur.a,
               distinctes[i].compteur);
    }

    return 0;
}