#include <stdio.h>
#include <stdlib.h>

struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
};

struct Nodo{
    Tarea T;
    Nodo *Siguiente;
}typedef Nodo;

Nodo * crearListaVacia(){
    return NULL;
}

Nodo * crearNodo( int dato){
    Nodo * NNodo= (*Nodo) malloc(sizeof(Tarea));
    NNodo->Siguiente = NULL;
    return NNodo;
}



void cargaTareas(){
    printf
    ("Ingrese el id de la tarea");

}
int main(){

 
//start = crearListaVacia();

    return 0;
}