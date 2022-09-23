#ifndef INGRESOSDEDATOS_H_
#define INGRESOSDEDATOS_H_


/**
 * @brief
 *
 * @param pResultado Puntero donde se va a guardar el entero que se ingrese
 * @param mensaje Mensaje que se va a mostrar al solicitar el entero
 * @param mensajeError Mensaje de error en caso de que lo haya
 * @param min Entero minimo que se puede ingresar
 * @param max Entero maximo que se puede ingresar
 * @return El entero ingresado
 */
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);


/**
 * @brief
 *
 * @param pResultado Puntero donde se va a guardar el flotante que se ingrese
 * @param mensaje Mensaje que se va a mostrar al solicitar el flotante
 * @param mensajeError Mensaje de error en caso de que lo haya
 * @param min Flotante minimo que se puede ingresar
 * @param max Flotante maximo que se puede ingresar
 * @return El flotante ingresado
 */
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);

#endif
