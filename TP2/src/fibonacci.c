
#include <stdio.h>

 int main() {
   int U0=0, U1=1;
   int n;
   int i=0;
   printf("Entrer un rang: ");
   scanf("%d", &n); 
 
   for(i = 0 ; i <= n ; i++){
    U1 += U0;        //on ajoute au nombre avancé le précédent
    U0 = U1 - U0;    //on oublie pas que le précédent est égal à l'avancé avant ajout
    printf("%d \n", U0); 
   }
   
   printf("\n");
   return 0;
 }
