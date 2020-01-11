/* fichier : couleur_compteur.c */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("\n");

 struct RGBA
  {
      unsigned char red[5];
      unsigned char green[5];
      unsigned char blue[5];
      unsigned char alpha[5];
      int nb_color;
  };
  
  int nb_color_table=0;
  int j=0;
  struct RGBA color[100]; //on se limite a 100 couleurs
  char red_color[5], green_color[5], blue_color[5], alpha_color[5]; //nos couleurs contiennent 5 caractères
  
  while(1) {
   int i = 0;
   int color_null = 0;
   printf("entrer une couleur");
   scanf("%s %s %s %s", red_color, green_color, blue_color, alpha_color); //a chaque fois qu'une couleur est rentree, elle est comparé avec le tableau
   if ( !(strcmp(red_color,"FIN")) || !(strcmp(green_color,"FIN")) || !(strcmp(blue_color,"FIN")) || !(strcmp(alpha_color,"FIN"))){ //si l'utilisateur rentre FIN on ne compare rien
	break;
   }
   else {
	   for(i=0; i<nb_color_table; i++){ //on teste la couleur rentree par l'utilisateur avec les autres couleurs qu'il a rentre auparavant
			if(strcmp(red_color, color[i].red)==0){ //si la couleur rouge rentree par l'utilisateur existe, on passe a la verte
				if(strcmp(green_color, color[i].green)==0){
					if(strcmp(blue_color, color[i].blue)==0){
						if(strcmp(alpha_color, color[i].alpha)==0){ //si toutes les couleurs correspondent, on incremente le compteur 
							color[i].nb_color = color[i].nb_color +1;
							color_null = 1;
							break;
						}
					}
				}
			}
		}
		
		if (color_null == 0){ //si la couleur n'est pas dans le tableau
			strcpy(color[i].red, red_color); 
			strcpy(color[i].green, green_color);
			strcpy(color[i].blue, blue_color);
			strcpy(color[i].alpha, alpha_color); //on la rajoute
			nb_color_table++;
		}
    }
   
   for (j=0; j<nb_color_table; j++){
     printf("%s %s %s %s : %d fois\n", color[j].red, color[j].green, color[j].blue, color[j].alpha, color[j].nb_color);
	}
  }  
return 0;
}


 