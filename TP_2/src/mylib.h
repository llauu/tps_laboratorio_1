
#ifndef MYLIB_H_
#define MYLIB_H_

#define LIBRE 0
#define OCUPADO 1

// Ingresos de datos
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max);
int getString(char string[], int sizeString, char* mensaje, char* mensajeError);
int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max);

int esNumerica(char* string);

// String functions
int StringUpper(char string[], int size);
int FirstToUppercase(char string[], int size);

int ConfirmarSalida(void);

#endif /* MYLIB_H_ */
