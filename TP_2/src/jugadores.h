
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

int PedirNombreJugador(char nombre[]);
int ValidarPosicionJugador(char posicion[]);
int PedirPosicionJugador(char posicion[], int size);
int PedirNumCamisetaJugador(short* numCamiseta);
int PedirSalarioJugador(float* salario);
int PedirConfJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones);
int PedirAnioContratoJugador(short* aniosContrato);

sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones);
int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int ChequearJugadorCargado(sJugador jugadores[], int tamJugadores);

int OrdenarJugadoresPorID(sJugador jugadores[], int tamJugadores);

void MostrarMenuDatosJugs(void);
int ObtenerNombreConfederacion(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador, char nombreConfederacion[]);
void MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones);
int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int BuscarJugadorPorID(sJugador jugadores[], int tamJugadores, int id);
int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int ModificarJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

#endif
