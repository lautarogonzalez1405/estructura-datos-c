#ifndef ESTADIO_H_INCLUDED
#define ESTADIO_H_INCLUDED

#include "nodo.h"
#include "persona.h"

struct Estadio;

typedef struct Estadio * EstadioPtr;

//Getters y setters

char* getNombreEstadio(EstadioPtr estadio);
int getCapacidadEstadio(EstadioPtr estadio);
char* getLocalidadEstadio(EstadioPtr estadio);
ColaPtr getColaPersonas(EstadioPtr estadio);

void setNombreEstadio(EstadioPtr estadio, char nuevoNombre[20]);
void setCapacidadEstadio(EstadioPtr estadio, int nuevaCapacidad);
void setLocalidadEstadio(EstadioPtr estadio, char nuevaLocalidad[20]);
void setColaPersonas(EstadioPtr estadio, ColaPtr nuevaCola);

EstadioPtr crearEstadio(char* nombre, int capacidad, char* localidad);
void encolarPersonas(EstadioPtr estadio, DatoPtr persona);
void mostrarEstadio(EstadioPtr estadio);
void desencolarYMostrar(EstadioPtr estadio);
void liberarEstadio(EstadioPtr estadio);

#endif // ESTADIO_H_INCLUDED
