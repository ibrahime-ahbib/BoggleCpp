#include <cstdio>
#include <iostream>
#include <cstring>

#include "helpers.h"
#include "conteneurs.h"

#pragma warning(disable:4996)

int main(void)
{
    unsigned int nb_pts = 0;
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