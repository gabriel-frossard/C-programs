#include<stdio.h>
#include<stdlib.h>
#include"operator.h"

int main(int argc, char **argv) {
  int num1, num2;
  char operation = argv[1][0]; // permet de rentrer l'opérateur voulu lors de l'execution
// focntion atoi :Cette fonction permet de transformer une chaîne de caractères, représentant une valeur entière, en une valeur numérique de type int .

  num1 = atoi(argv[2]); //permet d'entrer le numero lors de l execution
  num2 = atoi(argv[3]);  
  int resultat, d, e, f, g, h, i, j;

switch (operation) {
    case '+' : 
    resultat = somme(num1,num2);
    printf("%d + %d = %d\n", num1, num2, resultat);
    break;
    case '-' : d= soustraction(num1,num2);
    printf ("%d - %d = %d\n", num1, num2, d);
    break;
    case '*' : e = produit(num1,num2);
    printf ("%d * %d = %d\n", num1, num2, e);
    break;
    case '/' : f = quotient(num1,num2);
    printf ("%d / %d = %d\n", num1, num2, f);
    break;
    case '&'  : h = ET(num1,num2);
    printf ("%d ET %d = %d\n", num1, num2, h);
    break;
      
    case '%' : g=modulo(num1,num2);
    printf ("%d modulo %d = %d\n", num1, num2, g);
    break;
    
    case '|' :i = OU(num1,num2);
    printf ("%d OU %d = %d\n", num1, num2, i);
    break;
    
    case '~' : j= negation(num1);
    printf ("negation de %d  = %d\n", num1, j);
    break;
    
   
    default : printf("mauvais operateur \n");
    break;
     

  }
return 0;
}
// pour entrer l'operation et les nombre lors de l execution du programme, il faut utiliser argv et sscanf
// ce fichier fait appelle aux fonctions permettant d'effectuer les calcules
