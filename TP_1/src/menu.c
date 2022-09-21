
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ingresosDeDatos.h"
#include "calculos.h"


int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros){
	int opcion;

	printf("\n             Menu Principal\n");
	printf("\n1.Ingreso de los costos de mantenimiento");
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


int ValidarOpcionElegida(int opcion, float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros, int calculosHechos){
	int puedeContinuar = 0;

	if(opcion == 3){
		if(gastoHospedaje != 0 && gastoComida != 0 && gastoTransporte != 0){
			if(arqueros == MAX_ARQUEROS && defensas == MAX_DEFENSAS && mediocampistas == MAX_MEDIOS && delanteros == MAX_DELANTEROS){
				puedeContinuar = 1;
			}
			else{
				printf("\n[ERROR] Tenes que cargar a todos los jugadores antes de realizar los calculos.\n");
			}
		}
		else{
			printf("\n[ERROR] Tenes que cargar los gastos antes de realizar los calculos.\n");
		}
	}

	if(opcion == 4){
		if(calculosHechos == 1){
			puedeContinuar = 1;
		}
		else{
			printf("\n[ERROR] Tenes que realizar los calculos antes de informar los resultados.\n");
		}
	}

	return puedeContinuar;
}


void EjecutarOpcionElegida(int opcion, float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte, int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC, int* pCalculosHechos, float* pPromedioAFC, float* pPromedioCAF, float* pPromedioCONCACAF, float* pPromedioCONMEBOL, float* pPromedioUEFA, float* pPromedioOFC, float* pCostoMantenimiento){
	int puedeContinuar;

	int calculosHechos = *pCalculosHechos;
	float gastoHospedaje = *pGastoHospedaje;
	float gastoComida = *pGastoComida;
	float gastoTransporte = *pGastoTransporte;

	int arqueros = *pArqueros;
	int defensas = *pDefensas;
	int mediocampistas = *pMediocampistas;
	int delanteros = *pDelanteros;

	int contadorAFC = *pAFC;
	int contadorCAF = *pCAF;
	int contadorCONCACAF = *pCONCACAF;
	int contadorCONMEBOL = *pCONMEBOL;
	int contadorUEFA = *pUEFA;
	int contadorOFC = *pOFC;
	float promedioAFC = *pPromedioAFC;
	float promedioCAF = *pPromedioCAF;
	float promedioCONCACAF = *pPromedioCONCACAF;
	float promedioCONMEBOL = *pPromedioCONMEBOL;
	float promedioUEFA = *pPromedioUEFA;
	float promedioOFC = *pPromedioOFC;

	float costoMantenimiento = *pCostoMantenimiento;

	puedeContinuar = ValidarOpcionElegida(opcion, gastoHospedaje, gastoComida, gastoTransporte, arqueros, defensas, mediocampistas, delanteros, calculosHechos);

	switch(opcion){
		case 1:
			CargarCostosMantenimiento(pGastoHospedaje, pGastoComida, pGastoTransporte);
			break;

		case 2:
			CargaDeJugadores(pArqueros, pDefensas, pMediocampistas, pDelanteros, pAFC, pCAF, pCONCACAF, pCONMEBOL, pUEFA, pOFC);
			break;

		case 3:
			if(puedeContinuar == 1){
				CalcularTodasConfederaciones(MAX_JUGADORES, contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC, &promedioAFC, &promedioCAF, &promedioCONCACAF, &promedioCONMEBOL, &promedioUEFA, &promedioOFC);

				costoMantenimiento = CalcularCostoMantenimiento(gastoHospedaje, gastoComida, gastoTransporte);

				printf("\nLos calculos fueron realizados con exito!\n");
				*pCalculosHechos = 1;
			}

			break;

		case 4:
			if(puedeContinuar == 1){
				printf("\nPromedio de jugadores en AFC: %.2f", promedioAFC);
				printf("\nPromedio de jugadores en CAF: %.2f", promedioCAF);
				printf("\nPromedio de jugadores en CONCACAF: %.2f", promedioCONCACAF);
				printf("\nPromedio de jugadores en CONMEBOL: %.2f", promedioCONMEBOL);
				printf("\nPromedio de jugadores en UEFA: %.2f", promedioUEFA);
				printf("\nPromedio de jugadores en OFC: %.2f", promedioOFC);

				printf("\nEl costo de mantenimiento es de: $%.2f\n", costoMantenimiento);
			}

			break;

		case 5:
			printf("Saliendo...");
			break;
	}

	*pPromedioAFC = promedioAFC;
	*pPromedioCAF = promedioCAF;
	*pPromedioCONCACAF = promedioCONCACAF;
	*pPromedioCONMEBOL = promedioCONMEBOL;
	*pPromedioUEFA = promedioUEFA;
	*pPromedioOFC = promedioOFC;
	*pCostoMantenimiento = costoMantenimiento;
}


void CargarCostosMantenimiento(float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte){
	int opcion;
	float gastoHospedaje = *pGastoHospedaje;
	float gastoComida = *pGastoComida;
	float gastoTransporte = *pGastoTransporte;

	do{
		printf("\nIngreso de los costos de mantenimiento");
		printf("\n 1.Costo de Hospedaje -> $%.2f", gastoHospedaje);
		printf("\n 2.Costo de Comida -> $%.2f", gastoComida);
		printf("\n 3.Costo de Transporte -> $%.2f", gastoTransporte);
		printf("\n 4.Volver al menu principal");

		getInt(&opcion, "\n\nIngrese la opcion segun el costo que desea cargar: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 4);

		switch(opcion){
			case 1:
				getFloat(&gastoHospedaje, "\nIngrese el costo de hospedaje: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
				break;

			case 2:
				getFloat(&gastoComida, "\nIngrese el costo de comida: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
				break;

			case 3:
				getFloat(&gastoTransporte, "\nIngrese el costo de transporte: ", "\n[ERROR] El costo que ingreso no es valido.", 0, 715000000);
				break;
		}

		if(gastoHospedaje != 0 && gastoComida != 0 && gastoTransporte != 0){
			printf("\nTodos los costos de mantenimiento fueron ingresados con exito!");
			printf("\nVolviendo al menu principal...\n");

			opcion = 4;
		}

	}while(opcion != 4);

	*pGastoHospedaje = gastoHospedaje;
	*pGastoComida = gastoComida;
	*pGastoTransporte = gastoTransporte;
}


void CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC){
	int opcion;
	int validacionJugador;
	int confederacion;

	int contadorArqueros = *pArqueros;
	int contadorDefensas = *pDefensas;
	int contadorMediocampistas = *pMediocampistas;
	int contadorDelanteros = *pDelanteros;

	int contadorAFC = *pAFC;
	int contadorCAF = *pCAF;
	int contadorCONCACAF = *pCONCACAF;
	int contadorCONMEBOL = *pCONMEBOL;
	int contadorUEFA = *pUEFA;
	int contadorOFC = *pOFC;

	do{
		printf("\nCarga de jugadores");
		printf("\n 1.Arqueros -> %d", contadorArqueros);
		printf("\n 2.Defensores -> %d", contadorDefensas);
		printf("\n 3.Mediocampistas -> %d", contadorMediocampistas);
		printf("\n 4.Delanteros -> %d", contadorDelanteros);
		printf("\n 5.Volver al menu principal");

		getInt(&opcion, "\n\nIngrese la opcion segun la posicion del jugador que desea cargar: ", "\n[ERROR] La opcion que ingreso no es valida.", 1, 5);

		switch(opcion){
			case 1:
				validacionJugador = ValidarCantidadJugadores(contadorArqueros, MAX_ARQUEROS);

				if(validacionJugador == 1){
					contadorArqueros++;
					PedirDatosDelJugador(&confederacion);
					ContadorConfederaciones(confederacion, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
				}
				else{
					printf("\n[ERROR] No podes ingresar mas arqueros.\n");
				}

				break;

			case 2:
				validacionJugador = ValidarCantidadJugadores(contadorDefensas, MAX_DEFENSAS);

				if(validacionJugador == 1){
					contadorDefensas++;
					PedirDatosDelJugador(&confederacion);
					ContadorConfederaciones(confederacion, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
				}
				else{
					printf("\n[ERROR] No podes ingresar mas defensas.\n");
				}
				break;

			case 3:
				validacionJugador = ValidarCantidadJugadores(contadorMediocampistas, MAX_MEDIOS);

				if(validacionJugador == 1){
					contadorMediocampistas++;
					PedirDatosDelJugador(&confederacion);
					ContadorConfederaciones(confederacion, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
				}
				else{
					printf("\n[ERROR] No podes ingresar mas mediocampistas.\n");
				}
				break;

			case 4:
				validacionJugador = ValidarCantidadJugadores(contadorDelanteros, MAX_DELANTEROS);

				if(validacionJugador == 1){
					contadorDelanteros++;
					PedirDatosDelJugador(&confederacion);
					ContadorConfederaciones(confederacion, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
				}
				else{
					printf("\n[ERROR] No podes ingresar mas delanteros.\n");
				}
				break;
		}

		if(contadorArqueros == MAX_ARQUEROS && contadorDefensas == MAX_DEFENSAS && contadorMediocampistas == MAX_MEDIOS && contadorDelanteros == MAX_DELANTEROS){
			printf("\nTodos los jugadores fueron ingresados con exito!");
			printf("\nVolviendo al menu principal...\n");

			opcion = 5;
		}

	}while(opcion != 5);

	*pArqueros = contadorArqueros;
	*pDefensas = contadorDefensas;
	*pMediocampistas = contadorMediocampistas;
	*pDelanteros = contadorDelanteros;

	*pAFC = contadorAFC;
	*pCAF = contadorCAF;
	*pCONCACAF = contadorCONCACAF;
	*pCONMEBOL = contadorCONMEBOL;
	*pUEFA = contadorUEFA;
	*pOFC = contadorOFC;
}


int ValidarCantidadJugadores(int contador, int maximo){
	int retorno;

	if(contador < maximo){
		retorno = 1;
	}
	else{
		retorno = 0;
	}

	return retorno;
}


void PedirDatosDelJugador(int* pConfederacion){
	int numeroCamiseta;
	int confederacion;

	getInt(&numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\n[ERROR] El numero que ingreso no es valido.", 1, 99);
	//En este caso el numero de la camiseta lo piso todo el tiempo porque no se me solicito que haga nada con el

	confederacion = PedirConfederacion();
	*pConfederacion = confederacion;
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

































