#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input-output.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int rtn = -1;

	if(pFile != NULL && pArrayListJugador != NULL){
		char id[10];
		char nombre[100];
		char edad[10];
		char posicion[30];
		char nacionalidad[30];
		char idSeleccion[10];
		Jugador* jugadorAux;

		// Lectura fantasma
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombre, edad, posicion, nacionalidad, idSeleccion);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombre, edad, posicion, nacionalidad, idSeleccion);

			jugadorAux = jug_newParametros(id, nombre, edad, posicion, nacionalidad, idSeleccion);

			if(jugadorAux != NULL){
				ll_add(pArrayListJugador, jugadorAux);
			}
		}

		rtn = 1;
	}

    return rtn;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int parser_ConvocadoFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int idSeleccionAux;

	Jugador* jugadorAux;

	if(pFile != NULL && pArrayListJugador != NULL){
		MostrarCabeceraJugadores();
		while(!feof(pFile)){
			jugadorAux = jug_new();
			fread(jugadorAux, sizeof(Jugador), 1, pFile);

			if(feof(pFile)){
				break;
			}

			jug_getIdSeleccion(jugadorAux, &idSeleccionAux);

			if(idSeleccionAux > 0){
				jug_mostrarJugador(jugadorAux);
			}

			rtn = 1;
		}
		MostrarPieJugadores();
	}
    return rtn;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int rtn = -1;

	if(pFile != NULL && pArrayListSeleccion != NULL){
		char id[10];
		char pais[100];
		char confederacion[100];
		char convocados[30];
		Seleccion* seleccionAux;
		int estadoLista;

		estadoLista = ll_isEmpty(pArrayListSeleccion);

		if(!estadoLista){
			ll_clear(pArrayListSeleccion);
		}

		// Lectura fantasma
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados);

			seleccionAux = selec_newParametros(id, pais, confederacion, convocados);

			ll_add(pArrayListSeleccion, seleccionAux);
		}

		rtn = 1;
	}

    return rtn;
}

/**
 * @brief Parsea el ultimo id guardado en modo binario en el archivo .bin
 *
 * @param pFile
 * @param lastId
 * @return int -1 si salio mal, 1 si todo ok
 */
int parser_LastIdFromBinary(FILE* pFile, int* lastId){
	int rtn = -1;

	if(pFile != NULL){
		fread(lastId, sizeof(int), 1, pFile);

		rtn = 1;
	}

	return rtn;
}























