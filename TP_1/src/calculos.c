#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


float CalcularPromedioConfederacion(int cantJugadores, int contadorConfederacion){
	float promedioConfederacion;

	promedioConfederacion = (float)contadorConfederacion / cantJugadores;

	return promedioConfederacion;
}


int CalcularTodasConfederaciones(int cantJugadores, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* promedioAFC, float* promedioCAF, float* promedioCONCACAF, float* promedioCONMEBOL, float* promedioUEFA, float* promedioOFC){
	int retorno;

	if(cantJugadores != 0){
		*promedioAFC = CalcularPromedioConfederacion(cantJugadores, contadorAFC);
		*promedioCAF = CalcularPromedioConfederacion(cantJugadores, contadorCAF);
		*promedioCONCACAF = CalcularPromedioConfederacion(cantJugadores, contadorCONCACAF);
		*promedioCONMEBOL = CalcularPromedioConfederacion(cantJugadores, contadorCONMEBOL);
		*promedioUEFA = CalcularPromedioConfederacion(cantJugadores, contadorUEFA);
		*promedioOFC = CalcularPromedioConfederacion(cantJugadores, contadorOFC);

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


int CalcularAumento(float costo, int porcentajeAumento, float* pAumento, float* pCostoConAumento){
	int retorno;
	float aumento;
	float costoConAumento;

	retorno = -1;

	if(pAumento != NULL && pCostoConAumento != NULL){
		aumento = costo * porcentajeAumento / 100;
		costoConAumento = costo + aumento;

		*pAumento = aumento;
		*pCostoConAumento = costoConAumento;

		retorno = 0;
	}

	return retorno;
}






















