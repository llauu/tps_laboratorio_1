#ifndef CALCULOS_H_
#define CALCULOS_H_


/**
 * @brief Nos calcula el promedio de jugadores de una confederacion
 *
 * @param cantJugadores Corresponde a la cantidad de jugadores en total que se ingresaron
 * @param contadorConfederacion Corresponde al contador de jugadores que juegan en una confederacion especifica
 * @return El promedio de jugadores de una confederacion
 */
float CalcularPromedioConfederacion(int cantJugadores, int contadorConfederacion);


/**
 * @brief Nos calcula el promedio de jugadores de todas las confederaciones utilizando CalcularPromedioConfederacion()
 *
 * @param cantJugadores Corresponde a la cantidad de jugadores en total que se ingresaron
 * @param contadorAFC Contador de jugadores que juegan en AFC
 * @param contadorCAF Contador de jugadores que juegan en CAF
 * @param contadorCONCACAF Contador de jugadores que juegan en CONCACAF
 * @param contadorCONMEBOL Contador de jugadores que juegan en CONMEBOL
 * @param contadorUEFA Contador de jugadores que juegan en UEFA
 * @param contadorOFC Contador de jugadores que juegan en OFC
 * @param promedioAFC Puntero donde se va a guardar el promedio de jugadores en AFC
 * @param promedioCAF Puntero donde se va a guardar el promedio de jugadores en CAF
 * @param promedioCONCACAF Puntero donde se va a guardar el promedio de jugadores en CONCACAF
 * @param promedioCONMEBOL Puntero donde se va a guardar el promedio de jugadores en CONMEBOL
 * @param promedioUEFA Puntero donde se va a guardar el promedio de jugadores en UEFA
 * @param promedioOFC Puntero donde se va a guardar el promedio de jugadores en OFC
 * @return 0 si salio todo bien, -1 si hubo algun error
 */
int CalcularTodasConfederaciones(int cantJugadores, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* promedioAFC, float* promedioCAF, float* promedioCONCACAF, float* promedioCONMEBOL, float* promedioUEFA, float* promedioOFC);


/**
 * @brief Nos calcula el costo de mantenimiento a partir de los diferentes gastos ingresados
 *
 * @param gastoHospedaje Gasto de hospedaje de todo el plantel
 * @param gastoComida Gasto de comida de todo el plantel
 * @param gastoTransporte Gasto de transporte de todo el plantel
 * @return Costo de mantenimiento
 */
float CalcularCostoMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);


/**
 * @brief Aplica un aumento al costo original de acuerdo al porcentaje de aumento que se ingrese
 *
 * @param costo Costo original en bruto
 * @param porcentajeAumento Porcentaje del aumento
 * @param pAumento Puntero donde se va a guardar el valor del aumento
 * @param pCostoConAumento Puntero donde se va a guardar el nuevo costo con el aumento aplicado
 * @return 0 si salio todo bien, -1 si hubo algun error
 */
int CalcularAumento(float costo, int porcentajeAumento, float* pAumento, float* pCostoConAumento);

#endif









