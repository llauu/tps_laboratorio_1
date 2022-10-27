
#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}sJugador;

int ChequearValidezArrayJugs(sJugador jugadores[], int tamJugadores);
int InicializarJugadores(sJugador jugadores[], int tamJugadores);

int ObtenerJugadorLibre(sJugador jugadores[], int tamJugadores);

int PedirNombreJugador(char nombre[]);
int ValidarPosicionJugador(char posicion[]);
int PedirPosicionJugador(char posicion[], int size);
int PedirNumCamisetaJugador(short* numCamiseta);
int PedirSalarioJugador(float* salario);
int PedirAnioContratoJugador(short* aniosContrato);


int ChequearJugadorCargado(sJugador jugadores[], int tamJugadores);

int OrdenarJugadoresPorID(sJugador jugadores[], int tamJugadores);

void MostrarMenuDatosJugs(void);
void MostrarPieDatosJugs(void);

int BuscarJugadorPorID(sJugador jugadores[], int tamJugadores, int id);

int BuscarJugadorOcupado(int comienzo, sJugador jugadores[], int tamJugadores);

int OrdenarJugadoresAlfabeticamente(sJugador jugadores[], int tamJugadores);

float CalcularSalariosTotales(sJugador jugadores[], int tamJugadores);
int ContarJugadoresCargados(sJugador jugadores[], int tamJugadores);
float CalcularSalarioPromedio(sJugador jugadores[], int tamJugadores);
int JugadoresCobranMasQueElPromedio(sJugador jugadores[], int tamJugadores);

int MostrarInformeSalarios(sJugador jugadores[], int tamJugadores);

#endif
