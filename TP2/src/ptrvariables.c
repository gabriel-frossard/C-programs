#include <stdio.h>


int main() {
  char my_char = 'a';
   printf ("le char est %c\n", my_char);
  char *pointeur_char = &my_char; /*on pointe l adresse par le & ou il y a my_char */
  *pointeur_char = 'b'; /*on remplace l endroit ou on pointe par b */
   printf ("le char est %c\n", my_char);
  
  short my_short = 32767;
  printf ("le short est %hd\n", my_short);
  short *pointeur_short = &my_short;
  *pointeur_short = 458;
  printf ("le short est %hd\n", my_short);
  
  int my_int = -2147483647;
  printf ("le int est %d\n", my_int);
  int *pointeur_int = &my_int;
  *pointeur_int = -895;
  printf ("le int est %d\n", my_int);
  
  long int my_long_int = 2147483648;
  printf ("le long int est %ld\n", my_long_int);
  long int *pointeur_long_int = &my_long_int;
  *pointeur_long_int = 7;
  printf ("le long int est %ld\n", my_long_int); 
  
  long long int my_long_long_int = 2147483648;
  printf ("le long long int est %lld\n", my_long_long_int);
  long long int *pointeur_long_long_int = & my_long_long_int;
  *pointeur_long_long_int = 568;
  printf ("le long long int est %lld\n", my_long_long_int);
  
  float my_float = 2.56666666666;
  printf ("le float est %f\n", my_float);
  float *pointeur_float = &my_float;
  *pointeur_float = 5.8795;
  printf ("le float est %f\n", my_float);
  
  double my_double = 2.66666666;
  printf ("le double est %g\n", my_double);
  double *pointeur_double = &my_double;
  *pointeur_double = 5.78575485;
  printf ("le double est %g\n", my_double);
  
  long double my_long_double = 5.556;
  printf ("le long double est %Lg\n", my_long_double);
  long double *pointeur_long_double = &my_long_double;
  *pointeur_long_double = 5.12589;
  printf ("le long double est %Lg\n", my_long_double);
  

}
  
  
  
  /* on utilise les pointeurs pour changer la valeur d'une base sans la lui affecter directement */
  /* le pointeur_char refère l'adresse ou il y a le my_char et le *pointeur_char réfère la charactere my_char */
