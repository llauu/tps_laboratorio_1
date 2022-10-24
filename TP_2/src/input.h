
#ifndef INPUT_H_
#define INPUT_H_

#define LIBRE 0
#define OCUPADO 1

// Inputs
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max);
int getString(char string[], int sizeString, char* mensaje, char* mensajeError);
int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max);

int esNumerica(char* string);

// String functions
int StringUpper(char string[], int size);
int StringLower(char string[], int size);
int FirstToUppercase(char string[], int size);


int ConfirmarSalida(void);

#endif /* INPUT_H_ */