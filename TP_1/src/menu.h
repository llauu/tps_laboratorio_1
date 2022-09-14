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

void EjecutarOpcionElegida(int opcion, float* gastoHospedaje, float* gastoComida, float* gastoTransporte, int* arqueros, int* defensas, int* mediocampistas, int* delanteros);

void CargarCostosMantenimiento(float* gastoHospedaje, float* gastoComida, float* gastoTransporte);

#endif /* MENU_H_ */
