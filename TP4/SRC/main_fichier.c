/* fichier : fichier.c*/

#include<stdio.h>
#include"fichier.h" 

int main() 
{
  char* message = "Allez leur dire aux grands de ce monde ";
  lire_fichier("test.txt");
  ecrire_dans_fichier("test.txt", message);
  
  
}
/* ce fichier fait appelle aux fonctions permettant de lire un fichier et d'ecrire dedans */
