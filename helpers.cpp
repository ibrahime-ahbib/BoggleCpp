#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include "constantes.h"
#include "conteneurs.h"
#include "helpers.h"

#pragma warning(disable:4996)

unsigned int mots_vers_pts(const char* mot)
{
	size_t taille_mot = strlen(mot);
	if (taille_mot >= 8) {
		return 11;
	}
	switch (taille_mot) {
	case 0:
	case 1:
	case 2: return 0;
	case 3:
	case 4: return 1;
	case 5: return 2;
	case 6: return 3;
	case 7: return 5;
	default: return 0;
	}
}



bool lire(Liste_mot & liste_mot)
{
	Mot buffer;
	bool compteur = false;

	while (1)
    {
		scanf("%s", buffer);

		if (strcmp(buffer, "*") == 0) {
			return compteur; // si compteur = 0 on a entré seulement * dans la liste
		}

		if (!exister(liste_mot, buffer)) {
			ajouter(liste_mot, buffer);
			compteur = true;
		}
    }

	// inutile mais bon...
	return compteur;
}

/*
	lire sauf que y'a vérification de plateau
*/
bool lire(Liste_mot& liste_mot, Plateau& plateau)
{
	Mot buffer;
	bool compteur = false;

	while (1)
    {
		scanf("%s", buffer);

		if (strcmp(buffer, "*") == 0) {
			return compteur; // si compteur = 0 on a entré seulement * dans la liste
		}

		if ( !dans_le_plateau(plateau, buffer) )
			continue;

		if (!exister(liste_mot, buffer)) {
			ajouter(liste_mot, buffer);
			compteur = true;
		}
    }

	// inutile mais bon...
	return compteur;
}

bool exister(Liste_mot& liste_mot, Mot mot_test)
{
	for (unsigned int i = 0; i < liste_mot.inserted; ++i)
	{
		if (strcmp(liste_mot.tab[i], mot_test) == 0)
			return true;
	}

	return false;
}

void ajouter(Liste_mot& liste_mot, Mot buffer)
{
	unsigned int idx = liste_mot.inserted++;

	Mot* nouveau_tableau = new Mot[idx + 1];
	for (unsigned int i = 0; i < idx; ++i)
	{
		strcpy(nouveau_tableau[i], liste_mot.tab[i]);
	}
	strcpy(nouveau_tableau[idx], buffer);
	delete[] liste_mot.tab;
	liste_mot.tab = nouveau_tableau;
}

void initialiser(Liste_mot& liste_mot)
{
	liste_mot.inserted = 0;
	liste_mot.tab = new Mot[1];
}

void swap(Mot mot1, Mot mot2)
{
	Mot tmp;
	strcpy(tmp, mot1);
	strcpy(mot1, mot2);
	strcpy(mot2, tmp);
}

void afficher(Liste_mot& liste_mot)
{
	for (unsigned int i = 0; i < liste_mot.inserted; ++i)
	{
		std::cout << liste_mot.tab[i] << std::endl;
	}
	std::cout << "*" << std::endl;

}

void sans_repetition(Liste_mot& liste_mot1, Liste_mot& liste_mot2)
{
	for (unsigned int i = 0; i < liste_mot2.inserted; ++i)
	{
		if (exister(liste_mot1, liste_mot2.tab[i])) {
			continue;
		} 
		std::cout << liste_mot2.tab[i] << std::endl;
	}
	std::cout << "*" << std::endl;
}

void avec_repetition(Liste_mot& liste_mot1, Liste_mot& liste_mot2)
{
	for (unsigned int i = 0; i < liste_mot2.inserted; ++i)
	{
		if (!exister(liste_mot1, liste_mot2.tab[i])) {
			continue;
		}
		std::cout << liste_mot2.tab[i] << std::endl;
	}
	std::cout << "*" << std::endl;
}

void trier(Liste_mot& liste_mot)
{
	assert(liste_mot.inserted > 0);

	for (int i = liste_mot.inserted; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (strcmp(liste_mot.tab[j], liste_mot.tab[j + 1]) == 1)
			{
				swap(liste_mot.tab[j], liste_mot.tab[j + 1]);
			}
		}
	}
}


void initialiser_liste(Liste_de_liste& conteneur_liste)
{
	conteneur_liste.nb_listes = 0;
	conteneur_liste.listes = new Liste_mot[1];

	initialiser(conteneur_liste.listes[0]);

	return;
}



void lire_liste(Liste_de_liste & conteneur_liste)
{
    while (1)
    {
        Liste_mot liste_mot;
        initialiser(liste_mot);
        if (lire(liste_mot) == 0) {
            break;
        }
        trier(liste_mot);
        ajouter_liste(conteneur_liste, liste_mot);
        delete[] liste_mot.tab;
    }
}
//void lire_liste(Liste_de_liste& conteneur_liste, Plateau& plateau)
//{
//	while (1)
//	{
//		Liste_mot liste_mot;
//		initialiser(liste_mot);
//
//		
//		if (! lire(liste_mot, plateau)) {
//			break;
//		}
//		trier(liste_mot);
//		ajouter_liste(conteneur_liste, liste_mot);
//		delete[] liste_mot.tab;
//	}
//}

void ajouter_liste(Liste_de_liste& conteneur_liste, Liste_mot& liste_mot)
{
	unsigned int idx = conteneur_liste.nb_listes++;
	Liste_mot* nouveau_tableau_de_listes = new Liste_mot[idx + 1];

	for(unsigned int i = 0; i < idx; ++i)
	{
		unsigned int inserted = conteneur_liste.listes[i].inserted; 
		nouveau_tableau_de_listes[i].inserted = inserted;
		nouveau_tableau_de_listes[i].tab = new Mot[inserted];
		for (unsigned int j = 0; j < inserted; j++) {
			strcpy(nouveau_tableau_de_listes[i].tab[j], conteneur_liste.listes[i].tab[j]);
		}
	}

	nouveau_tableau_de_listes[idx].inserted = liste_mot.inserted;
	nouveau_tableau_de_listes[idx].tab = new Mot[liste_mot.inserted + 1];
	for (unsigned int j = 0; j < liste_mot.inserted; j++)
	{
		strcpy(nouveau_tableau_de_listes[idx].tab[j], liste_mot.tab[j]);
	}

	delete[] conteneur_liste.listes;
	conteneur_liste.listes = nouveau_tableau_de_listes;
	
}
void afficher_liste(Liste_de_liste& conteneur_liste) 
{
	Liste_mot liste_fin;
	initialiser(liste_fin);

	//la liste de tous les mots 
	for (unsigned int i = 0; i < conteneur_liste.nb_listes; ++i) 
	{
		for(unsigned int j = 0; j < conteneur_liste.listes[i].inserted; ++j)
		{
			ajouter(liste_fin, conteneur_liste.listes[i].tab[j]);
		}
	}

	trier(liste_fin);
	

	Mot dernier_mot_doublon = "";
	std::cout << liste_fin.tab[0] << std::endl;
	for (unsigned int i = 1; i < liste_fin.inserted; i++)
	{
		if (strcmp(liste_fin.tab[i], dernier_mot_doublon) == 0) {
			continue;
		}
		
		if (strcmp(liste_fin.tab[i - 1], liste_fin.tab[i]) == 0) {
			strcpy(dernier_mot_doublon, liste_fin.tab[i]);
		}
		std::cout << liste_fin.tab[i] << std::endl;
	}
	std::cout << "*";

}
void detruire_liste(Liste_de_liste& conteneur_liste) 
{
	conteneur_liste.nb_listes = 0;
	
	for(unsigned int i = 0; i < conteneur_liste.nb_listes; ++i)
	{
		delete[] conteneur_liste.listes[i].tab;
	}

	delete[] conteneur_liste.listes;
}

bool ajouter_plateau(Plateau& p)
{
	Mot unMot;
	for (unsigned int i= 0; i < TAILLE_PLATEAU; i++)
	{
		scanf("%5s", unMot);
		for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
		{
			if (unMot[j] >= 'A' && unMot[j] <= 'Z') {
				p[i][j] = unMot[j];
			} else {
				return false;
			}
		}
	}
	return true;
}

// inutile mais bon pour le debug
void afficher_plateau(const Plateau& p)
{
	for (unsigned int i= 0; i< TAILLE_PLATEAU; i++)
	{
		for (unsigned int j = 0; j< TAILLE_PLATEAU; j++)
		{
			printf("plateau[%d][%d] = %c \n", i,  j,  p[i][j]);
		}
	}
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
	if (pos >= strlen(mot)) {
		return true; // <=> le mot (complet) a été trouvé dans le plateau !
	}
	if ((c.ligne > 4 || c.col > 4) || (c.ligne < 0 || c.col < 0)) {
		return false; // hors limite !!
	}
	if (p[c.ligne][c.col] != mot[pos]) {
		return false; // case correspond pas à la lettre recherchée
	}

	if (p_bool[c.ligne][c.col]) {
		return false; // c'est visité :-(
	}

	p_bool[c.ligne][c.col] = true; // pas visité donc on marque comme visité

	for (int ligne = c.ligne - 1; ligne <= c.ligne + 1; ligne++) {
		for (int col = c.col - 1; col <= c.col + 1; col++)
		{			
			if (sous_recherche(mot, pos + 1, { ligne, col }, p, p_bool)) {
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
			if (sous_recherche(mot, 0, {ligne, col}, p, p_bool))
				return true;
		}
	}
	return false;
}
