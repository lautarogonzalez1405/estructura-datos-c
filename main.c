#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "persona.h"
#include "pila.h"
#include "cola.h"
#include "estadio.h"
#include "libro.h"
#include "nave.h"

int main()
{

    /*ListaPtr nuevaLista = crearLista();

    int n1 = 3, n2=4, n3=5, n4=6, n5 = 9, n6 = 321, n7 = 53, n8 = 412;

    insertarPrimero(nuevaLista, &n1);
    insertarPrimero(nuevaLista, &n2);
    insertarPrimero(nuevaLista, &n3);
    insertarPrimero(nuevaLista, &n4);
    //insertarPrimero(nuevaLista, 7);

    insertarUltimo(nuevaLista, &n5);
    insertarUltimo(nuevaLista, &n6);
    insertarUltimo(nuevaLista, &n7);

    insertarPosicion(nuevaLista, &n8, 2);

    mostrarLista(nuevaLista);

    ListaPtr listaFloat = crearLista();

    float f1 = 3.41, f2 = 5.65, f3 = 2.42;

    insertarPrimero(listaFloat, &f1);
    insertarUltimo(listaFloat, &f2);
    insertarPosicion(listaFloat, &f3, 1);

    mostrarListaFloat(listaFloat);**/

    PersonaPtr persona1 = crearPersona(43, "Lautaro");
    PersonaPtr persona2 = crearPersona(41, "Carla");
    PersonaPtr persona3 = crearPersona(48, "Roberto");
    PersonaPtr persona4 = crearPersona(542, "Pedro");
    PersonaPtr persona5 = crearPersona(22, "Lucia");

    /*ListaPtr listaPersonas = crearLista();

    insertarPrimero(listaPersonas, &persona1);
    insertarPrimero(listaPersonas, &persona2);
    insertarPrimero(listaPersonas, &persona3);
    insertarPrimero(listaPersonas, &persona4);
    insertarPrimero(listaPersonas, &persona5);

    mostrarListaGenerica(listaPersonas, mostrarPersonaDatoPtr);
    ordenarLista(listaPersonas, compararPersonasDatoPtr);
    mostrarListaGenerica(listaPersonas, mostrarPersonaDatoPtr);

    PilaPtr pilaPersonas = crearPila();

    apilar(pilaPersonas, persona1);
    apilar(pilaPersonas, persona2);
    apilar(pilaPersonas, persona3);
    apilar(pilaPersonas, persona4);
    apilar(pilaPersonas, persona5);

    PilaPtr pilaDupli = duplicarPila(pilaPersonas);
    liberarPilaMostrar(pilaDupli, mostrarPersonaDatoPtr);

    liberarPila(pilaPersonas);

    ColaPtr cola1 = crearCola();

    encolar(cola1, &persona1);
    encolar(cola1, &persona2);
    encolar(cola1, &persona3);
    encolar(cola1, &persona4);
    encolar(cola1, &persona5);

    ColaPtr dupli = duplicarCola(cola1);
    liberarColaMostrar(dupli, mostrarPersonaDatoPtr);
    liberarColaMostrar(cola1, mostrarPersonaDatoPtr);

    EstadioPtr estadio1 = crearEstadio("Jose Larralde", 20000, "Ramos Mejia");
    encolarPersonas(estadio1, &persona1);
    encolarPersonas(estadio1, &persona2);
    encolarPersonas(estadio1, &persona3);
    encolarPersonas(estadio1, &persona4);
    encolarPersonas(estadio1, &persona5);


    mostrarEstadio(estadio1);
    desencolarYMostrar(estadio1);
    desencolarYMostrar(estadio1);
    desencolarYMostrar(estadio1);
    desencolarYMostrar(estadio1);
    desencolarYMostrar(estadio1);
    liberarEstadio(estadio1);*/

    LibroPtr libro1 = crearLibro("Harry potter y la piedra filosofal", "J.K. Rowling.", 1997);

    reservarLibro(libro1, &persona1);
    reservarLibro(libro1, &persona2);
    reservarLibro(libro1, &persona3);
    reservarLibro(libro1, &persona4);
    reservarLibro(libro1, &persona5);

    mostrarLibro(libro1);
    entregarSiguienteReserva(libro1);
    entregarSiguienteReserva(libro1);
    entregarSiguienteReserva(libro1);

    NavePtr nave = crearNave("Apollo XI");
    ComandoPtr c1 = crearComando("Activar Motor");
    ComandoPtr c2 = crearComando("Prender Luces");

    agregarComando(nave, &c1);
    agregarComando(nave, &c2);

    mostrarNave(nave);
    ejecutarComando(nave);


    return 0;
}
