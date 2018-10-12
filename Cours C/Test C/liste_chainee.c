#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
};

typedef struct Liste Liste;
struct Liste 
{
	Element *premier;
};

Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL )
	{	
		printf("EXIT_FAILURE dans *initialisation()\n");
		exit(EXIT_FAILURE);
	}

	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;

	return liste;
}

void insertion(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));

	if (liste == NULL || nouveau == NULL)
	{
		printf("EXIT_FAILURE dans insertion()\n");
		exit(EXIT_FAILURE);
	}

	nouveau->nombre = nvNombre;
	nouveau->suivant = liste->premier;

	liste->premier = nouveau;
}

void insertionMilieu(Liste *liste, unsigned int index ,int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));

	if (liste == NULL || nouveau == NULL)
	{
		printf("EXIT_FAILURE dans insertionMilieu()\n");
		exit(EXIT_FAILURE);
	}

	if (index == 0)
	{
		insertion(liste, nvNombre);
	}

	else 
	{
		Element *actuel = liste->premier;
		int i = 1;
		while (i < index)
		{
			actuel = actuel->suivant;
			if (actuel == NULL || actuel->suivant == NULL)
			{
				printf("EXIT_FAILURE dans insertionMilieu()\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}

		nouveau->nombre = nvNombre;
		nouveau->suivant = actuel->suivant;
		actuel->suivant = nouveau;
	}
}

void suppression(Liste *liste)
{
	if (liste == NULL)
	{
		printf("EXIT_FAILURE dans suppression()\n");
		exit(EXIT_FAILURE);
	}

	if (liste->premier != NULL)
	{
		Element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
}

void afficherListe(Liste *liste)
{
	if (liste == NULL)
	{
		printf("EXIT_FAILURE dans afficherListe()\n");
		exit(EXIT_FAILURE);
	}

	Element *actuel = liste->premier;

	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->suivant;
	}

	printf("NULL \n");
}

/* A faire :
	- Supprimer élément en milieu de liste
	- Détruire la liste
	- Ajouter taille de la liste dans la structure Liste
*/

int main(int argc, char **argv)
{
	Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    insertionMilieu(maListe, atoi(argv[1]), 1);


    afficherListe(maListe);

	return 0;
}
