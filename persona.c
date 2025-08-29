#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

struct PersonaE{
    int dni;
    char nombre[15];
};

int getDNI(PersonaPtr p){
    return p->dni;

};
char* getNombre(PersonaPtr p){

    return p->nombre;
};

void setDNI(PersonaPtr p, int nuevoDNI){

    p->dni = nuevoDNI;
};

void setNombre(PersonaPtr p, char nuevoNombre[15]){

    strcpy(p->nombre, nuevoNombre);
};

PersonaPtr crearPersonaTeclado();

PersonaPtr crearPersona(int d, char n[15]){

    PersonaPtr p = (PersonaPtr)malloc(sizeof(struct PersonaE)); //void *

    p->dni = d;
    strcpy(p->nombre, n);

    return p;

};

PersonaPtr crearPersonaYCarton(int d, char n[15], char dir[15]){

    PersonaPtr p = crearPersona(d,n);

    return p;
}

void destruirPersona(PersonaPtr p){

    free(p);


};

void mostrarPersona(PersonaPtr p){


    printf("\n---------- PERSONA -----------\n");
    printf("DNI: %d\n", p->dni);
    printf("NOMBRE: %s\n", p->nombre);


};

void mostrarPersonaDatoPtr (void * p){

    PersonaPtr persona = *(PersonaPtr *)p;

    mostrarPersona(persona);


}

int compararPersonasDatoPtr(void * p1, void * p2){

    PersonaPtr persona1 = *(PersonaPtr *)p1;
    PersonaPtr persona2 = *(PersonaPtr *)p2;

    return (persona1->dni > persona2->dni);


}

int compararPorDNI(void * dato1, void * dato2) {
    PersonaPtr persona1 = *(PersonaPtr *)dato1;
    PersonaPtr persona2 = *(PersonaPtr *)dato2;

    if (persona1->dni == persona2->dni) {
        return 0;
    } else if (persona1->dni < persona2->dni) {
        return -1;
    } else {
        return 1;
    }
}


int verificar(void* n) {
    PersonaPtr p1 = *(PersonaPtr *)n;
    if (p1->dni % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

PersonaPtr crearPersonaBusqueda(int dni) {
    return crearPersona(dni, "");
}
