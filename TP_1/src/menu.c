
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ingresosDeDatos.h"

/// @brief
///
/// @param gastoHospedaje
/// @param gastoComida
/// @param gastoTransporte
/// @param arqueros
/// @param defensas
/// @param mediocampistas
/// @param delanteros
/// @return
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
			CargaDeJugadores(arqueros, defensas, mediocampistas, delanteros);
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

	getInt(&opcion, "\n\nIngrese el costo que desea cargar: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 4);

	switch(opcion){
		case 1:
			getFloat(*(&gastoHospedaje), "\nIngrese el costo de hospedaje: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
			break;

		case 2:
			getFloat(*(&gastoComida), "\nIngrese el costo de comida: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
			break;

		case 3:
			getFloat(*(&gastoTransporte), "\nIngrese el costo de transporte: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
			break;

		case 4:
			printf("\nSaliendo...");
			break;
	}

}


void CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros){
	int opcion;

	printf("\nCarga de jugadores");
	printf("\n 1.Arqueros");
	printf("\n 2.Defensores");
	printf("\n 3.Mediocampistas");
	printf("\n 4.Delanteros");
	printf("\n 5.Salir");

	getInt(&opcion, "\n\nIngrese la posicion del jugador que desea cargar: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 5);

	switch(opcion){
		case 1:
			*pArqueros += 1;
			break;

		case 2:
			*pDefensas += 1;
			break;

		case 3:
			*pMediocampistas += 1;
			break;

		case 4:
			*pDelanteros += 1;
			break;

		case 5:
			printf("\nSaliendo...");
			break;
	}
}


void PedirDatosDelJugador(int* numeroCamiseta){
	getInt(&numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\n[ERROR] El numero que ingreso no es valido.", 1, 99);
}

int PedirConfederacion(void){
	int opcion;

	printf("\nSeleccione la confederacion en la que el jugador esta jugando: ");
	printf("\n 1.AFC");
	printf("\n 2.CAF");
	printf("\n 3.CONCACAF");
	printf("\n 4.CONMEBOL");
	printf("\n 5.UEFA");
	printf("\n 6.OFC");

	getInt(&opcion, "\n\nIngrese el numero de la confederacion: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 6);

	return opcion;
}


void ContadorConfederaciones(int confederacion, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC){
	switch(confederacion){
	case 1:
		*pAFC += 1;
		break;

	case 2:
		*pCAF += 1;
		break;

	case 3:
		*pCONCACAF += 1;
		break;

	case 4:
		*pCONMEBOL += 1;
		break;

	case 5:
		*pUEFA += 1;
		break;

	case 6:
		*pOFC += 1;
		break;
	}
}




































