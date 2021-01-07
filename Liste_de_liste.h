#pragma once

#include "Liste_mot.h"

///////////////////////////////////////////////////
///    \brief Conteneur représentant une liste de
/// listes de mots
///////////////////////////////////////////////////
struct Liste_de_liste {
    Liste_mot* listes; ///< Contient les listes de mots entrées
    unsigned int nb_listes; ///< Contient le nombre de listes
};

/*
*  @brief Initialise un conteneur de liste de mots avec
*   une capacité et un coefficient d'extension
*
*  @param[in-out] conteneur_liste la liste de listes
*   qui sera initialisée
*/
void initialiser_liste(Liste_de_liste& conteneur_liste);

/*
*  @brief Lis un conteneur de listes de mots qui sera
*  entrée par l'utilsateur puis ajouter dans une liste
*  sans ajouter des doublons
*
*  @param[in-out] conteneur_liste la liste de listes de mots
*  que l'on va lire.
*/
void lire_liste(Liste_de_liste& conteneur_liste);

/*
*  @brief Ajouter une liste de mots à un conteneur de listes.
*
*  @param[in-out] conteneur_liste la liste de listes de mots
*  auquel on ajoutera le ou les listes de mots entrés.
*
*  @param[in] liste_mot liste de mots étant complétée et qui
*  sera entrée dans le conteneur de listes.
*/
void ajouter_liste(Liste_de_liste& conteneur_liste, Liste_mot& liste_mot);

/*
*  @brief Afficher un conteneur de listes de mots
*
*  @param[in] conteneur_liste la liste de listes de mots
*  que l'on va afficher.
*/
void afficher_liste(const Liste_de_liste& conteneur_liste);

/*
*  @brief Détruit un conteneur de liste de mots
*
*  @param[in] conteneur_liste la liste de listes de mots
*  que l'on va désallouer.
*/
void detruire_liste(Liste_de_liste& conteneur_liste);
