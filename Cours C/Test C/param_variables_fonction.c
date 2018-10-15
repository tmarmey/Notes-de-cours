#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

int sum(int fixe1, int fixe2 ,int n,...){
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

bool somme(int n,...){
	va_list va;
	va_start(va, n);

	int a = va_arg(va, int);
	int b = va_arg(va, int);
	va_end(va);
	
	if ((a+b) == 1)
		return true;
	else
		return false;
}

int main(int argc, char **argv){
	printf("%d\n",sum(0,0,4, 1,2,3,4));

	printf("%d\n",somme(2,1,0,0));
	printf("%d\n",somme(2,0,2,2));
}
