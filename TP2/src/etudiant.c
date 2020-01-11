/* Fichier : etudiant2.c */

#include <stdio.h>

int main(){
int i=0;

char prenom[5][50] = 
{
  "Jean-Michel",
  "Pierre",
  "Paul",
  "Jacques",
  "Gaston"}; /*tableau de 5 lignes contenant chacune 50 caracteres*/
  
char nom[5][100] = 
{
  "Dupont",
  "Bus",
  "Le Sang",
  "Cousteau",
  "Chaf"};
  
char adresse[5][100] =
{
  "1 rue de la Garignette",
  "25 bis rue des Caillasse",
  "101 Chemin du Valentin",
  "3 Avenue du Lavelinge",
  "51 Impasse du Pastis"};

float note1[5] =
{
   15 ,
   18.6 ,
   19 ,
   2 ,
   8 };

float note2[5] =
{
  5.5,
  15,
  1,
  17,
  6};

for (i=0 ; i<5 ; i++)
{
printf("%s %s %s %f %f \n", prenom[i], nom[i], adresse[i], note1[i], note2[i]);
}

return 0;

}


