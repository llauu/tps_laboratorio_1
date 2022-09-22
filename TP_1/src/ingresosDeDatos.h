#ifndef INGRESOSDEDATOS_H_
#define INGRESOSDEDATOS_H_

// Obtener datos
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max);
int getString(char string[], int sizeString, char* mensaje, char* mensajeError);

#endif
