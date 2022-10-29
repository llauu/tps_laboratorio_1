#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "input-output.h"


/**
 * @brief ID autoincremental, unico y autonomo. Es inicializado una unica vez al comienzo del programa, comienza desde el numero 1
 *
 * @return El ID generado
 */
static int GenerarID(void);
static int GenerarID(void){
	static int idIncremental = 1;

	return idIncremental++;
}


int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]){
	int retorno = -1;
	int opcion;
	int confirmoSalir;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		retorno = 0;

		do{
			MostrarMenuJugadores();

			getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 5);

			switch(opcion){
				case 1:
					AltaJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 2:
					BajaJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 3:
					ModificarJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 4:
					InformesJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones, confederacionesAux);
					break;

				case 5:
					confirmoSalir = ConfirmarSalida();
					break;
			}

		}while(opcion != 5 || confirmoSalir != 1);
	}

	return retorno;
}


sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones){
	sJugador auxJugador;

	PedirNombreJugador(auxJugador.nombre);

	PedirPosicionJugador(auxJugador.posicion, 14);

	PedirNumCamisetaJugador(&auxJugador.numeroCamiseta);

	PedirSalarioJugador(&auxJugador.salario);

	PedirConfJugador(&auxJugador.idConfederacion, confederaciones, tamConfederaciones);

	PedirAnioContratoJugador(&auxJugador.aniosContrato);

	return auxJugador;
}


int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int espacioLibre;
	sJugador auxJugador;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(BuscarConfederacionOcupada(0, confederaciones, tamConfederaciones) != -1){
			espacioLibre = ObtenerJugadorLibre(jugadores, tamJugadores);

			if(espacioLibre != -1){
				auxJugador = CargarJugador(confederaciones, tamConfederaciones);

				auxJugador.id = GenerarID();
				auxJugador.isEmpty = OCUPADO;

				jugadores[espacioLibre] = auxJugador;

				retorno = 0;
			}
			else{
				printf("[ERROR] Alcanzaste el maximo de jugadores cargados.\n");
			}
		}
		else{
			printf("[ERROR] Se debe cargar al menos una confederacion para dar de alta un jugador.\n");
		}
	}

	return retorno;
}


int EnlazarJugadorConConf(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador){
	int retorno = -1;

	for(int i = 0; i < tamConfederaciones; i++){
		if(idConfDelJugador == confederaciones[i].id){
			retorno = i;
			break;
		}
	}

	return retorno;
}


int MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		char nombreConfederacion[11];
		int indice;

		indice = EnlazarJugadorConConf(confederaciones, tamConfederaciones, jugador.idConfederacion);

		strcpy(nombreConfederacion, confederaciones[indice].nombre);

		if(indice != -1){
			printf("\n| %3d  | %-20s | %-13s |     %-7hd | %-12.2f | %-13s |        %-9hd |",
					jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta,
					jugador.salario, nombreConfederacion, jugador.aniosContrato);
		}

		retorno = 0;
	}

	return retorno;
}


int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int flagHayJugador = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(BuscarJugadorOcupado(0, jugadores, tamJugadores) != -1){
			MostrarMenuDatosJugs();
			for(int i = 0; i < tamJugadores; i++){
				if(jugadores[i].isEmpty == OCUPADO){
					MostrarJugador(jugadores[i], confederaciones, tamConfederaciones);
					flagHayJugador = 0;
				}
			}
			MostrarPieDatosJugs();
		}
	}

	return flagHayJugador;
}


int SolicitarYValidarIDJugador(sJugador jugadores[], int tamJugadores){
	int idIngresado;
	int indiceID = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		do{
			getInt(&idIngresado, "\nIngrese el ID del jugador: \n> ", "\n[ERROR] ID no valido.", 1, 10000);

			indiceID = BuscarJugadorPorID(jugadores, tamJugadores, idIngresado);

			if(indiceID == -1){
				printf("\n[ERROR] El ID %d no existe.", idIngresado);
			}
		}while(indiceID == -1);
	}

	return indiceID;
}


int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int indiceID;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(BuscarJugadorOcupado(0, jugadores, tamJugadores) != -1){
			MostrarMenuBaja();
			OrdenarJugadoresPorID(jugadores, tamJugadores);
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			indiceID = SolicitarYValidarIDJugador(jugadores, tamJugadores);

			if(indiceID != -1){
				jugadores[indiceID].isEmpty = LIBRE;

				MostrarBajaExitosa();
			}

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados.\n");
		}
	}

	return retorno;
}


int ModificarJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int indiceID;
	int opcionModificar;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(BuscarJugadorOcupado(0, jugadores, tamJugadores) != -1){
			MostrarMenuModificacion();
			OrdenarJugadoresPorID(jugadores, tamJugadores);
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			indiceID = SolicitarYValidarIDJugador(jugadores, tamJugadores);

			MostrarMenuModificacionJugs();

			getInt(&opcionModificar, "\nIngrese el numero de lo que quiere modificar: \n> ", "\n[ERROR] Opcion invalida.", 1, 6);

			switch(opcionModificar){
				case 1:
					PedirNombreJugador(jugadores[indiceID].nombre);
					break;

				case 2:
					PedirPosicionJugador(jugadores[indiceID].posicion, 14);
					break;

				case 3:
					PedirNumCamisetaJugador(&jugadores[indiceID].numeroCamiseta);
					break;

				case 4:
					PedirSalarioJugador(&jugadores[indiceID].salario);
					break;

				case 5:
					PedirConfJugador(&jugadores[indiceID].idConfederacion, confederaciones, tamConfederaciones);
					break;

				case 6:
					PedirAnioContratoJugador(&jugadores[indiceID].aniosContrato);
					break;
			}

			MostrarModificacionExitosa();

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados.\n");
		}
	}

	return retorno;
}


int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		int opcion;

		if(BuscarJugadorOcupado(0, jugadores, tamJugadores) != -1){
			MostrarMenuInformes();

			getInt(&opcion, "\nIngrese el numero del informe que desea ver: \n> ", "\n[ERROR] Opcion invalida.", 1, 6);

			switch(opcion){
				case 1:
					OrdenarJugadoresAlfabeticamente(jugadores, tamJugadores);
					OrdenarConfederacionesAlfabeticamente(confederaciones, tamConfederaciones);

					MostrarJugadoresPorConfOrdenados(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 2:
					OrdenarConfederacionesPorID(confederaciones, tamConfederaciones);
					MostrarJugadoresPorConf(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 3:
					MostrarInformeSalarios(jugadores, tamJugadores);
					break;

				case 4:
					MostrarConfMayorCantContratos(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
					break;

				case 5:
					MostrarPorcentajeJugadoresPorConf(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
					break;

				case 6:
					MostrarRegionConMasJugadores(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
					break;
			}

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados.\n");
		}
	}

	OrdenarConfederacionesAlfabeticamente(confederaciones, tamConfederaciones);
	return retorno;
}


int MostrarJugadoresDeUnaConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, int posConf){
	int contador = 0;

	for(int i = 0; i < tamJugadores; i++){
		if(jugadores[i].isEmpty == OCUPADO){
			if(confederaciones[posConf].id == jugadores[i].idConfederacion){
				contador++;
				MostrarJugador(jugadores[i], confederaciones, tamConfederaciones);
			}
		}
	}

	return contador;
}


int MostrarJugadoresPorConfOrdenados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		MostrarMenuDatosJugs();
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, i);
			}
		}
		MostrarPieDatosJugs();

		retorno = 0;
	}

	return retorno;
}


int MostrarJugadoresPorConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				MostrarMenuDatosConfs();
				MostrarConfederacion(confederaciones[i]);
				MostrarPieDatosConfs();

				MostrarMenuDatosJugs();
				MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, i);
				MostrarPieDatosJugs();

				printf("\n===============================================================================================================");
			}
		}

		retorno = 0;
	}

	return retorno;
}


int CalcularAniosContratoPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		VincularAuxConfederaciones(confederaciones, tamConfederaciones, confederacionesAux);

		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				for(int j = 0; j < tamJugadores; j++){
					if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederacionesAux[i].idConfederacion){
						confederacionesAux[i].acumuladorAniosContrato += jugadores[j].aniosContrato;
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}


int BuscarIndiceConfMasAniosDeContrato(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int indice;
	int flagPrimero = 1;
	int mayorCantAnioContrato;

	CalcularAniosContratoPorConf(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);

	for(int i = 0; i < tamConfederaciones; i++){
		if(flagPrimero == 1){
			mayorCantAnioContrato = confederacionesAux[i].acumuladorAniosContrato;
			indice = i;

			flagPrimero = 0;
		}
		else{
			if(confederacionesAux[i].acumuladorAniosContrato > mayorCantAnioContrato){
				mayorCantAnioContrato = confederacionesAux[i].acumuladorAniosContrato;
				indice = i;
			}
		}
	}

	return indice;
}


int ContarJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0 && ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		VincularAuxConfederaciones(confederaciones, tamConfederaciones, confederacionesAux);

		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				for(int j = 0; j < tamJugadores; j++){
					if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederacionesAux[i].idConfederacion){
						confederacionesAux[i].contadorJugadores++;
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}


int CalcularPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;
	int jugadoresTotales;
	float promedioAux;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0 && ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		jugadoresTotales = ContarJugadoresCargados(jugadores, tamJugadores);
		ContarJugadoresPorConf(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);

		if(jugadoresTotales != 0){
			for(int i = 0; i < tamConfederaciones; i++){
				if(confederaciones[i].isEmpty == OCUPADO){
					promedioAux = (confederacionesAux[i].contadorJugadores / (float)jugadoresTotales) * 100;

					confederacionesAux[i].promedioJugadores = promedioAux;
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}


int MostrarPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0 && ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		CalcularPorcentajeJugadoresPorConf(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);

		printf("\n+---------------+------------+"
			   "\n| CONFEDERACION | PORCENTAJE |"
			   "\n+---------------+------------+");

		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				printf("\n| %-13s | %9.2f%% |"
					   "\n+---------------+------------+", confederaciones[i].nombre, confederacionesAux[i].promedioJugadores);
			}
		}
		printf("\n");

		retorno = 0;
	}

	return retorno;
}


int BuscarIndiceRegionMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int indice;
	int flagPrimero = 1;
	int mayorCantJugadores;

	ContarJugadoresPorConf(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);

	for(int i = 0; i < tamConfederaciones; i++){
		if(flagPrimero == 1){
			mayorCantJugadores = confederacionesAux[i].contadorJugadores;
			indice = i;

			flagPrimero = 0;
		}
		else{
			if(confederacionesAux[i].contadorJugadores > mayorCantJugadores){
				mayorCantJugadores = confederacionesAux[i].contadorJugadores;
				indice = i;
			}
		}
	}

	return indice;
}


int MostrarConfMayorCantContratos(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;
	int indiceAux;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0 && ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		indiceAux = BuscarIndiceConfMasAniosDeContrato(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
		printf("\nLa confederacion con mayor cantidad de años de contratos total es %s, con %d años.\n", confederaciones[indiceAux].nombre, confederacionesAux[indiceAux].acumuladorAniosContrato);

		retorno = 0;
	}

	return retorno;
}


int MostrarRegionConMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores){
	int retorno = -1;
	int indice;

	if(confederacionesAux != NULL && tamConfederaciones > 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0 && ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		indice = BuscarIndiceRegionMasJugadores(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
		printf("\n+---------------+"
			   "\n|  REGION CON   |"
			   "\n| MAS JUGADORES |"
			   "\n+---------------+"
			   "\n| %-13s |"
			   "\n+---------------+", confederaciones[indice].region);

		printf("\n+---------------+"
			   "\n|  JUGADORES:   |"
			   "\n+---------------+");

		OrdenarJugadoresPorID(jugadores, tamJugadores);
		MostrarMenuDatosJugs();
		MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, indice);
		MostrarPieDatosJugs();

		retorno = 0;
	}

	return retorno;
}






