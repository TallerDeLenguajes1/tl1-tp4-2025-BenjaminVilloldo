#include <stdio.h>
#include <stdlib.h>

struct{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

struct Nodo{
    Tarea T;
    Nodo *Siguiente;
}typedef Nodo;

Nodo * crearListaVacia(){
    return NULL;
}


Nodo * crearNodo(Tarea *descripcion , int duracion , int ID){
    Nodo * NNodo= (Nodo*) malloc(sizeof(Nodo));
    NNodo->T.Descripcion= descripcion;
    NNodo->T.Duracion = duracion;
    NNodo->T.TareaID = ID;
    NNodo->Siguiente = NULL;
    return NNodo;
}

void InsertarNodo(Nodo ** Star, Nodo *Nodito){
    Nodito->Siguiente = *Star;
    *Star = Nodito;
    printf("\n");
    printf("Creando Tarea ID: %d \n", Nodito->T.TareaID);
    printf("\n");
}



void cargaTareas(Nodo ** Star){
    char continuar;
    char descripcion[100];
    int duracion = 0;
    int id = 0;
    do{
        printf("Ingresa los datos de la tarea \n");
        printf("Descripcion: ");
        gets(descripcion);
        fflush(stdin);
        printf("\nIngresa la duracion entre 10 y 100 :\n");
        scanf("%d", &duracion);
        fflush(stdin);
        printf("\nIngrese un id : ");
        scanf("%d", &id);
        InsertarNodo(Star , crearNodo(descripcion,duracion,id));
        printf("\n Desea ingresar otra tarea? (s/n)");
        scanf("%c", &continuar);
        fflush(stdin);
    }while (continuar == 's' || continuar == 'S');
    

}

void eliminarNodo(Nodo  * nodito){

    if (nodito) free(nodito); 
}
int main(){

    int eleccion;
    Nodo * Star;
   Star = crearListaVacia();
    printf("**Elija un opcion para realizar**\n");
    printf("1) Buscar tarea por nombre\n");
    scanf("%d",&eleccion);



   return 0;
}