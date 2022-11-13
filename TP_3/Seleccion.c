#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "input-output.h"

/**
 * @brief Constructor de seleccion
 *
 * @return Seleccion*
 */
Seleccion* selec_new(){
	Seleccion* miSeleccion;

	miSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return miSeleccion;
}

/**
 * @brief Constructor de seleccion parametrizado
 *
 * @param idStr char*
 * @param paisStr char*
 * @param confederacionStr char*
 * @param convocadosStr char*
 * @return Seleccion*
 */
Seleccion* selec_newParametros(char* idStr, char* paisStr, char* confederacionStr, char* convocadosStr){
	Seleccion* miSeleccion;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){
		miSeleccion = selec_new();

		miSeleccion->id = atoi(idStr);
		strcpy(miSeleccion->pais, paisStr);
		strcpy(miSeleccion->confederacion, confederacionStr);
		miSeleccion->convocados = atoi(convocadosStr);
	}

	return miSeleccion;
}

/**
 * @brief Borra una seleccion de memoria dinamica
 *
 * @param this
 */
void selec_delete(Seleccion* this){
	if(this != NULL){
		free(this);
	}
}

/**
 * @brief getter de id de seleccion
 *
 * @param this
 * @param id
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_getId(Seleccion* this, int* id){
	int rtn = -1;

	if(this != NULL && id != NULL){
		*id = this->id;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de pais de seleccion
 *
 * @param this
 * @param pais
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_getPais(Seleccion* this, char* pais){
	int rtn = -1;

	if(this != NULL && pais != NULL){
		strcpy(pais, this->pais);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de pais de seleccion
 *
 * @param this
 * @param pais
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_setPais(Seleccion* this, char* pais){
	int rtn = -1;

	if(this != NULL && pais != NULL){
		strcpy(this->pais, pais);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de confederacion de seleccion
 *
 * @param this
 * @param confederacion
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_getConfederacion(Seleccion* this, char* confederacion){
	int rtn = -1;

	if(this != NULL && confederacion != NULL){
		strcpy(confederacion, this->confederacion);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de confederacion
 *
 * @param this
 * @param confederacion
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_setConfederacion(Seleccion* this, char* confederacion){
	int rtn = -1;

	if(this != NULL && confederacion != NULL){
		strcpy(this->confederacion, confederacion);

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief setter de convocados de seleccion
 *
 * @param this
 * @param convocados
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_setConvocados(Seleccion* this, int convocados){
	int rtn = -1;

	if(this != NULL && convocados >= 0){
		this->convocados = convocados;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief getter de convocados de seleccion
 *
 * @param this
 * @param convocados
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_getConvocados(Seleccion* this, int* convocados){
	int rtn = -1;

	if(this != NULL && convocados != NULL){
		*convocados = this->convocados;

		rtn = 1;
	}

	return rtn;
}

/**
 * @brief Permite mostrar una seleccion
 *
 * @param seleccion
 * @return int -1 si salio mal, 1 si todo ok
 */
int selec_mostrarSeleccion(Seleccion* seleccion){
	int rtn = -1;
	int idAux;
	char paisAux[100];
	char confederacionAux[100];
	int convocadosAux;

	selec_getId(seleccion, &idAux);
	selec_getPais(seleccion, paisAux);
	selec_getConfederacion(seleccion, confederacionAux);
	selec_getConvocados(seleccion, &convocadosAux);

	printf("\n| %4d | %-30s | %-25s | %-12d |", idAux, paisAux, confederacionAux, convocadosAux);

	rtn = 1;

	return rtn;
}

/**
 * @brief ordena por confederacion 2 selecciones
 *
 * @param pSeleccionUno
 * @param pSeleccionDos
 * @return 1 si se hace swap, 0 si son iguales
 */
int selec_OrdenarPorConfederacion(void* pSeleccionUno, void* pSeleccionDos){
	int rtn = -1;
	char confederacionUno[100];
	char confederacionDos[100];

	Seleccion* seleccionUno;
	Seleccion* seleccionDos;

	seleccionUno = (Seleccion*) pSeleccionUno;
	seleccionDos = (Seleccion*) pSeleccionDos;

	selec_getConfederacion(seleccionUno, confederacionUno);
	selec_getConfederacion(seleccionDos, confederacionDos);

	StringUpper(confederacionUno, 100);
	StringUpper(confederacionDos, 100);

	if(strcmp(confederacionUno, confederacionDos) > 0){
		rtn = 1;
	}
	else{
		if(strcmp(confederacionUno, confederacionDos) == 0){
			rtn = 0;
		}
	}

	return rtn;
}


