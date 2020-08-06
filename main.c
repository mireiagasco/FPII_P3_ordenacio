#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "sort.h"
#include "generarVector.h"
#include "input.h"
#include "pruebaDicotomica.h"


void main()
{
	setlocale(LC_ALL, "");

	/*Inicialitzem a zero els comptadors que necessitarem*/
	srand((unsigned int)time(NULL));
	int n_elem = 0;
	long long int n_lect = 0;
	long long int n_esc = 0;
	long long int n_bucle = 0;
	int n_cerca = 0;

	/*Variables per calcular el temps d'execució*/
	clock_t clocks;
	double temps;

	/*Generem la llista*/
	int* vector = GenerarLista(&n_elem);
	int* vector_copia = CrearLista(n_elem);

	bool continuar = true;
	while (continuar)
	{
		/*Cada cop que fem una ordenació posem a zero aquests valors*/
		n_lect = 0;
		n_esc = 0;
		n_bucle = 0;

		/*Fem una copia del vector*/
		copiaVector(vector_copia, vector, n_elem);
				
		/*Mostrem les opcions d'ordenació i fem que l'usuari en trii una*/
		mostrarMenu();

		/*Demanem quin tipus d'ordenació es vol fer*/
		char opcio = demanarOpcio();

		/*Guardem el temps inicial*/
		clocks = clock();

		switch (opcio)
		{
		case '1': bubbleSort(vector_copia, n_elem, &n_lect, &n_esc, &n_bucle);
			break;
		case '2': insertionSort(vector_copia, n_elem, &n_lect, &n_esc, &n_bucle);
			break;
		case '3': selectionSort(vector_copia, n_elem, &n_lect, &n_esc, &n_bucle);
			break;
		case '4': mostrarVector(vector, n_elem);
			break;
		case '5': cercaDicotomica(vector_copia, n_elem, &n_lect, &n_esc, &n_bucle, &n_cerca);
			break;
		default: continuar = false;
		}

		if (continuar && opcio != '4' && opcio !='5')
		{
			/*Obtenim el temps emprat*/
			clocks = clock() - clocks;
			temps = (double)clocks / CLOCKS_PER_SEC;

			/*Mostrem el vector ordenat*/
			mostrarVector(vector_copia, n_elem);

			/*Mostrem el temps utilitzat*/
			printf("\n\nTemps d'execució: %f segons\n", temps);

			/*Mostrem els cops que s'executa el bucle intern de l'algorisme d'ordenació*/
			printf("Nombre de cops que s'executa el bucle: %lld\n", n_bucle);

			/*Mostrem els cops que s'ha accedit al vector*/
			printf("Número d'accessos al vector: %lld \n", n_lect + n_esc);
			printf("	-> Dels quals lectures: %lld \n", n_lect);
			printf("	-> Dels quals escriptures: %lld \n", n_esc);
		}
		system("pause");
		system("cls");
	}	
}