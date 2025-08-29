#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "cola.h"
#include "libro.h"

struct LibroE{

    char nombre[40];
    char autor[20];
    int anio;
    ColaPtr reservas;

};
int getAnio(LibroPtr libro){

    return libro->anio;

};
char* getNombreLibro(LibroPtr libro){

    return libro->nombre;

};
char* getAutor(LibroPtr libro){

    return libro->autor;

};
ColaPtr getColaReservas(LibroPtr libro){

    return libro->reservas;

};

void setAnio(LibroPtr libro, int nuevoAnio){

    libro->anio = nuevoAnio;

};
void setNombreLibro(LibroPtr libro, char nuevoNomobre[40]){

    strcpy(libro->nombre, nuevoNomobre);

};
void setAutor(LibroPtr libro, char nuevoAutor[20]){

    strcpy(libro->autor, nuevoAutor);

};
void setColaReservas(LibroPtr libro, ColaPtr nuevaCola){

    libro->reservas = nuevaCola;

};

LibroPtr crearLibro(char* titulo, char* autor, int anio){

    LibroPtr libro = (LibroPtr)malloc(sizeof(struct LibroE));

    libro->anio = anio;
    strcpy(libro->nombre, titulo);
    strcpy(libro->autor, autor);
    libro->reservas = crearCola();
    return libro;

};//Crea hilo con datos por parametro
void reservarLibro(LibroPtr libro, DatoPtr persona){

    encolar(libro->reservas, persona);

};//Encola a una persona con el libro

void mostrarLibro(LibroPtr libro){

    printf("\n--------LIBRO---------\n");
    printf("Titulo: %s\n", libro->nombre);
    printf("Autor: %s\n", libro->autor);
    printf("Anio de publicacion: %d\n", libro->anio);

};
void entregarSiguienteReserva(LibroPtr libro){

    DatoPtr eliminado = desencolar(libro->reservas);
    printf("\nEntregada la reserva de:");
    mostrarPersonaDatoPtr(eliminado);

};//Desencola una persona y la muestra
