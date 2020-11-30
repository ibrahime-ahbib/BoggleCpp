- Pour toutes questions relatives au projet, ne pas hésiter à m'écrire (Denis.Poitrenaud@u-paris.fr)

- Le sujet du projet est dans le document projetSDA.pdf.

- Le répertoire inout contient les sorties attendues de vos programmes (out?.txt) pour des entrées données (in?.txt). Le fichier in1-2.txt est le fichier d'entrée des deux premiers programmes.

- Au sein des fichiers de sorties, les listes de mots sont toutes sous forme canonique (pour la définition d'une liste canonique, voir le sujet). Si l'un de vos programmes ne produit pas une liste respectant ce format, employez le second programme pour filter sa sortie. Par exemple, si le programme exo3.exe ne produit pas une liste au format canonique et que exo2.exe correspond au second programme demandé alors la commande

(exo3 < in3.txt) | exo2

doit afficher le contenu de out3.txt.

- Pour comparer 2 fichiers texte, vous pouvez vous reposer sur le site www.diffchecker.com ou employer la commande fc. Par exemple, pour comparer le fichier out3.txt avec le fichier produit par la commande 

(exo3 < in3.txt) | exo2 > myout3.txt

vous pouvez employer la commande

fc out3.txt myout3.txt

doit afficher les 2 lignes suivantes

Comparaison des fichiers out3.txt et myout3.txt
FC : aucune différence trouvée

En cas de différence, l'emploi de www.diffchecker.com peut être utile pour localiser les erreurs.


- l'archive ods4.zip contient un fichier présentant une liste de 369085 mots français (Attention, cette liste n'est pas terminée par *). Vous pouvez vous en servir trouver automatiquement tous les mots présents dans un plateau de jeu.

Bon projet !
D. Poitrenaud