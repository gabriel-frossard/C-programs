#include <stdio.h>
#include <string.h>


int main(){
  int i=0;

  struct etudiant
  {
      char prenom[100];
      char nom[100];
      char adresse[100];
      float note[2];
 
  };

  struct etudiant etu[5]; /*dans la structure etudiant, il y a 5 etudiant d'ou le etu[5]*/
 
  /*for(i=0; i<5; i++) {
    scanf("%s", etu[i].prenom);
  }
  avec scanf on peut rentrer les prenoms au clavier lors de l'execution
  */
  strcpy(etu[0].prenom, "Jean-Michel"); /*strcpy copie la chaine de caractere Michel dans l etudiant 0 dans la premiereligne */ 
  strcpy(etu[1].prenom, "Pierre"); /*etudiant 1 */
  strcpy(etu[2].prenom, "Paul");
  strcpy(etu[3].prenom, "Jacques");
  strcpy(etu[4].prenom, "Gaston");
  
  strcpy(etu[0].nom, "Dupont");
  strcpy(etu[1].nom, "Bus");
  strcpy(etu[2].nom, "Le Sang");
  strcpy(etu[3].nom, "Cousteau");
  strcpy(etu[4].nom, "Chaf");
  
  strcpy(etu[0].adresse, "1 rue de la garignette");
  strcpy(etu[1].adresse, "25 bis rue des caillasse");
  strcpy(etu[2].adresse, "101 chemin du Valentin");
  strcpy(etu[3].adresse, "3 avenue du Lavelinge");
  strcpy(etu[4].adresse, "51 impasse du pastis");
  
  
  etu[0].note[0] = 15;
  etu[0].note[1] = 5.5;
  etu[1].note[0] = 18.6;
  etu[1].note[1] = 15;
  etu[2].note[0] = 19;
  etu[2].note[1] = 1;
  etu[3].note[0] = 2;
  etu[3].note[1] = 17;
  etu[4].note[0] = 8;
  etu[4].note[1] = 6;
  
  for(i=0; i<5; i++) {
    printf("%s %s %s %f %f\n", etu[i].prenom, etu[i].nom, etu[i].adresse, etu[i].note[0], etu[i].note[1]);
  }

  return 0;

}
 /* le but de cet exercice est d'utiliser les structure ainsi que strcpy */
