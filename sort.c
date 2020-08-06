#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

/*Procediment pel mètode d'inserció*/
void insertionSort(int v[], int mida, long long int* n_lec, long long int* n_esc, long long int* n_buc)
{
	int i, j, aux;

	/*Mentre no arribem al final de la llista, l'anem ordenant*/
	for (i = 1; i < mida; i++)
	{
		/*Guardem el primer número no ordenat en la variable pivot*/
		aux = v[i];

		/*Augmentem el nº de lectures*/
		(*n_lec)++;

		/*Inicialitzem j per fer que apunti a la posició anterior a i*/
		j = i - 1;
		
		/*Mentre j sigui major de 0 i el valor del pivot sigui més petit que el seu previ, col·loquem a la posició
		j + 1 el valor de la posició j i decrementem j.  D'aquesta forma, estem assegurant que el vector ordenat es
		manté així i que només sortim del bucle quan ens haguem "passat" anant enrere en aquest per col·locar el noú
		número*/
		while (j >= 0 && aux < v[j])
		{
			(*n_lec)++;
			(*n_lec)++;
			v[j + 1] = v[j];
			(*n_esc)++;
			j--;
			(*n_buc)++;
		}

		/*Un cop hem sortit, col·loquem el nou número en la seva posició*/
		v[j + 1] = aux;
		(*n_esc)++;
	}
}


/*Procediment pel mètode de selecció*/
void selectionSort(int v[], int mida, long long int* n_lec, long long int* n_esc, long long int* n_buc)
{
	int i, j, pos, minim;
	/*Mentre no arribem al final de la llista (en aquest cas final-1, ja que lúltim valor sempre serà el més gran)*/
	for (i = 0; i < mida - 1; i++)
	{
		/*Seleccionem el primer valor com el més petit*/
		minim = v[i];
		(*n_lec)++;
		pos = i;

		/*Recorrem el vector per buscar si hi ha algún número més petit que el que hem seleccionat com a mínim. Si és
		així, canviem el valor del mínim i guardem la posició on es troba aquest nou mínim*/
		for (j = i + 1; j < mida; j++)
		{
			(*n_lec)++;
			if (v[j] < minim)
			{
				minim = v[j];
				pos = j;
				(*n_lec)++;
			}
			(*n_buc)++;
		}

		/*Un cop tenim el mínim, col·loquem el valor de la primera posició al seu lloc i aquest al de la primera.*/
		v[pos] = v[i];
		(*n_lec)++;
		(*n_esc)++;
		v[i] = minim;
		(*n_esc)++;
	}
} 


/*Procediment pel mètode de bombolla*/
void bubbleSort(int secuencia[], int n_element, long long int* n_lec, long long int* n_escr, long long int* n_buc)
{
	int i = 1, j;
	bool ordenado = false; /*Indicará si la secuencia está ordenada o no*/
	while (!ordenado) /*Mientras la secuencia no esté ordenada se realizará el bucle*/
	{
		ordenado = true; /*Damos por hecho que esté ordenada*/
		for (j = 0; j < (n_element - i); j++) /*j empieza valiendo 0, y se irá implementando
		hasta que j deje de ser más pequeño que el número de elementos que tiene la secuencia -1*/
		{
			if (secuencia[j] > secuencia[j + 1]) /*Se entrará en el bucle si el número posterior a otro es inferior*/
			{
				ordenado = false; /*Como no está ordenada, volverá a ser falsa*/
				intercambia(secuencia, j, j + 1, n_lec, n_escr);
			}
			/*Implementamos dos veces el número de lecturas, ya que en en la cabecera del if se realizaron dos*/
			(*n_lec)++;
			(*n_lec)++;
			(*n_buc)++;
		}
		i++;
	}
}

/*Procediment que intercanvia dues posicions d'un vector*/
void intercambia(int tabla[], int a, int b, long long int* n_lec, long long int* n_esc)
{
	/*Para no perder los valores que vamos a intercambiar de la tabla, los guardamos en otras variables,
	he implementamos dos veces el número de lecturas*/
	int nA = tabla[a], nB = tabla[b];
	(*n_lec)++;
	(*n_lec)++;
	/*Colocamos b en el lugar de a y viceversa. He implemantamos el número de veces que se modifica la tabla*/
	tabla[a] = nB;
	tabla[b] = nA;
	(*n_esc)++;
	(*n_esc)++;
}
