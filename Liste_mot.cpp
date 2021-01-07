/**
 * @file Liste_mot.cpp
 * @author Logan Tann (LoganTann), Ibrahime Ahbib (Braxoia)
 * @version 1 07/01/2021
 * @brief Conteneur dynamique extensible optimisé pour stocker des éléments de
 *        type Mot
 */

#include <iostream>// std::cin, std::cout ..
#include <cstring> // strcpy

#include "Liste_mot.h"

void initialiser(Liste_mot& liste_mot)
{
	liste_mot.inserted = 0;
	liste_mot.capacite = 10;
	liste_mot.tab = new Mot[liste_mot.capacite];
}

void ajouter(Liste_mot& liste_mot, const Mot buffer)
{
	unsigned int nouvTaille;
	unsigned int idx = liste_mot.inserted++;

	if (idx < liste_mot.capacite)
	{
		strcpy(liste_mot.tab[idx], buffer);
	}
	else {
		nouvTaille = ((idx <= 100000) ? liste_mot.coef_extension_defaut : liste_mot.coef_extension_grooos) * liste_mot.capacite;

		Mot* nouveau_tableau = new Mot[nouvTaille];
		for (unsigned int i = 0; i < idx; ++i)
		{
			strcpy(nouveau_tableau[i], liste_mot.tab[i]);
		}
		strcpy(nouveau_tableau[idx], buffer);

		delete[] liste_mot.tab;

		liste_mot.tab = nouveau_tableau;
		liste_mot.capacite = nouvTaille;
	}


}

void afficher(const Liste_mot& liste_mot)
{
	for (unsigned int i = 0; i < liste_mot.inserted; ++i)
	{
		std::cout << liste_mot.tab[i] << std::endl;
	}
	std::cout << "*" << std::endl;

}
