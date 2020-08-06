#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"	//Arxiu amb les capçaleres de les funcions que demanen dades a l'usuari

/*Funcions que demanen i comproven dades introduides per l'usuari o mostren informació per pantalla*/

/*Acció que mostra un menú*/
void mostrarMenu()
{
	printf("----- Algorismes d'ordenació i cerca dicotòmica-----\n\n");
	printf("1) Bubble Sort\n2) Insertion Sort\n3) Selection Sort\n4) Mostrar vector original\n5) Cerca dicotòmica \n0) Sortir\n\n");
}


/*Funció que demana un número per teclat entre un màxim i un mínim donats, comprova que sigui un valor vàlid, i el retorna.
Si el màxim i el mínim són iguals, vol dir que no hi ha límits i, per tant, no cal controlar res*/
int demanarNum(int min, int max)
{
	int numero;
	if (min != max)
	{
		numero = max + 1;
		while (numero < min || numero > max)
		{
			printf("Indiqui un número (entre %d i %d): ", min, max);
			scanf(" %d", &numero);
			if (numero < min || numero > max)
			{
				printf("Valor no vàlid, ha d'estar entre %d i %d\n", min, max);
			}
		}
	}
	else
	{
		printf("Indiqui un número: ");
		scanf(" %d", &numero);
	}
	return numero;
}

/*Acció que demana a l'usuari quina opció vol realitzar*/
char demanarOpcio()
{
	char opcio = 'a';
	char dades[MAX_CHAR];
	printf("Indiqui quina acció vol realitzar: ");
	scanf(" %s", dades);

	if (dades[1] == '\0')
	{
		opcio = dades[0];
	}

	return opcio;
}

/*Funció que comprova que el un número és natural i, si no ho és, el converteix*/
int convertirNatural(int a)
{
	if (a < 0)
	{
		a = a * (-1);
	}
	return a;
}