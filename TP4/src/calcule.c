#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[])
{
    char op;
    int a;
    int b = 0;
    int resultat;

    if (argc < 3)
    {
        printf("Utilisation : %s <operateur> <num1> [num2]\n", argv[0]);
        return 1;
    }

    op = argv[1][0];
    a = atoi(argv[2]);

    if (argc >= 4)
        b = atoi(argv[3]);

    switch (op)
    {
        case '+': resultat = somme(a, b); break;
        case '-': resultat = difference(a, b); break;
        case '*': resultat = produit(a, b); break;
        case '/':
            if (b == 0) return 1;
            resultat = quotient(a, b);
            break;
        case '%':
            if (b == 0) return 1;
            resultat = modulo(a, b);
            break;
        case '&': resultat = operation_et(a, b); break;
        case '|': resultat = operation_ou(a, b); break;
        case '~': resultat = negation(a, b); break;
        default:
            printf("Operateur inconnu\n");
            return 1;
    }

    printf("Resultat : %d\n", resultat);
    return 0;
}