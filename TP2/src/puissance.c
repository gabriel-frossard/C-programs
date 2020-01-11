
#include <stdio.h>

 int main() {

   int i=1;
   int a, b;
   
   printf("Entrer un entier a : ");
   scanf("%d", &a);  
   printf("Entrer une puissance b : ");
   scanf("%d", &b);
   
   int c=a; 

   for(i=1;i<b;i++){
     a=c*a;
   }
   printf("a puissance b = %d\n", a); 
   return 0;
 }
