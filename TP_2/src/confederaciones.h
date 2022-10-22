
#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}sConfederacion;


int ChequearValidezArrayConf(sConfederacion confederaciones[], int tamConfederaciones);

int InicializarConfs(sConfederacion confederaciones[], int tamConfederaciones);

int MenuConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ObtenerIndiceLibre(sConfederacion confederaciones[], int tamConfederaciones);

sConfederacion CargarConfederacion(void);
int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ChequearConfCargada(sConfederacion confederaciones[], int tamConfederaciones);

void MostrarMenuDatosConfs(void);
void MostrarConfederacion(sConfederacion confederaciones);
int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones);

int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id);

int BajaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ModificarConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

#endif
