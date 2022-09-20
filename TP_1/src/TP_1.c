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

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int calculosHechos = 0;

	float gastoHospedaje;
	float gastoComida;
	float gastoTransporte;
	int arqueros;
	int defensas;
	int mediocampistas;
	int delanteros;


	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorOFC = 0;

	gastoHospedaje = 0;
	gastoComida = 0;
	gastoTransporte = 0;
	arqueros = 0;
	defensas= 0;
	mediocampistas = 0;
	delanteros = 0;

	do{
		opcion = Menu(gastoHospedaje, gastoComida, gastoTransporte, arqueros, defensas, mediocampistas, delanteros);

		EjecutarOpcionElegida(opcion, &gastoHospedaje, &gastoComida, &gastoTransporte, &arqueros, &defensas, &mediocampistas, &delanteros, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC, &calculosHechos);

	}while(opcion != 5);

	printf("\nAFC: %d\nCAF: %d\nCONCACAF: %d\nCONMEBOL: %d\nUEFA: %d\nOFC: %d", contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC);


	return EXIT_SUCCESS;
}
