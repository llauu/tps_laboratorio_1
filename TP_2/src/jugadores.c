#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "nexo.h"
#include "input.h"


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


int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]){
	int retorno = -1;
	int opcion;
	int confirmoSalir;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		retorno = 0;

		do{
			printf("\n+---------------------------+"
				   "\n|      MENU JUGADORES       |"
				   "\n+---------------------------+"
				   "\n| 1.Alta jugador            |"
				   "\n| 2.Baja jugador            |"
				   "\n| 3.Modificar jugador       |"
				   "\n| 4.Informes                |"
			       "\n| 5.Salir                   |"
				   "\n+---------------------------+\n");

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
		getString(nombre, 21, "\nIngrese el nombre del jugador: \n> ", "\n[ERROR] Superaste el limite de caracteres.");
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
		retorno = getString(posicion, size, "\nIngrese la posicion del jugador: \n> ", "\n[ERROR] Superaste el limite de caracteres.");
		FirstToUppercase(posicion, strlen(posicion));

	}while(ValidarPosicionJugador(posicion) == -1);

	return retorno;
}

int PedirNumCamisetaJugador(short* numCamiseta){
	int retorno = -1;
	short numTmp;

	if(numCamiseta != NULL){
		getShort(&numTmp, "\nIngrese el numero de camiseta del jugador: \n> ", "\n[ERROR] Numero de camiseta no valido.", 1, 99);
		*numCamiseta = numTmp;

		retorno = 0;
	}

	return retorno;
}

int PedirSalarioJugador(float* salario){
	int retorno = -1;
	float salarioTmp;

	if(salario != NULL){
		getFloat(&salarioTmp, "\nIngrese el salario del jugador: \n> ", "\n[ERROR] Salario no valido.", 1, 999999999);
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
		getInt(&tmpID, "\nIngrese el ID de la confederacion del jugador: \n> ", "\n[ERROR] ID no valido.", 100, 10000);

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
		getShort(&aniosTmp, "\nIngrese los años de contrato del jugador: \n> ", "\n[ERROR] Año no valido.", 1, 100);
		*aniosContrato = aniosTmp;

		retorno = 0;
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
	int j;
	int contador = 0;
	int retorno = -1;
	sJugador jugadorTmp;
    int nuevoTam;

    if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
    	nuevoTam = tamJugadores - 1;

    	do{
    		flagSwap = 0;

    		for(i = 0; i < nuevoTam; i++){
    			if(jugadores[i].isEmpty == OCUPADO){
        			j = BuscarJugadorOcupado((i+1), jugadores, nuevoTam);
					contador++;

        			if(j != -1){
						if(jugadores[i].id > jugadores[j].id){
							flagSwap = 1;

							jugadorTmp = jugadores[i];
							jugadores[i] = jugadores[j];
							jugadores[j] = jugadorTmp;
						}
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
	printf("\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+"
		   "\n|  ID  | NOMBRE               | POSICION      | N° CAMISETA | SUELDO       | CONFEDERACION | AÑOS DE CONTRATO |"
		   "\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+");
}

void MostrarPieDatosJugs(void){
	printf("\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+\n");
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




int BuscarJugadorOcupado(int comienzo, sJugador jugadores[], int tamJugadores){
	int i;
	int indice = -1;

	for(i = comienzo; i < tamJugadores; i++){
		if(jugadores[i].isEmpty == OCUPADO){
			indice = i;
			break;
		}
	}

	return indice;
}


int OrdenarJugadoresAlfabeticamente(sJugador jugadores[], int tamJugadores){
	int flagSwap;
	int i;
	int j;
	int contador = 0;
	int retorno = -1;
	sJugador jugadorTmp;
    int nuevoTam;

    if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
    	nuevoTam = tamJugadores - 1;

    	do{
    		flagSwap = 0;

    		for(i = 0; i < nuevoTam; i++){
    			if(jugadores[i].isEmpty == OCUPADO){
    				j = BuscarJugadorOcupado((i+1), jugadores, nuevoTam);
    				contador++;

    				if(j != -1){
        				if(strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0){
        					flagSwap = 1;

        					jugadorTmp = jugadores[i];
        					jugadores[i] = jugadores[j];
        					jugadores[j] = jugadorTmp;
        				}
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


float CalcularSalariosTotales(sJugador jugadores[], int tamJugadores){
	float acumuladorSalarios = 0;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				acumuladorSalarios += jugadores[i].salario;
			}
		}
	}

	return acumuladorSalarios;
}


int ContarJugadoresCargados(sJugador jugadores[], int tamJugadores){
	int contador = 0;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				contador++;
			}
		}
	}

	return contador;
}


float CalcularSalarioPromedio(sJugador jugadores[], int tamJugadores){
	float salarioPromedio;
	float totalSalarios;
	int totalJugadores;

	totalSalarios = CalcularSalariosTotales(jugadores, tamJugadores);
	totalJugadores = ContarJugadoresCargados(jugadores, tamJugadores);

	salarioPromedio = totalSalarios / totalJugadores;

	return salarioPromedio;
}


int JugadoresCobranMasQueElPromedio(sJugador jugadores[], int tamJugadores){
	//  Contador de jugadores que cobran mas que el promedio
	int contJugadores = 0;
	float salarioPromedio;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		salarioPromedio = CalcularSalarioPromedio(jugadores, tamJugadores);

		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == OCUPADO && jugadores[i].salario > salarioPromedio){
				contJugadores++;
			}
		}
	}

	return contJugadores;
}


int MostrarInformeSalarios(sJugador jugadores[], int tamJugadores){
	int retorno = -1;

	if(ChequearValidezArrayJugs(jugadores, tamJugadores) == 0){
		float totalSalarios;
		float salarioPromedio;
		int contadorJugadoresMasDelPromedio;

		totalSalarios = CalcularSalariosTotales(jugadores, tamJugadores);
		salarioPromedio = CalcularSalarioPromedio(jugadores, tamJugadores);
		contadorJugadoresMasDelPromedio = JugadoresCobranMasQueElPromedio(jugadores, tamJugadores);

		printf("\nEl total de todos los salarios es: %.2f", totalSalarios);
		printf("\nEl promedio de todos los salarios es: %.2f", salarioPromedio);
		printf("\nLa cantidad de jugadores que cobran mas del salario promedio es: %d\n", contadorJugadoresMasDelPromedio);
	}

	return retorno;
}











