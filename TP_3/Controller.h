#include "Jugador.h"

int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayListJugador);
int controller_cargarConvocadosDesdeBinario(char* path, LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path, LinkedList* pArrayListJugador);
int controller_guardarConvocadosModoBinario(char* path, LinkedList* pArrayListJugador);

int controller_cargarSeleccionesDesdeTexto(char* path, LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path, LinkedList* pArrayListSeleccion);

// FUNCIONES Q HICE YO
int controller_cargarUltimoIDJugador(char* path, int* ultimoId);

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_listarJugadoresConSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int mostrarJugadorConSeleccion(Jugador* jugador, LinkedList* pArrayListSeleccion);

int controller_menuListados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_buscarJugadorPorID(LinkedList* pArrayListJugador, int idIngresado);
int controller_solicitarYValidarIdJugador(LinkedList* pArrayListJugador);

int controller_buscarSeleccionPorID(LinkedList* pArrayListSeleccion, int idIngresado);
int controller_solicitarYValidarIdSeleccion(LinkedList* pArrayListSeleccion);

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_quitarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_menuConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);





