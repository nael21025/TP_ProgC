#ifndef LISTE_H
#define LISTE_H

struct couleur
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct element
{
    struct couleur couleur;
    struct element *suivant;
};

struct liste_couleurs
{
    struct element *premier;
};

void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *couleur, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste);

#endif