#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mylib.h"
#include "jugadores.h"
#include "confederaciones.h"


static int GenerarID(void);
static int GenerarID(void){
	static int idIncremental = 1;

	return idIncremental++;
}


int ChequearValidezArrayJugs(sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(jugadores != NULL && tamJugadores > 0){
		retorno = 0;
	}

	return retorno;
}


int InicializarJugadores(sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		retorno = 0;

		for(int i = 0; i < tamJugadores; i++){
			jugadores[i].isEmpty = LIBRE;
		}
	}

	return retorno;
}


int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int opcion;
	int confirmoSalir;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		retorno = 0;

		do{
			printf("\n============================="
				   "\n|      MENU JUGADORES       |"
				   "\n|---------------------------|"
				   "\n| 1.Alta jugador            |"
				   "\n| 2.Baja jugador            |"
				   "\n| 3.Modificar jugador       |"
				   "\n| 4.Informes                |"
		           "\n| 5.Salir                   |"
				   "\n=============================\n");

			getInt(&opcion, "\nSeleccione una opcion: ", "\n[ERROR] Opcion invalida.", 1, 5);

			switch(opcion){
				case 1:
					AltaJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					break;

				case 2:
					MostrarJugadoresCargados(jugadores, tamJugadores);
					break;

				case 3:
					break;

				case 4:
					break;

				case 5:
					confirmoSalir = ConfirmarSalida();
					break;
			}

		}while(opcion != 5 || confirmoSalir != 1);
	}

	return retorno;
}


int ObtenerJugadorLibre(sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int ValidarPosicionJugador(char posicion[]){
	int retorno;
	retorno = 1;

	if((strcasecmp("Arquero", posicion) != 0) && (strcasecmp("Defensor", posicion) != 0) && (strcasecmp("Mediocampista", posicion) != 0) && (strcasecmp("Delantero", posicion) != 0)){
		printf("\n[ERROR] La posicion que ingreso no es correcta.");
		retorno = 0;
	}

	return retorno;
}

int CargarPosEnJugador(char posicion[], int size){
	int retorno = -1;

	do{
		retorno = getString(posicion, size, "\nIngrese la posicion del jugador: ", "\n[ERROR] Superaste el limite de caracteres.");
		FirstToUppercase(posicion, strlen(posicion));

	}while(ValidarPosicionJugador(posicion) == 0);

	return retorno;
}

int CargarConfEnJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones){
	int indiceID;
	int tmpID;

	MostrarConfsDisponibles(confederaciones, tamConfederaciones);

	do{
		getInt(&tmpID, "\nIngrese el ID de la confederacion del jugador: ", "\n[ERROR] ID no valido.", 100, 10000);

		indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, tmpID);

		if(indiceID == -1){
			printf("\n[ERROR] El ID %d no existe.", tmpID);
		}
	}while(indiceID == -1);

	*idConfederacion = tmpID;

	return indiceID;
}

sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones){
	sJugador auxJugador;

	getString(auxJugador.nombre, 21, "\nIngrese el nombre del jugador: ", "\n[ERROR] Superaste el limite de caracteres.");
	FirstToUppercase(auxJugador.nombre, strlen(auxJugador.nombre));

	CargarPosEnJugador(auxJugador.posicion, 14);

	getShort(&auxJugador.numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\n[ERROR] Numero de camiseta no valido.", 1, 99);

	getFloat(&auxJugador.salario, "\nIngrese el salario del jugador: ", "\n[ERROR] Salario no valido.", 1, 999999999);

	CargarConfEnJugador(&auxJugador.idConfederacion, confederaciones, tamConfederaciones);

	getShort(&auxJugador.aniosContrato, "\nIngrese los años de contrato del jugador: ", "\n[ERROR] Año no valido.", 1, 100);

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

int ChequearJugadorCargado(sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void MostrarMenuDatosJugs(void){
	printf("\n===============================================================================================================");
	printf("\n|  ID  | NOMBRE               | POSICION      | N° CAMISETA | SUELDO       | CONFEDERACION | AÑOS DE CONTRATO |");
	printf("\n---------------------------------------------------------------------------------------------------------------");
}

void MostrarJugador(sJugador jugador){
	printf("\n| %3d  | %-20s | %-13s |     %-7d | %-12.2f | %-13d |        %-9d |", jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta, jugador.salario, jugador.idConfederacion, jugador.aniosContrato);
}

int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores){
	int flagHayJugador = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
			MostrarMenuDatosJugs();
			for(int i = 0; i < tamJugadores; i++){
				if(jugadores[i].isEmpty == OCUPADO){
					MostrarJugador(jugadores[i]);
					flagHayJugador = 0;
				}
			}
			printf("\n===============================================================================================================\n");
		}
	}

	return flagHayJugador;
}













