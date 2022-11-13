#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"


Jugador* jug_new(){
	Jugador* miJugador;

	miJugador = (Jugador*) malloc(sizeof(Jugador));

	return miJugador;
}


Jugador* jug_newParametros(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	Jugador* miJugador;
	miJugador = jug_new();

	if(miJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL){

		if(!jug_setId(miJugador, atoi(idStr)) || !jug_setNombreCompleto(miJugador, nombreCompletoStr) ||
		   !jug_setEdad(miJugador, atoi(edadStr)) || !jug_setPosicion(miJugador, posicionStr) ||
		   !jug_setNacionalidad(miJugador, nacionalidadStr) || !jug_setIdSeleccion(miJugador, atoi(idSeleccionStr))){
			// SI HUBO ALGUN ERROR A LA HORA DE CARGAR EL JUGADOR CREADO, LO ELIMINO Y CAMBIO SU PUNTERO A NULO
			jug_delete(miJugador);
			miJugador = NULL;
		}
	}

	return miJugador;
}


Jugador jug_cargarjugador(void){//todo
	Jugador jugadorAux;

//	getString(nombreAux, 100, "\nNombre: ", "\nERROR");
//	getStringNumeric(edadAux, 100, "\nEdad: ", "\nERROR");
//	getString(posicionAux, 100, "\nPosicion: ", "\nERROR");
//	getString(nacionalidadAux, 100, "\nNacionalidad: ", "\nERROR");
//
//	FirstToUppercase(nombreAux, 100);
//	FirstToUppercase(posicionAux, 100);
//	FirstToUppercase(nacionalidadAux, 100);

	return jugadorAux;
}


void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}


int jug_setId(Jugador* this, int id){
	int rtn = -1;

	if(this != NULL && id > 0){
		this->id = id;

		rtn = 1;
	}

	return rtn;
}


int jug_getId(Jugador* this, int* id){
	int rtn = -1;

	if(this != NULL && id != NULL){
		*id = this->id;

		rtn = 1;
	}

	return rtn;
}


int jug_setNombreCompleto(Jugador* this, char* nombreCompleto){
	int rtn = -1;

	if(this != NULL && nombreCompleto != NULL){
		strcpy(this->nombreCompleto, nombreCompleto);

		rtn = 1;
	}

	return rtn;
}

int jug_getNombreCompleto(Jugador* this, char* nombreCompleto){
	int rtn = -1;

	if(this != NULL && nombreCompleto != NULL){
		strcpy(nombreCompleto, this->nombreCompleto);

		rtn = 1;
	}

	return rtn;
}


int jug_setPosicion(Jugador* this, char* posicion){
	int rtn = -1;

	if(this != NULL && posicion != NULL){
		strcpy(this->posicion, posicion);

		rtn = 1;
	}

	return rtn;
}

int jug_getPosicion(Jugador* this, char* posicion){
	int rtn = -1;

	if(this != NULL && posicion != NULL){
		strcpy(posicion, this->posicion);

		rtn = 1;
	}

	return rtn;
}


int jug_setNacionalidad(Jugador* this, char* nacionalidad){
	int rtn = -1;

	if(this != NULL && nacionalidad != NULL){
		strcpy(this->nacionalidad, nacionalidad);

		rtn = 1;
	}

	return rtn;
}

int jug_getNacionalidad(Jugador* this, char* nacionalidad){
	int rtn = -1;

	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad, this->nacionalidad);

		rtn = 1;
	}

	return rtn;
}


int jug_setEdad(Jugador* this, int edad){
	int rtn = -1;

	if(this != NULL && edad > 0){
		this->edad = edad;

		rtn = 1;
	}

	return rtn;
}

int jug_getEdad(Jugador* this, int* edad){
	int rtn = -1;

	if(this != NULL && edad != NULL){
		*edad = this->edad;

		rtn = 1;
	}

	return rtn;
}


int jug_setIdSeleccion(Jugador* this, int idSeleccion){
	int rtn = -1;

	if(this != NULL && idSeleccion >= 0){
		this->idSeleccion = idSeleccion;

		rtn = 1;
	}

	return rtn;
}

int jug_getIdSeleccion(Jugador* this, int* idSeleccion){
	int rtn = -1;

	if(this != NULL && idSeleccion != NULL){
		*idSeleccion = this->idSeleccion;

		rtn = 1;
	}

	return rtn;
}


int jug_mostrarJugador(Jugador* jugador){
	int rtn = -1;
	int idAux;
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	int edadAux;
	int idSeleccionAux;

	jug_getId(jugador, &idAux);
	jug_getNombreCompleto(jugador, nombreAux);
	jug_getPosicion(jugador, posicionAux);
	jug_getNacionalidad(jugador, nacionalidadAux);
	jug_getEdad(jugador, &edadAux);
	jug_getIdSeleccion(jugador, &idSeleccionAux);

	printf("\n| %4d | %-30s | %-25s | %-20s | %-4d | %-4d |", idAux, nombreAux, posicionAux, nacionalidadAux, edadAux, idSeleccionAux);

	rtn = 1;

	return rtn;
}



