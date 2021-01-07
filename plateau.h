#pragma once

#include "Liste_mot.h"

typedef char Plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]; ///< Contient le plateau entré
typedef bool Plateau_bool[TAILLE_PLATEAU][TAILLE_PLATEAU]; ///< Contient le plateau booleen du plateau

///////////////////////////////////////////////////
///	\brief Conteneur représentant des coordonnées
///////////////////////////////////////////////////
struct Coords {
    int ligne; ///< Coordonnée en abcisse
    int col; ///< Coordonnée en ordonnée
};


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
bool entree_dans_plateau(Liste_mot& liste_mot, const Plateau& plateau);

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
void initialiser_plateau_bool(Plateau_bool& p_bool);

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
bool dans_le_plateau(const Plateau& p, const Mot mot); // fonction de recherche
