#pragma once

#include "conteneurs.h"

/*
*  @brief Retourne le nombre de points pour un mot entré
* 
*  @param[in] mot le mot entré
* 
*  @return le nombre de points pour le mot
*/
unsigned int mots_vers_pts(const char* mot);

/*
*  @brief Ajoute un mot dans une liste de mots
* 
*  @param[out] liste_mot liste où sera contenu le nouveau mot
*  @paramin] buffer a ajouté dans la liste
*/
void ajouter(Liste_mot& liste_mot, Mot buffer);

/*
*  @brief Inverse le contenu de deux mots
* 
*  @param[in-out] mot1 Mot qui aura le contenu de mot2
*  @param[in-out] mot2 Mot qui aura le contenu de mot1
*/
void swap(Mot mot1, Mot mot2);

/*
*  @brief Initialise une liste de mots avec une capacité et
*  un coefficient d'extension
* 
*  @param[in-out] liste_mot la liste qui sera initialisée
*/
void initialiser(Liste_mot& liste_mot);

/*
*  @brief Trie par ordre alphabétique une liste de mots
*
*  @param[in-out] liste_mot la liste qui sera triée
*/
void trier(Liste_mot& liste_mot);

/*
*  @brief Affiche une liste de mots
*
*  @param[in] liste_mot la liste qui sera affichée
*/
void afficher(Liste_mot& liste_mot);

/*
*  @brief Vérifie l'existance d'un mot dans une liste de mots
*
*  @param[in] liste_mot la liste de mot étudié
*  @param[in] mot_test le mot dont on va vérifier l'existence
*  
*  @return Vrai si le mot existe dans la liste
*/
bool exister(const Liste_mot& liste_mot, const Mot mot_test);

/*
*  @brief Lis une liste de mots qui sera entrée par l'utilsateur
*  puis ajouter dans une liste sans ajouter des doublons
*
*  @param[in-out] liste_mot la liste de mot auquel on ajoutera 
*  les mots entrés.
*  
*
*  @return Vrai si au moins un mot a été ajouté à la liste
*/
bool lire(Liste_mot& liste_mot);


bool lire(Liste_mot& liste_mot, Plateau& plateau);
void sans_repetition(Liste_mot& liste_mot, Liste_mot& liste_mot2);
void avec_repetition(Liste_mot& liste_mot, Liste_mot& liste_mot2);






void initialiser_liste(Liste_de_liste& conteneur_liste);
void lire_liste(Liste_de_liste& conteneur_liste);
void ajouter_liste(Liste_de_liste& conteneur_liste, Liste_mot& liste_mot);
void afficher_liste(Liste_de_liste& conteneur_liste);
void detruire_liste(Liste_de_liste& conteneur_liste);






bool ajouter_plateau(Plateau& p);
void initialiser_plateau(Plateau_bool& p_bool);
bool dans_le_plateau(Plateau& p, Mot mot); // fonction de recherche
