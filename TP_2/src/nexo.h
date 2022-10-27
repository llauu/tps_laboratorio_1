
#ifndef NEXO_H_
#define NEXO_H_
#include "confederaciones.h"
#include "jugadores.h"


int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);
int PedirConfJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones);
sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones);
int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int EnlazarJugadorConConf(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador);
void MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones);
int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int ModificarJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones,  sConfederacionAux confederacionesAux[]);

int MostrarJugadoresDeUnaConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, int posConf);
int MostrarJugadoresPorConfOrdenados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);
int MostrarJugadoresPorConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);

int CalcularAniosContratoPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);
int BuscarIndiceConfMasAniosDeContrato(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);

int ContarJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);

int CalcularPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);
int MostrarPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);

int BuscarIndiceRegionMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);
int MostrarRegionConMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


#endif /* NEXO_H_ */
