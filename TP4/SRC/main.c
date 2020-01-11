#include<stdio.h>
#include"operator.h" //fait appel au fichier .h qui lie ce fichier et celui contenant les fonctions.

int main() 
{

  int  resultat,d,e,f,g,h, i, j;
  int a= 5;
  int b = 3;
  char op = '+';           // opérateur qui sera choisi pour effectuer l'opération 
  switch (op) {
    case '+' :                  // case permet suivant la valeur donnée dans op de choisir la bonne opération à effectuer.
      resultat = somme(a,b);
      printf("a+b = %d\n", resultat);
    break;
    case '-' : d= soustraction(a,b);
    printf ("a-b = %d\n", d);
    break;
    case '*' : e = produit(a,b);
    printf ("a*b = %d\n", e);
    break;
    case '/' : f = quotient(a,b);
    printf ("a/b = %d\n", f);
    break;
    case '&'  : h = ET(a,b);
    printf ("a ET b = %d\n", h);
    break;
      
    case '%' : g=modulo(a,b);
    printf ("a modulo b = %d\n", g);
    break;
    
    case '|' :i = OU(a,b);
    printf ("a ou b = %d\n", i);
    break;
    
    case '~' : j= negation(a);
    printf ("-a = %d\n", j);
    break;
    
   
    default : printf("mauvais operateur");  // si l'opérateur n'est pas connue on renvoie que l'opérateur n'est pas bon.
    break;
     
  }
return 0;
}


