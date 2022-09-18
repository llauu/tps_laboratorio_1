/*
 * menu.h
 *
 *  Created on: Sep 14, 2022
 *      Author: llauu
 */

#ifndef MENU_H_
#define MENU_H_

int Menu(float gastoHospedaje, float gastoComida, float gastoTransporte, int arqueros, int defensas, int mediocampistas, int delanteros);

int ImprimirCostosMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);
int ImprimirJugadores(int arqueros, int defensas, int mediocampistas, int delanteros);

void EjecutarOpcionElegida(int opcion, float* gastoHospedaje, float* gastoComida, float* gastoTransporte, int* arqueros, int* defensas, int* mediocampistas, int* delanteros, int* confederacion);

void CargarCostosMantenimiento(float* pGastoHospedaje, float* pGastoComida, float* pGastoTransporte);
void CargaDeJugadores(int* pArqueros, int* pDefensas, int* pMediocampistas, int* pDelanteros, int* confederacion);

void PedirDatosDelJugador(int* confederacion);
int PedirConfederacion(void);
void ContadorConfederaciones(int confederacion, int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);

#endif /* MENU_H_ */
