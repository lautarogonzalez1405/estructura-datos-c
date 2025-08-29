#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "nodo.h"

struct Pila;

typedef struct Pila * PilaPtr;


NodoPtr getUltimoPila(PilaPtr p);
void setUltimoPila(PilaPtr p,NodoPtr nuevoPrimero);

//NodoPtr getUltimo(ColaPtr c);
//void setUltimo(ColaPtr c, NodoPtr nuevoUltimo);


PilaPtr crearPila();
void apilar(PilaPtr p, DatoPtr d);
DatoPtr desapilar(PilaPtr p);
int esPilaVacia(PilaPtr p);
PilaPtr duplicarPila(PilaPtr p);
void liberarPila(PilaPtr p);
void liberarPilaMostrar(PilaPtr p,void (*mostrar)(void *));


#endif // PILA_H_INCLUDED
