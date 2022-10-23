#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "input.h"


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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		retorno = 0;

		do{
			printf("\n┌───────────────────────────┐"
				   "\n│   MENU CONFEDERACIONES    │"
				   "\n├───────────────────────────┤"
				   "\n│ 1.Alta confederacion      │"
				   "\n│ 2.Baja confederacion      │"
				   "\n│ 3.Modificar confederacion │"
				   "\n│ 4.Salir                   │"
				   "\n└───────────────────────────┘\n");

			getInt(&opcion, "\nSeleccione una opcion: \n» ", "\n[ERROR] Opcion invalida.", 1, 4);

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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int PedirNombreConfederacion(char nombre[]){
	int retorno = -1;

	if(nombre != NULL){
		getString(nombre, 11, "\nIngrese el nombre de la confederacion: \n» ", "\n[ERROR] Superaste el limite de caracteres.");
		StringUpper(nombre, strlen(nombre));

		retorno = 0;
	}

	return retorno;
}


int PedirRegionConfederacion(char region[]){
	int retorno = -1;

	if(region != NULL){
		getString(region, 31, "\nIngrese la region de la confederacion: \n» ", "\n[ERROR] Superaste el limite de caracteres.");
		StringUpper(region, strlen(region));

		retorno = 0;
	}

	return retorno;
}


int PedirAnioConfederacion(int* anioCreada){
	int retorno = -1;
	int anioTmp;

	if(anioCreada != NULL){
		getInt(&anioTmp, "\nIngrese el año de creacion de la confederacion: \n» ", "\n[ERROR] Año no valido.", 1, 2022);
		*anioCreada = anioTmp;

		retorno = 0;
	}

	return retorno;
}


sConfederacion CargarConfederacion(void){
	sConfederacion auxConf;

	PedirNombreConfederacion(auxConf.nombre);
	PedirRegionConfederacion(auxConf.region);
	PedirAnioConfederacion(&auxConf.anioCreacion);

	return auxConf;
}


int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones){
	int retorno = -1;
	int espacioLibre;
	sConfederacion auxConfederacion;

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int OrdenarConfederacionesPorID(sConfederacion confederaciones[], int tamConfederaciones){
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	sConfederacion confederacionTmp;
    int nuevoTam;

    if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
    	nuevoTam = tamConfederaciones - 1;

    	do{
    		flagSwap = 0;

    		for(i = 0; i < nuevoTam; i++){
    			if(confederaciones[i].isEmpty == OCUPADO && confederaciones[i+1].isEmpty == OCUPADO){
        			contador++;
        			if(confederaciones[i].id > confederaciones[i+1].id){
        				flagSwap = 1;

        				confederacionTmp = confederaciones[i];
        				confederaciones[i] = confederaciones[i+1];
        				confederaciones[i+1] = confederacionTmp;
        			}
    			}
    		}
    		nuevoTam--;
    	}
    	while(flagSwap);
    	retorno = contador;
    }

	return retorno;
}


void MostrarMenuDatosConfs(void){
	printf("\n┌─────┬────────────┬────────────────────────────────┬──────────────┐"
		   "\n│ ID  │ NOMBRE     │ REGION                         │ AÑO CREACION │"
		   "\n├─────┼────────────┼────────────────────────────────┼──────────────┤");
}


void MostrarConfederacion(sConfederacion confederaciones){
	printf("\n│ %-4d│ %-10s │ %-30s │ %-12d │", confederaciones.id, confederaciones.nombre, confederaciones.region, confederaciones.anioCreacion);
}


int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones){
	int flagHayConfederacion = -1;

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			OrdenarConfederacionesPorID(confederaciones, tamConfederaciones);
			MostrarMenuDatosConfs();
			for(int i = 0; i < tamConfederaciones; i++){
				if(confederaciones[i].isEmpty == OCUPADO){
					MostrarConfederacion(confederaciones[i]);
					flagHayConfederacion = 0;
				}
			}
			printf("\n└─────┴────────────┴────────────────────────────────┴──────────────┘\n");
		}
	}

	return flagHayConfederacion;
}


int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id){
	int retorno = -1;

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			MostrarConfsDisponibles(confederaciones, tamConfederaciones);

			do{
				getInt(&idABajar, "\nIngrese el ID de la confederacion que quiere dar de baja: \n» ", "\n[ERROR] ID no valido.", 100, 10000);

				indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, idABajar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idABajar);
				}
			}while(indiceID == -1);

			confederaciones[indiceID].isEmpty = LIBRE;

			printf("\n┌───────────────────────────────────────┐"
				   "\n│ CONFEDERACION DADA DE BAJA CON EXITO! │"
				   "\n└───────────────────────────────────────┘\n");

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

	if(ChequearValidezArrayConf(confederaciones, tamConfederaciones) == 0){
		if(ChequearConfCargada(confederaciones, tamConfederaciones) == 0){
			MostrarConfsDisponibles(confederaciones, tamConfederaciones);

			do{
				getInt(&idAModificar, "\nIngrese el ID de la confederacion que quiere modificar: \n» ", "\n[ERROR] ID no valido.", 100, 10000);

				indiceID = BuscarConfPorID(confederaciones, tamConfederaciones, idAModificar);

				if(indiceID == -1){
					printf("\n[ERROR] El ID %d no existe.", idAModificar);
				}
			}while(indiceID == -1);

			printf("\n┌───────────────────────────┐"
				   "\n│  MODIFICAR CONFEDERACION  │"
				   "\n├───────────────────────────┤"
				   "\n│ 1.Nombre                  │"
				   "\n│ 2.Region                  │"
				   "\n│ 3.Año de creacion         │"
				   "\n└───────────────────────────┘\n");

			getInt(&opcionModificar, "\nIngrese el numero de lo que quiere modificar: \n» ", "\n[ERROR] Opcion invalida.", 1, 3);

			switch(opcionModificar){
				case 1:
					PedirNombreConfederacion(confederaciones[indiceID].nombre);
					break;

				case 2:
					PedirRegionConfederacion(confederaciones[indiceID].region);
					break;

				case 3:
					PedirAnioConfederacion(&confederaciones[indiceID].anioCreacion);
					break;
			}

			printf("\n┌───────────────────────────────────┐"
				   "\n│ MODIFICACION REALIZADA CON EXITO! │"
				   "\n└───────────────────────────────────┘\n");

			retorno = 0;
		}
		else{
			printf("\n[ERROR] No hay confederaciones cargadas.\n");
		}
	}

	return retorno;
}
























