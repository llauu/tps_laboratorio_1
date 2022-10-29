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
 * @brief Valida si un array de tipo sConfederacion ingresado es valido
 *
 * @param confederaciones Array de tipo sConfederacion a validar
 * @param tamConfederaciones Tamanio del array a validar
 * @return 0 si el array es valido, -1 si no es valido
 */
int ChequearValidezArrayConf(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Inicializa el array de confederaciones para que todos los estados esten en LIBRE
 *
 * @param confederaciones Array de tipo sConfederacion a inicializar
 * @param tamConfederaciones Tamanio del array a inicializar
 * @return 0 si salio todo bien, -1 si hubo error
 */
int InicializarConfs(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Menu principal del ABM de las confederaciones
 *
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MenuConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Recorre un array de tipo sConfederacion hasta encontrar un espacio libre
 *
 * @param confederaciones Array de tipo sConfederacion a recorrer
 * @param tamConfederaciones Tamanio del array
 * @return Indice del primer espacio libre encontrado, -1 si no se encontro espacio
 */
int ObtenerConfLibre(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite el ingreso del nombre de una confederacion
 *
 * @param nombre Puntero a donde se va a guardar el nombre
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirNombreConfederacion(char nombre[]);


/**
 * @brief Permite el ingreso de la region de una confederacion
 *
 * @param region Puntero a donde se va a guardar la region
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirRegionConfederacion(char region[]);


/**
 * @brief Permite el ingreso del anio de creacion de una confederacion
 *
 * @param anioCreada Puntero a donde se va a guardar el anio
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirAnioConfederacion(int* anioCreada);


/**
 * @brief Permite la carga de una estructura tipo sConfederacion
 *
 * @return Una estructura de tipo sConfederacion con sus datos cargados
 */
sConfederacion CargarConfederacion(void);


/**
 * @brief Permite dar de alta una confederacion
 *
 * @param confederaciones Array de tipo sConfederacion a donde se va a cargar la confederacion
 * @param tamConfederaciones Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite cargar una confederacion al momento de dar el alta de un jugador, mostrando todas las disponibles
 *
 * @param idConfederacion Puntero a donde se va a guardar el ID de la confederacion elegida
 * @param confederaciones Array de tipo sConfederacion
 * @param tamConfederaciones Tamanio del array
 * @return El indice en el que se encontro el ID de la confederacion elegida
 */
int PedirConfJugador(int* idConfederacion, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite ordenar un array de tipo sConfederacion por su ID de menor a mayor
 *
 * @param confederaciones Array de tipo sConfederacion a ordenar
 * @param tamConfederaciones Tamanio del array
 * @return Cantidad de iteraciones que realizo para ordenarlo, -1 si hubo error
 */
int OrdenarConfederacionesPorID(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Muestra los datos de una confederacion en formato columnas
 *
 * @param confederaciones Estructura de tipo sConfederacion a mostrar
 */
void MostrarConfederacion(sConfederacion confederaciones);


/**
 * @brief Recorre un array de tipo sConfederacion mostrando unicamente los datos de las confederaciones cargadas
 *
 * @param confederaciones Array de tipo sConfederacion a mostrar
 * @param tamConfederaciones Tamanio del array
 * @return 0 si hay al menos una confederacion cargada, -1 si no hay
 */
int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Recorre un array de tipo sConfederacion hasta encontrarse la primer posicion OCUPADA
 *
 * @param comienzo Indice desde el que se desea comenzar a recorrer el array
 * @param confederaciones Array de tipo sConfederacion a recorrer
 * @param tamConfederaciones Tamanio del array
 * @return Indice donde se encontro el primer elemento OCUPADO, -1 si no se encontro
 */
int BuscarConfederacionOcupada(int comienzo, sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Recorre un array de tipo sConfederacion hasta encontrar un elemento
 *  que coincida con el ID ingresado, siempre y cuando este OCUPADO
 *
 * @param confederaciones Array de tipo sConfederacion a recorrer
 * @param tamConfederaciones Tamanio del array
 * @param id ID que se desea buscar dentro del array
 * @return Indice donde se encontro coincidencia con el ID, -1 si no se encontro
 */
int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id);


/**
 * @brief Permite ingresar y buscar un ID de una confederacion dentro de un array de
 * tipo sConfederacion
 *
 * @param confederaciones Array de tipo sConfederacion donde se va a buscar el ID
 * @param tamConfederaciones Tamanio del array
 * @return Indice donde se encontro coincidencia con el ID, -1 si no se encontro
 */
int SolicitarYValidarIDConf(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite dar de baja una confederacion cargada en una array de tipo sConfederacion
 *
 * @param confederaciones Array de tipo sConfederacion donde se va a dar de baja la confederacion
 * @param tamConfederaciones Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int BajaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite modificar el dato de una confederacion cargada en un array de tipo sConfederacion
 *
 * @param confederaciones Array de tipo sConfederacion donde se va a modificar la confederacion
 * @param tamConfederaciones Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int ModificarConfederacion(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite ordenar un array de tipo sConfederacion alfabeticamente
 *
 * @param confederaciones Array de tipo sConfederacion a ordenar
 * @param tamConfederaciones Tamanio del array
 * @return Cantidad de iteraciones que realizo para ordenarlo, -1 si hubo error
 */
int OrdenarConfederacionesAlfabeticamente(sConfederacion confederaciones[], int tamConfederaciones);


/**
 * @brief Permite vincular un array de tipo sConfederacion con un array de una estructura auxiliar
 * para tener contadores y acumuladores necesarios para los informes
 *
 * @param confederaciones Array de tipo sConfederacion a vincular con el auxiliar
 * @param tamConfederaciones Tamanio del array
 * @param confederacionesAux Array de tipo sConfederacionAux a utilizar como auxiliar
 * @return 0 si salio todo bien, -1 si hubo error
 */
int VincularAuxConfederaciones(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);


#endif
