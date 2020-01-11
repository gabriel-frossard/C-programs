
#include <stdio.h>
#include <time.h>

//On reprend le code du tri.c

 int main() {
   srand(time(NULL)); //genere une "graine parmi le nombre de seconde depuis 1970"
   
   int table[100];
   int i, j, k, min, t;
   int entier = rand()%200;
   int ind, bmin=0, bmax=100, mid;
   
   for(i=0;i<100;i++){
     table[i]= rand()%200;
     printf(" %d ", table[i]);  
   }
   putchar('\n');
   
   for(j=0;j<99;j++){
     min=j; //min stock le pointeur du minimum
     
     for(k=j+1;k<100;k++){      
       if(table[k] < table[min])
	min = k;    
     }
     
      if (min != k){
	t=table[j];
	table[j]=table[min];
	table[min]=t;
      }
   }
   putchar('\n');
   
   for(i=0;i<100;i++){
     printf(" %d ", table[i]);  
   }
   
   printf("\n");
   ind=-1;
   
   while ((bmin<=bmax) && (ind==-1)){
     mid=(bmax+bmin)/2;
     if (entier < table[mid]){
       bmax=mid-1;
     }
     else if (entier > table[mid]){
       bmin=mid+1;
     }
     else{
       ind=mid;
     }
   }
        
   if (ind==-1){
     printf("La valeur recherchée ne se trouve pas dans le tableau.\n");
   }
   else{
     printf("La valeur %d se trouve à la position %d. \n", entier, ind);
   }
		
   return 0;
 }