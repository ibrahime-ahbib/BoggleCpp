#include <cstdio>
#include <iostream>
#include <cstring>

#include "conteneurs.h"
#include "helpers.h"

#pragma warning(disable:4996)

int main(void)
{
    unsigned int nb_pts = 0;

    Liste_de_liste liste_de_liste;
    initialiser_liste(liste_de_liste);
    lire_liste(liste_de_liste);
    afficher_liste(liste_de_liste);
    detruire_liste(liste_de_liste);

    return 0;
}