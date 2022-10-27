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
#include "nexo.h"

#define CANT_JUGADORES 3000
#define CANT_CONF 6

int main(void) {
	int opcion;
	int confirmoSalir;

//	sJugador jugadores[CANT_JUGADORES];
	sJugador jugadores[CANT_JUGADORES] = {{1, "Lionel Messi", "Delantero", 10, 101, 436000, 4, OCUPADO},
										  {2, "Cristiano Ronaldo", "Delantero", 7, 104, 53426.54, 2, OCUPADO},
										  {3, "Martin Rodriguez", "Defensor", 34, 102, 23666.3, 5, OCUPADO},
										  {4, "Roman Riquelme", "Delantero", 11, 101, 433410, 1, OCUPADO},
										  {5, "Martin Palermo", "Mediocampista", 9, 103, 124565, 9, OCUPADO},
										  {6, "Alex Busquets", "Defensor", 5, 101, 66377, 1, OCUPADO},
										  {7, "Diego Maradona", "Delantero", 10, 100, 4333334.23, 3, OCUPADO},
										  {8, "Juana De Arco", "Mediocampista", 15, 101, 532677, 4, OCUPADO},
										  {9, "Mr Roman", "Mediocampista", 15, 103, 1232233.4, 6, OCUPADO},
										  {10, "Agustin Rossi", "Arquero", 1, 102, 125600.13, 5, OCUPADO},
										  {11, "Julian Alvarez", "Arquero", 9, 105, 423690.9, 7, OCUPADO}};


//	sConfederacion confederaciones[CANT_CONF];
	sConfederacion confederaciones[CANT_CONF] = {{100, "CONMEBOL", "SUDAMERICA", 1916, OCUPADO}, // 1
												 {101, "UEFA", "EUROPA", 1954, OCUPADO}, // 4
												 {102, "AFC", "ASIA", 1954, OCUPADO}, // 2
												 {103, "CAF", "AFRICA", 1957, OCUPADO}, // 2
												 {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, OCUPADO},// 1
												 {105, "OFC", "OCEANIA", 1966, OCUPADO}}; // 1

	sConfederacionAux auxiliar[CANT_CONF];

//	InicializarJugadores(jugadores, CANT_JUGADORES);
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
				MenuJugadores(jugadores, CANT_JUGADORES, confederaciones, CANT_CONF, auxiliar);
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




































