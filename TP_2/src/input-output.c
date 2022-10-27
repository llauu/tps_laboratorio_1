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
			if(string[i] != '.' && string[i] != ' ' && (string[i] < 'A' || string[i] > 'Z' ) && (string[i] < 'a' || string[i] > 'z' )){
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
			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%[^\n]", buffer); // El %[^\n] marca que va a leer hasta q detecte un salto de linea

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
		for(int i = 0; i < size; i++){
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


// SALIDAS --------------------------------------------------------------------------
void MostrarMenuDatosJugs(void){
	printf("\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+"
		   "\n|  ID  | NOMBRE               | POSICION      | N° CAMISETA | SUELDO       | CONFEDERACION | AÑOS DE CONTRATO |"
		   "\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+");
}

void MostrarPieDatosJugs(void){
	printf("\n+------+----------------------+---------------+-------------+--------------+---------------+------------------+\n");
}

void MostrarMenuDatosConfs(void){
	printf("\n"
		   "\n+-----+------------+--------------------------------+--------------+"
		   "\n| ID  | NOMBRE     | REGION                         | AÑO CREACION |"
		   "\n+-----+------------+--------------------------------+--------------+");
}

void MostrarPieDatosConfs(void){
	printf("\n+-----+------------+--------------------------------+--------------+\n");
}

void MostrarMenuPrincipal(void){
	printf("\n+---------------------------+"
		   "\n|      MENU PRINCIPAL       |"
		   "\n+---------------------------+"
		   "\n| 1.Menu de jugadores       |"
		   "\n| 2.Menu de confederaciones |"
		   "\n| 3.Salir                   |"
		   "\n+---------------------------+\n");
}

void MostrarMenuJugadores(void){
	printf("\n+---------------------------+"
		   "\n|      MENU JUGADORES       |"
		   "\n+---------------------------+"
		   "\n| 1.Alta jugador            |"
		   "\n| 2.Baja jugador            |"
		   "\n| 3.Modificar jugador       |"
		   "\n| 4.Informes                |"
	       "\n| 5.Salir                   |"
		   "\n+---------------------------+\n");
}

void MostrarMenuConfederaciones(void){
	printf("\n+---------------------------+"
		   "\n|   MENU CONFEDERACIONES    |"
		   "\n+---------------------------+"
		   "\n| 1.Alta confederacion      |"
		   "\n| 2.Baja confederacion      |"
		   "\n| 3.Modificar confederacion |"
		   "\n| 4.Salir                   |"
		   "\n+---------------------------+\n");
}

void MostrarMenuBaja(void){
	printf("\n+--------------+"
		   "\n| MENU DE BAJA |"
		   "\n+--------------+");
}

void MostrarMenuModificacion(void){
	printf("\n+----------------------+"
		   "\n| MENU DE MODIFICACION |"
		   "\n+----------------------+");
}

void MostrarBajaExitosa(void){
	printf("\n+---------------------------+"
		   "\n| BAJA REALIZADA CON EXITO! |"
		   "\n+---------------------------+\n");
}

void MostrarModificacionExitosa(void){
	printf("\n+-----------------------------------+"
		   "\n| MODIFICACION REALIZADA CON EXITO! |"
		   "\n+-----------------------------------+\n");
}

void MostrarMenuModificacionJugs(void){
	printf("\n+---------------------------+"
		   "\n|     MODIFICAR JUGADOR     |"
		   "\n+---------------------------+"
		   "\n| 1.Nombre                  |"
		   "\n| 2.Posicion                |"
		   "\n| 3.Numero de camiseta      |"
		   "\n| 4.Salario                 |"
		   "\n| 5.Confederacion           |"
		   "\n| 6.Años de contrato        |"
		   "\n+---------------------------+\n");
}

void MostrarMenuModificacionConfs(void){
	printf("\n+---------------------------+"
		   "\n|  MODIFICAR CONFEDERACION  |"
		   "\n+---------------------------+"
		   "\n| 1.Nombre                  |"
		   "\n| 2.Region                  |"
		   "\n| 3.Año de creacion         |"
		   "\n+---------------------------+\n");
}

void MostrarMenuInformes(void){
	printf("\n+--------------------------------------+"
		   "\n|          INFORMES JUGADOR            |"
		   "\n+--------------------------------------+"
		   "\n| 1.Listado de los jugadores ordenados |"
		   "\n|   alfabeticamente por nombre de      |"
		   "\n|   confederacion y nombre de jugador. |"
		   "\n|                                      |"
		   "\n| 2.Listado de confederaciones con sus |"
		   "\n|   jugadores.                         |"
		   "\n|                                      |"
		   "\n| 3.Total y promedio de todos los      |"
		   "\n|   salarios y cuantos jugadores       |"
		   "\n|   cobran mas del salario promedio.   |"
		   "\n|                                      |"
		   "\n| 4.Informar la confederacion con      |"
		   "\n|   mayor cantidad de años de          |"
		   "\n|   contratos total.                   |"
		   "\n|                                      |"
		   "\n| 5.Informar porcentaje de jugadores   |"
		   "\n|   por cada confederacion.            |"
		   "\n|                                      |"
		   "\n| 6.Informar cual es la region con     |"
		   "\n|   mas jugadores y el listado de      |"
		   "\n|   los mismos.                        |"
		   "\n+--------------------------------------+\n");
}

















