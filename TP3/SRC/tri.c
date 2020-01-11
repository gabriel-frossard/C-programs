
#include <stdio.h>
#include <time.h>
 int main() {
   srand(time(NULL)); //genere une "graine parmi le nombre de seconde depuis 1970"
   
   int table[100];
   int i, j, k, min, t;
   
   for(i=0;i<100;i++){
     table[i]= rand()%200;
     printf(" %d ", table[i]);  
   }
   putchar('\n');
   
   for(j=0;j<99;j++){
     min=j; //min stock le pointeur du minimum
     
     for(k=j+1;k<100;k++){      
       if(table[k] < table[min]){
	min = k;    
       }
     }
      if (min != k){
	t=table[j];
	table[j]=table[min];
	table[min]=t;
    }
   }
   putchar('\n');
   
   for(i=0;i<100;i++){
     //table[i]= rand()%200;
     printf(" %d ", table[i]);  
   } 
   return 0; 
 }  