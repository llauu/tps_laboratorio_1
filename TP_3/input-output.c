#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input-output.h"


// ENTRADAS - VALIDACIONES --------------------------------------------------------------------------
static int esTexto(char string[], int sizeString){
	int i = 0;
	int retorno = -1;

	if(string != NULL && sizeString > 0){
		for( ; string[i] != '\0' && i < sizeString; i++){
			if(string[i] != '.' && string[i] != ' ' && (string[i] < 'A' || string[i] > 'Z' ) && (string[i] < 'a' || string[i] > 'z' ) && (string[i] > '9' || string[i] < '0')){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

static int esNumerica(char* string){
    int retorno = 1;
    int i = 0;

    if(string[0] == '-'){
        i = 1;
    }

    for( ; string[i] != '\0'; i++){
        if(string[i] == '.')
        {
            if((string[i] > '9' || string[i] < '0') && (string[i] != '.')){
                retorno = 0;
                break;
            }
        } else
            {
                if((string[i] > '9' || string[i] < '0') && (string[i] != '.')){
                    retorno = 0;
                    break;
             }
        }

    }

    return retorno;
}

int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max){
	int retorno;
	int numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumerica(buffer)){
				numero = atoi(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
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
	float numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumerica(buffer)){
				numero = atof(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
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
			PedirTexto(buffer, mensaje);

			// Este while es para que se valide si se ingreso un enter y se dejo el campo vacio, en ese caso, que no le permita continuar hasta que ingrese un texto valido
			while(buffer[0] == '\0'){
				printf("%s", mensajeError);

				PedirTexto(buffer, mensaje);
			}


			if(strlen(buffer) < sizeString){
				if(esTexto(buffer, sizeString) != 0){
					strcpy(string, buffer);
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}

		}while(retorno == -1);
	}

	return retorno;
}

int getStringNumeric(char string[], int sizeString, char* mensaje, char* mensajeError){
	int retorno;
	char buffer[1024];

	retorno = -1;

	if(string != NULL && mensaje != NULL && mensaje != NULL && sizeString > 0){
		do{
			PedirTexto(buffer, mensaje);

			if(strlen(buffer) < sizeString){
				if(esNumerica(buffer)){
					strcpy(string, buffer);
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}

		}while(retorno == -1);
	}

	return retorno;
}

int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max){
	int retorno;
	short numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumerica(buffer)){
				numero = atoi(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}

int PedirTexto(char buffer[], char* mensaje){
	int retorno = -1;

	if(buffer != NULL && mensaje != NULL){
		__fpurge(stdin);// El %[^\n] marca que va a leer hasta q detecte un salto de linea
		printf("%s", mensaje);

		scanf("%[^\n]", buffer);

		retorno = 0;
	}

	return retorno;
}

int StringUpper(char string[], int size){
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0){
		for(int i = 0; i < size; i++){
			string[i] = toupper(string[i]);
		}

		retorno = 0;
	}

	return retorno;
}

int StringLower(char string[], int size){
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0){
		for(int i = 0; i < size; i++){
			string[i] = tolower(string[i]);
		}

		retorno = 0;
	}

	return retorno;
}

int FirstToUppercase(char string[], int size){
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0){
		StringLower(string, size);

		string[0] = toupper(string[0]);
		for(int i = 0; i < size || string[i] == '\0' ; i++){
			if(string[i] == ' '){
				string[i+1] = toupper(string[i+1]);
			}
		}

		retorno = 0;
	}

	return retorno;
}

int ConfirmarSalida(void){
	int confirmo = 0;
	char confirmacion[5];

	getString(confirmacion, 5, "\nSeguro que desea salir? (Escriba 'si' para confirmar)\n> ", "\n[ERROR] Opcion invalida.");

	if(strcasecmp(confirmacion, "si") == 0){
		confirmo = 1;
	}

	return confirmo;
}


//========== Salidas =========================================================================================


void MostrarCabeceraJugadores(void){
	printf("\n+------+--------------------------------+---------------------------+----------------------+------+------+"
		   "\n|  ID  |            NOMBRE              |         POSICION          |     NACIONALIDAD     | EDAD | ID S |"
		   "\n+------+--------------------------------+---------------------------+----------------------+------+------+");
}

void MostrarPieJugadores(void){
	printf("\n+------+--------------------------------+---------------------------+----------------------+------+------+\n");
}


void MostrarCabeceraConSeleccion(void){
	printf("\n+------+--------------------------------+---------------------------+----------------------+------+----------------------+"
		   "\n|  ID  |            NOMBRE              |         POSICION          |     NACIONALIDAD     | EDAD |      SELECCION       |"
		   "\n+------+--------------------------------+---------------------------+----------------------+------+----------------------+");
}

void MostrarPieConSeleccion(void){
	printf("\n+------+--------------------------------+---------------------------+----------------------+------+----------------------+\n");
}








