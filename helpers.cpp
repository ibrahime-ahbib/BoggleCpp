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

void lire(Liste_mot& liste_mot)
{
	Mot buffer;
	while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0) {
			return;
        }

        if (!exister(liste_mot, buffer))
            ajouter(liste_mot, buffer);
    }
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

/*void retirer(Liste_mot& liste_mot, int j)
{
	unsigned int idx = --liste_mot.inserted;

	Mot* nouveau_tableau = new Mot[idx];
	unsigned int compteur = 0;
	for (unsigned int i = 0; i < idx; ++i)
	{
		if (i != j) {
			strcpy(nouveau_tableau[compteur], liste_mot.tab[i]);
			compteur++;
		}
	}
	delete[] liste_mot.tab;
	liste_mot.tab = nouveau_tableau;
}*/

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
