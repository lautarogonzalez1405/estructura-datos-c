#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED
#include "nodo.h"

struct ComandoE;

typedef struct ComandoE * ComandoPtr;

char* getTipoComando(ComandoPtr comando);

void setTipoComando(ComandoPtr comando, char nuevoTipo[30]);

ComandoPtr crearComando(char* tipo);
void mostrarComando(ComandoPtr comando);
void mostrarComandoPtr(void * c);


#endif // COMANDO_H_INCLUDED
