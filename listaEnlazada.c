#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int TareaID; // numero incremental
    char *descripcion;
    int duracion; // entre 10 y 100
} typedef Tarea;

struct
{
    Tarea T;
    struct Nodo* siguiente;
}typedef Nodo;

//-----funciones-----

void insertarNodo(Nodo** start, Tarea nuevaTarea){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->T= nuevaTarea;
    nuevo->siguiente= *start;
    *start = nuevo;
}

void mostrarTareas(Nodo* start){
    Nodo* actual = start;
    while (actual != NULL)
    {
        printf("Id: %d\n",actual->T.TareaID);
        printf("Descripcion: %s\n",actual->T.descripcion);
        printf("Duracion %d\n",actual->T.duracion);
        actual = actual->siguiente;
    }
    
}
int main(){
Nodo * lista = NULL; // iniciamos en null
Tarea tarea1;//creamos un dato, tipo de dato Tarea

//datos de manera dinamica
tarea1.TareaID = 100;
tarea1.duracion = 50;
tarea1.descripcion = strdup("Esta es la descripcion");
//funciones
insertarNodo(&lista ,tarea1);
mostrarTareas(lista);

//liberamos la memoria
Nodo* temp;
while (lista != NULL)
{
    temp= lista;
    lista = lista->siguiente;
    free(temp->T.descripcion);
    free(temp);
}

    return 0;
}


