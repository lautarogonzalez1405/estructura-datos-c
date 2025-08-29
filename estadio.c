#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "cola.h"
#include "estadio.h"

struct Estadio{

    char nombre[20];
    int capacidad;
    char localidad[20];
    ColaPtr personas;

};

char* getNombreEstadio(EstadioPtr estadio){

    return estadio->nombre;

};
int getCapacidadEstadio(EstadioPtr estadio){

    return estadio->capacidad;

};
char* getLocalidadEstadio(EstadioPtr estadio){

    return estadio->localidad;

};
ColaPtr getColaPersonas(EstadioPtr estadio){

    return estadio->personas;

};

void setNombreEstadio(EstadioPtr estadio, char nuevoNombre[20]){

    strcpy(estadio->nombre, nuevoNombre);

};
void setCapacidadEstadio(EstadioPtr estadio, int nuevaCapacidad){

    estadio->capacidad = nuevaCapacidad;

};
void setLocalidadEstadio(EstadioPtr estadio, char nuevaLocalidad[20]){

    strcpy(estadio->localidad, nuevaLocalidad);

};
void setColaPersonas(EstadioPtr estadio, ColaPtr nuevaCola){

    estadio->personas = nuevaCola;

};

EstadioPtr crearEstadio(char* nombre, int capacidad, char* localidad){

    EstadioPtr estadio = (EstadioPtr)malloc(sizeof(struct Estadio));

    strcpy(estadio->nombre, nombre);
    estadio->capacidad = capacidad;
    strcpy(estadio->localidad, localidad);
    estadio->personas = crearCola();
    return estadio;

};
void encolarPersonas(EstadioPtr estadio, DatoPtr persona){

    encolar(estadio->personas, persona);

};
void mostrarEstadio(EstadioPtr estadio){

    printf("\n----------ESTADIO-------------\n");
    printf("Nombre: %s\n", estadio->nombre);
    printf("Capacidad: %d\n", estadio->capacidad);
    printf("Localidad: %s\n", estadio->localidad);

};
void desencolarYMostrar(EstadioPtr estadio){

    DatoPtr eliminado = desencolar(estadio->personas);
    mostrarPersonaDatoPtr(eliminado);
};

void liberarEstadio(EstadioPtr estadio){

    if(estadio == NULL)return;

    if(estadio->personas != NULL){
        liberarCola(estadio->personas);
    }

    free(estadio);

}
