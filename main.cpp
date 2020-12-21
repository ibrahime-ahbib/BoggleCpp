#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>

#include "conteneurs.h"
#include "helpers.h"

#pragma warning(disable:4996)

int main(void)
{

    unsigned int nb_pts = 0;

    Plateau plateau;
    assert(ajouter_plateau(plateau));

    afficher_plateau(plateau);
    Liste_de_liste liste_de_liste;
    initialiser_liste(liste_de_liste);
    lire_liste(liste_de_liste);
    //dans_le_plateau(p,)
    afficher_liste(liste_de_liste);
    detruire_liste(liste_de_liste);

    return 0;
}
