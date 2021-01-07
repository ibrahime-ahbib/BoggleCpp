/**
 * @file Liste_de_liste.cpp
 * @author Logan Tann (LoganTann), Ibrahime Ahbib (Braxoia)
 * @version 1 07/01/2021
 * @brief Conteneur dynamique extensible symplifié permettant le stockage de
 *        liste de mots.
 * @see Liste_mot.cpp pour la définition du type Liste_mot, et helpers.cpp pour 
 *      les fonctions de manipulations non basiques (recherche...)
 */

#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include "Liste_de_liste.h"
#include "helpers.h"

void initialiser_liste(Liste_de_liste& conteneur_liste)
{
	conteneur_liste.nb_listes = 0;
	conteneur_liste.listes = new Liste_mot[1];

	initialiser(conteneur_liste.listes[0]);
}



void lire_liste(Liste_de_liste& conteneur_liste)
{
	while (1)
	{
		Liste_mot liste_mot;
		initialiser(liste_mot);
		if (!lire(liste_mot)) {
			break;
		}
		trier(liste_mot);
		ajouter_liste(conteneur_liste, liste_mot);
	}
}

void ajouter_liste(Liste_de_liste& conteneur_liste, Liste_mot& liste_mot)
{
	unsigned int idx = conteneur_liste.nb_listes++;
	Liste_mot* nouveau_tableau_de_listes = new Liste_mot[idx + 1];

	for (unsigned int i = 0; i < idx; ++i)
	{
		unsigned int inserted = conteneur_liste.listes[i].inserted;
		nouveau_tableau_de_listes[i].inserted = inserted;
		nouveau_tableau_de_listes[i].tab = conteneur_liste.listes[i].tab;
	}

	nouveau_tableau_de_listes[idx].inserted = liste_mot.inserted;
	nouveau_tableau_de_listes[idx].tab = liste_mot.tab;

	delete[] conteneur_liste.listes;
	conteneur_liste.listes = nouveau_tableau_de_listes;
}

void afficher_liste(const Liste_de_liste& conteneur_liste)
{
	Liste_mot liste_fin;
	initialiser(liste_fin);

	//la liste de tous les mots
	for (unsigned int i = 0; i < conteneur_liste.nb_listes; ++i)
	{
		for (unsigned int j = 0; j < conteneur_liste.listes[i].inserted; ++j)
		{
			ajouter(liste_fin, conteneur_liste.listes[i].tab[j]);
		}
	}

	trier(liste_fin);


	Mot dernier_mot_doublon = "";
	//std::cout << liste_fin.tab[0] << std::endl;
	for (unsigned int i = 1; i < liste_fin.inserted; i++)
	{
		if (strcmp(liste_fin.tab[i], dernier_mot_doublon) == 0) {
			continue;
		}

		if (strcmp(liste_fin.tab[i - 1], liste_fin.tab[i]) == 0) {
			strcpy(dernier_mot_doublon, liste_fin.tab[i]);

			std::cout << liste_fin.tab[i] << std::endl;
		}
		// std::cout << liste_fin.tab[i] << std::endl;
	}
	std::cout << "*";

}
void detruire_liste(Liste_de_liste& conteneur_liste)
{
	conteneur_liste.nb_listes = 0;

	for (unsigned int i = 0; i < conteneur_liste.nb_listes; ++i)
	{
		delete[] conteneur_liste.listes[i].tab;
	}

	delete[] conteneur_liste.listes;
}
