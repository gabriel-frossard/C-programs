#include <stdio.h>
int main() {
  
int taille = 100;
int tableau[taille];
int rand();
int i;
int max=0;
int min=1000;


for (i = 0 ; i < taille ; i++)
  {
    tableau[i] = rand()%200;
    printf("%d ", tableau[i]);
    if (tableau[i]>=max)
    {
      max=tableau[i];
    }
    if (tableau[i]<=min)
    {
      min=tableau[i];
    }
  }
printf(" \n le nombre max est %d \n", max);
printf(" le nombre min est %d \n", min);

return 0;  
}