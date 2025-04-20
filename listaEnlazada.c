#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int TareaID;
    char *Descripcion;
    int Duracion;
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
int idActual = 1000;

Tarea CrearTarea(char *desc) {
    Tarea nueva;
    nueva.TareaID = idActual++;
    nueva.Descripcion = malloc(strlen(desc) + 1);
    strcpy(nueva.Descripcion, desc);
    nueva.Duracion = rand() % 91 + 10; // Duración entre 10 y 100
    return nueva;
}
void InsertarTarea(Nodo **lista, Tarea t) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T = t;
    nuevoNodo->Siguiente = *lista;
    *lista = nuevoNodo;
}
void MostrarLista(Nodo *lista) {
    while (lista) {
        printf("ID: %d\n", lista->T.TareaID);
        printf("Descripción: %s\n", lista->T.Descripcion);
        printf("Duración: %d minutos\n\n", lista->T.Duracion);
        lista = lista->Siguiente;
    }
}
