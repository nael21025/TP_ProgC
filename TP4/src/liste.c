#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste)
{
    liste->premier = NULL;
}

void insertion(struct couleur *couleur, struct liste_couleurs *liste)
{
    struct element *nouveau = malloc(sizeof(struct element));

    if (nouveau == NULL)
        return;

    nouveau->couleur = *couleur;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void parcours(struct liste_couleurs *liste)
{
    struct element *courant = liste->premier;

    while (courant != NULL)
    {
        printf("R=%u G=%u B=%u A=%u\n",
               courant->couleur.r,
               courant->couleur.g,
               courant->couleur.b,
               courant->couleur.a);

        courant = courant->suivant;
    }
}

void liberer_liste(struct liste_couleurs *liste)
{
    struct element *courant = liste->premier;

    while (courant != NULL)
    {
        struct element *suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }

    liste->premier = NULL;
}