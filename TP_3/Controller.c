#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "Controller.h"
#include "Jugador.h"
#include "LinkedList.h"
#include "parser.h"
#include "input-output.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	FILE* miArchivo;

	if(pArrayListJugador != NULL){
		miArchivo = fopen(path, "r");

		if(miArchivo != NULL){
			rtn = parser_JugadorFromText(miArchivo, pArrayListJugador);

			fclose(miArchivo);
		}
	}

    return rtn;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarConvocadosDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	FILE* miArchivo;

	if(pArrayListJugador != NULL){
		miArchivo = fopen(path, "rb");

		if(miArchivo != NULL){
			rtn = parser_ConvocadoFromBinary(miArchivo, pArrayListJugador);

			fclose(miArchivo);
		}
	}

    return rtn;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int ultimoIdAux;
	char edadAux[100];
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	char idSeleccionAux[10] = "0";
	char idAux[10];
	Jugador* jugadorAux = NULL;

	if(pArrayListJugador != NULL){
		if(ll_len(pArrayListJugador) > 0){
			rtn = controller_cargarUltimoIDJugador("ultimoIdJugador.bat", &ultimoIdAux);

			if(rtn){
				sprintf(idAux, "%d", ultimoIdAux);

				getString(nombreAux, 100, "\nNombre: ", "\nERROR");
				getStringNumeric(edadAux, 100, "\nEdad: ", "\nERROR");
				getString(posicionAux, 100, "\nPosicion: ", "\nERROR");
				getString(nacionalidadAux, 100, "\nNacionalidad: ", "\nERROR");

				FirstToUppercase(nombreAux, 100);
				FirstToUppercase(posicionAux, 100);
				FirstToUppercase(nacionalidadAux, 100);

				jugadorAux = jug_newParametros(idAux, nombreAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);

				ll_add(pArrayListJugador, jugadorAux);

				printf("\nJugador agregado con exito!\n");
			}
			else{
				printf("\n[ERROR] Hubo un fallo en la carga del ultimo id.\n");
			}

		}
		else{
			printf("\n[ERROR] Tenes que cargar los archivos .csv antes de dar de alta nuevos jugadores.\n");
		}
	}

    return rtn;
}


/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int opcion;
	int edadAux;
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	int indiceAEditar;
	Jugador* jugadorAEditar;

	if(pArrayListJugador != NULL){
		if(ll_len(pArrayListJugador) > 0){
			controller_listarJugadores(pArrayListJugador);

			indiceAEditar = controller_solicitarYValidarIdJugador(pArrayListJugador);
			jugadorAEditar = (Jugador*) ll_get(pArrayListJugador, indiceAEditar);

			printf("\n+---------------------------+"
				   "\n|     MENU MODIFICACION     |"
				   "\n+---------------------------+"
				   "\n| 1.NOMBRE                  |"
				   "\n| 2.EDAD                    |"
				   "\n| 3.POSICION                |"
				   "\n| 4.NACIONALIDAD            |"
				   "\n+---------------------------+\n");

			getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 4);

			switch(opcion){
				case 1: // nombre:
					getString(nombreAux, 100, "\nIngrese el nuevo nombre del jugador: ", "\nERROR");
					FirstToUppercase(nombreAux, 100);
					jug_setNombreCompleto(jugadorAEditar, nombreAux);
					break;

				case 2: // edad:
					getInt(&edadAux, "\nIngrese la nueva edad del jugador: ", "\nERROR", 1, 100);
					jug_setEdad(jugadorAEditar, edadAux);
					break;

				case 3: // posi:
					getString(posicionAux, 100, "\nIngrese la nueva posicion del jugador: ", "\nERROR");
					FirstToUppercase(posicionAux, 100);
					jug_setPosicion(jugadorAEditar, posicionAux);
					break;

				case 4: // nacio:
					getString(nacionalidadAux, 100, "\nIngrese la nueva nacionalidad del jugador: ", "\nERROR");
					FirstToUppercase(nacionalidadAux, 100);
					jug_setNacionalidad(jugadorAEditar, nacionalidadAux);
					break;
			}

			printf("\nSe modifico con exito!");
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para editar.\n");
		}
	}

    return rtn;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int indiceABajar;
	int idSeleccionJugador;
	int indiceSeleccionJugador;
	Jugador* jugadorABajar;
	Seleccion* seleccionAux;
	int convocadosAux;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(ll_len(pArrayListJugador) > 0){
			controller_listarJugadores(pArrayListJugador);

			indiceABajar = controller_solicitarYValidarIdJugador(pArrayListJugador);
			jugadorABajar = (Jugador*) ll_get(pArrayListJugador, indiceABajar);

			jug_getIdSeleccion(jugadorABajar, &idSeleccionJugador);

			if(idSeleccionJugador != 0){// VERIFICO SI EL JUGADOR ESTABA EN UNA SELECCION
				indiceSeleccionJugador = controller_buscarSeleccionPorID(pArrayListSeleccion, idSeleccionJugador);

				seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccionJugador);

				selec_getConvocados(seleccionAux, &convocadosAux);
				convocadosAux--;
				selec_setConvocados(seleccionAux, convocadosAux);
			}

			ll_remove(pArrayListJugador, indiceABajar);
			jug_delete(jugadorABajar);

			printf("\nBaja dada con exito!");
			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para dar de baja.\n");
		}
	}

    return rtn;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int cant;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			MostrarCabeceraJugadores();

			for(int i = 0; i < cant; i++){
				jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

				jug_mostrarJugador(jugadorAux);
			}

			MostrarPieJugadores();

			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para mostrar.\n");
		}
	}

    return rtn;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int cant;
	FILE* miArchivo;
	Jugador* jugadorAux;

	int idAux;
	char nombreAux[100];
	int edadAux;
	char posicionAux[100];
	char nacionalidadAux[100];
	int idSeleccionAux;

	if(path != NULL && pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			miArchivo = fopen(path, "w");
			if(miArchivo != NULL){
				fprintf(miArchivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

				for(int i = 0; i < cant; i++){
					jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

					jug_getId(jugadorAux, &idAux);
					jug_getNombreCompleto(jugadorAux, nombreAux);
					jug_getEdad(jugadorAux, &edadAux);
					jug_getPosicion(jugadorAux, posicionAux);
					jug_getNacionalidad(jugadorAux, nacionalidadAux);
					jug_getIdSeleccion(jugadorAux, &idSeleccionAux);

					fprintf(miArchivo, "%d,%s,%d,%s,%s,%d\n", idAux, nombreAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);
				}

			    fclose(miArchivo);

			    rtn = 1;
			}
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para guardar.\n");
		}
	}

    return rtn;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarConvocadosModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int cant;
	FILE* miArchivo;
	Jugador* jugadorAux;
	int idSeleccionAux;

	if(path != NULL && pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			miArchivo = fopen(path, "wb");

			if(miArchivo != NULL){
				for(int i = 0; i < cant; i++){
					jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

					jug_getIdSeleccion(jugadorAux, &idSeleccionAux);

					if(idSeleccionAux > 0){
						fwrite(jugadorAux, sizeof(Jugador), 1, miArchivo);
					}
				}
			    fclose(miArchivo);

			    rtn = 1;
			}
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para guardar.\n");
		}
	}

    return rtn;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int rtn = -1;

	FILE* miArchivo;

	miArchivo = fopen(path, "r");

	if(miArchivo != NULL){
	    rtn = parser_SeleccionFromText(miArchivo, pArrayListSeleccion);

	    fclose(miArchivo);
	}

    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int cant;
	Seleccion* seleccionAux;

	if(pArrayListSeleccion != NULL){
		cant = ll_len(pArrayListSeleccion);

		if(cant > 0){
			printf("\n+------+--------------------------------+---------------------------+--------------+"
				   "\n|  ID  |            PAIS                |       CONFEDERACION       |  CONVOCADOS  |"
				   "\n+------+--------------------------------+---------------------------+--------------+");

			for(int i = 0; i < cant; i++){
				seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);

				selec_mostrarSeleccion(seleccionAux);
			}

			printf("\n+------+--------------------------------+---------------------------+--------------+\n");

			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay selecciones cargadas para mostrar.\n");
		}
	}

	return rtn;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int cant;
	FILE* miArchivo;
	Seleccion* seleccionAux;

	int idAux;
	char paisAux[100];
	char confederacionAux[100];
	int convocadosAux;

	if(path != NULL && pArrayListSeleccion != NULL){
		cant = ll_len(pArrayListSeleccion);

		if(cant > 0){
			miArchivo = fopen(path, "w");
			if(miArchivo != NULL){
				fprintf(miArchivo,"id,pais,confederacion,convocados\n");

				for(int i = 0; i < cant; i++){
					seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);

					selec_getId(seleccionAux, &idAux);
					selec_getPais(seleccionAux, paisAux);
					selec_getConfederacion(seleccionAux, confederacionAux);
					selec_getConvocados(seleccionAux, &convocadosAux);

					fprintf(miArchivo, "%d,%s,%s,%d\n", idAux, paisAux, confederacionAux, convocadosAux);
				}

			    fclose(miArchivo);

			    rtn = 1;
			}
		}
		else{
			printf("\n[ERROR] No hay selecciones cargadas para guardar.\n");
		}
	}

    return rtn;
}


int controller_cargarUltimoIDJugador(char* path, int* ultimoId){
	int rtn = -1;
	int ultimoIdAux = 370;

	FILE* miArchivo;

	if(path != NULL && ultimoId != NULL){
		miArchivo = fopen(path, "rb");

		if(miArchivo != NULL){
			// SI EL ARCHIVO YA EXISTE ENTRA ACA
			rtn = parser_LastIdFromBinary(miArchivo, &ultimoIdAux);

			fclose(miArchivo);
		}

		// Incrementamos en uno el ID leido
		ultimoIdAux++;

		miArchivo = fopen(path, "wb");

		fwrite(&ultimoIdAux, sizeof(int), 1, miArchivo);

		fclose(miArchivo);

		*ultimoId = ultimoIdAux;

		rtn = 1;
	}

	return rtn;
}


int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int cant;
	int idSeleccionAux;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			MostrarCabeceraConSeleccion();

			for(int i = 0; i < cant; i++){
				jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

				jug_getIdSeleccion(jugadorAux, &idSeleccionAux);

				if(idSeleccionAux > 0){
					mostrarJugadorConSeleccion(jugadorAux, pArrayListSeleccion);
				}
			}

			MostrarPieConSeleccion();

			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para mostrar.\n");
		}
	}

	return rtn;
}


int controller_obtenerNombreSeleccion(LinkedList* pArrayListSeleccion, int idSeleccion){
	int rtn = -1;

	if(pArrayListSeleccion != NULL && idSeleccion > 0){

	}

	return rtn;
}


int controller_listarJugadoresConSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int cant;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			MostrarCabeceraConSeleccion();

			for(int i = 0; i < cant; i++){
				jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

				mostrarJugadorConSeleccion(jugadorAux, pArrayListSeleccion);
			}

			MostrarPieConSeleccion();

			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para mostrar.\n");
		}
	}

    return rtn;
}


int mostrarJugadorConSeleccion(Jugador* jugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int idAux;
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	int edadAux;
	int idSeleccionAux;
	char nombreSeleccion[100];
	int indiceSeleccion;
	Seleccion* seleccionAux;

	if(jugador != NULL && pArrayListSeleccion != NULL){
		jug_getIdSeleccion(jugador, &idSeleccionAux);

		if(idSeleccionAux > 0){
			indiceSeleccion = controller_buscarSeleccionPorID(pArrayListSeleccion, idSeleccionAux);
			seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

			selec_getPais(seleccionAux, nombreSeleccion);
		}
		else{
			strcpy(nombreSeleccion, "No convocado");
		}

		jug_getId(jugador, &idAux);
		jug_getNombreCompleto(jugador, nombreAux);
		jug_getPosicion(jugador, posicionAux);
		jug_getNacionalidad(jugador, nacionalidadAux);
		jug_getEdad(jugador, &edadAux);

		printf("\n| %4d | %-30s | %-25s | %-20s | %-4d | %-20s |", idAux, nombreAux, posicionAux, nacionalidadAux, edadAux, nombreSeleccion);
		rtn = 1;
	}

	return rtn;
}


int controller_menuListados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int opcion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(ll_len(pArrayListJugador) > 0 && ll_len(pArrayListSeleccion) > 0){
	    	printf("\n+----------------------------+"
	    		   "\n|       MENU LISTADOS        |"
	    		   "\n+----------------------------+"
	    		   "\n| 1.TODOS LOS JUGADORES      |"
	    		   "\n| 2.TODAS LAS SELECCIONES    |"
	    		   "\n| 3.JUGADORES CONVOCADOS     |"
	     		   "\n| 4.VOLVER AL MENU PRINCIPAL |"
	    		   "\n+----------------------------+\n");
	    	getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 4);

	    	switch(opcion){
				case 1:
					controller_listarJugadores(pArrayListJugador);
					break;

				case 2:
					controller_listarSelecciones(pArrayListSeleccion);
					break;

				case 3:
					controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
					break;
	    	}

			rtn = 1;
		}
		else{
			printf("\n[ERROR] Es necesario cargar los jugadores y selecciones para ingresar a los listados.\n");
		}
	}

	return rtn;
}


int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int indiceJugador;
	int indiceSeleccion;
	int idSeleccionJugador;
	int idSeleccion;
	int convocadosAux;

	Jugador* jugadorAux;
	Seleccion* seleccionAux;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(ll_len(pArrayListJugador) > 0 && ll_len(pArrayListSeleccion) > 0){
			controller_listarJugadores(pArrayListJugador);
			indiceJugador = controller_solicitarYValidarIdJugador(pArrayListJugador);

			jugadorAux = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

			jug_getIdSeleccion(jugadorAux, &idSeleccionJugador);

			if(idSeleccionJugador == 0){ // SI NO ESTA CONVOCADO
				controller_listarSelecciones(pArrayListSeleccion);
				indiceSeleccion = controller_solicitarYValidarIdSeleccion(pArrayListSeleccion);

				seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

				selec_getConvocados(seleccionAux, &convocadosAux);

				if(convocadosAux < 22){ // SI LA SELECCION NO ESTA LLENA LO AGREGO
					selec_getId(seleccionAux, &idSeleccion);

					jug_setIdSeleccion(jugadorAux, idSeleccion);

					convocadosAux++;
					selec_setConvocados(seleccionAux, convocadosAux);

					printf("\nJugador convocado con exito!\n");
				}
				else{
					printf("\n[ERROR] La seleccion ya esta llena.\n");
				}
			}
			else{
				printf("\n[ERROR] El jugador ya fue convocado a una seleccion. Sacalo de la seleccion o convoca otro.\n");
			}
		}
		else{
			printf("\n[ERROR] No hay jugadores y selecciones cargados para convocar.\n");
		}

		rtn = 1;
	}

	return rtn;
}


int controller_quitarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

	int rtn = -1;
	int indiceJugador;
	int idSeleccionJugador;
	int idSeleccion;
	int convocadosAux;
	int cantSelecciones;

	Jugador* jugadorAux;
	Seleccion* seleccionAux;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(ll_len(pArrayListJugador) > 0 && ll_len(pArrayListSeleccion) > 0){
			controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
			indiceJugador = controller_solicitarYValidarIdJugador(pArrayListJugador);

			jugadorAux = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

			jug_getIdSeleccion(jugadorAux, &idSeleccionJugador);

			if(idSeleccionJugador > 0){
				cantSelecciones = ll_len(pArrayListSeleccion);

				for(int i = 0; i < cantSelecciones; i++){
					seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);

					selec_getId(seleccionAux, &idSeleccion);

					if(idSeleccionJugador == idSeleccion){
						break;
					}
				}

				selec_getConvocados(seleccionAux, &convocadosAux);

				jug_setIdSeleccion(jugadorAux, 0);

				convocadosAux--;
				selec_setConvocados(seleccionAux, convocadosAux);

				printf("\nJugador quitado de la seleccion con exito!");

			}
			else{
				printf("\n[ERROR] El jugador no esta convocado en una seleccion.");
			}
		}
		else{
			printf("\n[ERROR] No hay jugadores cargados para quitar de las selecciones.\n");
		}

		rtn = 1;
	}

	return rtn;
}


int controller_menuConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int opcion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
    	printf("\n+----------------------------+"
    		   "\n|      MENU CONVOCADOS       |"
    		   "\n+----------------------------+"
    		   "\n| 1.CONVOCAR                 |"
    		   "\n| 2.QUITAR DE LA SELECCION   |"
      		   "\n| 3.VOLVER AL MENU PRINCIPAL |"
    		   "\n+----------------------------+\n");
    	getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 3);

    	switch(opcion){
			case 1:
				controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion);
				break;

			case 2:
				controller_quitarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
				break;
    	}

		rtn = 1;
	}

	return rtn;
}


int controller_buscarJugadorPorID(LinkedList* pArrayListJugador, int idIngresado){
	int indiceId = -1;
	int cant;
	int idAux;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			for(int i = 0; i < cant; i++){
				jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

				jug_getId(jugadorAux, &idAux);

				if(idAux == idIngresado){
					indiceId = i;
					break;
				}
			}
		}
	}

	return indiceId;
}


int controller_solicitarYValidarIdJugador(LinkedList* pArrayListJugador){
	int indiceId = -1;
	int idIngresado;

	if(pArrayListJugador != NULL){
		do{
			getInt(&idIngresado, "\nIngrese el ID del jugador: \n> ", "\n[ERROR] ID no valido.", 1, 10000);

			indiceId = controller_buscarJugadorPorID(pArrayListJugador, idIngresado);

			if(indiceId == -1){
				printf("\n[ERROR] El ID ingresado no existe, vuelva a ingresar uno valido.\n");
			}

		}while(indiceId == -1);
	}

	return indiceId;
}


int controller_buscarSeleccionPorID(LinkedList* pArrayListSeleccion, int idIngresado){
	int indiceId = -1;
	int cant;
	int idAux;
	Seleccion* seleccionAux;

	if(pArrayListSeleccion != NULL){
		cant = ll_len(pArrayListSeleccion);

		if(cant > 0){
			for(int i = 0; i < cant; i++){
				seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);

				selec_getId(seleccionAux, &idAux);

				if(idAux == idIngresado){
					indiceId = i;
					break;
				}
			}
		}

	}

	return indiceId;
}


int controller_solicitarYValidarIdSeleccion(LinkedList* pArrayListSeleccion){
	int indiceId = -1;
	int idIngresado;

	if(pArrayListSeleccion != NULL){
		do{
			getInt(&idIngresado, "\nIngrese el ID de la seleccion: \n> ", "\n[ERROR] ID no valido.", 1, 100);

			indiceId = controller_buscarSeleccionPorID(pArrayListSeleccion, idIngresado);

			if(indiceId == -1){
				printf("\n[ERROR] El ID ingresado no existe, vuelva a ingresar uno valido.\n");
			}

		}while(indiceId == -1);

	}

	return indiceId;
}














