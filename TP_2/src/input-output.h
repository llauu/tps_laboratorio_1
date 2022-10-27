
#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#define LIBRE 0
#define OCUPADO 1

// Entradas - Validaciones
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max);
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max);
int getString(char string[], int sizeString, char* mensaje, char* mensajeError);
int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max);

int StringUpper(char string[], int size);
int StringLower(char string[], int size);
int FirstToUppercase(char string[], int size);

int ConfirmarSalida(void);


// Salidas
void MostrarMenuDatosJugs(void);
void MostrarPieDatosJugs(void);
void MostrarMenuDatosConfs(void);
void MostrarPieDatosConfs(void);
void MostrarMenuPrincipal(void);
void MostrarMenuJugadores(void);
void MostrarMenuConfederaciones(void);
void MostrarMenuBaja(void);
void MostrarMenuModificacion(void);
void MostrarBajaExitosa(void);
void MostrarModificacionExitosa(void);
void MostrarMenuModificacionJugs(void);
void MostrarMenuModificacionConfs(void);
void MostrarMenuInformes(void);

#endif /* INPUT_OUTPUT_H_ */
