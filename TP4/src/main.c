#include <stdio.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

void exercice_operateurs(void)
{
    int a;
    int b;
    char op;
    int resultat = 0;

    printf("num1 : ");
    scanf("%d", &a);

    printf("num2 : ");
    scanf("%d", &b);

    printf("Operateur (+ - * / %% & | ~) : ");
    scanf(" %c", &op);

    switch (op)
    {
        case '+': resultat = somme(a, b); break;
        case '-': resultat = difference(a, b); break;
        case '*': resultat = produit(a, b); break;
        case '/':
            if (b == 0)
            {
                printf("Division par zero impossible\n");
                return;
            }
            resultat = quotient(a, b);
            break;
        case '%':
            if (b == 0)
            {
                printf("Modulo par zero impossible\n");
                return;
            }
            resultat = modulo(a, b);
            break;
        case '&': resultat = operation_et(a, b); break;
        case '|': resultat = operation_ou(a, b); break;
        case '~': resultat = negation(a, b); break;
        default:
            printf("Operateur inconnu\n");
            return;
    }

    printf("Resultat : %d\n", resultat);
}

void exercice_fichier(void)
{
    int choix;
    char nom[100];
    char message[300];

    printf("1. Lire\n2. Ecrire\nChoix : ");
    scanf("%d", &choix);

    printf("Nom du fichier : ");
    scanf("%99s", nom);

    if (choix == 1)
    {
        lire_fichier(nom);
    }
    else if (choix == 2)
    {
        getchar();
        printf("Message : ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';
        ecrire_dans_fichier(nom, message);
    }
}

void exercice_liste(void)
{
    struct liste_couleurs liste;
    struct couleur couleurs[10] = {
        {0xff, 0x00, 0x00, 0xff},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0xff},
        {0xff, 0x00, 0xff, 0xff},
        {0x00, 0xff, 0xff, 0xff},
        {0x80, 0x80, 0x80, 0xff},
        {0xff, 0xff, 0xff, 0xff},
        {0x00, 0x00, 0x00, 0xff},
        {0xef, 0x78, 0x12, 0xff}
    };
    int i;

    init_liste(&liste);

    for (i = 0; i < 10; i++)
        insertion(&couleurs[i], &liste);

    parcours(&liste);
    liberer_liste(&liste);
}

int main()
{
    int exercice;

    printf("Exercice 4.1, 4.2 ou 4.7 ? Entrez 1, 2 ou 7 : ");
    scanf("%d", &exercice);

    switch (exercice)
    {
        case 1:
            exercice_operateurs();
            break;
        case 2:
            exercice_fichier();
            break;
        case 7:
            exercice_liste();
            break;
        default:
            printf("Choix inconnu\n");
    }

    return 0;
}