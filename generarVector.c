#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generarVector.h"

#define MAX_NUM 100
#define MAX_LONGITUD 100000


int* CrearLista(int largo)
{
	int* vector;  /*Creamos un puntero a entero que nos indicará el inicio de la tabla*/
	vector = malloc(largo * sizeof(int)); 
	return (vector);
}

void RellenarTabla(int tabla[], int largo)
{
	int cont = 0;
	while (cont < largo)
	{
		tabla[cont] = NumeroAleatorio();
		cont++;
	}
}

int NumeroAleatorio()  /*Se van creando números aleatorios entre 0 y MAX_NUM*/
{
	int n_ale = rand() % (MAX_NUM + 1);
	return(n_ale);
}

int* GenerarLista(int* n_elem)  /*Genera una lista del tamaño que desee el usuario, y la rellena con números aleatorios*/
{
	int longitud = MAX_LONGITUD+1;  /*Inicialización necesaria para entrar en el bucle*/
	while ((longitud > MAX_LONGITUD) || (longitud < 0))  /*No se saldrá del bucle hasta que no se introduzca un valor que se encuentra dentro del intervalo aceptado*/
	{
		printf("¿De que tamaño desea que sea la tabla?\n");
		scanf("%d", &longitud);
	}
	system("cls");
	*n_elem = longitud;
	int* tabla_aleatorios = CrearLista(longitud);  /*Se crea la lista, pero esta está "vacia"*/
	RellenarTabla(tabla_aleatorios, longitud);  /*Rellenamos la lista con números aleatorio*/
	return(tabla_aleatorios);
}

/*Procediment que mostra el contingut d'un vector de mida n*/
void mostrarVector(int v[], int n)
{
	printf("El vector és:\n");
	for (int cont = 0; cont < n; cont++)
	{
		printf("%d ", v[cont]);
	}
	printf("\n");
}

/*Procediment que copia un vector de llargada n*/
void copiaVector(int* desti, int* origen, int n)
{
	for (int i = 0; i < n; i++)
	{
		desti[i] = origen[i];
	}
}