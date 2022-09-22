#ifndef MENU_H_
#define MENU_H_

#define MAX_JUGADORES 22
#define MAX_ARQUEROS 2
#define MAX_DEFENSAS 8
#define MAX_MEDIOS 8
#define MAX_DELANTEROS 4

#define AFC 1
#define CAF 2
#define CONCACAF 3
#define CONMEBOL 4
#define UEFA 5
#define OFC 6

int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros);

int ImprimirCostosMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);
int ImprimirJugadores(int arqueros, int defensas, int mediocampistas, int delanteros);
int ValidarOpcionElegida(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros);

void CargarCostosMantenimiento(float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte);
void CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);
int ValidarCantidadJugadores(int contador, int maximo);
void PedirDatosDelJugador(int* pConfederacion);
int PedirConfederacion(void);
void ContadorConfederaciones(int confederacion, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);
int ChequearMayoriaUEFA(float promedioAFC, float promedioCAF, float promedioCONCACAF, float promedioCONMEBOL, float promedioUEFA, float promedioOFC);

#endif
