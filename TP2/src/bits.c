#include <stdio.h>


int main () {
	int nombrebinaire = 0b10010011001101001011; 
// tester avec par exemple 0b10000011001101001011, cela affichera bien 0
	int mask1 =     0b00010000000000000001;
        int var1 = nombrebinaire & mask1;
	printf ("var1 = %d \n", var1);
	if (var1 == mask1) {
		printf ("1 \n");
	} else {
		printf ("0 \n");
	}
	
return 0;
}
