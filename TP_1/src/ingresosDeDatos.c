#include <stdio.h>
#include <stdlib.h>
#include "ingresosDeDatos.h"


int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max){
	int retorno;
	int buffer;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%d", &buffer);

			if(buffer >= min && buffer <= max){
				*pResultado = buffer;
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}


int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max){
	int retorno;
	float buffer;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%f", &buffer);

			if(buffer >= min && buffer <= max){
				*pResultado = buffer;
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}


