#pragma once

#include "conteneurs.h"

unsigned int mots_vers_pts(const char* mot);
void ajouter(Liste_mot& liste_mot, Mot buffer);
void swap(Mot mot1, Mot mot2);
void initialiser(Liste_mot& liste_mot);
void trier(Liste_mot& liste_mot);
void afficher(Liste_mot& liste_mot);
bool exister(Liste_mot& liste_mot, Mot mot_test);

int lire(Liste_mot& liste_mot);
void sans_repetition(Liste_mot& liste_mot, Liste_mot& liste_mot2);
void avec_repetition(Liste_mot& liste_mot, Liste_mot& liste_mot2);

void initialiser_liste(Liste_de_liste& conteneur_liste);
void lire_liste(Liste_de_liste& conteneur_liste);
void ajouter_liste(Liste_de_liste& conteneur_liste, Liste_mot& liste_mot);
void afficher_liste(Liste_de_liste& conteneur_liste);
void detruire_liste(Liste_de_liste& conteneur_liste);

/**
 * @brief
 * @see https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles
 * @pre
 *
*/
