#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "input.h"
#include "generarVector.h"
#include "sort.h"
#include "pruebaDicotomica.h"

/*"main" de la cerca dicotòmica*/
void cercaDicotomica(int v[], int mida, long long int* n_lect, long long int* n_esc, long long int* n_bucle, int* n_cerc)
{
	setlocale(LC_ALL, "");
	printf("\n---Cerca dicotomica---\n");

	int numeroAbuscar = 0;
	bool trobat = false;

	//muestra el vector creado y ordenado //no nesesario :D
	printf("elementos creados aleatorios:\n");///////
	mostrarVector(v, mida);///////
	printf("\nelementos ordenados: Insertion Sort\n");/////
	insertionSort(v, mida, &n_lect, &n_esc, &n_bucle); /*ordenado por inserción*/
	mostrarVector(v, mida);//////


	/*busqueda por numeros que se encuentran en el vector*/
	printf("\n\n-----Elementos que se encuentran en el vector, son 10 pruebas-----\n");
	for (int i = 0; i < MAX_CERCAS; ++i)
	{
		n_cerc = 0;
		int n_posicion = rand() % (mida-1 + 1);

		/*Busquedas donde el elemento se encuentra en el vector, escogemos aleatoriamente una posicion del vector
		y guardamos el numero que se encuentra en esa posicion*/
		numeroAbuscar = v[n_posicion];
		trobat = busquedaAlvector(v, numeroAbuscar, mida, &n_cerc);
		printf("\nPRUEBA %d numero a buscar %d:\n", i + 1, numeroAbuscar);
		resultados(trobat, n_cerc);
	}

	printf("\n___________________________________________________________________\n\n");

	/*busqueda por numeros que NO se encuentran en el vector*/
	printf("\n\n-----Elementos que no se encuentran en el vector, son 10 pruebas-----\n");
	for (int i = 0; i < MAX_CERCAS; ++i)
	{
		n_cerc = 0;

		//numeroAbuscar = demanarNum(101,200); /* 101-200 no se encuentran en el vector*/
		numeroAbuscar = rand() % (200 + 1-102) + 101;
		trobat = busquedaAlvector(v, numeroAbuscar, mida, &n_cerc);
		printf("\nPRUEBA %d, numero a buscar %d:\n",i +1,numeroAbuscar);
		resultados(trobat, n_cerc);
	}
}

/*Algorisme que fa la cerca dicotòmica*/
bool busquedaAlvector(int vector[],int numeroBuscar, int n_elem, long long int* n_cer)
{
	int contador = 0;
	int inferior = 0, superior=n_elem-1; /*Se crea las posiciones de busqueda en la tabla*/
	bool resultado = false;

	while(inferior<= superior)
	{
		int medio = (inferior+superior)/2; /*ubicamos la mitad del vector*/
		int elem_medio=vector[medio]; /*Guarda el elemento que esta en el medio*/
		resultado = comparacion(elem_medio,numeroBuscar);
		(*n_cer)++;

		if (resultado) /*Si encuentra el numero a buscar sale del bucle*/
		{
			contador++;
			inferior=n_elem;
		}
		else
		{
			if (numeroBuscar<elem_medio) /*revisamos en que zona del vector se encuentraria el elemento*/
			{/*si se encuentra en la zona inferior, nuestro nuevo max se le resta 1 */
				superior=medio-1;
			}
			else
			{/*si no lo es, el nuevo inicio se le suma 1*/
				inferior =medio+1;
			}
		}
	}
	return (resultado);
}

bool comparacion(int nposi, int nbuscar)
{
	bool comparado = false;
	if (nposi == nbuscar)
	{
		comparado = true;
	}
	return comparado;
}


void resultados(bool encontrado, int num)
{
	printf("Numero de comparacions fetes: %d\n", num);
	if (encontrado)
	{
		printf("Si s'ha trobat el numero a la taula\n");
	}
	else
	{
		printf("No s'ha trobat el numero a la taula\n");
	}
}