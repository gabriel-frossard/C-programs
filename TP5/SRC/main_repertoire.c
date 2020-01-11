#include<stdio.h>
#include"repertoire.h"

int main(int argc, char *argv[]) {
  if (argc == 2){ //s'il y a un repertoire dans la chemin ou l'on se trouve
    printf("facon iterative \n");
    lire_dossier_iteratif(argv[1]); // on ouvre le premier repertoire ou le chemin est contenu dans argv[1](argv[0] contient le chemin de l'executable : ./repertoire)
    printf("facon recursive \n");
    lire_dossier_recursif(argv[1]); 
  } 
  return 0;
}
// quand on execute le programme : ./repertoire . le point signifie le repertoire dans lequel on est 
//si on execute : ./repertoire .. le programme va afficher le repertoire parent( celui du dessus)
//pour la facon iterative nous parcourons le repertoire courant et on regarde s'il y a un  sous repertoire 
//dans la liste chainee et on parcourt ainsi de suite tant qu'il y a des repertoires dans la liste chainee
