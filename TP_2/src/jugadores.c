#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "input.h"


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
			printf("\n┌───────────────────────────┐"
				   "\n│      MENU JUGADORES       │"
				   "\n├───────────────────────────┤"
				   "\n│ 1.Alta jugador            │"
				   "\n│ 2.Baja jugador            │"
				   "\n│ 3.Modificar jugador       │"
				   "\n│ 4.Informes                │"
			       "\n│ 5.Salir                   │"
				   "\n└───────────────────────────┘\n");

			getInt(&opcion, "\nSeleccione una opcion: \n» ", "\n[ERROR] Opcion invalida.", 1, 5);

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
//					MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);
					InformesJugador(jugadores, tamJugadores, confederaciones, tamConfederaciones);
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

int PedirNombreJugador(char nombre[]){
	int retorno = -1;

	if(nombre != NULL){
		getString(nombre, 21, "\nIngrese el nombre del jugador: \n» ", "\n[ERROR] Superaste el limite de caracteres.");
		FirstToUppercase(nombre, strlen(nombre));

		retorno = 0;
	}

	return retorno;
}

int ValidarPosicionJugador(char posicion[]){
	int retorno;
	retorno = 0;

	if((strcasecmp("Arquero", posicion) != 0) && (strcasecmp("Defensor", posicion) != 0) && (strcasecmp("Mediocampista", posicion) != 0) && (strcasecmp("Delantero", posicion) != 0)){
		printf("\n[ERROR] La posicion que ingreso no es correcta.");
		retorno = -1;
	}

	return retorno;
}

int PedirPosicionJugador(char posicion[], int size){
	int retorno = -1;

	do{
		retorno = getString(posicion, size, "\nIngrese la posicion del jugador: \n» ", "\n[ERROR] Superaste el limite de caracteres.");
		FirstToUppercase(posicion, strlen(posicion));

	}while(ValidarPosicionJugador(posicion) == -1);

	return retorno;
}

int PedirNumCamisetaJugador(short* numCamiseta){
	int retorno = -1;
	short numTmp;

	if(numCamiseta != NULL){
		getShort(&numTmp, "\nIngrese el numero de camiseta del jugador: \n» ", "\n[ERROR] Numero de camiseta no valido.", 1, 99);
		*numCamiseta = numTmp;

		retorno = 0;
	}

	return retorno;
}

int PedirSalarioJugador(float* salario){
	int retorno = -1;
	float salarioTmp;

	if(salario != NULL){
		getFloat(&salarioTmp, "\nIngrese el salario del jugador: \n» ", "\n[ERROR] Salario no valido.", 1, 999999999);
		*salario = salarioTmp;

		retorno = 0;
	}

	return retorno;
}

int PedirConfJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones){
	int indiceID;
	int tmpID;

	MostrarConfsDisponibles(confederaciones, tamConfederaciones);

	do{
		getInt(&tmpID, "\nIngrese el ID de la confederacion del jugador: \n» ", "\n[ERROR] ID no valido.", 100, 10000);

		indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, tmpID);

		if(indiceID == -1){
			printf("\n[ERROR] El ID %d no existe.", tmpID);
		}
	}while(indiceID == -1);

	*idConfederacion = tmpID;

	return indiceID;
}

int PedirAnioContratoJugador(short* aniosContrato){
	int retorno = -1;
	short aniosTmp;

	if(aniosContrato != NULL){
		getShort(&aniosTmp, "\nIngrese los años de contrato del jugador: \n» ", "\n[ERROR] Año no valido.", 1, 100);
		*aniosContrato = aniosTmp;

		retorno = 0;
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
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int OrdenarJugadoresPorID(sJugador jugadores[], int tamJugadores){
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	sJugador jugadorTmp;
    int nuevoTam;

    if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
    	nuevoTam = tamJugadores - 1;

    	do{
    		flagSwap = 0;

    		for(i = 0; i < nuevoTam; i++){
    			if(jugadores[i].isEmpty == OCUPADO && jugadores[i+1].isEmpty == OCUPADO){
        			contador++;
        			if(jugadores[i].id > jugadores[i+1].id){
        				flagSwap = 1;

        				jugadorTmp = jugadores[i];
        				jugadores[i] = jugadores[i+1];
        				jugadores[i+1] = jugadorTmp;
        			}
    			}
    		}
    		nuevoTam--;
    	}
    	while(flagSwap);
    	retorno = contador;
    }

	return retorno;
}


void MostrarMenuDatosJugs(void){
	printf("\n┌──────┬──────────────────────┬───────────────┬─────────────┬──────────────┬───────────────┬──────────────────┐"
		   "\n│  ID  │ NOMBRE               │ POSICION      │ N° CAMISETA │ SUELDO       │ CONFEDERACION │ AÑOS DE CONTRATO │"
		   "\n├──────┼──────────────────────┼───────────────┼─────────────┼──────────────┼───────────────┼──────────────────┤");
}


int ObtenerNombreConfederacion(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador, char nombreConfederacion[]){
	int retorno = -1;

	for(int i = 0; i < tamConfederaciones; i++){
		if(idConfDelJugador == confederaciones[i].id){
			strcpy(nombreConfederacion, confederaciones[i].nombre);
			retorno = 0;

			break;
		}
	}

	return retorno;
}


void MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones){
	char nombreConfederacion[11];
	int existeConf = -1;

	existeConf = ObtenerNombreConfederacion(confederaciones, tamConfederaciones, jugador.idConfederacion, nombreConfederacion);

	if(existeConf == 0){
		printf("\n│ %3d  │ %-20s │ %-13s │     %-7d │ %-12.2f │ %-13s │        %-9d │",
				jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta,
				jugador.salario, nombreConfederacion, jugador.aniosContrato);
	}

}


int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int flagHayJugador = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
			OrdenarJugadoresPorID(jugadores, tamJugadores);
			MostrarMenuDatosJugs();
			for(int i = 0; i < tamJugadores; i++){
				if(jugadores[i].isEmpty == OCUPADO){
					MostrarJugador(jugadores[i], confederaciones, tamConfederaciones);
					flagHayJugador = 0;
				}
			}
			printf("\n└──────┴──────────────────────┴───────────────┴─────────────┴──────────────┴───────────────┴──────────────────┘\n");
		}
	}

	return flagHayJugador;
}


int BuscarJugadorPorID(sJugador jugadores[], int tamJugadores, int id){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].id == id && jugadores[i].isEmpty == OCUPADO){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int idABajar;
	int indiceID;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			do{
				getInt(&idABajar, "\nIngrese el ID del jugador a dar de baja: \n» ", "\n[ERROR] ID no valido.", 1, 10000);

				indiceID = BuscarJugadorPorID(jugadores, tamJugadores, idABajar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idABajar);
				}
			}while(indiceID == -1);

			jugadores[indiceID].isEmpty = LIBRE;

			printf("\n┌─────────────────────────────────┐"
				   "\n│ JUGADOR DADO DE BAJA CON EXITO! │"
				   "\n└─────────────────────────────────┘\n");

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
			MostrarJugadoresCargados(jugadores, tamJugadores, confederaciones, tamConfederaciones);

			do{
				getInt(&idAModificar, "\nIngrese el ID del jugador a modificar: \n» ", "\n[ERROR] ID no valido.", 1, 10000);

				indiceID = BuscarJugadorPorID(jugadores, tamJugadores, idAModificar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idAModificar);
				}
			}while(indiceID == -1);

			printf("\n┌───────────────────────────┐"
				   "\n│     MODIFICAR JUGADOR     │"
				   "\n├───────────────────────────┤"
				   "\n│ 1.Nombre                  │"
				   "\n│ 2.Posicion                │"
				   "\n│ 3.Numero de camiseta      │"
				   "\n│ 4.Salario                 │"
				   "\n│ 5.Confederacion           │"
				   "\n│ 6.Años de contrato        │"
				   "\n└───────────────────────────┘\n");

			getInt(&opcionModificar, "\nIngrese el numero de lo que quiere modificar: \n» ", "\n[ERROR] Opcion invalida.", 1, 6);

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

			printf("\n┌───────────────────────────────────┐"
				   "\n│ MODIFICACION REALIZADA CON EXITO! │"
				   "\n└───────────────────────────────────┘\n");

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados.\n");
		}
	}

	return retorno;
}


int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int opcion;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0 && ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(ChequearJugadorCargado(jugadores, tamJugadores) == 0){

			printf("\n┌──────────────────────────────────────┐"
				   "\n│          INFORMES JUGADOR            │"
				   "\n├──────────────────────────────────────┤"
				   "\n│ 1.Listado de los jugadores ordenados │"
				   "\n│   alfabeticamente por nombre de      │"
				   "\n│   confederación y nombre de jugador. │"
				   "\n│                                      │"
				   "\n│ 2.Listado de confederaciones con sus │"
				   "\n│   jugadores.                         │"
				   "\n│                                      │"
				   "\n│ 3.Total y promedio de todos los      │"
				   "\n│   salarios y cuántos jugadores       │"
				   "\n│   cobran mas del salario promedio.   │"
				   "\n│                                      │"
				   "\n│ 4.Informar la confederación con      │"
				   "\n│   mayor cantidad de años de          │"
				   "\n│   contratos total.                   │"
				   "\n│                                      │"
				   "\n│ 5.Informar porcentaje de jugadores   │"
				   "\n│   por cada confederación.            │"
				   "\n│                                      │"
				   "\n│ 6.Informar cual es la región con     │"
				   "\n│   más jugadores y el listado de      │"
				   "\n│   los mismos.                        │"
				   "\n└──────────────────────────────────────┘\n");

			getInt(&opcion, "\nIngrese el numero del informe que desea ver: \n» ", "\n[ERROR] Opcion invalida.", 1, 6);

			switch(opcion){
				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					break;

				case 5:
					break;

				case 6:
					break;
			}

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados.\n");
		}
	}

	return retorno;
}


