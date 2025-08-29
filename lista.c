#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;

};

void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;


};
void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    if(lista->primero == NULL){
        insertarPrimero(lista, dato);
    }else{
        NodoPtr actual = lista->primero;
        while(getSiguiente(actual) != NULL){
            actual = getSiguiente(actual);
        }
        //actual->siguiente = nuevoNodo;
        setSiguiente(actual, nuevoNodo);
    }

};
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){

    int tam = obtenerTamanioLista(lista);
    if(posicion == 0){
        insertarPrimero(lista, dato);
    }else if(posicion == tam + 1){
        insertarUltimo(lista, dato);
    }else if(posicion > tam+1){
        printf("\nIMPOSIBLE INSERTAR EN POSICIONES FUERA DEL ALCANCE\n");
    }else{
        NodoPtr actual = lista->primero;
        for(int i = 0; i < posicion - 1; i++){
            actual = getSiguiente(actual);
        }
        NodoPtr nuevoNodo = crearNodo(dato, getSiguiente(actual));
        setSiguiente(actual, nuevoNodo);
    }

};

DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int pos);

int obtenerTamanioLista(ListaPtr lista){

    NodoPtr actual = lista->primero;
    int tam = 0;
    while(actual != NULL){
        tam++;
        actual = getSiguiente(actual);
    }
    return tam;
};

void mostrarLista(ListaPtr lista){

    NodoPtr nuevoNodo = lista->primero;
    while(nuevoNodo != NULL){
        mostrarNodo(nuevoNodo);
        nuevoNodo = getSiguiente(nuevoNodo);
    }
    printf("\n");
};

void mostrarListaFloat(ListaPtr lista){

    NodoPtr nuevoNodo = lista->primero;
    while(nuevoNodo != NULL){
        mostrarNodoFloat(nuevoNodo);
        nuevoNodo = getSiguiente(nuevoNodo);
    }
    printf("\n");
};

void mostrarListaChar(ListaPtr lista){

    NodoPtr nuevoNodo = lista->primero;
    while(nuevoNodo != NULL){
        mostrarNodoChar(nuevoNodo);
        nuevoNodo = getSiguiente(nuevoNodo);
    }
    printf("\n");
};
void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){
    NodoPtr actual = lista->primero;

    while(actual!=NULL){
        mostrar(getDato(actual));
        actual=getSiguiente(actual);
    }

}


void ordenarLista(ListaPtr lista, int(*funcionComparar)(DatoPtr, DatoPtr)){

    int tam = 0;
    tam = obtenerTamanioLista(lista);

    for(int i = 0; i < tam; i++){
        NodoPtr actual = lista->primero;
        NodoPtr siguiente = getSiguiente(actual);
        while(siguiente!=NULL){
            if(funcionComparar(getDato(actual), getDato(siguiente))){
                //aux = actual->dato;
                DatoPtr aux = getDato(actual);
                //actual->dato = siguiente->dato;
                setDato(actual, getDato(siguiente));
                //siguiente->dato = aux;
                setDato(siguiente, aux);
            }
            //actual = actual->siguiente;
            actual = getSiguiente(actual);
            //siguiente = actual->siguiente;
            siguiente = getSiguiente(actual);
        }
        //actual = actual->siguiente;
        actual = getSiguiente(actual);
    }

}
