
#include <stdio.h>

 int main() {
   int a = sizeof(int);
   int b = sizeof(int *);
   int c = sizeof(int **);
   int d = sizeof(char *);
   int e = sizeof(char **);
   int f = sizeof(char ***);
   int g = sizeof(float *);
   int h = sizeof(float **);
   int i = sizeof(float ***);
   
   printf(" %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n", a, b, c, d, e, f, g, h, i);
   return 0;
 }