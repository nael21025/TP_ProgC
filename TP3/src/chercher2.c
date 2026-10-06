#include <stdio.h>

int chaines_egales(const char *a, const char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return 0;

        i++;
    }

    return a[i] == '\0' && b[i] == '\0';
}

int main()
{
    const char *phrases[10] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[200];
    int trouve = 0;
    int i;
    int j = 0;

    printf("Phrase a chercher : ");
    fgets(recherche, sizeof(recherche), stdin);

    while (recherche[j] != '\0')
    {
        if (recherche[j] == '\n')
        {
            recherche[j] = '\0';
            break;
        }
        j++;
    }

    for (i = 0; i < 10; i++)
    {
        if (chaines_egales(phrases[i], recherche))
        {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Phrase trouvee\n");
    else
        printf("Phrase non trouvee\n");

    return 0;
}