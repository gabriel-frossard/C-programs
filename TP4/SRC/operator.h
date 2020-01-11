#ifndef OPERATOR_H // si operator.h n'est pas defini,
#define OPERATOR_H // on le defini
int somme (int, int); /*int somme car on retourne un int*/

int soustraction (int, int);

int produit (int, int);

int quotient (int, int);

int modulo (int, int);

int ET (int, int);

int OU (int, int);

int negation (int);

#endif

/* ce fichier .h permet de faire le lien entre les deux fichiers .c : operator.c contenant les fonctions et main.c faisant appel a ces fonctions
 * Le fichier .h doit donc contenir le nom de toutes les fonctions*/
