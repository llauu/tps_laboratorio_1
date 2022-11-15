#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "input-output.h"

/*\
 * 	Trabajo Practico 3
 *	Alumno: Lautaro Monserrat
 *	Div C 2022
\*/

int main()
{
    int option;
	int confirmoSalir;
	int realizoCambios;
	int flagGuardoCambios;
    int rtnJugadores;
    int rtnSelecciones;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    if(listaJugadores != NULL && listaSelecciones != NULL){
        do{
        	MostrarMenuPrincipal();
        	getInt(&option, "\nSeleccione una opcion: \n> ", "\n[ERROR] Opcion invalida.", 1, 11);

            switch(option)
            {
                case 1: // CARGA DE ARCHIVOS:
                	rtnJugadores = controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores);
                	rtnSelecciones = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);

                	if(rtnJugadores == 1 && rtnSelecciones == 1){
                		printf("\nArchivos cargados con exito!\n");
                	}
                	else{
                		printf("\n[ERROR] No se pudieron cargar los archivos...\n");
                	}

                    break;

                case 2: // ALTA DE JUGADOR:
                	realizoCambios = controller_agregarJugador(listaJugadores);
                    break;

                case 3: // MODIFICACIÓN DE JUGADOR:
                	realizoCambios = controller_editarJugador(listaJugadores);
                    break;

                case 4: // BAJA DE JUGADOR:
                	realizoCambios = controller_removerJugador(listaJugadores, listaSelecciones);
                    break;

                case 5: // LISTADOS:
                	controller_menuListados(listaJugadores, listaSelecciones);
                    break;

                case 6: // CONVOCAR JUGADORES:
                	realizoCambios = controller_menuConvocados(listaJugadores, listaSelecciones);
                    break;

                case 7: // ORDENAR Y LISTAR:
                	controller_menuOrdenamientos(listaJugadores, listaSelecciones);
                    break;

                case 8: // GENERAR ARCHIVO BINARIO:
                	rtnJugadores = controller_menuGuardarConvocadosBinario("convocados.bin", listaSelecciones, listaJugadores);

                	if(rtnJugadores == 1){
                		printf("\nArchivos guardados con exito!\n");
                	}
                	else{
                		printf("\n[ERROR] No se pudieron guardar los archivos...\n");
                	}

                    break;

                case 9: // CARGAR ARCHIVO BINARIO:
                	rtnJugadores = controller_cargarConvocadosDesdeBinario("convocados.bin", listaJugadores);

                	if(rtnJugadores == -1){
                		printf("\n[ERROR] No se pudieron cargar los archivos...\n");
                	}

                    break;

                case 10: // GUARDAR ARCHIVOS .CSV:
                	rtnJugadores = controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
                	rtnSelecciones = controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);

                	if(rtnJugadores == 1 && rtnSelecciones == 1){
                		printf("\nArchivos guardados con exito!\n");
                		flagGuardoCambios = 1;
                	}
                	else{
                		printf("\n[ERROR] No se pudieron guardar los archivos...\n");
                	}

                    break;

                case 11: // SALIR:
                	if(flagGuardoCambios == 0 && realizoCambios == 1){
                		printf("\n[CUIDADO] Se realizaron cambios y no fueron guardados, si sale del programa se perderan los datos no guardados.");
                	}
                	confirmoSalir = ConfirmarSalida();

                	break;
            }
        }while(option != 11 || confirmoSalir != 1);
    }

    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaSelecciones);

    return 0;
}

