#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include "nodo.h"
#include "persona.h"

struct LibroE;

typedef struct LibroE * LibroPtr;

//Getters y Setters
int getAnio(LibroPtr libro);
char* getNombreLibro(LibroPtr libro);
char* getAutor(LibroPtr libro);
ColaPtr getColaReservas(LibroPtr libro);

void setAnio(LibroPtr libro, int nuevoAnio);
void setNombreLibro(LibroPtr libro, char nuevoNomobre[40]);
void setAutor(LibroPtr libro, char nuevoAutor[20]);
void setColaReservas(LibroPtr libro, ColaPtr nuevaCola);

LibroPtr crearLibro(char* titulo, char* autor, int anio);//Crea hilo con datos por parametro
void reservarLibro(LibroPtr libro, DatoPtr persona);//Encola a una persona con el libro
void mostrarLibro(LibroPtr libro);
void entregarSiguienteReserva(LibroPtr libro);//Desencola una persona y la muestra


#endif // LIBRO_H_INCLUDED
