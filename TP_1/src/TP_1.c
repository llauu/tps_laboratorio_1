/*
Trabajo Practico 1

Lautaro Monserrat
45426439
DIV C
*/

#include <stdio.h>
#include <stdlib.h>
#include "ingresosDeDatos.h"
#include "menu.h"
#define SIZE 10

int main(void) {
	char liga[SIZE];
	int opcion;

	float gastoHospedaje;
	float gastoComida;
	float gastoTransporte;
	int arqueros;
	int defensas;
	int mediocampistas;
	int delanteros;

	gastoHospedaje = 0;
	gastoComida = 0;
	gastoTransporte = 0;
	arqueros = 0;
	defensas= 0;
	mediocampistas = 0;
	delanteros = 0;

	do{
		opcion = Menu(gastoHospedaje, gastoComida, gastoTransporte, arqueros, defensas, mediocampistas, delanteros);

		EjecutarOpcionElegida(opcion, &gastoHospedaje, &gastoComida, &gastoTransporte, &arqueros, &defensas, &mediocampistas, &delanteros);
	}while(opcion != 5);


	return EXIT_SUCCESS;
}
