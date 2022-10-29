#ifndef JUGADORES_H_
#define JUGADORES_H_

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


/**
 * @brief Valida si un array de tipo sJugador ingresado es valido
 *
 * @param jugadores Array de tipo sJugador a validar
 * @param tamJugadores Tamanio del array a validar
 * @return 0 si el array es valido, -1 si no es valido
 */
int ChequearValidezArrayJugs(sJugador jugadores[], int tamJugadores);


/**
 * @brief Inicializa el array de jugadores para que todos los estados esten en LIBRE
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int InicializarJugadores(sJugador jugadores[], int tamJugadores);


/**
 * @brief Recorre el array jugadores hasta encontrar un espacio libre
 *
 * @param jugadores Array de tipo sJugador
 * @param tamJugadores Tamanio del array
 * @return El indice en el cual se encontro el primer espacio libre
 */
int ObtenerJugadorLibre(sJugador jugadores[], int tamJugadores);


/**
 * @brief Solicita el ingreso del nombre del jugador
 *
 * @param nombre Puntero al primer elemento del array donde se va a guardar el nombre
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirNombreJugador(char nombre[]);


/**
 * @brief Valida si la posicion ingresada es correcta
 *
 * @param posicion Posicion ingresada a validar
 * @return 0 si la posicion es correcta, -1 si es incorrecta
 */
int ValidarPosicionJugador(char posicion[]);


/**
 * @brief Solicita el ingreso de la posicion del jugador
 *
 * @param posicion Array donde se va a guardar la posicion del jugador
 * @param size Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirPosicionJugador(char posicion[], int size);


/**
 * @brief Solicita el ingreso del numero de camiseta del jugador
 *
 * @param numCamiseta Puntero donde se va a guardar el numero de camiseta
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirNumCamisetaJugador(short* numCamiseta);


/**
 * @brief Solicita el ingreso del salario del jugador
 *
 * @param salario Puntero donde se va a guardar el salario del jugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirSalarioJugador(float* salario);


/**
 * @brief Solicita el ingreso de los anios de contrato del jugador
 *
 * @param aniosContrato Puntero donde se va a guardar los anios de contrato del jugador
 * @return 0 si salio todo bien, -1 si hubo error
 */
int PedirAnioContratoJugador(short* aniosContrato);


/**
 * @brief Ordena los jugadores ingresados por ID de menor a mayor
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return cantidad de iteraciones que realizo para ordenar si salio todo bien, -1 si hubo error
 */
int OrdenarJugadoresPorID(sJugador jugadores[], int tamJugadores);


/**
 * @brief Recorre un array hasta encontrar la posicion del ID deseado
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @param id ID a buscar en el array
 * @return indice donde se encuentra ese ID, -1 si no encontro nada
 */
int BuscarJugadorPorID(sJugador jugadores[], int tamJugadores, int id);


/**
 * @brief Recorre un array hasta encontrar el primer espacio OCUPADO
 *
 * @param comienzo Indice desde el que se desea comenzar a recorrer el array
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return indice del primer elemento OCUPADO, -1 si no encontro nada
 */
int BuscarJugadorOcupado(int comienzo, sJugador jugadores[], int tamJugadores);


/**
 * @brief Ordena los jugadores ingresados alfabeticamente
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return cantidad de iteraciones que realizo para ordenar si salio todo bien, -1 si hubo error
 */
int OrdenarJugadoresAlfabeticamente(sJugador jugadores[], int tamJugadores);


/**
 * @brief Acumula todos los salarios ingresados de los jugadores ocupados
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return El total de todos los salarios acumulados
 */
float CalcularSalariosTotales(sJugador jugadores[], int tamJugadores);


/**
 * @brief Cuenta cuantos jugadores ingresados hay
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return Contador de jugadores ingresados
 */
int ContarJugadoresCargados(sJugador jugadores[], int tamJugadores);


/**
 * @brief Calcula el salario promedio total
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return El salario promedio
 */
float CalcularSalarioPromedio(sJugador jugadores[], int tamJugadores);


/**
 * @brief Cuenta la cantidad de jugadores que cobran mas que el salario promedio
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return Contador de jugadores que cobran mas que el promedio
 */
int JugadoresCobranMasQueElPromedio(sJugador jugadores[], int tamJugadores);


/**
 * @brief Muestra los informes de salarios solicitados
 *
 * @param jugadores Array de tipo sJugador a ordenar
 * @param tamJugadores Tamanio del array
 * @return 0 si salio todo bien, -1 si hubo error
 */
int MostrarInformeSalarios(sJugador jugadores[], int tamJugadores);


#endif
