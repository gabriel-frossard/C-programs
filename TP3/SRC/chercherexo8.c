
#include <stdio.h> 

int main() {

    char lphrase[10][100]={"Bonjour","Hello world!", "c'est pas facile la progC","ok","aller on s'y met.","Je fais du sport","je vais faire les courses",
    "Il faut travailler","allo la terre.","ici la lune"};

char phrase[100];
	printf("donne une phrase :\n");
	scanf("%s", phrase);

    int test;  //si test = 1, les phrases correspondent, sinon elles sont différentes

    for (int i = 0; i < 10; i++) //on repète l'opération sur toutes les phrases
    {
        test=1; //on suppose que les phrases sont identiques

        for (int j = 0;lphrase[i][j] ; j++) 
        {
            if (lphrase[i][j]!=phrase[j])
            {
                test=0; //si un caractère est différent, ce n'est pas bon
            }

        }

        if (test==1) //si test=1, alors aucun caractère n'est différent (on raisonne par négation) donc les phrases sont identiques
        {
            printf("La phrase %s est dans le tableau !\n", phrase);
            break;  //on sort pour ne pas afficher le message suivant
        }
        
        
    }
    if (test==0)
    {
        printf("La phrase %s n'est pas dans le tableau !\n", phrase); //si test=0 après avoir testé toutes les phrases, alors la phrase n'est pas dans le tableau
    }
    

    return 0;
}
