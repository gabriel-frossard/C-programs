#include <stdio.h>
#include <stdlib.h>

int main () {
  int tableau_int[5];
  float tableau_float[5];
  int i = 0;
  for (i=0 ; i<5 ; i++){
   tableau_int[i] = rand()%10;  /*le %10 permet d avoir un nombre entre 0 et 10 pour qu'il n'y ai pas de probleme avec le int quand on fait *3 */
   tableau_float[i] = rand()%10 +0.5; /*on cree un nombre à virgule*/
   
   printf("tableau int avant %d",  *(tableau_int+i));
   printf( " valeur de l'indice %d\n", i);
   printf("tableau float avant %f", *(tableau_float+i));
   printf( " valeur de l'indice %d\n", i);
   
   if (i%2 == 0){
     
    int *pointeur_tableau_int = tableau_int+i; /*tableau[i] */
    *pointeur_tableau_int *= 3;
    float *pointeur_tableau_float = tableau_float+i;
    *pointeur_tableau_float *=3; 
    printf("tableau int apres %d", *(tableau_int+i));
    printf(" valeur de l'indice %d \n", i);
    printf("tableau float apres %f", *(tableau_float+i));
    printf(" valeur de l'indice %d \n", i);
   }
  }  
return 0;   
}
// a[b] <=> *(a+b)
//&* s'annulent donc &*(tableau_int+i) <=> tableau_int+i (l'étoile réfère à la valeur : *tableau_int+i refère à la valeur de l'indice tableau_int+i et le & réfère à l'adresse de la valeur située à l'indice tableau_int+i)
/* on utilise les pointeurs pour changer certaines valeurs du tableau */
