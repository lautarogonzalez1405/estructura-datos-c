#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "pila.h"
#include "nave.h"

struct NaveE{

    char nombre[30];
    PilaPtr comandos;

};

char* getNombreNave(NavePtr nave){

    return nave->nombre;
};
PilaPtr getComandos(NavePtr nave){

    return nave->comandos;

};

void setNombreNave(NavePtr nave, char nuevoNombre[30]){

    strcpy(nave->nombre, nuevoNombre);

};
void setPilaNave(NavePtr nave, PilaPtr nuevaPila){

    nave->comandos = nuevaPila;

};

NavePtr crearNave(char* nombre){

    NavePtr nave = (NavePtr)malloc(sizeof(struct NaveE));
    strcpy(nave->nombre, nombre);
    nave->comandos = crearPila();
    return nave;

};
void agregarComando(NavePtr nave, DatoPtr comando){

    apilar(nave->comandos, comando);

};//Apilar los comando en la nave
void ejecutarComando(NavePtr nave){

    DatoPtr eliminado = desapilar(nave->comandos);
    printf("\n-----EJECUTADO------");
    mostrarComandoPtr(eliminado);

};//Desapilar los comandos
void mostrarNave(NavePtr nave){

    printf("\n----------NAVE---------\n");
    printf("Nombre: %s\n", nave->nombre);

};
void liberarNave(NavePtr nave){

    if(nave == NULL)return;

    if(nave->comandos != NULL){
        liberarPila(nave->comandos);
    }
    free(nave);
};
