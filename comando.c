#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "pila.h"
#include "comando.h"

struct ComandoE{

    char tipo[30];

};
char* getTipoComando(ComandoPtr comando){

    return comando->tipo;

};

void setTipoComando(ComandoPtr comando, char nuevoTipo[30]){

    strcpy(comando->tipo, nuevoTipo);

};

ComandoPtr crearComando(char* tipo){

    ComandoPtr comando = (ComandoPtr)malloc(sizeof(struct ComandoE));

    strcpy(comando->tipo, tipo);

    return comando;

};

void mostrarComando(ComandoPtr comando){

    printf("\n------COMANDO-------\n");
    printf("Tipo: %s\n", comando->tipo);

}

void mostrarComandoPtr(void * c){

    ComandoPtr comando = *(ComandoPtr *)c;
    mostrarComando(comando);

};
