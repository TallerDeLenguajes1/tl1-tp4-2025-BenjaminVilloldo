#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1) Desarrolle una interfaz de carga de tareas para solicitar tareas pendientes, 
//en la cual se solicite descripción y duración de la misma (el id debe ser generado automáticamente por el sistema,
// de manera autoincremental comenzando desde el número 1000). 
//Al cabo de cada tarea consulte al usuario si desea ingresar una nueva tarea o finalizar la carga. 
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
        printf("Duracion: %d\n",actual->T.duracion);
        actual = actual->siguiente;
    }
    
}

int generarId(){
    static int id = 1000;
    return id++;
}




int main(){
    
int id,duracion,cantidadTareas;
char descripcion[100];

Nodo * lista = NULL; // iniciamos en null
Tarea tarea1;//creamos un dato, tipo de dato Tarea


//Cantidad de tareas
printf("Primero ingrese la cantidad de tarea: ");
scanf("%d",&cantidadTareas);
getchar();
for (int i = 0; i < cantidadTareas; i++)
{
    
//ID
tarea1.TareaID=generarId();

//Descripcion
printf("Ingrese la descripcionde de la tarea: ");
gets(descripcion);
tarea1.descripcion=descripcion;
id = rand()% 1000;

//Duracion
printf("Ingrese la duracion en horas de la tarea: ");
scanf("%d",&duracion);
tarea1.duracion=duracion;
}


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


