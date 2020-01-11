#include <stdio.h>

int main() {
  
  //int
  int a = 400;
  unsigned char* pointeur;
  pointeur = (unsigned char*)&a; //convertit l'adresse d'un entier en char comme pointeur est un char
  int i=0;
  printf("le int est en octet :");
  while (i<sizeof(int)){ // on parcourt la taille de la base
  printf(" %d , ", pointeur[i]); //affichage des differents octets
  i++;
  }
  printf("\n");
  
  
  
  //float
  int j=0;
  float b = 400.0;
  pointeur = (unsigned char*)&b; //le unsigned permet d'afficher entre 0 et 256. Sinon le terminal affiche de -127 a 128
  printf("le float est en octet :");
  while (j<sizeof(float)){
  printf(" %d , ", pointeur[j]);
  j++;
  }
  printf("\n");
  
  
  
  
  //long int
  int k=0;
  long int c = 400;
  pointeur = (unsigned char*)&c;
  printf("le long int est en octet :");
  while (k<sizeof(long int)){
  printf(" %d , ", pointeur[k]);
  k++;
  }
  printf("\n");
  
  
  //short
  int l=0;
  short d = 400;
  pointeur = (unsigned char*)&d;
  printf("le short est en octet :");
  while (l<sizeof(short)){
  printf(" %d , ", pointeur[l]);
  l++;
  }
  printf("\n");
 
 
 //double
  int m=0;
  double e = 400.0;
  pointeur = (unsigned char*)&e;
  printf("le double est en octet :");
  while (m<sizeof(double)){
  printf(" %d , ", pointeur[m]);
  m++;
  }
  printf("\n");
  
  
  //long double
  int n=0;
  double f = 400.0;
  pointeur = (unsigned char*)&f;
  printf("le long double est en octet :");
  while (n<sizeof(long double)){
  printf(" %d , ", pointeur[n]);
  n++;
  }
  printf("\n");

  return 0;  
}

