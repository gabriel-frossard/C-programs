#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"fichier.h"

#define taille_max 1000

int slen(char* s) // fonction qui calcule la longueur de la chaine de caractères
{
    int i = 0;
    while(s[i] != 0)
    {
        i++;
    }
    return i;
}

int main(int argc, char *argv[]) {
  int i=0;
  char* mot;
    if ((argc <50)&&(argc>2)) //on suppose que la phrase recherchée fait moins de 48 mots
    {
        FILE* fichier = NULL;
        fichier = fopen(argv[1], "r"); // ouverture du fichier en mode lecture
        char chaine[taille_max] = "";
        for (i=1 ; i<argc-1 ; i++) {
	  fichier = fopen(argv[1], "r");
	  strcpy(mot,"");
	  char* mot = argv[i+1];
	  printf("%s\n", mot);
	  int compteur_ligne = 0;
	  int longueur_mot = slen(mot);
	  
	  if (fichier != NULL) //tant que le fichier existe
	  {
	    
	      while (fgets(chaine, taille_max, fichier)!=NULL) //parcourt le fichier ligne par ligne, la fonction fgets lit les caractères du fichier et les range dans le tableau pointé par la chaîne jusqu'à ce qu'il ne reste plus qu'un seul caractère libre dans le tableau. fgets complète alors les caractères lus par un caractère null.

	      { 

		  compteur_ligne += 1; //on incrémente le compteur de ligne
		  char* compar;
		  int compteur_mot = 0;
		  char* ligne = chaine;
		  do
		  {
		      compar = strstr(ligne, mot); //fonction permettant de trouver la 1ere représentation d'une chaine de caractères dans une autre : cherche la 1ère présence de la sous-chaîne mot au sein de la chaîne ligne.
		      if(compar != NULL && slen(ligne) > longueur_mot)// on verifie la presence du mot dans la ligne et si la ligne>longueur du mot alors on rentre dans le if pour verifier si le mot est present a nouveau dans la ligne
		      {
			  compteur_mot += 1;
			  ligne  = compar + longueur_mot; //on se place à la fin du mot pour chercher si il y a une autre occurence dans la ligne
			  
		      }
		  }
		  while(compar != NULL);// des que le mot n'est pas dans la ligne (strstr renvoie NULL et la condition du while est vraie) donc le do s'arrete
		  printf( "Ligne %d, %d fois\n", compteur_ligne, compteur_mot); //on affiche le nombre d'occurence du mot dans la ligne 
	      
	      }
	  }
    }
	fclose(fichier);
    }
    return 0;
}





