#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}sConfederacion;

typedef struct{
	int idConfederacion;
	int acumuladorAniosContrato;
	int contadorJugadores;
	float promedioJugadores;
}sConfederacionAux;


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int ChequearValidezArrayConf(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int InicializarConfs(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MenuConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int ObtenerIndiceLibre(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param nombre
 * @return
 */
int PedirNombreConfederacion(char nombre[]);


/**
 * @brief
 *
 * @param region
 * @return
 */
int PedirRegionConfederacion(char region[]);


/**
 * @brief
 *
 * @param anioCreada
 * @return
 */
int PedirAnioConfederacion(int* anioCreada);


/**
 * @brief
 *
 * @return
 */
sConfederacion CargarConfederacion(void);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param idConfederacion
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int PedirConfJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int ChequearConfCargada(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int OrdenarConfederacionesPorID(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 */
void MostrarConfederacion(sConfederacion confederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param comienzo
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int BuscarConfederacionOcupada(int comienzo, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param id
 * @return
 */
int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int SolicitarYValidarIDConf(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int BajaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int ModificarConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @return
 */
int OrdenarConfederacionesAlfabeticamente(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief
 *
 * @param confederaciones
 * @param tamConfederaciones
 * @param confederacionesAux
 * @return
 */
int VincularAuxConfederaciones(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);


#endif
