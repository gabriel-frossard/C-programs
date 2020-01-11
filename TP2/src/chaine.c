#include <stdio.h>


int main () {
	char chaine1[100] = "bonjour";
	char chaine2[100];
	char chaine3[100] = "hello";
	char chaine4[100];
	int cpt;
	int cpt2;
	int cpt3;

	for (cpt=0 ; chaine1[cpt]!='\0'; cpt++)
	{
	    chaine4[cpt] = chaine1[cpt];
	}

	for (cpt2=0 ; chaine1[cpt2]!= '\0'; cpt2++) 
	{
		chaine2[cpt2] = chaine1[cpt2];
	}	
		
	for(cpt3=0 ; chaine3[cpt3]!='\0' ; cpt3++)
	{
	    chaine4[cpt2+cpt3]=chaine3[cpt3];
	}
	printf("Il y a %d cararctères dans la chaine 1", cpt2);
	printf("\nChaine2 = %s \n ", chaine2);
	printf("La chaine concatenée est %s \n", chaine4);	
	
return 0;
}
