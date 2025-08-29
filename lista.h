#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista{

    NodoPtr primero;

};

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int pos);
int obtenerTamanioLista(ListaPtr lista);
void ordenarLista(ListaPtr lista, int(*funcionComparar)(DatoPtr, DatoPtr));

void mostrarLista(ListaPtr lista);
void mostrarListaFloat(ListaPtr lista);
void mostrarListaChar(ListaPtr lista);
void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

#endif // LISTA_H_INCLUDED
