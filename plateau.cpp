#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include "plateau.h"


#include "Liste_de_liste.h"
#include "helpers.h"

bool lire_plateau(Liste_mot& liste_mot, Plateau& plateau)
{
	Mot buffer;
	bool compteur = false;

	while (1)
	{
		scanf("%s", buffer);

		if (strcmp(buffer, "*") == 0) {
			return compteur; // si compteur = 0 on a entré seulement * dans la liste
		}

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
		scanf("%5s", unMot);
		for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
		{
			p[i][j] = unMot[j];
		}
	}

	return true;
}

void initialiser_plateau(Plateau_bool& p_bool)
{
	for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
	{
		for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
		{
			p_bool[i][j] = false;
		}
	}

}

bool sous_recherche(Mot mot, int pos, Coords c, Plateau& p, Plateau_bool& p_bool)
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

bool dans_le_plateau(Plateau& p, Mot mot)
{
	Plateau_bool p_bool;
	initialiser_plateau(p_bool);

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
