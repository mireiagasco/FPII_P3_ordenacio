#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"	//Arxiu amb les cap�aleres de les funcions que demanen dades a l'usuari

/*Funcions que demanen i comproven dades introduides per l'usuari o mostren informaci� per pantalla*/

/*Acci� que mostra un men�*/
void mostrarMenu()
{
	printf("----- Algorismes d'ordenaci� i cerca dicot�mica-----\n\n");
	printf("1) Bubble Sort\n2) Insertion Sort\n3) Selection Sort\n4) Mostrar vector original\n5) Cerca dicot�mica \n0) Sortir\n\n");
}


/*Funci� que demana un n�mero per teclat entre un m�xim i un m�nim donats, comprova que sigui un valor v�lid, i el retorna.
Si el m�xim i el m�nim s�n iguals, vol dir que no hi ha l�mits i, per tant, no cal controlar res*/
int demanarNum(int min, int max)
{
	int numero;
	if (min != max)
	{
		numero = max + 1;
		while (numero < min || numero > max)
		{
			printf("Indiqui un n�mero (entre %d i %d): ", min, max);
			scanf(" %d", &numero);
			if (numero < min || numero > max)
			{
				printf("Valor no v�lid, ha d'estar entre %d i %d\n", min, max);
			}
		}
	}
	else
	{
		printf("Indiqui un n�mero: ");
		scanf(" %d", &numero);
	}
	return numero;
}

/*Acci� que demana a l'usuari quina opci� vol realitzar*/
char demanarOpcio()
{
	char opcio = 'a';
	char dades[MAX_CHAR];
	printf("Indiqui quina acci� vol realitzar: ");
	scanf(" %s", dades);

	if (dades[1] == '\0')
	{
		opcio = dades[0];
	}

	return opcio;
}

/*Funci� que comprova que el un n�mero �s natural i, si no ho �s, el converteix*/
int convertirNatural(int a)
{
	if (a < 0)
	{
		a = a * (-1);
	}
	return a;
}