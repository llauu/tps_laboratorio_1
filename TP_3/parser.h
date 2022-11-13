
#ifndef PARSER_H_
#define PARSER_H_

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_ConvocadoFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

// YO
int parser_LastIdFromBinary(FILE* pFile, int* lastId);

#endif /* PARSER_H_ */
