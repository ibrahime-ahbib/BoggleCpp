#pragma once

#include "constantes.h"

typedef char Mot[TAILLE_MAX + 1];

struct Liste_mot {
	Mot* tab;
	unsigned int inserted;
};

struct Liste_de_liste {
	Liste_mot* listes;
	unsigned int nb_listes;
};
