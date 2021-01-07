/**
 * @file plateau.cpp
 * @author Logan Tann (LoganTann), Ibrahime Ahbib (Braxoia)
 * @version 1 07/01/2021
 * @brief Fonctions permettant la manipulation d'un plateau, et définition de ce
 *        dernier.
 */

#include <iostream> // std::cin std::cout
#include <cstring> // strcpy strcpy

#include "plateau.h"

#include "Liste_mot.h" // + Mot et constantes
#include "helpers.h" // exister

bool entree_dans_plateau(Liste_mot& liste_mot, const Plateau& plateau)
{
	Mot buffer;
	bool compteur = false;

	while (1)
	{
		std::cin >> buffer;

		if (strcmp(buffer, "*") == 0) {
			return compteur; // si compteur = 0 on a entré seulement * dans la liste
		}

		/* skip si c'est pas dans le plateau */
		if (!dans_le_plateau(plateau, buffer))
			continue;

		if (!exister(liste_mot, buffer)) {
			ajouter(liste_mot, buffer);
			compteur = true;
		}
	}

	// inutile mais bon...
	return compteur;
}

bool ajouter_plateau(Plateau& p)
{
	Mot unMot;
	for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
	{
		std::cin >> unMot; // sera tronqué juste ci-dessous
		for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
		{
			p[i][j] = unMot[j];
		}
	}

	return true;
}

void initialiser_plateau_bool(Plateau_bool& p_bool)
{
	for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
	{
		for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
		{
			p_bool[i][j] = false;
		}
	}

}

// fonctions de recherche ---

bool sous_recherche(const Mot mot, int pos, Coords c, const Plateau p, Plateau_bool& p_bool)
{
	if (pos == strlen(mot)) {
		return true; // <=> le mot (complet) a été trouvé dans le plateau !
	}
	if (c.ligne >= 4 || c.col >= 4 || c.ligne < 0 || c.col < 0) {
		return false; // hors limite !!
	}
	if (p[c.ligne][c.col] != mot[pos]) {
		return false; // case correspond pas à la lettre recherchée
	}
	if (p_bool[c.ligne][c.col]) {
		return false; // c'est visité :-(
	}

	p_bool[c.ligne][c.col] = true; // pas visité donc on marque comme visité

	for (int ligne = c.ligne - 1; ligne <= c.ligne + 1; ligne++)
	{
		for (int col = c.col - 1; col <= c.col + 1; col++)
		{
			if (sous_recherche(mot, pos + 1, { ligne, col }, p, p_bool))
			{
				return true;
			}
		}
	}

	p_bool[c.ligne][c.col] = false; // pas visité donc on marque comme visité
	return false;
}

bool dans_le_plateau(const Plateau& p, const Mot mot)
{
	Plateau_bool p_bool;
	initialiser_plateau_bool(p_bool);

	for (int ligne = 0; ligne < TAILLE_PLATEAU; ligne++)
	{
		for (int col = 0; col < TAILLE_PLATEAU; col++)
		{
			// Mot mot, int pos, Coords c, Plateau& p, Plateau_bool& p_bool
			if (sous_recherche(mot, 0, { ligne, col }, p, p_bool))
			{
				return true;
			}
		}
	}
	return false;
}
