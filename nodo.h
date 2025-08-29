#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef void * DatoPtr;
typedef struct Nodo * NodoPtr;


DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr dato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
void mostrarNodo(NodoPtr nodo);
void mostrarNodoFloat(NodoPtr nodo);
void mostrarNodoChar(NodoPtr nodo);
void liberarNodo(NodoPtr nodo);
void liberarNodoRecursivo(NodoPtr nodo);


#endif // NODO_H_INCLUDED
