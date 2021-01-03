#pragma once

#include "constantes.h"

typedef char Mot[TAILLE_MAX + 1];

struct Liste_mot {
	Mot* tab;
	unsigned int inserted;
};
