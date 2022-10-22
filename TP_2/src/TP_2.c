/*
Trabajo Practico 2

Lautaro Monserrat
45426439
DIV C 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "confederaciones.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}sJugador;

int main(void) {
	sConfederacion confederaciones[CANT_CONF];

//	sConfederacion confederaciones[CANT_CONF] = {{100, "CONMEBOL", "SUDAMERICA", 1916},
//												 {101, "UEFA", "EUROPA", 1954},
//												 {102, "AFC", "ASIA", 1954},
//												 {103, "CAF", "AFRICA", 1957},
//												 {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
//												 {103, "OFC", "OCEANIA", 1966}};

	int opcion;
	int confirmoSalir;

	InicializarConfs(confederaciones, CANT_CONF);

	do{
		printf("\n============================="
			   "\n|      MENU PRINCIPAL       |"
			   "\n|---------------------------|"
			   "\n| 1.Menu de jugadores       |"
			   "\n| 2.Menu de confederaciones |"
			   "\n| 3.Salir                   |"
			   "\n=============================\n");

		getInt(&opcion, "\nSeleccione una opcion: ", "\n[ERROR] Opcion invalida.", 1, 3);

		switch(opcion){
			case 1://jugadores
				printf("jugadores");
				break;

			case 2://confederaciones
				MenuConfederacion(confederaciones, CANT_CONF);
				break;

			case 3://salir
				confirmoSalir = ConfirmarSalida();
				break;
		}

	}while(opcion != 3 || confirmoSalir != 1);

	return EXIT_SUCCESS;
}




































