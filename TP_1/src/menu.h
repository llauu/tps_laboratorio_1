/*
 * menu.h
 *
 *  Created on: Sep 14, 2022
 *      Author: llauu
 */

#ifndef MENU_H_
#define MENU_H_
#define MAX_JUGADORES 4
#define MAX_ARQUEROS 1
#define MAX_DEFENSAS 1
#define MAX_MEDIOS 1
#define MAX_DELANTEROS 1
#define CANTIDAD_CONF 6

int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros);

int ImprimirCostosMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);
int ImprimirJugadores(int arqueros, int defensas, int mediocampistas, int delanteros);
int ValidarOpcionElegida(int opcion, float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros, int calculosHechos);
void EjecutarOpcionElegida(int opcion, float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte, int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC, int* pCalculosHechos, float* pPromedioAFC, float* pPromedioCAF, float* pPromedioCONCACAF, float* pPromedioCONMEBOL, float* pPromedioUEFA, float* pPromedioOFC, float* pCostoMantenimiento);

void CargarCostosMantenimiento(float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte);
void CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);
int ValidarCantidadJugadores(int contador, int maximo);
void PedirDatosDelJugador(int* pConfederacion);
int PedirConfederacion(void);
void ContadorConfederaciones(int confederacion, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);

#endif /* MENU_H_ */
