
#ifndef NEXO_H_
#define NEXO_H_
#include "confederaciones.h"
#include "jugadores.h"


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @return
 */
int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param idConfDelJugador
 * @return
 */
int EnlazarJugadorConConf(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador);


/**
 * @brief
 *
 * @param jugador
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int ModificarJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @return
 */
int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones,  sConfederacionAux confederacionesAux[]);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @param posConf
 * @return
 */
int MostrarJugadoresDeUnaConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, int posConf);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MostrarJugadoresPorConfOrdenados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param jugadores
 * @param tamJugadores
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MostrarJugadoresPorConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int CalcularAniosContratoPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int BuscarIndiceConfMasAniosDeContrato(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int ContarJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int CalcularPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int MostrarPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int BuscarIndiceRegionMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int MostrarConfMayorCantContratos(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @param jugadores
 * @param tamJugadores
 * @return
 */
int MostrarRegionConMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


#endif
