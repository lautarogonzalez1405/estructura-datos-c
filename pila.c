#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"

struct Pila{

    DatoPtr ultimo;

};

NodoPtr getUltimoPila(PilaPtr p){

    return p->ultimo;

};
void setUltimoPila(PilaPtr p,NodoPtr nuevoUltimo){

    p->ultimo = nuevoUltimo;

};

PilaPtr crearPila(){

    PilaPtr pila = malloc(sizeof(struct Pila));
    pila->ultimo = NULL;
    return pila;

};
void apilar(PilaPtr p, DatoPtr d){

    NodoPtr nuevoNodo = crearNodo(d, NULL);
    if(p->ultimo == NULL){
        p->ultimo = nuevoNodo;
    }else{
        setSiguiente(nuevoNodo, p->ultimo);
        p->ultimo = nuevoNodo;
    }

};
DatoPtr desapilar(PilaPtr p){

    NodoPtr nodo = p->ultimo;
    DatoPtr dato = getDato(nodo);
    p->ultimo = getSiguiente(nodo);
    liberarNodo(nodo);
    return dato;

};
int esPilaVacia(PilaPtr p){

    return(p->ultimo == NULL);

};
PilaPtr duplicarPila(PilaPtr p){

    PilaPtr duplicada = crearPila();
    PilaPtr auxiliar = crearPila();
    DatoPtr dato;
    while(!esPilaVacia(p)){
        dato = desapilar(p);
        apilar(duplicada, dato);
        apilar(auxiliar, dato);
    }
    while(!esPilaVacia(auxiliar)){
        dato = desapilar(auxiliar);
        apilar(p, dato);
    }
    liberarPila(auxiliar);
    return duplicada;

};
void liberarPila(PilaPtr p){

    while(!esPilaVacia(p)){
        NodoPtr nodo = p->ultimo;
        p->ultimo=getSiguiente(nodo);
        liberarNodo(nodo);
    }
    free(p);
};
void liberarPilaMostrar(PilaPtr p,void (*mostrar)(void *)){

    while(!esPilaVacia(p)){
        DatoPtr eliminado = desapilar(p);
        mostrar(eliminado);
    }
    liberarPila(p);
};
