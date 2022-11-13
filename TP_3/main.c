#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "input-output.h"


int main()
{
    int option = 0;
    int rtnJugadores;
    int rtnSelecciones;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    	printf("\n+---------------------------+"
    		   "\n|      MENU PRINCIPAL       |"
    		   "\n+---------------------------+"
    		   "\n| 1.CARGA DE ARCHIVOS       |"
    		   "\n| 2.ALTA DE JUGADOR         |"
    		   "\n| 3.MODIFICACION DE JUGADOR |"
     		   "\n| 4.BAJA DE JUGADOR         |"
     		   "\n| 5.LISTADOS                |"
     		   "\n| 6.CONVOCAR JUGADORES      |"
     		   "\n| 7.ORDENAR Y LISTAR        |"
     		   "\n| 8.GENERAR ARCHIVO BINARIO |"
     		   "\n| 9.CARGAR ARCHIVO BINARIO  |"
     		   "\n| 10.GUARDAR ARCHIVOS .CSV  |"
     		   "\n| 11.SALIR                  |"
    		   "\n+---------------------------+\n");

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
            	controller_agregarJugador(listaJugadores);
                break;

            case 3: // MODIFICACIÓN DE JUGADOR:
            	controller_editarJugador(listaJugadores);
                break;

            case 4: // BAJA DE JUGADOR:
            	controller_removerJugador(listaJugadores, listaSelecciones);
                break;

            case 5: // LISTADOS:
            	controller_menuListados(listaJugadores, listaSelecciones);
                break;

            case 6: // CONVOCAR JUGADORES:
            	controller_menuConvocados(listaJugadores, listaSelecciones);
                break;

            case 7: // ORDENAR Y LISTAR:
            	controller_listarJugadoresConSelecciones(listaJugadores, listaSelecciones);
                break;

            case 8: // GENERAR ARCHIVO BINARIO:
            	rtnJugadores = controller_guardarConvocadosModoBinario("convocados.bin", listaJugadores);

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
            	}
            	else{
            		printf("\n[ERROR] No se pudieron guardar los archivos...\n");
            	}

                break;

            case 11: // SALIR:
            	break;
        }
    }while(option != 11);

    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaSelecciones);

    return 0;
}

