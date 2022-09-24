#ifndef MENU_H_
#define MENU_H_

#define AFC 1
#define CAF 2
#define CONCACAF 3
#define CONMEBOL 4
#define UEFA 5
#define OFC 6


/**
 * @brief Nos despliega un menu de opciones y nos permite ingresar el numero de la opcion que deseamos
 *
 * @param gastoHospedaje Gasto del hospedaje ingresado hasta el momento
 * @param gastoComida Gasto de la comida ingresado hasta el momento
 * @param gastoTransporte Gasto del transporte ingresado hasta el momento
 * @param arqueros Cantidad de arqueros ingresados hasta el momento
 * @param defensas Cantidad de defensas ingresados hasta el momento
 * @param mediocampistas Cantidad de mediocampistas ingresados hasta el momento
 * @param delanteros Cantidad de delanteros ingresados hasta el momento
 * @return La opcion seleccionada
 */
int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros);


/**
 * @brief Imprime los costos de mantenimiento ingresados hasta el momento
 *
 * @param gastoHospedaje Gasto del hospedaje ingresado hasta el momento
 * @param gastoComida Gasto de la comida ingresado hasta el momento
 * @param gastoTransporte Gasto del transporte ingresado hasta el momento
 */
void ImprimirCostosMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);


/**
 * @brief Imprime la cantidad de arqueros, defensas, mediocampistas y delanteros ingresados hasta el momento
 *
 * @param arqueros Cantidad de arqueros ingresados hasta el momento
 * @param defensas Cantidad de defensas ingresados hasta el momento
 * @param mediocampistas Cantidad de mediocampistas ingresados hasta el momento
 * @param delanteros Cantidad de delanteros ingresados hasta el momento
 */
void ImprimirJugadores(int arqueros, int defensas, int mediocampistas, int delanteros);


/**
 * @brief Nos permite verificar si se cargaron los costos de mantenimiento y al menos un jugador para realizar los calculos
 *
 * @param gastoHospedaje Gasto de hospedaje ingresado
 * @param gastoComida Gasto de comida ingresado
 * @param gastoTransporte Gasto de transporte ingresado
 * @param contadorJugadoresEnTotal Cantidad de jugadores ingresados hasta el momento
 * @return 0 si NO se ingresaron los gastos o jugadores, 1 si se ingresaron los gastos y al menos un jugador
 */
int ValidarOpcionTres(float gastoHospedaje, float gastoComida, float gastoTransporte, int contadorJugadoresEnTotal);


/**
 * @brief Nos permite ingresar el costo del hospedaje, comida o transporte, a traves de un submenu
 *
 * @param pGastoHospedaje Puntero donde se va a guardar el gasto de hospedaje
 * @param pGastoComida Puntero donde se va a guardar el gasto de comida
 * @param pGastoTransporte Puntero donde se va a guardar el gasto de transporte
 * @return 0 si NO se cargo ningun costo nuevo, 1 si se cargo un costo nuevo
 */
int CargarCostosMantenimiento(float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte);


/**
 * @brief Nos permite la carga de los datos de los jugadores a traves de un submenu
 *
 * @param pArqueros Puntero donde se va a guardar la cantidad de arqueros ingresados
 * @param pDefensas Puntero donde se va a guardar la cantidad de defensas ingresados
 * @param pMediocampistas Puntero donde se va a guardar la cantidad de mediocampistas ingresados
 * @param pDelanteros Puntero donde se va a guardar la cantidad de delanteros ingresados
 * @param pAFC Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en AFC
 * @param pCAF Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en CAF
 * @param pCONCACAF Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en CONCACAF
 * @param pCONMEBOL Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en CONMEBOL
 * @param pUEFA Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en UEFA
 * @param pOFC Puntero donde se va a guardar la cantidad de jugadores ingresados que juegan en OFC
 * @param maxArqueros Cantidad maxima de arqueros que se pueden ingresar
 * @param maxDefensas Cantidad maxima de defensas que se pueden ingresar
 * @param maxMedios Cantidad maxima de medios que se pueden ingresar
 * @param maxDelanteros Cantidad maxima de delanteros que se pueden ingresar
 * @return 0 si NO se cargo ningun jugador nuevo, 1 si se cargo un jugador nuevo
 */
int CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC, int maxArqueros, int maxDefensas, int maxMedios, int maxDelanteros);


/**
 * @brief Verifica si se supero el maximo de jugadores en cierta posicion
 *
 * @param contador Contador de los jugadores en cierta posicion ingresados hasta el momento
 * @param maximo Maximo de jugadores en cierta posicion que se pueden ingresar
 * @return 0 si se supero el limite, 1 si se puede ingresar
 */
int ValidarCantidadJugadores(int contador, int maximo);


/**
 * @brief Nos permite pedir el numero de camiseta de un jugador, y la confederacion en la que esta jugando
 *
 * @param pConfederacion Puntero donde se va a guardar la confederacion del jugador ingresada
 * @param pNumeroCamiseta Puntero donde se va a guardar el numero de camiseta del jugador ingresado
 */
void PedirDatosDelJugador(int* pConfederacion, int* pNumeroCamiseta);


/**
 * @brief Despliega un submenu que solicita que se ingrese un numero de acuerdo a la confederacion que desee ingresar
 *
 * @return El numero de la confederacion elegida
 */
int PedirConfederacion(void);


/**
 * @brief Nos permite sumar uno al contador de la confederacion ingresada
 *
 * @param confederacion Confederacion ingresada
 * @param pAFC Puntero a un contador de jugadores en AFC
 * @param pCAF Puntero a un contador de jugadores en CAF
 * @param pCONCACAF Puntero a un contador de jugadores en CONCACAF
 * @param pCONMEBOL Puntero a un contador de jugadores en CONMEBOL
 * @param pUEFA Puntero a un contador de jugadores en UEFA
 * @param pOFC Puntero a un contador de jugadores en OFC
 */
void ContadorConfederaciones(int confederacion, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);


/**
 * @brief Nos permite verificar si la mayoria de los jugadores estan jugando en la UEFA
 *
 * @param promedioAFC Promedio de jugadores en AFC
 * @param promedioCAF Promedio de jugadores en CAF
 * @param promedioCONCACAF Promedio de jugadores en CONCACAF
 * @param promedioCONMEBOL Promedio de jugadores en CONMEBOL
 * @param promedioUEFA Promedio de jugadores en UEFA
 * @param promedioOFC Promedio de jugadores en OFC
 * @return 0 si la mayoria no juega en la UEFA, 1 si la mayoria juega en la UEFA
 */
int ChequearMayoriaUEFA(float promedioAFC, float promedioCAF, float promedioCONCACAF, float promedioCONMEBOL, float promedioUEFA, float promedioOFC);


/**
 * @brief Nos permite mostrar el promedio de jugadores en cada confederacion, y el costo de mantenimiento (en caso de que se aplique el aumento se mostrara tambien)
 *
 * @param promedioAFC Promedio de jugadores en AFC
 * @param promedioCAF Promedio de jugadores en CAF
 * @param promedioCONCACAF Promedio de jugadores en CONCACAF
 * @param promedioCONMEBOL Promedio de jugadores en CONMEBOL
 * @param promedioUEFA Promedio de jugadores en UEFA
 * @param promedioOFC Promedio de jugadores en OFC
 * @param mayoriaUEFA Variable que puede valer 0 o 1, nos indica si la mayoria de los jugadores pertenecen a la UEFA
 * @param costoMantenimiento Costo del mantenimiento original, en bruto
 * @param aumento Aumento aplicado al costo del mantenimiento, solo se va a utilizar si mayoriaUEFA es igual a 1
 * @param costoMantenimientoAumento Costo del mantenimiento con el aumento aplicado, solo se va a utilizar si mayoriaUEFA es igual a 1
 */
void MostrarResultados(float promedioAFC, float promedioCAF, float promedioCONCACAF, float promedioCONMEBOL, float promedioUEFA, float promedioOFC, int mayoriaUEFA, float costoMantenimiento, float aumento, float costoMantenimientoAumento);

#endif
