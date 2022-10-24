/*
Trabajo Practico 2

Lautaro Monserrat
45426439
DIV C 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "confederaciones.h"
#include "input.h"
#include "jugadores.h"

#define CANT_JUGADORES 3000
#define CANT_CONF 6

int main(void) {
	int opcion;
	int confirmoSalir;

	sJugador jugadores[CANT_JUGADORES];
//	sConfederacion confederaciones[CANT_CONF];
	sConfederacion confederaciones[CANT_CONF] = {{100, "CONMEBOL", "SUDAMERICA", 1916, OCUPADO},
												 {101, "UEFA", "EUROPA", 1954, OCUPADO},
												 {102, "AFC", "ASIA", 1954, OCUPADO},
												 {103, "CAF", "AFRICA", 1957, OCUPADO},
												 {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, OCUPADO},
												 {105, "OFC", "OCEANIA", 1966, OCUPADO}};

//	InicializarConfs(confederaciones, CANT_CONF);

	do{
		printf("\n+---------------------------+"
			   "\n|      MENU PRINCIPAL       |"
			   "\n+---------------------------+"
			   "\n| 1.Menu de jugadores       |"
			   "\n| 2.Menu de confederaciones |"
			   "\n| 3.Salir                   |"
			   "\n+---------------------------+\n");

		getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 3);

		switch(opcion){
			case 1:
				MenuJugadores(jugadores, CANT_JUGADORES, confederaciones, CANT_CONF);
				break;

			case 2:
				MenuConfederacion(confederaciones, CANT_CONF);
				break;

			case 3:
				confirmoSalir = ConfirmarSalida();
				break;
		}

	}while(opcion != 3 || confirmoSalir != 1);

	return EXIT_SUCCESS;
}




































