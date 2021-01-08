:: La grille à jouer est dans grille.txt
:: Les listes de mots des 3 joueurs sont dans coup-j1.txt, coup-j2.txt et coup-j3.txt
:: Le script qui suit affiche les points remportés par chaque joueur

@echo off

:: ----------------------------  A ADAPTER selon votre organisation ---------------------------
:: Chemin vers l'exécutable exo
set cheminexe=..\..\x64\Release
:: Chemin vers le dictionnaire ods4.txt
set chemindico=.
:: --------------------------------------------------------------------------------------------

:: calculer les mots présents dans au moins deux des listes des joueurs
(echo 5 & type coup-j1.txt & type coup-j2.txt & type coup-j3.txt & echo *) | %cheminexe%\exo > commun.txt

:: supprimer ces mots de chacune de ces listes en en profitant pour supprimer les mots répétés

(echo 3 & type commun.txt & type coup-j1.txt) | %cheminexe%\exo > tmp.txt
(echo 2 & type tmp.txt) | %cheminexe%\exo > tmp-j1.txt
(echo 3 & type commun.txt & type coup-j2.txt) | %cheminexe%\exo > tmp.txt
(echo 2 & type tmp.txt) | %cheminexe%\exo > tmp-j2.txt
(echo 3 & type commun.txt & type coup-j3.txt) | %cheminexe%\exo > tmp.txt
(echo 2 & type tmp.txt) | %cheminexe%\exo > tmp-j3.txt

del tmp.txt commun.txt

:: supprimer de ces listes les mots n'apparaissant pas dans le dictionnaire

(echo 4 & type %chemindico%\ods4.txt & echo * & type tmp-j1.txt) | %cheminexe%\exo > tmp.txt
copy /Y tmp.txt tmp-j1.txt > NUL
(echo 4 & type %chemindico%\ods4.txt & echo * & type tmp-j2.txt) | %cheminexe%\exo > tmp.txt
copy /Y tmp.txt tmp-j2.txt > NUL
(echo 4 & type %chemindico%\ods4.txt & echo * & type tmp-j3.txt) | %cheminexe%\exo > tmp.txt
copy /Y tmp.txt tmp-j3.txt > NUL

del tmp.txt

:: supprimer de ces listes les mots n'apparaissant pas dans la grille et afficher le nombre de points

(echo 6 & type grille.txt & type tmp-j1.txt) | %cheminexe%\exo > tmp.txt
(echo 1 & type tmp.txt) | %cheminexe%\exo & echo ^ point(s) pour le joueur 1
(echo 6 & type grille.txt & type tmp-j2.txt) | %cheminexe%\exo > tmp.txt
(echo 1 & type tmp.txt) | %cheminexe%\exo & echo ^ point(s) pour le joueur 2
(echo 6 & type grille.txt & type tmp-j3.txt) | %cheminexe%\exo > tmp.txt
(echo 1 & type tmp.txt) | %cheminexe%\exo & echo ^ point(s) pour le joueur 3

:: faire le peu de ménage restant

del tmp-j?.txt

:: afficher le nombre maximal de points qui était possible pour cette grille

echo ----------
(echo 6 & type grille.txt & type %chemindico%\ods4.txt & echo *) | %cheminexe%\exo > tmp.txt
(echo 1 & type tmp.txt) | %cheminexe%\exo & echo ^ point(s) au maximum possible

del tmp.txt
