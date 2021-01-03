#include <cstdio> //< permet d'utiliser les fonctions standards du C
#include <iostream> //< permet d'utiliser la classe std
#include <cstring> //< permet d'utiliser strcpy, strcmp du C
#include <cassert> //< permet d'utiliser la fonction assert

#include "fonction_conteneurs.h" //< fonctions relatives à un conteneurs de listes ou une liste de mots
#include "plateau.h" //< fonctions relatives à la manipulation d'un plateau de jeu

#pragma warning(disable:4996) //< pas de warning si scanf ou strcpy

/*
* Lire une liste de mots saisie au clavier et  afficher à l’ecran 
* le nombre de points qu’elle représente 
*/
int exo1()
{
    unsigned int nb_pts = 0;
    char buffer[TAILLE_MAX + 1];
    while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0)
            break;

        nb_pts += mots_vers_pts(buffer);
    }
    std::cout << nb_pts;

    return 0;
}

/*
* Lire une liste de mots saisie au clavier et l’afficher à l’écran 
* sous forme canonique (les mots sont triés, chaque mot n’est présent 
* qu’une fois et les mots sont séparés par un retour à la ligne)
*/
int exo2()
{
    Mot buffer;

    Liste_mot cette_liste;
    initialiser(cette_liste);
    while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0) {
            break; // skip
        }

        if (!exister(cette_liste, buffer))
            ajouter(cette_liste, buffer);
    }

    trier(cette_liste);
    afficher(cette_liste);

    delete[] cette_liste.tab;

    return 0;
}

/*
* Lire deux listes de mots saisies au clavier et afficher à 
* l'écran les mots de la seconde liste n’apparaissant pas
* dans la première
*/
int exo3() {


    Liste_mot cette_liste, cette_liste2;
    initialiser(cette_liste);
    initialiser(cette_liste2);

    lire(cette_liste);
    lire(cette_liste2);

    trier(cette_liste);
    trier(cette_liste2);

    // afficher les éléments de liste_mot2 qui ne sont pas dans liste_mot1
    sans_repetition(cette_liste, cette_liste2);

    delete[] cette_liste.tab;
    delete[] cette_liste2.tab;

    return 0;
}

/*
* Lire deux listes de mots saisies au clavier et afficher à 
* l'écran les mots de la seconde liste apparaissant dans la
* première 
*/
int exo4() 
{

    Liste_mot cette_liste, cette_liste2;
    initialiser(cette_liste);
    initialiser(cette_liste2);

    lire(cette_liste);
    lire(cette_liste2);

    trier(cette_liste);
    trier(cette_liste2);

    // afficher les éléments de liste_mot2 qui sont **dans** liste_mot1
    avec_repetition(cette_liste, cette_liste2);


    // TODO : faire une fonction detruire
    delete[] cette_liste.tab;
    delete[] cette_liste2.tab;

    return 0;
}

/*
* Lire une liste de listes de mots saisie au clavier et 
* afficher à l'écran la liste de tous les mots apparaissant dans
* au moins deux de ces listes
*/
int exo5() {

    Liste_de_liste liste_de_liste;
    initialiser_liste(liste_de_liste);
    lire_liste(liste_de_liste);
    afficher_liste(liste_de_liste);
    detruire_liste(liste_de_liste);
 
    return 0;
}

/*
* Lire un plateau suivi d’une liste de mots saisis au clavier et 
* afficher à l'écran les mots de la liste étant présents
* sur la plateau.
*/
int exo6()
{
    Plateau plateau;

    bool verif = ajouter_plateau(plateau);
    assert(verif);

    Liste_mot cette_liste;
    initialiser(cette_liste);
    lire(cette_liste, plateau);

    trier(cette_liste);
    afficher(cette_liste);

    delete[] cette_liste.tab;
    return 0;
}

int main() 
{
    int num;

    std::cin >> num;

    switch (num)
    {
    case 1:
        return exo1();
    case 2:
        return exo2();
    case 3:
        return exo3();
    case 4:
        return exo4();
    case 5:
        return exo5();
    case 6:
        return exo6();
    }

    return 1;
}
