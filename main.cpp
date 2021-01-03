#include <cstdio>
#include <iostream>
#include <cstring>

#include "helpers.h"
#include "conteneurs.h"

#pragma warning(disable:4996)

int main(void)
{
    unsigned int nb_pts = 0;

    Liste_mot cette_liste, cette_liste2;
    initialiser(cette_liste);
    initialiser(cette_liste2);
    
    lire(cette_liste);
    lire(cette_liste2);

    trier(cette_liste);
    trier(cette_liste2);

    // afficher les éléments de liste_mot2 qui sont **dans** liste_mot1
    avec_repetition(cette_liste, cette_liste2);
    

    // TODO : faire une fonction detruire
    delete[] cette_liste.tab;
    delete[] cette_liste2.tab;

    return 0;
}
