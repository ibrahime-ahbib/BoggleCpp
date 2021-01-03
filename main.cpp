#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>

#include "conteneurs.h"
#include "helpers.h"

#pragma warning(disable:4996)

int exo1()
{
    unsigned int nb_pts = 0;
    char buffer[TAILLE_MAX + 1];
    while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0)
            break;

        nb_pts += mots_vers_pts(buffer);
    }
    std::cout << nb_pts;

    return 0;
}

int exo2()
{
    Mot buffer;

    Liste_mot cette_liste;
    initialiser(cette_liste);
    while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0) {
            break; // skip
        }

        if (!exister(cette_liste, buffer))
            ajouter(cette_liste, buffer);
    }

    trier(cette_liste);
    afficher(cette_liste);

    delete[] cette_liste.tab;

    return 0;
}

int exo3() {


    Liste_mot cette_liste, cette_liste2;
    initialiser(cette_liste);
    initialiser(cette_liste2);

    lire(cette_liste);
    lire(cette_liste2);

    trier(cette_liste);
    trier(cette_liste2);

    // afficher les éléments de liste_mot2 qui ne sont pas dans liste_mot1
    sans_repetition(cette_liste, cette_liste2);

    delete[] cette_liste.tab;
    delete[] cette_liste2.tab;

    return 0;
}

int exo4() 
{

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

int exo5() {

    Liste_de_liste liste_de_liste;
    initialiser_liste(liste_de_liste);
    lire_liste(liste_de_liste);
    afficher_liste(liste_de_liste);
    detruire_liste(liste_de_liste);
 
    return 0;
}

int exo6()
{
    Plateau plateau;

    bool verif = ajouter_plateau(plateau);
    assert(verif);

    Liste_mot cette_liste;
    initialiser(cette_liste);
    lire(cette_liste, plateau);

    trier(cette_liste);
    afficher(cette_liste);

    delete[] cette_liste.tab;
    return 0;
}

int main() 
{
    int num;

    std::cin >> num;

    switch (num)
    {
    case 1:
        return exo1();
    case 2:
        return exo2();
    case 3:
        return exo3();
    case 4:
        return exo4();
    case 5:
        return exo5();
    case 6:
        return exo6();
    }

    return 1;
}
