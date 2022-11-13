#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"


Seleccion* selec_new(){
	Seleccion* miSeleccion;

	miSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return miSeleccion;
}

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

void selec_delete(Seleccion* this){
	if(this != NULL){
		free(this);
	}
}

int selec_getId(Seleccion* this, int* id){
	int rtn = -1;

	if(this != NULL && id != NULL){
		*id = this->id;

		rtn = 1;
	}

	return rtn;
}

int selec_getPais(Seleccion* this, char* pais){
	int rtn = -1;

	if(this != NULL && pais != NULL){
		strcpy(pais, this->pais);

		rtn = 1;
	}

	return rtn;
}

int selec_getConfederacion(Seleccion* this, char* confederacion){
	int rtn = -1;

	if(this != NULL && confederacion != NULL){
		strcpy(confederacion, this->confederacion);

		rtn = 1;
	}

	return rtn;
}

int selec_setConvocados(Seleccion* this, int convocados){
	int rtn = -1;

	if(this != NULL && convocados >= 0){
		this->convocados = convocados;

		rtn = 1;
	}

	return rtn;
}

int selec_getConvocados(Seleccion* this, int* convocados){
	int rtn = -1;

	if(this != NULL && convocados != NULL){
		*convocados = this->convocados;

		rtn = 1;
	}

	return rtn;
}


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



