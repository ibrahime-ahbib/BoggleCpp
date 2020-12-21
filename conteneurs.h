#pragma once

#include "constantes.h"

typedef char Mot[TAILLE_MAX + 1];

typedef char Plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
typedef bool Plateau_bool[TAILLE_PLATEAU][TAILLE_PLATEAU];

struct Liste_mot {
	Mot* tab;
	unsigned int inserted;
};

struct Liste_de_liste {
	Liste_mot* listes;
	unsigned int nb_listes;
};

struct Coords {
	int ligne;
	int col;
};
