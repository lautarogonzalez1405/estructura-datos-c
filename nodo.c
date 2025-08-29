#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo{

    DatoPtr dato;
    struct Nodo * siguiente;

};

DatoPtr getDato(NodoPtr nodo){

    return nodo->dato;

};
NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;

};

void setDato(NodoPtr nodo, DatoPtr dato){

    nodo->dato = dato;

};
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){

    nodo->siguiente =  nuevoSiguiente;

};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

}

void mostrarNodo(NodoPtr nodo){

    printf("{ %d }", *(int*)(nodo->dato));

}

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }", *(float*)(nodo->dato));

}

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }", (char*)(nodo->dato));

}

void liberarNodo(NodoPtr nodo){

    free(nodo);

}
void liberarNodoRecursivo(NodoPtr nodo){

    if(nodo == NULL){
        return;
    }

    liberarNodoRecursivo(getSiguiente(nodo));

    liberarNodo(nodo);

}

