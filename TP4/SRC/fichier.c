#include<stdio.h>
#include "fichier.h"
#define taille_max 1000 //instruction preprocesseur mieux qu'un int


void lire_fichier( char *nom_de_fichier){

  FILE* fichier = NULL;


  fichier = fopen(nom_de_fichier, "r"); // ouverture du fichier en mode lecture
  char chaine[taille_max]="";


  if (fichier != NULL) //tant que le fichier existe
  {
   
    while (fgets(chaine, taille_max, fichier)!=NULL){ 
      printf("%s", chaine);
    }
      printf("%s", chaine);
  }
  fclose(fichier);
  
}


void ecrire_dans_fichier(char *nom_de_fichier, char *message){

  FILE* fichier = NULL;

  fichier = fopen(nom_de_fichier, "a"); //ouverture du fichier en mode ecriture (a pour ne pas que ca ecrase ce que contenait le fichier avant)
  if (fichier != NULL)
    {

  
    fputs(message, fichier); //ecrit le message dans le fichier
    fclose(fichier);
    }
  
  
}

 // ce programme contient deux fonctions permettant d'ouvrir un fichier et d'ecrire dedans 
