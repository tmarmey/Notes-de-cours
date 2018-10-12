#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

int somme(int fixe1, int fixe2 ,int n,...){
	va_list va;
	va_start(va, n); 
	// On fait commencer le va_start au dernier paramètre fixe

	int resultat = 0;
	
	for (int i = 0; i < n ; i++){
		resultat += va_arg(va, int);
	}
	va_end(va);
	return resultat;
}

int main(int argc, char **argv){
	printf("%d\n",somme(0,0,4, 1,2,3,4));
}
