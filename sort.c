#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

/*Procediment pel m�tode d'inserci�*/
void insertionSort(int v[], int mida, long long int* n_lec, long long int* n_esc, long long int* n_buc)
{
	int i, j, aux;

	/*Mentre no arribem al final de la llista, l'anem ordenant*/
	for (i = 1; i < mida; i++)
	{
		/*Guardem el primer n�mero no ordenat en la variable pivot*/
		aux = v[i];

		/*Augmentem el n� de lectures*/
		(*n_lec)++;

		/*Inicialitzem j per fer que apunti a la posici� anterior a i*/
		j = i - 1;
		
		/*Mentre j sigui major de 0 i el valor del pivot sigui m�s petit que el seu previ, col�loquem a la posici�
		j + 1 el valor de la posici� j i decrementem j.  D'aquesta forma, estem assegurant que el vector ordenat es
		mant� aix� i que nom�s sortim del bucle quan ens haguem "passat" anant enrere en aquest per col�locar el no�
		n�mero*/
		while (j >= 0 && aux < v[j])
		{
			(*n_lec)++;
			(*n_lec)++;
			v[j + 1] = v[j];
			(*n_esc)++;
			j--;
			(*n_buc)++;
		}

		/*Un cop hem sortit, col�loquem el nou n�mero en la seva posici�*/
		v[j + 1] = aux;
		(*n_esc)++;
	}
}


/*Procediment pel m�tode de selecci�*/
void selectionSort(int v[], int mida, long long int* n_lec, long long int* n_esc, long long int* n_buc)
{
	int i, j, pos, minim;
	/*Mentre no arribem al final de la llista (en aquest cas final-1, ja que l�ltim valor sempre ser� el m�s gran)*/
	for (i = 0; i < mida - 1; i++)
	{
		/*Seleccionem el primer valor com el m�s petit*/
		minim = v[i];
		(*n_lec)++;
		pos = i;

		/*Recorrem el vector per buscar si hi ha alg�n n�mero m�s petit que el que hem seleccionat com a m�nim. Si �s
		aix�, canviem el valor del m�nim i guardem la posici� on es troba aquest nou m�nim*/
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

		/*Un cop tenim el m�nim, col�loquem el valor de la primera posici� al seu lloc i aquest al de la primera.*/
		v[pos] = v[i];
		(*n_lec)++;
		(*n_esc)++;
		v[i] = minim;
		(*n_esc)++;
	}
} 


/*Procediment pel m�tode de bombolla*/
void bubbleSort(int secuencia[], int n_element, long long int* n_lec, long long int* n_escr, long long int* n_buc)
{
	int i = 1, j;
	bool ordenado = false; /*Indicar� si la secuencia est� ordenada o no*/
	while (!ordenado) /*Mientras la secuencia no est� ordenada se realizar� el bucle*/
	{
		ordenado = true; /*Damos por hecho que est� ordenada*/
		for (j = 0; j < (n_element - i); j++) /*j empieza valiendo 0, y se ir� implementando
		hasta que j deje de ser m�s peque�o que el n�mero de elementos que tiene la secuencia -1*/
		{
			if (secuencia[j] > secuencia[j + 1]) /*Se entrar� en el bucle si el n�mero posterior a otro es inferior*/
			{
				ordenado = false; /*Como no est� ordenada, volver� a ser falsa*/
				intercambia(secuencia, j, j + 1, n_lec, n_escr);
			}
			/*Implementamos dos veces el n�mero de lecturas, ya que en en la cabecera del if se realizaron dos*/
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
	he implementamos dos veces el n�mero de lecturas*/
	int nA = tabla[a], nB = tabla[b];
	(*n_lec)++;
	(*n_lec)++;
	/*Colocamos b en el lugar de a y viceversa. He implemantamos el n�mero de veces que se modifica la tabla*/
	tabla[a] = nB;
	tabla[b] = nA;
	(*n_esc)++;
	(*n_esc)++;
}
