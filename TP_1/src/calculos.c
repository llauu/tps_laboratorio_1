#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


float CalcularPromedioConfederacion(int maxJugadores, int contadorConfederacion){
	float promedioConfederacion;

	promedioConfederacion = (float)contadorConfederacion / maxJugadores;

	return promedioConfederacion;
}


int CalcularTodasConfederaciones(int maxJugadores, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* promedioAFC, float* promedioCAF, float* promedioCONCACAF, float* promedioCONMEBOL, float* promedioUEFA, float* promedioOFC){
	int retorno;

	if(maxJugadores != 0){
		*promedioAFC = CalcularPromedioConfederacion(maxJugadores, contadorAFC);
		*promedioCAF = CalcularPromedioConfederacion(maxJugadores, contadorCAF);
		*promedioCONCACAF = CalcularPromedioConfederacion(maxJugadores, contadorCONCACAF);
		*promedioCONMEBOL = CalcularPromedioConfederacion(maxJugadores, contadorCONMEBOL);
		*promedioUEFA = CalcularPromedioConfederacion(maxJugadores, contadorUEFA);
		*promedioOFC = CalcularPromedioConfederacion(maxJugadores, contadorOFC);

		retorno = 0;
	}
	else{
		retorno = -1;
	}

	return retorno;
}


float CalcularCostoMantenimiento(float gastoHospedaje, float gastoComida, float gastoTransporte){
	float costoMantenimiento;

	costoMantenimiento = gastoHospedaje + gastoComida + gastoTransporte;

	return costoMantenimiento;
}

























