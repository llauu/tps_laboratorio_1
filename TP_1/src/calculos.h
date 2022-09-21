/*
 * calculos.h
 *
 *  Created on: Sep 20, 2022
 *      Author: llauu
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float CalcularPromedioConfederacion(int maxJugadores, int contadorConfederacion);
int CalcularTodasConfederaciones(int maxJugadores, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* promedioAFC, float* promedioCAF, float* promedioCONCACAF, float* promedioCONMEBOL, float* promedioUEFA, float* promedioOFC);

float CalcularCostoMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte);

#endif /* CALCULOS_H_ */
