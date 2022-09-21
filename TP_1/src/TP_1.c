/*
Trabajo Practico 1

Lautaro Monserrat
45426439
DIV C
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int calculosHechos = 0;

	float gastoHospedaje = 0;
	float gastoComida = 0;
	float gastoTransporte = 0;
	int arqueros = 0;
	int defensas = 0;
	int mediocampistas = 0;
	int delanteros = 0;

	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorOFC = 0;

	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;

	float costoMantenimiento;

	do{
		opcion = Menu(gastoHospedaje, gastoComida, gastoTransporte, arqueros, defensas, mediocampistas, delanteros);

		EjecutarOpcionElegida(opcion, &gastoHospedaje, &gastoComida, &gastoTransporte, &arqueros, &defensas, &mediocampistas, &delanteros, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC, &calculosHechos, &promedioAFC, &promedioCAF, &promedioCONCACAF, &promedioCONMEBOL, &promedioUEFA, &promedioOFC, &costoMantenimiento);

	}while(opcion != 5);

//	printf("\nAFC: %d\nCAF: %d\nCONCACAF: %d\nCONMEBOL: %d\nUEFA: %d\nOFC: %d", contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC);


	return EXIT_SUCCESS;
}
