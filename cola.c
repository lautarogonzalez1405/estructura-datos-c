#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cola.h"
#include "persona.h"

struct Cola{
NodoPtr primero;
NodoPtr ultimo;

};

NodoPtr getPrimeroCola(ColaPtr c){
    return c->primero;
}
void setPrimeroCola(ColaPtr c,NodoPtr nuevoPrimero){
    c->primero=nuevoPrimero;
}

NodoPtr getUltimo(ColaPtr c){
    return c->ultimo;
}
void setUltimo(ColaPtr c, NodoPtr nuevoUltimo){
    c->ultimo=nuevoUltimo;
}

ColaPtr crearCola(){

    ColaPtr cola = malloc(sizeof(struct Cola));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
};
void encolar(ColaPtr c, DatoPtr d){

    NodoPtr nuevoNodo = crearNodo(d, NULL);
    NodoPtr actual = c->primero;
    if(actual == NULL){
        c->primero = nuevoNodo;
        c->ultimo = nuevoNodo;
    }else{
        setSiguiente(c->ultimo, nuevoNodo);
        c->ultimo = nuevoNodo;
    }

};
DatoPtr desencolar(ColaPtr c){

    NodoPtr nodo = c->primero;
    DatoPtr dato = getDato(nodo);
    c->primero=getSiguiente(nodo);
    liberarNodo(nodo);
    return dato;

};

int esColaVacia(ColaPtr c) {
    return (c->primero == NULL);
}

ColaPtr duplicarCola(ColaPtr c){

    if(c == NULL)return NULL;

    ColaPtr duplicada = crearCola();
    ColaPtr auxiliar = crearCola();

    while(!esColaVacia(c)){
        DatoPtr dato = desencolar(c);
        encolar(duplicada, dato);
        encolar(auxiliar, dato);

    }

    while(!esColaVacia(auxiliar)){
        DatoPtr dato = desencolar(auxiliar);
        encolar(c, dato);

    }

    liberarCola(auxiliar);

    return duplicada;
};
void liberarCola(ColaPtr c){

    liberarNodoRecursivo(c->primero);
    free(c);
};
void liberarColaMostrar(ColaPtr c,void (*mostrar)(void *)){

    while(!esColaVacia(c)){

        DatoPtr eliminado = desencolar(c);
        mostrar(eliminado);

    }

    free(c);
};
