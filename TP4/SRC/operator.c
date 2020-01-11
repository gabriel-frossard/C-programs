#include<stdio.h>
#include "operator.h" // fait appelle au fichier headers operator.h

int somme (int a, int b) {
 return a+b;
}

int soustraction (int a, int b) {
  return a-b;
}

int produit (int a, int b) {
  return a*b;
}

int quotient (int a, int b) {
  return a/b;
}

int modulo (int a, int b) {
  return a%b ;
}

int ET (int a, int b) {
  return a && b ;
}

int OU (int a, int b) {
  return a || b;
}

int negation (int a){
  return ~a;
}
// fichier appelé par le fichier principal "main.c" pour effectuer les différentes opérations demandées.
