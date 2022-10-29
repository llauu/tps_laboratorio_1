#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "input-output.h"
#include "nexo.h"


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
		getString(nombre, 21, "\nIngrese el nombre del jugador: \n> ", "\n[ERROR] Texto invalido.");
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
		retorno = getString(posicion, size, "\nIngrese la posicion del jugador: \n> ", "\n[ERROR] Texto invalido.");
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
	float salarioPromedio = -1;
	float totalSalarios;
	int totalJugadores;

	totalSalarios = CalcularSalariosTotales(jugadores, tamJugadores);
	totalJugadores = ContarJugadoresCargados(jugadores, tamJugadores);

	if(totalJugadores != 0){
		salarioPromedio = totalSalarios / totalJugadores;
	}

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

		retorno = 0;
	}

	return retorno;
}











