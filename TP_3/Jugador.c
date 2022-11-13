#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "input-output.h"

/**
 * @brief Constructor de jugador
 *
 * @return Jugador*
 */
Jugador* jug_new(){
	Jugador* miJugador;

	miJugador = (Jugador*) malloc(sizeof(Jugador));

	return miJugador;
}

/**
 * @brief Constructor de jugador parametrizado
 *
 * @param idStr char*
 * @param nombreCompletoStr char*
 * @param edadStr char*
 * @param posicionStr char*
 * @param nacionalidadStr char*
 * @param idSeleccionStr char*
 * @return Jugador*
 */
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

/**
 * @brief Borra un jugador de memoria dinamica
 *
 * @param this
 */
void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}

/**
 * @brief setter de id de jugador
 *
 * @param this
 * @param id
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setId(Jugador* this, int id){
	int rtn = -1;

	if(this != NULL && id > 0){
		this->id = id;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de id de jugador
 *
 * @param this
 * @param id
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getId(Jugador* this, int* id){
	int rtn = -1;

	if(this != NULL && id != NULL){
		*id = this->id;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter del nombre de jugador
 *
 * @param this
 * @param nombreCompleto
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setNombreCompleto(Jugador* this, char* nombreCompleto){
	int rtn = -1;

	if(this != NULL && nombreCompleto != NULL){
		strcpy(this->nombreCompleto, nombreCompleto);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter del nombre de jugador
 *
 * @param this
 * @param nombreCompleto
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getNombreCompleto(Jugador* this, char* nombreCompleto){
	int rtn = -1;

	if(this != NULL && nombreCompleto != NULL){
		strcpy(nombreCompleto, this->nombreCompleto);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de posicion
 *
 * @param this
 * @param posicion
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setPosicion(Jugador* this, char* posicion){
	int rtn = -1;

	if(this != NULL && posicion != NULL){
		strcpy(this->posicion, posicion);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de posicion
 *
 * @param this
 * @param posicion
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getPosicion(Jugador* this, char* posicion){
	int rtn = -1;

	if(this != NULL && posicion != NULL){
		strcpy(posicion, this->posicion);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de nacionalidad
 *
 * @param this
 * @param nacionalidad
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setNacionalidad(Jugador* this, char* nacionalidad){
	int rtn = -1;

	if(this != NULL && nacionalidad != NULL){
		strcpy(this->nacionalidad, nacionalidad);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de nacionalidad
 *
 * @param this
 * @param nacionalidad
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getNacionalidad(Jugador* this, char* nacionalidad){
	int rtn = -1;

	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad, this->nacionalidad);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de edad
 *
 * @param this
 * @param edad
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setEdad(Jugador* this, int edad){
	int rtn = -1;

	if(this != NULL && edad > 0){
		this->edad = edad;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de edad
 *
 * @param this
 * @param edad
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getEdad(Jugador* this, int* edad){
	int rtn = -1;

	if(this != NULL && edad != NULL){
		*edad = this->edad;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de id seleccion
 *
 * @param this
 * @param idSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_setIdSeleccion(Jugador* this, int idSeleccion){
	int rtn = -1;

	if(this != NULL && idSeleccion >= 0){
		this->idSeleccion = idSeleccion;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de id seleccion
 *
 * @param this
 * @param idSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int jug_getIdSeleccion(Jugador* this, int* idSeleccion){
	int rtn = -1;

	if(this != NULL && idSeleccion != NULL){
		*idSeleccion = this->idSeleccion;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief muestra un solo jugador
 *
 * @param jugador
 * @return int -1 si salio mal, 1 si todo ok
 */
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

/**
 * @brief permite ordenar por nacionalidad 2 jugadores
 *
 * @param pJugadorUno
 * @param pJugadorDos
 * @return 1 si se hace swap, 0 si son iguales
 */
int jug_OrdenarPorNacionalidad(void* pJugadorUno, void* pJugadorDos){
	int rtn = -1;
	int comparacion;
	char nacionalidadUno[100];
	char nacionalidadDos[100];

	Jugador* jugadorUno;
	Jugador* jugadorDos;

	jugadorUno = (Jugador*) pJugadorUno;
	jugadorDos = (Jugador*) pJugadorDos;

	jug_getNacionalidad(jugadorUno, nacionalidadUno);
	jug_getNacionalidad(jugadorDos, nacionalidadDos);

	StringUpper(nacionalidadUno, 100);
	StringUpper(nacionalidadDos, 100);

	comparacion = strcmp(nacionalidadUno, nacionalidadDos);

	if(comparacion > 0){
		rtn = 1;
	}
	else{
		if(comparacion == 0){
			rtn = 0;
		}
	}

	return rtn;
}

/**
 * @brief permite ordenar por edad 2 jugadores
 *
 * @param pJugadorUno
 * @param pJugadorDos
 * @return 1 si se hace swap, 0 si son iguales
 */
int jug_OrdenarPorEdad(void* pJugadorUno, void* pJugadorDos){
	int rtn = -1;
	int edadUno;
	int edadDos;

	Jugador* jugadorUno;
	Jugador* jugadorDos;

	jugadorUno = (Jugador*) pJugadorUno;
	jugadorDos = (Jugador*) pJugadorDos;

	jug_getEdad(jugadorUno, &edadUno);
	jug_getEdad(jugadorDos, &edadDos);

	if(edadUno > edadDos){
		rtn = 1;
	}
	else{
		if(edadUno == edadDos){
			rtn = 0;
		}
	}

	return rtn;
}

/**
 * @brief permite ordenar por nombre 2 jugadores
 *
 * @param pJugadorUno
 * @param pJugadorDos
 * @return 1 si se hace swap, 0 si son iguales
 */
int jug_OrdenarPorNombre(void* pJugadorUno, void* pJugadorDos){
	int rtn = -1;
	int comparacion;
	char nombreUno[100];
	char nombreDos[100];

	Jugador* jugadorUno;
	Jugador* jugadorDos;

	jugadorUno = (Jugador*) pJugadorUno;
	jugadorDos = (Jugador*) pJugadorDos;

	jug_getNombreCompleto(jugadorUno, nombreUno);
	jug_getNombreCompleto(jugadorDos, nombreDos);

	StringUpper(nombreUno, 100);
	StringUpper(nombreDos, 100);

	comparacion = strcmp(nombreUno, nombreDos);

	if(comparacion > 0){
		rtn = 1;
	}
	else{
		if(comparacion == 0){
			rtn = 0;
		}
	}

	return rtn;
}

















