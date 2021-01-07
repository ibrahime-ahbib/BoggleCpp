/**
 * @file helpers.h
 * @author Logan Tann (LoganTann), Ibrahime Ahbib (Braxoia)
 * @version 1 07/01/2021
 * @brief Contient des fonctions dites *utilitaires* permettant d'effectuer des
 *		  opérations non basiques sur des conteneurs de type Liste_mot.
 * @see Liste_mot.h pour la définition du type Liste_mot
 */
#pragma once

#include "constantes.h" // + type Mot
#include "Liste_mot.h"

/*
*  @brief Retourne le nombre de points pour un mot entré
*
*  @param[in] mot le mot entré
*
*  @return le nombre de points pour le mot
*/
unsigned int mots_vers_pts(const char* mot);

/*
*  @brief Inverse le contenu de deux mots
*
*  @param[in-out] mot1 Mot qui aura le contenu de mot2
*  @param[in-out] mot2 Mot qui aura le contenu de mot1
*/
void swap(Mot mot1, Mot mot2);

/*
*  @brief Trie par ordre alphabétique une liste de mots
*
*  @param[in-out] liste_mot la liste qui sera triée
*/
void trier(Liste_mot& liste_mot);

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
