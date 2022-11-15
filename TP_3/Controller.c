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
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int estadoLista;
	FILE* miArchivo;

	if(pArrayListJugador != NULL){
		estadoLista = ll_isEmpty(pArrayListJugador);

		if(estadoLista == 1){
			miArchivo = fopen(path, "r");

			if(miArchivo != NULL){
				rtn = parser_JugadorFromText(miArchivo, pArrayListJugador);

				fclose(miArchivo);
			}
		}
		else{
			printf("\n[ERROR] La lista de jugadores ya fue cargada!");
		}
	}

    return rtn;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
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
 * \return int -1 si salio mal, 1 si todo ok
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int ultimoIdAux;
	char edadAux[100];
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	char idSeleccionAux[10] = "0"; // Inicializo el id de la seleccion en 0, osea no convocado
	char idAux[10];
	Jugador* jugadorAux = NULL;

	if(pArrayListJugador != NULL){
		if(ll_len(pArrayListJugador) > 0){
			if(jug_PedirDatos(nombreAux, edadAux, posicionAux, nacionalidadAux, 100) == 1){
				rtn = controller_cargarUltimoIDJugador("ultimoIdJugador.bat", &ultimoIdAux);

				if(rtn == 1){
					sprintf(idAux, "%d", ultimoIdAux);
					jugadorAux = jug_newParametros(idAux, nombreAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);

					if(jugadorAux != NULL){
						ll_add(pArrayListJugador, jugadorAux);
						printf("\nJugador agregado con exito!\n");
					}
				}
				else{
					printf("\n[ERROR] Hubo un fallo en la carga del ultimo id.\n");
				}
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
 * \return int -1 si salio mal, 1 si todo ok
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
					rtn = getString(nombreAux, 100, "\nIngrese el nombre: \n> ", "\n[ERROR] Nombre no valido.");
					if(rtn == 1){
						FirstToUppercase(nombreAux, 100);
						jug_setNombreCompleto(jugadorAEditar, nombreAux);
					}
					break;

				case 2: // edad:
					rtn = getInt(&edadAux, "\nIngrese la nueva edad del jugador: ", "\nERROR", 18, 100);
					if(rtn == 1){
						jug_setEdad(jugadorAEditar, edadAux);
					}
					break;

				case 3: // posi:
					rtn = getString(posicionAux, 100, "\nIngrese la posicion: \n> ", "\n[ERROR] Posicion no valida.");
					if(rtn == 1){
						FirstToUppercase(posicionAux, 100);
						jug_setPosicion(jugadorAEditar, posicionAux);
					}
					break;

				case 4: // nacio:
					rtn = getString(nacionalidadAux, 100, "\nIngrese la nacionalidad: \n> ", "\n[ERROR] Nacionalidad no valida.");
					if(rtn == 1){
						FirstToUppercase(nacionalidadAux, 100);
						jug_setNacionalidad(jugadorAEditar, nacionalidadAux);
					}
					break;
			}

			if(rtn == 1){
				printf("\nSe modifico con exito!");
			}
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
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
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
			if(controller_listarJugadores(pArrayListJugador) == 1){
				indiceABajar = controller_solicitarYValidarIdJugador(pArrayListJugador);
				jugadorABajar = (Jugador*) ll_get(pArrayListJugador, indiceABajar);

				if(jugadorABajar != NULL){
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
				}
			}
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
 * \return int -1 si salio mal, 1 si todo ok
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
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int rtn = -1;
	int opcion;
	int criterioOrdenamiento;

	if(pArrayListJugador != NULL){
		if(ll_len(pArrayListJugador) > 0){
			printf("\n+---------------------------------+"
				   "\n|        ORDENAR Y LISTAR         |"
				   "\n+---------------------------------+"
				   "\n| 1.JUGADORES POR NACIONALIDAD    |"
				   "\n| 2.JUGADORES POR EDAD            |"
				   "\n| 3.JUGADORES POR NOMBRE          |"
				   "\n+---------------------------------+\n");
			getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 3);

			getInt(&criterioOrdenamiento, "\nSeleccione un criterio de ordenamiento\n 0 para descendente o 1 para ascendente: \n> ",  "\n[ERROR] Opcion invalida.", 0, 1);

			switch(opcion){
				case 1:
					rtn = ll_sort(pArrayListJugador, jug_OrdenarPorNacionalidad, criterioOrdenamiento);
					break;

				case 2:
					rtn = ll_sort(pArrayListJugador, jug_OrdenarPorEdad, criterioOrdenamiento);
					break;

				case 3:
					rtn = ll_sort(pArrayListJugador, jug_OrdenarPorNombre, criterioOrdenamiento);
					break;
			}
		}
		else{
			printf("\n[ERROR] Es necesario cargar los jugadores para ordenarlos.\n");
		}
	}

    return rtn;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
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

/**
 * @brief Menu para guardar los jugadores de una confederacion
 *
 * @param path
 * @param pArrayListSeleccion
 * @param pArrayListJugador
 * @return int -1 si salio mal, 1 si todo ok
 */
int controller_menuGuardarConvocadosBinario(char* path, LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador){
	int rtn = -1;
	int opcion;

	if(path != NULL && pArrayListSeleccion != NULL && pArrayListJugador != NULL){
		if(ll_len(pArrayListJugador) > 0){
			printf("\n1.AFC"
				   "\n2.CAF"
				   "\n3.CONCACAF"
				   "\n4.CONMEBOL"
				   "\n5.UEFA");
			getInt(&opcion, "\nSeleccione que confederacion quiere guardar: \n> ", "\n[ERROR] Opcion invalida.", 1, 5);

			switch(opcion){
				case 1:
					controller_guardarConvocadosModoBinario(path, pArrayListJugador, pArrayListSeleccion, "AFC");
					break;

				case 2:
					controller_guardarConvocadosModoBinario(path, pArrayListJugador, pArrayListSeleccion, "CAF");
					break;

				case 3:
					controller_guardarConvocadosModoBinario(path, pArrayListJugador, pArrayListSeleccion, "CONCACAF");
					break;

				case 4:
					controller_guardarConvocadosModoBinario(path, pArrayListJugador, pArrayListSeleccion, "CONMEBOL");
					break;

				case 5:
					controller_guardarConvocadosModoBinario(path, pArrayListJugador, pArrayListSeleccion, "UEFA");
					break;
			}

			rtn = 1;
		}
		else{
			printf("\n[ERROR] Se deben cargar los archivos antes de guardar en binario los convocados.\n");
		}
	}

	return rtn;
}


/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_guardarConvocadosModoBinario(char* path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char* confederacionAGuardar)
{
	int rtn = -1;
	int cant;
	FILE* miArchivo;
	Jugador* jugadorAux;
	Seleccion* seleccionAux;
	char confederacion[100];
	int idSeleccionAux;
	int indiceSeleccion;

	if(path != NULL && pArrayListJugador != NULL){
		cant = ll_len(pArrayListJugador);

		if(cant > 0){
			miArchivo = fopen(path, "wb");

			if(miArchivo != NULL){
				for(int i = 0; i < cant; i++){
					jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);

					jug_getIdSeleccion(jugadorAux, &idSeleccionAux);

					if(idSeleccionAux > 0){
						indiceSeleccion = controller_buscarSeleccionPorID(pArrayListSeleccion, idSeleccionAux);

						seleccionAux = ll_get(pArrayListSeleccion, indiceSeleccion);

						selec_getConfederacion(seleccionAux, confederacion);

						if(strcmp(confederacion, confederacionAGuardar) == 0){
							fwrite(jugadorAux, sizeof(Jugador), 1, miArchivo);
						}
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
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int estadoLista;
	FILE* miArchivo;

	if(pArrayListSeleccion != NULL){
		estadoLista = ll_isEmpty(pArrayListSeleccion);

		if(estadoLista == 1){
			miArchivo = fopen(path, "r");

			if(miArchivo != NULL){
			    rtn = parser_SeleccionFromText(miArchivo, pArrayListSeleccion);

			    fclose(miArchivo);
			}
		}
		else{
			printf("\n[ERROR] La lista de selecciones ya fue cargada!");
		}
	}


    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int opcion;
	char paisAux[100];
	char confederacionAux[100];
	int indiceAEditar;
	Seleccion* seleccionAEditar;

	if(pArrayListSeleccion != NULL){
		if(ll_len(pArrayListSeleccion) > 0){
			controller_listarSelecciones(pArrayListSeleccion);

			indiceAEditar = controller_solicitarYValidarIdSeleccion(pArrayListSeleccion);
			seleccionAEditar = (Seleccion*) ll_get(pArrayListSeleccion, indiceAEditar);

			printf("\n+---------------------------+"
				   "\n|     MENU MODIFICACION     |"
				   "\n+---------------------------+"
				   "\n| 1.PAIS                    |"
				   "\n| 2.CONFEDERACION           |"
				   "\n+---------------------------+\n");

			getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 2);

			switch(opcion){
				case 1:
					getString(paisAux, 100, "\nIngrese el nuevo pais de la seleccion: ", "\nERROR");
					FirstToUppercase(paisAux, 100);
					selec_setPais(seleccionAEditar, paisAux);
					break;

				case 2:
					getString(confederacionAux, 100, "\nIngrese la nueva confederacion de la seleccion: ", "\nERROR");
					StringUpper(confederacionAux, 100);
					selec_setConfederacion(seleccionAEditar, confederacionAux);
					break;
			}

			printf("\nSe modifico con exito!");
			rtn = 1;
		}
		else{
			printf("\n[ERROR] No hay selecciones cargadas para editar.\n");
		}
	}

    return rtn;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
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
			MostrarCabeceraConfederaciones();

			for(int i = 0; i < cant; i++){
				seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);

				selec_mostrarSeleccion(seleccionAux);
			}

			MostrarPieConfederaciones();

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
 * \return int -1 si salio mal, 1 si todo ok
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int rtn = -1;
	int opcion;
	int criterioOrdenamiento;

	if(pArrayListSeleccion != NULL){
		if(ll_len(pArrayListSeleccion) > 0){
			printf("\n+---------------------------------+"
				   "\n|        ORDENAR Y LISTAR         |"
				   "\n+---------------------------------+"
				   "\n| 1.SELECCIONES POR CONFEDERACION |"
				   "\n| 1.SELECCIONES POR CONFEDERACION |"
				   "\n+---------------------------------+\n");
			getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 2);

			getInt(&criterioOrdenamiento, "\nSeleccione un criterio de ordenamiento\n 0 para descendente o 1 para ascendente: \n> ",  "\n[ERROR] Opcion invalida.", 0, 1);

			switch(opcion){
				case 1:
					rtn = ll_sort(pArrayListSeleccion, selec_OrdenarPorConfederacion, criterioOrdenamiento);
					break;
			}
		}
		else{
			printf("\n[ERROR] Es necesario cargar las selecciones para ordenarlas.\n");
		}
	}

    return rtn;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int -1 si salio mal, 1 si todo ok
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

/**
 * @brief Carga un archivo donde se guardo el ultimo id del jugador utilizado
 *
 * @param path
 * @param ultimoId
 * @return int -1 si salio mal, 1 si todo ok
 */
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

/**
 * @brief Lista los jugadores convocados en una seleccion
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
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
					controller_mostrarJugadorConSeleccion(jugadorAux, pArrayListSeleccion);
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

/**
 * @brief Lista los jugadores pero con el nombre de la seleccion a la que pertenece
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
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

				controller_mostrarJugadorConSeleccion(jugadorAux, pArrayListSeleccion);
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

/**
 * @brief Muestra un solo jugador con el nombre de su seleccion
 *
 * @param jugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int controller_mostrarJugadorConSeleccion(Jugador* jugador, LinkedList* pArrayListSeleccion){
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
		strcpy(nombreSeleccion, "No convocado");
		jug_getIdSeleccion(jugador, &idSeleccionAux);

		if(idSeleccionAux > 0){
			indiceSeleccion = controller_buscarSeleccionPorID(pArrayListSeleccion, idSeleccionAux);
			seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

			selec_getPais(seleccionAux, nombreSeleccion);
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

/**
 * @brief Muestra el menu de listados disponibles
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int controller_menuListados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int opcion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(ll_len(pArrayListJugador) > 0 && ll_len(pArrayListSeleccion) > 0){
			do{
		    	printf("\n+----------------------------+"
		    		   "\n|       MENU LISTADOS        |"
		    		   "\n+----------------------------+"
		    		   "\n| 1.TODOS LOS JUGADORES      |"
		    		   "\n| 2.TODAS LAS SELECCIONES    |"
		    		   "\n| 3.JUGADORES CONVOCADOS     |"
		     		   "\n| 4.SALIR                    |"
		    		   "\n+----------------------------+\n");
		    	getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 4);

		    	switch(opcion){
					case 1:
						rtn = controller_listarJugadores(pArrayListJugador);
						break;

					case 2:
						rtn = controller_listarSelecciones(pArrayListSeleccion);
						break;

					case 3:
						rtn = controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
						break;

					case 4:
						rtn = 1;
						break;
		    	}
			}while(opcion != 4);
		}
		else{
			printf("\n[ERROR] Es necesario cargar los jugadores y selecciones para ingresar a los listados.\n");
		}
	}

	return rtn;
}

/**
 * @brief Permite convocar jugadores a las selecciones
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
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
			if(controller_listarJugadores(pArrayListJugador) == 1){
				indiceJugador = controller_solicitarYValidarIdJugador(pArrayListJugador);

				jugadorAux = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

				jug_getIdSeleccion(jugadorAux, &idSeleccionJugador);
			}

			if(idSeleccionJugador == 0){ // SI NO ESTA CONVOCADO
				if(controller_listarSelecciones(pArrayListSeleccion) == 1){
					indiceSeleccion = controller_solicitarYValidarIdSeleccion(pArrayListSeleccion);

					seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

					selec_getConvocados(seleccionAux, &convocadosAux);
				}

				if(convocadosAux < 22){ // SI LA SELECCION NO ESTA LLENA LO AGREGO
					selec_getId(seleccionAux, &idSeleccion);

					jug_setIdSeleccion(jugadorAux, idSeleccion);

					convocadosAux++;
					selec_setConvocados(seleccionAux, convocadosAux);

					printf("\nJugador convocado con exito!\n");

					rtn = 1;
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
	}

	return rtn;
}

/**
 * @brief Permite desconvocar jugadores de sus selecciones
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
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
			if(controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion) == 1){
				indiceJugador = controller_solicitarYValidarIdJugador(pArrayListJugador);

				jugadorAux = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

				jug_getIdSeleccion(jugadorAux, &idSeleccionJugador);
			}

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
				rtn = 1;
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

/**
 * @brief Muestra el menu de las opciones de convocados
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int controller_menuConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int opcion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
    	printf("\n+----------------------------+"
    		   "\n|      MENU CONVOCADOS       |"
    		   "\n+----------------------------+"
    		   "\n| 1.CONVOCAR                 |"
    		   "\n| 2.QUITAR DE LA SELECCION   |"
      		   "\n| 3.SALIR                    |"
    		   "\n+----------------------------+\n");
    	getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 3);

    	switch(opcion){
			case 1:
				rtn = controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion);
				break;

			case 2:
				rtn = controller_quitarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
				break;
    	}
	}

	return rtn;
}

/**
 * @brief Permite buscar el indice de un id en la linkedlist
 *
 * @param pArrayListJugador
 * @param idIngresado
 * @return int indice donde se encontro el id ingresado
 */
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

/**
 * @brief Permite pedir un id para buscar
 *
 * @param pArrayListJugador
 * @return int indice donde se encontro el id ingresado
 */
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

/**
 * @brief Permite buscar el indice de un id en la linkedlist
 *
 * @param pArrayListSeleccion
 * @param idIngresado
 * @return int indice donde se encontro el id ingresado
 */
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

/**
 * @brief Permite pedir un id para buscar
 *
 * @param pArrayListSeleccion
 * @return int indice donde se encontro el id ingresado
 */
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

/**
 * @brief Muestra el menu de ordenamientos disponibles y permite elegir que se desea hacer
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int controller_menuOrdenamientos(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int rtn = -1;
	int opcion;
    LinkedList* listaJugadoresAux = ll_newLinkedList();
    LinkedList* listaSeleccionesAux = ll_newLinkedList();

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && listaJugadoresAux != NULL && listaSeleccionesAux != NULL){
		if(ll_len(pArrayListJugador) > 0 && ll_len(pArrayListSeleccion) > 0){

			listaJugadoresAux = ll_clone(pArrayListJugador);
			listaSeleccionesAux = ll_clone(pArrayListSeleccion);

			do{
		    	printf("\n+----------------+"
		    		   "\n|    ORDENAR     |"
		    		   "\n+----------------+"
		    		   "\n| 1.JUGADORES    |"
		    		   "\n| 2.SELECCIONES  |"
		    		   "\n| 3.SALIR        |"
		    		   "\n+----------------+\n");
		    	getInt(&opcion, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 3);

		    	switch(opcion){
					case 1:
						if(controller_ordenarJugadores(listaJugadoresAux) == 1){
							controller_listarJugadoresConSelecciones(listaJugadoresAux, listaSeleccionesAux);
						}

						break;

					case 2:
						if(controller_ordenarSelecciones(listaSeleccionesAux) == 1){
							controller_listarSelecciones(listaSeleccionesAux);
						}

						break;
		    	}
			}while(opcion != 3);

		    ll_deleteLinkedList(listaJugadoresAux);
		    ll_deleteLinkedList(listaSeleccionesAux);

			rtn = 1;
		}
		else{
			printf("\n[ERROR] Es necesario cargar los jugadores y selecciones para ordenar.\n");
		}


	}

    return rtn;
}











