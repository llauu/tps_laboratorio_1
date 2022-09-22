#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
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


int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max){
	int retorno;
	char buffer;

	retorno = -1;

	if(pCaracter != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%c", &buffer);

			if(buffer >= min && buffer <= max){
				*pCaracter = buffer;
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}


int getString(char string[], int sizeString, char* mensaje, char* mensajeError){
	int retorno;
	char buffer[1024];

	retorno = -1;

	if(string != NULL && mensaje != NULL && mensaje != NULL && sizeString > 0){
		do{
			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%[^\n]", buffer); // El %[^\n] marca que va a leer hasta q detecte un salto de linea

			if(strlen(buffer) < sizeString){
				strcpy(string, buffer);
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}


