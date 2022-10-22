
#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "confederaciones.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}sJugador;

int ChequearValidezArrayJugs(sJugador jugadores[], int tamJugadores);
int InicializarJugadores(sJugador jugadores[], int tamJugadores);
int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int ObtenerJugadorLibre(sJugador jugadores[], int tamJugadores);
int ValidarPosicionJugador(char posicion[]);
int CargarConfEnJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones);
sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones);
int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int ChequearJugadorCargado(sJugador jugadores[], int tamJugadores);

void MostrarMenuDatosJugs(void);
void MostrarJugador(sJugador jugador);
int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores);

#endif
