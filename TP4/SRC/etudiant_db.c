#include <stdio.h>
#include <string.h>
#include"fichier.h" //fait appelle au fichier.h permettant de lire et d'ecrire dans un fichier texte

int main(){
  int i=0;


  struct etudiant //structure contenant 5 donnes differents
  {
      char prenom[100];
      char nom[100];
      char adresse[100];
      float note1;
      float note2;
 
  };

  struct etudiant etu[5]; /*dans la structure etudiant, il y a 5 etudiant d'ou le etu[5]*/
 
  for(i=0; i<5; i++) {
    printf("prenom %d \n", i);
    scanf("%s", etu[i].prenom); //permet a l'utilisateur de rentrer le prenom
    while(getchar()!='\n');
    printf("nom %d \n", i);
    scanf("%s", etu[i].nom);
    while(getchar()!='\n');//consomme les caracteres non lus jusqu a \n(entrer) car scanf s'arrete des que l'utilisateur entre un espace
    puts("adresse");
    fgets(etu[i].adresse,100,stdin); //fgets ne s'arrete pas lorsque l'utilisateur entre un espace
    //scanf("%s", etu[i].adresse);
    puts(etu[i].adresse);
    puts("premiere note ?"); //puts est un printf de chaine de caracteres uniquement
    scanf("%f", &etu[i].note1);
    puts("deuxieme note ?");
    scanf("%f", &etu[i].note2);
  }
  
  
  for(i=0; i<5; i++) {
    char message[400];
    printf("%s %s %s %f %f\n", etu[i].prenom, etu[i].nom, etu[i].adresse, etu[i].note1, etu[i].note2);
    sprintf(message, "%s %s %s %f %f\n", etu[i].prenom, etu[i].nom, etu[i].adresse, etu[i].note1, etu[i].note2); //sprint ecrit les noms, prenoms, adresses et notes dans une chaine de caractere message
    ecrire_dans_fichier("etudiant.txt", message); //dans le fichier etudiant.txt, on ecrit le message contenant tous les donnes des etudiants
    
  }
  

  return 0;

}

// ce prgramme permet a l'utilisateur d'entrer cinq noms, prenoms, adresses, et 10 notes. Il les rentre dans un fichier texte deja cree
