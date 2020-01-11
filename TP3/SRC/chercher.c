#include <stdio.h>

int main() {
  
int taille = 100;
int tableau[taille];
int rand();
int i;
int ok = 0;
int nombre = rand()%20;


printf (" nombre aléatoire: %d\n", nombre);
for (i = 0 ; i < taille ; i++)
  {
    tableau[i] = rand()%50;
    printf("%d ", tableau[i]);
  if (nombre == tableau[i])
  {
      ok=1;
  }
  }
  if (ok ==1) {
printf("\n le nombre %d est présent dans le tableau \n ",nombre);
  }
return 0;
}

