/*
Trabajo Practico 1

Lautaro Monserrat
45426439
DIV C 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"

#define MAX_ARQUEROS 2
#define MAX_DEFENSAS 8
#define MAX_MEDIOS 8
#define MAX_DELANTEROS 4

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int calculosHechos = 0;
	int puedeContinuar;
	int mayoriaUEFA;

	float gastoHospedaje = 0;
	float gastoComida = 0;
	float gastoTransporte = 0;
	int arqueros = 0;
	int defensas = 0;
	int mediocampistas = 0;
	int delanteros = 0;

	int contadorJugadoresEnTotal;
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
	float costoMantenimientoAumento;
	int porcentajeAumento = 35;
	float aumento;

	do{
		opcion = Menu(gastoHospedaje, gastoComida, gastoTransporte, arqueros, defensas, mediocampistas, delanteros);

		switch(opcion){
			case 1:
				CargarCostosMantenimiento(&gastoHospedaje, &gastoComida, &gastoTransporte);
				break;

			case 2:
				CargaDeJugadores(&arqueros, &defensas, &mediocampistas, &delanteros, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC, MAX_ARQUEROS, MAX_DEFENSAS, MAX_MEDIOS, MAX_DELANTEROS);
				break;

			case 3:
				contadorJugadoresEnTotal = arqueros + defensas + mediocampistas + delanteros;
				puedeContinuar = ValidarOpcionTres(gastoHospedaje, gastoComida, gastoTransporte, contadorJugadoresEnTotal);

				if(puedeContinuar == 1){
					// Promedio de jugadores de cada mercado
					CalcularTodasConfederaciones(contadorJugadoresEnTotal, contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC, &promedioAFC, &promedioCAF, &promedioCONCACAF, &promedioCONMEBOL, &promedioUEFA, &promedioOFC);

					// Costo de mantenimiento
					costoMantenimiento = CalcularCostoMantenimiento(gastoHospedaje, gastoComida, gastoTransporte);

					// Verificamos si aplica para el aumento (en caso de que si, se calcula el aumento)
					mayoriaUEFA = ChequearMayoriaUEFA(promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC);

					if(mayoriaUEFA == 1){
						CalcularAumento(costoMantenimiento, porcentajeAumento, &aumento, &costoMantenimientoAumento);
					}

					printf("\nTodos los calculos fueron realizados con exito!\n");
					calculosHechos = 1;
				}

				break;

			case 4:
				if(calculosHechos == 1){
					MostrarResultados(promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC, mayoriaUEFA, costoMantenimiento, aumento, costoMantenimientoAumento);
				}
				else{
					printf("\n[ERROR] Tenes que realizar los calculos antes de informar los resultados.\n");
				}

				break;

			case 5:
				printf("Saliendo...\n");
				break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
