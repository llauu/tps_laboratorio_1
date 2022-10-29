
#ifndef NEXO_H_
#define NEXO_H_
#include "confederaciones.h"
#include "jugadores.h"


/**
 * @brief Menu principal del ABM de los jugadores, y de los informes
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio de array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio de array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MenuJugadores(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);


/**
 * @brief Permite la carga de todos los datos de un jugador de tipo sJugador
 *
 * @param confederaciones Array de tipo sConfederacion con las confederaciones disponibles
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return Una estructura de tipo sJugador con sus datos cargados
 */
sJugador CargarJugador(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite dar de alta un jugador de tipo sJugador y agregarlo a un array del mismo tipi
 *
 * @param jugadores Array de tipo sJugador donde se va a cargar el jugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion con las confederaciones disponibles
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si salio todo bien, -1 si hubo error
 */
int AltaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Recorre un array de tipo sConfederacion hasta encontrar una confederacion con
 * el mismo ID ingresado en la carga del jugador
 *
 * @param confederaciones Array de tipo sConfederacion a recorrer
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param idConfDelJugador ID de la confederacion elegida a la hora de cargar el jugador
 * @return Indice donde se encontro coincidencia de IDs, -1 si no se encontro
 */
int EnlazarJugadorConConf(sConfederacion confederaciones[], int tamConfederaciones, int idConfDelJugador);


/**
 * @brief Permite mostrar un jugador de tipo sJugador con todos sus datos
 *
 * @param jugador Jugador a mostrar
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MostrarJugador(sJugador jugador, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Recorre un array de tipo sJugador, mostrando solo los que estan OCUPADOS
 *
 * @param jugadores Array de tipo sJugador a mostrar
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si hay al menos un jugador cargado, -1 si no hay ninguno
 */
int MostrarJugadoresCargados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite ingresar un ID de un jugador, y verifica si ese ID existe
 *
 * @param jugadores Array de tipo sJugador donde se va a buscar el ID
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return Indice donde se encontro el ID ingresado, -1 si no se encontro
 */
int SolicitarYValidarIDJugador(sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite dar de baja un jugador cargado en un array de tipo sJugador
 *
 * @param jugadores Array de tipo sJugador donde se va a dar de baja el jugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si salio todo bien, -1 si hubo error
 */
int BajaJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite modificar el dato de un jugador cargado en un array de tipo sJugador
 *
 * @param jugadores Array de tipo sJugador donde se va a modificar el jugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si salio todo bien, -1 si hubo error
 */
int ModificarJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite mostrar un menu de informes y seleccionar uno para que se muestre
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux, necesario para realizar los informes
 * @return 0 si salio todo bien, -1 si hubo error
 */
int InformesJugador(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones,  sConfederacionAux confederacionesAux[]);


/**
 * @brief Permite mostrar todos los jugadores de una misma confederacion
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param posConf Posicion de la confederacion que se quiere mostrar
 * @return Contador de la cantidad de jugadores cargados en esa confederacion
 */
int MostrarJugadoresDeUnaConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones, int posConf);


/**
 * @brief Muestra los jugadores cargados de cada confederacion ordenadamente
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return  0 si salio todo bien, -1 si hubo error
 */
int MostrarJugadoresPorConfOrdenados(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Muestra los jugadores cargados en cada confederacion, mostrando primero
 * la confederacion con todos sus datos, y despues los jugadores
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MostrarJugadoresPorConf(sJugador jugadores[], int tamJugadores, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite calcular los anios de contrato totales de cada confederacion
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para calcular los anios de contrato
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int CalcularAniosContratoPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Recorre un array de tipo sConfederacion, buscando cual es la confederacion
 * con mas anios de contrato en total
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para calcular los anios de contrato
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return Indice de la confederacion con mas anios de contrato
 */
int BuscarIndiceConfMasAniosDeContrato(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Recorre todas las confederaciones cargadas, contando cuantos jugadores
 * cargados hay
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para el conteo
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int ContarJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite calcular el porcentaje de jugadores cargados en una confederacion
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para calcular el porcentaje
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int CalcularPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite mostrar los porcentajes de jugadores cargados en las confederaciones
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para mostrar los porcentajes
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MostrarPorcentajeJugadoresPorConf(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite buscar el indice donde se encuentra la region con mas jugadores cargados
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para encontrar la region con mas jugadores
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return Indice donde se encuentra la region con mas jugadores cargados
 */
int BuscarIndiceRegionMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite mostrar la confederacion con mas cantidad de anios de contrato en total
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para encontrar la confederacion con mas contratos
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MostrarConfMayorCantContratos(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


/**
 * @brief Permite mostrar cual es la region con mas jugadores cargados, mostrando
 * todos sus jugadores con todos sus datos
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array de tipo sConfederacion
 * @param confederacionesAux Array de tipo sConfederacionAux necesario para encontrar la region con mas jugadores cargados
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array de tipo sJugador
 * @return
 */
int MostrarRegionConMasJugadores(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[], sJugador jugadores[], int tamJugadores);


#endif
