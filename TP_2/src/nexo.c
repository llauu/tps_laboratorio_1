#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "input.h"

static int GenerarID(void);
static int GenerarID(void){
	static int idIncremental = 1;

	return idIncremental++;
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


void MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones){
	char nombreConfederacion[11];
	int indice;

	indice = EnlazarJugadorConConf(confederaciones, tamConfederaciones, jugador.idConfederacion);

	strcpy(nombreConfederacion, confederaciones[indice].nombre);


	if(indice != -1){
		printf("\n| %3d  | %-20s | %-13s |     %-7hd | %-12.2f | %-13s |        %-9hd |",
				jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta,
				jugador.salario, nombreConfederacion, jugador.aniosContrato);
	}

}


int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int flagHayJugador = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
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



int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int idABajar;
	int indiceID;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
			OrdenarJugadoresPorID(jugadores, tamJugadores);
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			do{
				getInt(&idABajar, "\nIngrese el ID del jugador a dar de baja: \n> ", "\n[ERROR] ID no valido.", 1, 10000);

				indiceID = BuscarJugadorPorID(jugadores, tamJugadores, idABajar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idABajar);
				}
			}while(indiceID == -1);

			jugadores[indiceID].isEmpty = LIBRE;

			printf("\n+---------------------------------+"
				   "\n| JUGADOR DADO DE BAJA CON EXITO! |"
				   "\n+---------------------------------+\n");

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
	int idAModificar;
	int indiceID;
	int opcionModificar;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
			OrdenarJugadoresPorID(jugadores, tamJugadores);
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			do{
				getInt(&idAModificar, "\nIngrese el ID del jugador a modificar: \n> ", "\n[ERROR] ID no valido.", 1, 10000);

				indiceID = BuscarJugadorPorID(jugadores, tamJugadores, idAModificar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idAModificar);
				}
			}while(indiceID == -1);

			printf("\n+---------------------------+"
				   "\n|     MODIFICAR JUGADOR     |"
				   "\n+---------------------------+"
				   "\n| 1.Nombre                  |"
				   "\n| 2.Posicion                |"
				   "\n| 3.Numero de camiseta      |"
				   "\n| 4.Salario                 |"
				   "\n| 5.Confederacion           |"
				   "\n| 6.Años de contrato        |"
				   "\n+---------------------------+\n");

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

			printf("\n+-----------------------------------+"
				   "\n| MODIFICACION REALIZADA CON EXITO! |"
				   "\n+-----------------------------------+\n");

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
		int indiceAux;

		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){

			printf("\n+--------------------------------------+"
				   "\n|          INFORMES JUGADOR            |"
				   "\n+--------------------------------------+"
				   "\n| 1.Listado de los jugadores ordenados |"
				   "\n|   alfabeticamente por nombre de      |"
				   "\n|   confederación y nombre de jugador. |"
				   "\n|                                      |"
				   "\n| 2.Listado de confederaciones con sus |"
				   "\n|   jugadores.                         |"
				   "\n|                                      |"
				   "\n| 3.Total y promedio de todos los      |"
				   "\n|   salarios y cuántos jugadores       |"
				   "\n|   cobran mas del salario promedio.   |"
				   "\n|                                      |"
				   "\n| 4.Informar la confederación con      |"
				   "\n|   mayor cantidad de años de          |"
				   "\n|   contratos total.                   |"
				   "\n|                                      |"
				   "\n| 5.Informar porcentaje de jugadores   |"
				   "\n|   por cada confederación.            |"
				   "\n|                                      |"
				   "\n| 6.Informar cual es la región con     |"
				   "\n|   más jugadores y el listado de      |"
				   "\n|   los mismos.                        |"
				   "\n+--------------------------------------+\n");

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
					indiceAux = BuscarIndiceConfMasAniosDeContrato(confederaciones, tamConfederaciones, confederacionesAux, jugadores, tamJugadores);
					printf("\nLa confederacion con mayor cantidad de años de contratos total es %s, con %d años.\n", confederaciones[indiceAux].nombre, confederacionesAux[indiceAux].acumuladorAniosContrato);
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

	for(int j = 0; j < tamJugadores; j++){
		if(jugadores[j].isEmpty == OCUPADO){
			if(confederaciones[posConf].id == jugadores[j].idConfederacion){
				contador++;
				MostrarJugador(jugadores[j], confederaciones, tamConfederaciones);
			}
		}
	}

	return contador;
}


int MostrarJugadoresPorConfOrdenados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
			MostrarMenuDatosJugs();
			for(int i = 0; i < tamConfederaciones; i++){
				if(confederaciones[i].isEmpty == OCUPADO){
					MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, i);
				}
			}
			MostrarPieDatosJugs();

			retorno = 0;
		}
	}

	return retorno;
}


int MostrarJugadoresPorConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
			for(int i = 0; i < tamConfederaciones; i++){
				if(confederaciones[i].isEmpty == OCUPADO){
					MostrarMenuDatosConfs();
					MostrarConfederacion(confederaciones[i]);
					printf("\n+-----+------------+--------------------------------+--------------+");

					MostrarMenuDatosJugs();
					MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, i);
					MostrarPieDatosJugs();
				}
			}

			retorno = 0;
		}
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

		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				promedioAux = (confederacionesAux[i].contadorJugadores / (float)jugadoresTotales) * 100;

				confederacionesAux[i].promedioJugadores = promedioAux;
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

		MostrarMenuDatosJugs();
		MostrarJugadoresDeUnaConf(jugadores, tamJugadores, confederaciones, tamConfederaciones, indice);
		MostrarPieDatosJugs();

		retorno = 0;
	}

	return retorno;
}






