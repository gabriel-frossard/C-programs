#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "repertoire.h"

void lire_dossier(char *rep){ // * car un repertoire a une longue chaine de caractere
  DIR *fichier = opendir(rep); //ouverture du repertoire rep
  struct dirent *lecture; //structure deja existante qui permet d'amorcer la lecture dans le repertoire rep ci-dessous
  if(fichier!=NULL)
  {
    lecture=readdir(fichier); //readdir va parcourir le repertoire
    while(lecture!=NULL){ //lorsque les fichiers ont été lu, readdir renvoie NULL, car on les a tous lu : il n'en reste plus
      puts(lecture->d_name); // "ptr->struct" est equivalent a "(*ptr).struct" permet de pointer une structure (désigne un champ particulier)
      lecture=readdir(fichier); //readdir va parcourir le repertoire
    }
  }
  closedir(fichier);
}

void lire_dossier_recursif(char *rep){
  chdir(rep); //on se place dans rep
  DIR *fichier = opendir("."); //ouverture du repertoire courant
  struct dirent *lecture; //structure deja existante qui permet d'amorcer la lecture dans le repertoire rep ci-dessous
  if(fichier!=NULL)
  {
   lecture=readdir(fichier); //readdir va parcourir le repertoire

    while(lecture!=NULL){ //lorsque les fichiers ont été lu, readdir renvoie NULL, car on les a tous lu : il n'en reste plus

      puts(lecture->d_name); // "ptr->struct" est equivalent a "(*ptr).struct" permet de pointer une structure (désigne un champ particulier)
      if ( (strcmp(lecture->d_name, ".")  !=0) && (strcmp("..", lecture->d_name) != 0) && (lecture->d_type == DT_DIR)) //si le dossier n'est pas le fichier . et .. et si c'est un repertoire, on fait appelle a la meme fonction
      {
	lire_dossier_recursif(lecture->d_name); //on rappelle la fonction en prenant comme nouveau repertoire celui qu'on vient d' ouvrir : on a une fonction recursive
	chdir(".."); //on remonte d'un cran pour pouvoir ouvrir les autres dossiers
      }
      lecture=readdir(fichier);
  }
  closedir(fichier);
  }
}
// structure liste chainee

Liste *initialisation(char *rep) //creation d'une liste chainee
{
    Liste *liste = malloc(sizeof(*liste)); //controle
    Dossier *dossier = malloc(sizeof(*dossier));
    if (liste == NULL || dossier == NULL)
    {
        exit(EXIT_FAILURE);
    }
//remplissage de la structure
    dossier->rep = rep; 
    dossier->suivant = NULL;
    liste->premier = dossier;
    return liste;
}

void insertion( Liste *liste, char *nvRep)
{
    /* Création du nouvel élément */
    Dossier *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->rep = nvRep; //on definit un nouveau element dans le structure
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        struct Dossier *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer); //supprime le premier element de la liste chainee
    }
}

//fin structure liste chainee
void lire_dossier_iteratif(char *rep)
{
    Liste *liste_dossier = initialisation(rep);
    while(liste_dossier->premier != NULL) //tant qu'il y a des dossiers
    {
        printf("%s:\n",liste_dossier->premier->rep); //on affiche un repertoire
        chdir(liste_dossier->premier->rep); //on se place dans rep
        DIR *fichier = opendir("."); //ouverture du repertoire courant
        struct dirent *lecture; //structure deja existante qui permet d'amorcer la lecture dans le repertoire rep ci-dessous
        suppression(liste_dossier);
        if(fichier!=NULL)
        {
            lecture=readdir(fichier); //readdir va parcourir le repertoire
            while(lecture!=NULL)//lorsque les fichiers ont été lu, readdir renvoie NULL, car on les a tous lu : il n'en reste plus
            { 
                if ( (strcmp(lecture->d_name, ".")  !=0) && (strcmp("..", lecture->d_name) != 0) && (lecture->d_type == DT_DIR)) //si le dossier n'est pas le fichier . et .. et si c'est un repertoire, on fait appelle a la meme fonction
                {
                    insertion(liste_dossier, lecture->d_name); //on insere dans la liste chainee le nouveau repertoire trouve
                }
                else
                { //affichage du fichier (qui n'est pas un dossier
                     puts(lecture->d_name); // "ptr->struct" est equivalent a "(*ptr).struct" permet de pointer une structure (désigne un champ particulier), puts est un printf d'une chaine de caractere
                }
                lecture=readdir(fichier);
            }
        }
        closedir(fichier);
        printf("\n\n");
    } 
}
