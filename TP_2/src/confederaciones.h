#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}sConfederacion;

typedef struct{
	int idConfederacion;
	int acumuladorAniosContrato;
	int contadorJugadores;
	float promedioJugadores;
}sConfederacionAux;


int ChequearValidezArrayConf(sConfederacion confederaciones[], int tamConfederaciones);

int InicializarConfs(sConfederacion confederaciones[], int tamConfederaciones);

int MenuConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ObtenerIndiceLibre(sConfederacion confederaciones[], int tamConfederaciones);

int PedirNombreConfederacion(char nombre[]);

int PedirRegionConfederacion(char region[]);

int PedirAnioConfederacion(int* anioCreada);

sConfederacion CargarConfederacion(void);

int AltaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ChequearConfCargada(sConfederacion confederaciones[], int tamConfederaciones);

int OrdenarConfederacionesPorID(sConfederacion confederaciones[], int tamConfederaciones);

void MostrarConfederacion(sConfederacion confederaciones);

int MostrarConfsDisponibles(sConfederacion confederaciones[], int tamConfederaciones);

int BuscarConfederacionOcupada(int comienzo, sConfederacion confederaciones[], int tamConfederaciones);

int BuscarConfPorID(sConfederacion confederaciones[], int tamConfederaciones, int id);

int SolicitarYValidarIDConf(sConfederacion confederaciones[], int tamConfederaciones);

int BajaConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int ModificarConfederacion(sConfederacion confederaciones[], int tamConfederaciones);

int OrdenarConfederacionesAlfabeticamente(sConfederacion confederaciones[], int tamConfederaciones);

int VincularAuxConfederaciones(sConfederacion confederaciones[], int tamConfederaciones, sConfederacionAux confederacionesAux[]);


#endif
