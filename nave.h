#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED
#include "nodo.h"
#include "comando.h"

struct NaveE;

typedef struct NaveE * NavePtr;

//Getters y Setter
char* getNombreNave(NavePtr nave);
PilaPtr getComandos(NavePtr nave);

void setNombreNave(NavePtr nave, char nuevoNombre[30]);
void setPilaNave(NavePtr nave, PilaPtr nuevaPila);

NavePtr crearNave(char* nombre);
void agregarComando(NavePtr nave, DatoPtr comando);//Apilar los comando en la nave
void ejecutarComando(NavePtr nave);//Desapilar los comandos
void mostrarNave(NavePtr nave);
void liberarNave(NavePtr nave);


#endif // NAVE_H_INCLUDED
