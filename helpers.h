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
void afficher(const Liste_mot& liste_mot);

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
*  @brief Lis un ou plusieurs mots qui seront entrés par l'utilsateur
*  puis ajouter dans une liste de mots sans ajouter des doublons
*
*  @param[in-out] liste_mot la liste de mot auquel on ajoutera 
*  les mots entrés.
*  
*
*  @return Vrai si au moins un mot a été ajouté à la liste
*/
bool lire(Liste_mot& liste_mot);

/*
*  @brief Lis un ou plusieurs mots qui seront entrés par l'utilsateur
*  puis ajouter dans une liste si ils sont contenus dans le plateau
*
*  @param[in-out] liste_mot la liste de mot auquel on ajoutera
*  les mots entrés.
* 
*  @param[in] plateau le plateau dans lequel le mot sera vérifié
*  avant d'être ajouté.
*
*  @return Vrai si au moins un mot a été ajouté à la liste
*/
bool lire(Liste_mot& liste_mot, Plateau& plateau);

/*
*  @brief Affiche les mots de la seconde liste n'aparaissant pas 
*   dans la première
*
*  @param[in] liste_mot la liste qui sera comparée à la deuxieme
*  @param[in] liste_mot2 la liste qui sera étudié afin qu'elle 
*  affiche les mots demandés
*/
void sans_repetition(const Liste_mot& liste_mot, const Liste_mot& liste_mot2);

/*
*  @brief Affiche les mots de la seconde liste aparaissant 
*   dans la première
*
*  @param[in] liste_mot la liste qui sera comparée à la deuxieme
*  @param[in] liste_mot2 la liste qui sera étudié afin qu'elle 
*  affiche les mots demandés
*/
void avec_repetition(const Liste_mot& liste_mot, const Liste_mot& liste_mot2);





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





/*
*  @brief Insère un plateau entrée par l'utilisateur 
*  dans notre plateau
* 
*  @param[in-out] p plateau dans lequel on aura notre 
*  plateau entré
* 
*  @return Vrai si le plateau a bien été rajouté
*/
bool ajouter_plateau(Plateau& p);

/*
*  @brief Initialise les cases d'un plateau comme
*  non-visitées
*
*  @param[in-out] p_bool plateau dans lequel on aura nos
*  cases non-visitées.
*/
void initialiser_plateau(Plateau_bool& p_bool);

/*
*  @brief Vérifie si le mot entré par l'utilisateur
*  est bien dans le plateau
*
*  @param[in] p plateau où l'on va vérifier l'existence
*  du mot
* 
*  @param[in] mot Mot qui sera vérifié dans le plateau
* 
*  @return Vrai si le mot est dans le plateau
*/
bool dans_le_plateau(Plateau& p, Mot mot); // fonction de recherche
