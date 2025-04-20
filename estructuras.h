#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct
{
    int TareaID;
    char *descripcion;
    int duracion;
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *siguiente;
} Nodo;

// Declaración de la función generadora de ID
int generarId();

#endif