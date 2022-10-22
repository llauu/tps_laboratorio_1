#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mylib.h"
#include "confederaciones.h"


static int GenerarID(void);
static int GenerarID(void){
	static int idIncremental = 100;

	return idIncremental++;
}


int ChequearValidezArrayConf(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;

	if(confederaciones != NULL && tamConfederaciones > 0){
		retorno = 0;
	}

	return retorno;
}


int InicializarConfs(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		retorno = 0;

		for(int i = 0; i < tamConfederaciones; i++){
			confederaciones[i].isEmpty = LIBRE;
		}
	}

	return retorno;
}


int MenuConfederacion(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int opcion;
	int confirmoSalir;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		retorno = 0;

		do{
			printf("\n============================="
				   "\n|   MENU CONFEDERACIONES    |"
				   "\n|---------------------------|"
				   "\n| 1.Alta confederacion      |"
				   "\n| 2.Baja confederacion      |"
				   "\n| 3.Modificar confederacion |"
		           "\n| 4.Salir                   |"
				   "\n=============================\n");

			getInt(&opcion, "\nSeleccione una opcion: ", "\n[ERROR] Opcion invalida.", 1, 4);

			switch(opcion){
				case 1:
					AltaConfederacion(confederaciones, tamConfederaciones);
					break;

				case 2:
					BajaConfederacion(confederaciones, tamConfederaciones);
					break;

				case 3:
					ModificarConfederacion(confederaciones, tamConfederaciones);
					break;

				case 4:
					confirmoSalir = ConfirmarSalida();
					break;
			}

		}while(opcion != 4 || confirmoSalir != 1);
	}

	return retorno;
}


int ObtenerConfLibre(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


sConfederacion CargarConfederacion(void){
	sConfederacion auxConf;

	getString(auxConf.nombre, 11, "\nIngrese el nombre de la confederacion: ", "\n[ERROR] Superaste el limite de caracteres.");
	StringUpper(auxConf.nombre, strlen(auxConf.nombre));

	getString(auxConf.region, 31, "\nIngrese la region de la confederacion: ", "\n[ERROR] Superaste el limite de caracteres.");
	StringUpper(auxConf.region, strlen(auxConf.region));

	getInt(&auxConf.anioCreacion, "\nIngrese el año de creacion de la confederacion: ", "\n[ERROR] Año no valido.", 1, 2022);

	return auxConf;
}


int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int espacioLibre;
	int arrayValido;
	sConfederacion auxConfederacion;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		espacioLibre = ObtenerConfLibre(confederaciones, tamConfederaciones);

		if(espacioLibre != -1){
			auxConfederacion = CargarConfederacion();

			auxConfederacion.id = GenerarID();
			auxConfederacion.isEmpty = OCUPADO;

			confederaciones[espacioLibre] = auxConfederacion;

			retorno = 0;
		}
		else{
			printf("[ERROR] Alcanzaste el maximo de confederaciones cargadas.\n");
		}
	}

	return retorno;
}


int ChequearConfCargada(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


void MostrarMenuDatos(void){
	printf("\n====================================================================");
	printf("\n| ID  | NOMBRE     | REGION                         | AÑO CREACION |");
	printf("\n--------------------------------------------------------------------");
}


void MostrarConfederacion(sConfederacion confederaciones){
	printf("\n| %-4d| %-10s | %-30s | %-12d |", confederaciones.id, confederaciones.nombre, confederaciones.region, confederaciones.anioCreacion);
}


int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones){
	int flagHayConfederacion = -1;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			MostrarMenuDatos();
			for(int i = 0; i < tamConfederaciones; i++){
				if(confederaciones[i].isEmpty == OCUPADO){
					MostrarConfederacion(confederaciones[i]);
					flagHayConfederacion = 0;
				}
			}
			printf("\n====================================================================\n");
		}
	}

	return flagHayConfederacion;
}


int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id){
	int retorno = -1;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].id == id && confederaciones[i].isEmpty == OCUPADO){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int BajaConfederacion(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int idABajar;
	int indiceID;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			MostrarConfsDisponibles(confederaciones, tamConfederaciones);

			do{
				getInt(&idABajar, "\nIngrese el ID de la confederacion que quiere dar de baja: ", "\n[ERROR] ID no valido.", 100, 10000);

				indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, idABajar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idABajar);
				}
			}while(indiceID == -1);

			confederaciones[indiceID].isEmpty = LIBRE;

			printf("\nConfederacion con |ID: %d| dada de baja exitosamente!\n", idABajar);

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay confederaciones cargadas.\n");
		}
	}

	return retorno;
}


int ModificarConfederacion(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int idAModificar;
	int indiceID;
	int opcionModificar;
	int arrayValido;

	arrayValido = ChequearValidezArrayConf(confederaciones, tamConfederaciones);

	if(arrayValido == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			MostrarConfsDisponibles(confederaciones, tamConfederaciones);

			do{
				getInt(&idAModificar, "\nIngrese el ID de la confederacion que quiere modificar: ", "\n[ERROR] ID no valido.", 100, 10000);

				indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, idAModificar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idAModificar);
				}
			}while(indiceID == -1);

			printf("\n============================="
				   "\n|  MODIFICAR CONFEDERACION  |"
				   "\n|---------------------------|"
				   "\n| 1.Nombre                  |"
				   "\n| 2.Region                  |"
				   "\n| 3.Año de creacion         |"
				   "\n=============================\n");

			getInt(&opcionModificar, "\nIngrese el numero de lo que quiere modificar: ", "\n[ERROR] Opcion invalida.", 1, 3);

			switch(opcionModificar){
				case 1://nombre
					getString(confederaciones[indiceID].nombre, 11, "\nIngrese el nombre de la confederacion: ", "\n[ERROR] Superaste el limite de caracteres.");
					StringUpper(confederaciones[indiceID].nombre, strlen(confederaciones[indiceID].nombre));
					break;

				case 2://region
					getString(confederaciones[indiceID].region, 31, "\nIngrese la region de la confederacion: ", "\n[ERROR] Superaste el limite de caracteres.");
					StringUpper(confederaciones[indiceID].region, strlen(confederaciones[indiceID].region));
					break;

				case 3://anio
					getInt(&confederaciones[indiceID].anioCreacion, "\nIngrese el año de creacion de la confederacion: ", "\n[ERROR] Año no valido.", 1, 2022);
					break;
			}

			printf("Modificacion realizada con exito!\n");
			printf("\nTabla actualizada: ");
			MostrarConfsDisponibles(confederaciones, tamConfederaciones);

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay confederaciones cargadas.\n");
		}
	}

	return retorno;
}


























