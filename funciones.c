#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertarNodo(Nodo **start, Tarea nuevaTarea)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->T = nuevaTarea;
    nuevo->siguiente = *start;
    *start = nuevo;
}

void mostrarTareas(Nodo *start)
{
    Nodo *actual = start;
    int i = 1;
    while (actual != NULL)
    {
        printf("\n**Tarea %d**\n", i++);
        printf("Id: %d\n", actual->T.TareaID);
        printf("Descripcion: %s\n", actual->T.descripcion);
        printf("Duracion: %d\n", actual->T.duracion);
        actual = actual->siguiente;
    }
}

int generarId()
{
    static int id = 1000;
    return id++;
}
