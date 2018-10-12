#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void changerTableau(int*, int);
void lireTableau(int*, int);

void changePointeur(int **_p1, int **_p2){
	int *_ptr = *_p1;
	*_p1 = *_p2;
	*_p2 = _ptr;
}

void changeNombre(int *_ptra, int *_ptrb){
	int a = *_ptra;

	*_ptra = *_ptrb;
	*_ptrb = a;
}

void changerMot(char **t, char *mot){
	*t = malloc(sizeof(mot));
	*t = mot;
	printf("%s\n", *t);
}

void changerLettre(char *t){
	*(t+1) = 'a';
	printf("%s\n", t);
}

void fonctionArgument(void (*function)()){
	(*function)();
}

void fonction1(){
	printf("fonction1\n");
}

void fonction2(){
	printf("fonction2\n");
}

int *renvoyerTableau(){
	int static tab[2] = {1, 2};
	return tab;
}


//idée : 
	// travailler sur des structures
	// créer fonction pour print un tableau quelconque
	// commuter deux chaînes de caractères
	// travailler sur des listes chaînées

int main(int argc, char **argv){


	//---------------------------------------
	/*int *tableau;
	tableau = renvoyerTableau();

	for(int i = 0; i < 2; i++){
		printf(" %d ", tableau[i]);
	}/*
	//---------------------------------------

	//---------------------------------------
	/*fonctionArgument(fonction1);
	fonctionArgument(fonction2);*/
	//---------------------------------------

	//---------------------------------------
	/*char *tab = malloc(3);
	tab = "abc";
	changerMot(&tab, "titi");

	printf("%s\n",tab);*/
	//---------------------------------------

	//---------------------------------------
	  /*int numbers[5];
	  int * p;
	  p = numbers;  *p = 10;
	  p++;  *p = 20;
	  p = &numbers[2];  *p = 30;
	  p = numbers + 3;  *p = 40;
	  p = numbers;  *(p+4) = 50;
	  for (int n=0; n<5; n++)
	    printf(", %d",numbers[n]);
	printf("\n");*/
	//---------------------------------------

	//---------------------------------------
	/*int a = 1;
	int *p = &a;
	int **pp = &p;
	printf("valeur a : %d\n", a);
	printf("valeur p : %p\n", p);
	printf("adresse a : %p\n", &a);
	printf("adresse p : %p\n", &p);
	printf("valeur *p : %d\n", *p);
	printf("adresse *p : %p\n\n", &(*p));

	printf("valeur pp : %p\n", pp);
	printf("adresse pp : %p\n", &pp);
	printf("valeur *pp : %p\n", *pp);
	printf("adresse *pp : %p\n", &(*pp));
	printf("valeur **pp : %d\n", **pp);
	printf("adresse **pp : %p\n", &(**pp));*/
	//---------------------------------------

	//---------------------------------------
	/*int a = 1;
	int b = 2;
	int *ptr1 = &a;
	int *ptr2 = &b;
	//int **pp = &ptr1

	printf("valeur ptr1 : %d\n", *ptr1);
	printf("valeur ptr2 : %d\n", *ptr2);

	changePointeur(&ptr1, &ptr2);

	printf("valeur ptr1 : %d\n", *ptr1);
	printf("valeur ptr2 : %d\n", *ptr2);

	printf("adresse ptr1 : %p\n", ptr1);
	printf("valeur a : %d\n", a);
	printf("adresse a : %p\n", &a);
	printf("valeur b : %d\n", b);
	printf("adresse b : %p\n", &b);*/
	//---------------------------------------

	//---------------------------------------
	/*int taille = 5;
	int *ptr = (int *)malloc(sizeof(int)*taille);

	for (int i = 0; i < taille; i++) {
		*(ptr+i) = i*i;
	}

	lireTableau(ptr, taille);
	lireTableau(ptr, sizeof(*ptr));
	printf("valeur pointeur : %d \n", *ptr);
	printf("adresse : %p \n", ptr);

	changerTableau(ptr, taille);

	printf("Apres :");
	lireTableau(ptr, taille);

	printf("Nouvelle valeur pointeur : %d \n", *ptr);
	printf("Nouvelle adresse : %p \n", ptr);*/
	//---------------------------------------
	return 0;
}

//---------------------------------------
/*void changerTableau(int *_ptr, int 	_taille){
	for (int i = 0; i < _taille; i++) {
		*(_ptr+i) = 1;
	}
}

void lireTableau(int *_tab, int _taille){
	printf("\n[ ");
	for (int i = 0; i < _taille; i++) {
		printf("%d ", *(_tab+i));
	}
	printf("]\n");
}/*
//---------------------------------------