#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include "fonction_listes.h"


#pragma warning(disable:4996)

unsigned int mots_vers_pts(const char* mot)
{
	size_t taille_mot = strlen(mot);
	if (taille_mot >= 8) {
		return 11;
	}
	switch (taille_mot)
	{
		case 0: return 0;
		case 1: return 0;
		case 2:	return 0;
		case 3: return 1;
		case 4: return 1;
		case 5: return 2;
		case 6: return 3;
		case 7: return 5;
		default: return 0;
	}
}

bool lire(Liste_mot& liste_mot)
{
	Mot buffer;
	bool success = false;

	while (1)
	{
		scanf("%s", buffer);

		if (strcmp(buffer, "*") == 0)
		{
			return success; // si compteur = 0 on a entré seulement * dans la liste
		}

		if (liste_mot.capacite > 500 || !exister(liste_mot, buffer)) //permet de savoir si ce que j'étudie c'est un dictionnaire ou simplement une liste de mots
		{
			ajouter(liste_mot, buffer);
			success = true;
		}
	}

	return success;
}

bool exister(const Liste_mot& liste_mot, const Mot mot_test)
{
	for (unsigned int i = 0; i < liste_mot.inserted; ++i)
	{
		if (strcmp(liste_mot.tab[i], mot_test) == 0)
			return true;
	}

	return false;
}

void initialiser(Liste_mot& liste_mot)
{
	liste_mot.inserted = 0;
	liste_mot.capacite = 10;
	liste_mot.tab = new Mot[liste_mot.capacite];
}

void ajouter(Liste_mot& liste_mot, Mot buffer)
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

void sans_repetition(const Liste_mot& liste_mot1, const Liste_mot& liste_mot2)
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

void avec_repetition(const Liste_mot& liste_mot1, const Liste_mot& liste_mot2)
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


static int comparer_mots(void const* a, void const* b) //Prototype à suivre pour le qsort
{
	const Mot* pa = (const Mot*)a;
	const Mot* pb = (const Mot*)b;

	/*cast en const Mot* pour deux raisons :
		1) Renseigner au void le type que je veux manipuler
		2) Renseigner à pa l'adresse vers mon Mot qui est lui aussi déjà une adresse
	*/
	return strcmp(*pa, *pb);
}

void trier(Liste_mot& liste_mot)
{
	if (liste_mot.inserted < 2) return;

	if (liste_mot.capacite > 1000) return; //Permet de savoir si il ce qu'on trie est le dictionnaire,
										   //dans le cas échéant, on ne trie pas.

	qsort(liste_mot.tab, liste_mot.inserted, sizeof(Mot), comparer_mots);
}
