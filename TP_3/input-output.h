
#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#define LIBRE 0
#define OCUPADO 1


//========== Entradas- Validaciones =========================================================================================
/**
 * @brief Permite ingresar un numero entero
 *
 * @param pResultado Puntero a donde se va a guardar el resultado
 * @param mensaje Mensaje que se muestra a la hora de solicitar el entero
 * @param mensajeError Mensaje de error, en caso que haya
 * @param min Entero minimo a ingresar
 * @param max Entero maximo a ingresar
 * @return 0 si salio bien, -1 en caso de error
 */
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);


/**
 * @brief Permite ingresar un numero flotante
 *
 * @param pResultado Puntero a donde se va a guardar el resultado
 * @param mensaje Mensaje que se muestra a la hora de solicitar el flotante
 * @param mensajeError Mensaje de error, en caso que haya
 * @param min Flotante minimo a ingresar
 * @param max Flotante maximo a ingresar
 * @return 0 si salio bien, -1 en caso de error
 */
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);


/**
 * @brief Permite ingresar un caracter
 *
 * @param pResultado Puntero a donde se va a guardar el caracter
 * @param mensaje Mensaje que se muestra a la hora de solicitar el caracter
 * @param mensajeError Mensaje de error, en caso que haya
 * @param min Caracter minimo a ingresar (en base al codigo ASCII)
 * @param max Caracter maximo a ingresar (en base al codigo ASCII)
 * @return 0 si salio bien, -1 en caso de error
 */
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max);


/**
 * @brief Permite ingresar un string
 *
 * @param string Puntero al primer elemento del array donde se va a guardar el string
 * @param sizeString Tamanio max. del string
 * @param mensaje Mensaje que se muestra a la hora de solicitar el string
 * @param mensajeError Mensaje de error, en caso que haya
 * @return 0 si salio bien, -1 en caso de error
 */
int getString(char string[], int sizeString, char* mensaje, char* mensajeError);

int getStringNumeric(char string[], int sizeString, char* mensaje, char* mensajeError);

/**
 * @brief Permite ingresar un numero de tipo short
 *
 * @param pResultado Puntero a donde se va a guardar el resultado
 * @param mensaje Mensaje que se muestra a la hora de solicitar el short
 * @param mensajeError Mensaje de error, en caso que haya
 * @param min Short minimo a ingresar
 * @param max Short maximo a ingresar
 * @return 0 si salio bien, -1 en caso de error
 */
int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max);


/**
 * @brief Solicita el ingreso de un texto
 *
 * @param buffer Buffer donde se va a guardar el texto ingresado
 * @param mensaje Mensaje que se muestra a la hora de solicitar el texto
 * @return 0 si salio bien, -1 en caso de error
 */
int PedirTexto(char buffer[], char* mensaje);


/**
 * @brief Pasa todo un string a mayusculas
 *
 * @param string String que se quiere pasar a mayuscula
 * @param size Tamanio del string
 * @return 0 si salio bien, -1 en caso de error
 */
int StringUpper(char string[], int size);


/**
 * @brief Pasa todo un string a minusculas
 *
 * @param string String que se quiere pasar a minuscula
 * @param size Tamanio del string
 * @return 0 si salio bien, -1 en caso de error
 */
int StringLower(char string[], int size);


/**
 * @brief Pasa la primer letra despues de un espacio a mayuscula
 *
 * @param string String que se quiere modificar
 * @param size Tamanio del string
 * @return 0 si salio bien, -1 en caso de error
 */
int FirstToUppercase(char string[], int size);


/**
 * @brief Permite solicitar una confirmacion a la hora de salir de un menu
 *
 * @return 0 si no confirmo la salida, 1 si confirmo la salida
 */
int ConfirmarSalida(void);


//========== Salidas =========================================================================================
void MostrarMenuPrincipal(void);
void MostrarMenuModificacion(void);
void MostrarMenuConvocados(void);

void MostrarCabeceraJugadores(void);
void MostrarPieJugadores(void);

void MostrarCabeceraConSeleccion(void);
void MostrarPieConSeleccion(void);

void MostrarCabeceraConfederaciones(void);
void MostrarPieConfederaciones(void);

void MostrarAltaExitosa(void);
void MostrarBajaExitosa(void);
void MostrarModificacionExitosa(void);

void MostrarConfederaciones(void);

#endif
