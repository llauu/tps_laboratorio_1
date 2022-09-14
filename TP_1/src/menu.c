
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ingresosDeDatos.h"

int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros){
	int opcion;

	printf("\n             Menu Principal\n");
	printf("\n1.Ingreso de los costos de Mantenimiento");
	ImprimirCostosMantenimiento(gastoHospedaje, gastoComida, gastoTransporte);

	printf("\n2.Carga de jugadores");
	ImprimirJugadores(arqueros, defensas, mediocampistas, delanteros);

	printf("\n3.Realizar todos los calculos");

	printf("\n4.Informar todos los resultados");

	printf("\n5.Salir");

	getInt(&opcion, "\n\nOpcion: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 5);

	return opcion;
}


int ImprimirCostosMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte){
	printf("\n Costo de Hospedaje -> $%.2f", gastoHospedaje);
	printf("\n Costo de Comida -> $%.2f", gastoComida);
	printf("\n Costo de Transporte -> $%.2f", gastoTransporte);

	return 0;
}


int ImprimirJugadores(int arqueros, int defensas, int mediocampistas, int delanteros){
	printf("\n Arqueros -> %d", arqueros);
	printf("\n Defensores -> %d", defensas);
	printf("\n Mediocampistas -> %d", mediocampistas);
	printf("\n Delanteros -> %d", delanteros);

	return 0;
}


void EjecutarOpcionElegida(int opcion, float* gastoHospedaje, float* gastoComida, float* gastoTransporte, int* arqueros, int* defensas, int* mediocampistas, int* delanteros){
	switch(opcion){
		case 1:
			CargarCostosMantenimiento(gastoHospedaje, gastoComida, gastoTransporte);
			break;

		case 2:
			printf("Entraste al 2");

			break;

		case 3:
			printf("Entraste al 3");

			break;

		case 4:
			printf("Entraste al 4");

			break;

		case 5:
			printf("Saliendo...");
			break;
	}
}


void CargarCostosMantenimiento(float* gastoHospedaje, float* gastoComida, float* gastoTransporte){
	int opcion;

	printf("\nIngreso de los costos de Mantenimiento");
	printf("\n 1.Costo de Hospedaje");
	printf("\n 2.Costo de Comida");
	printf("\n 3.Costo de Transporte");
	printf("\n 4.Salir");

	getInt(&opcion, "\n\nIngrese el costo que quiera cargar: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 4);

	switch(opcion){
		case 1:
			getFloat(*(&gastoHospedaje), "\nIngrese el costo de hospedaje: ", "\[ERROR] El costo que ingreso no es valido.", 0, 2147483645);
			break;

		case 2:
			getFloat(*(&gastoComida), "\nIngrese el costo de comida: ", "\[ERROR] El costo que ingreso no es valido.", 0, 2147483645);
			break;

		case 3:
			getFloat(*(&gastoTransporte), "\nIngrese el costo de transporte: ", "\[ERROR] El costo que ingreso no es valido.", 0, 2147483645);
			break;

		case 4:
			printf("\nSaliendo...");
			break;
	}

}


