#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int TareaID;
    char *Descripcion;
    int Duracion;
    int estado; // 1 pendiente, 2 realizada, 3 en proceso
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
} TNodo;

// GENERAR ID
int generarId()
{
    static int id = 1000;
    return id++;
}

//***CREACION DE NODO***
TNodo *crearNodo(int id, char *descripcion, int duracion, int estado)
{                                                  // con esta funcion creamos un nuevo nodo, no es lo mismo que insertar nodo
    TNodo *NNodo = (TNodo *)malloc(sizeof(TNodo)); // necesitamos reservar un espacio en la memoria para el nodo
    NNodo->T.estado = estado;
    NNodo->T.TareaID = id; // copiamos todos los parametros que recibe la funcion en los espacios de cada informacion de la memoria ya reservada
    NNodo->T.Duracion = duracion;
    NNodo->T.Descripcion = (char *)malloc(strlen(descripcion) + 1); // reservamos espacio para la descripcion
    strcpy(NNodo->T.Descripcion, descripcion);
    NNodo->Siguiente = NULL;
    return NNodo;
}

//***INSERTAR DE NODO***
void insertarNodo(TNodo **start, TNodo *Nodo)
{
    // TNodo *nuevoNodo = (TNodo *)malloc(sizeof(TNodo)); //
    if (Nodo == NULL)
    {
        printf("No se puede asignar memoria al nodo.\n");
        // return start;
    }

    Nodo->T.TareaID = Nodo->T.TareaID;
    Nodo->T.Duracion = Nodo->T.Duracion;
    Nodo->T.Descripcion = (char *)malloc(strlen(Nodo->T.Descripcion) + 1);
    if (Nodo->T.Descripcion == NULL)
    {
        printf("ERROR:No se asigno correctamente la memoria.\n");
        free(Nodo);
        // return start;
    }
    strcpy(Nodo->T.Descripcion, Nodo->T.Descripcion);

    Nodo->Siguiente = *start;
    *start = Nodo;
}

//***CREAR NUEVA TAREA***
void crearTarea(TNodo **start)
{
    int continuar;
    int duracion;
    char descripcion[256];
    printf("***NUEVA TAREA***\n");
    do
    {
        int estado = 1, id = generarId();

        printf("Id: %d", id);
        printf("\nIngrese la duracion de la tarea:");
        scanf("%d", &duracion);
        fflush(stdin);
        printf("Ingrese la descripcion de la tarea:");
        gets(descripcion);

        TNodo *aux = crearNodo(id, descripcion, duracion, estado);
        insertarNodo(start, aux);
        if (insertarNodo)
        {
            printf("Tarea cargada correctamente! Id: %d", id);
        }
        printf("\n¿Desea seguir cargando tareas?\n1 - Si\n2 - No");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

TNodo *CrearListaVacia() // Creamos la lista vacía para que inicialice la lista apuntando a NULL
{
    return NULL;
}

// MOSTRAR TODAS LAS TAREA
void mostrarTareas(TNodo *start)
{

    TNodo *actual = start;
    while (actual != NULL)
    {
        printf("Id: %d | Duracion: %d | Descripcion: %s | Estado: %d\n", actual->T.TareaID, actual->T.Duracion, actual->T.Descripcion, actual->T.estado);
        actual = actual->Siguiente;
    }
}

// MOSTRAR TAREAS PENDIENTES
void mostrarTareasPendientes(TNodo *lista, int estado)
{

    while (lista != NULL)
    {
        if (lista->T.estado == 1)
        {
            printf("Id: %d | Descripcion: %s | Duracion: %d | Estado: %d\n", lista->T.TareaID, lista->T.Descripcion, lista->T.Duracion, lista->T.estado);
        }
        lista = lista->Siguiente;
    }
};

// QUITAR NODO

TNodo *quitarNodoPorId(TNodo **lista, int id)
{
    TNodo *nodoaux = *lista;
    TNodo *nodoant = NULL;
    while (nodoaux != NULL && nodoaux->T.TareaID != id)
    {
        nodoant = nodoaux;
        nodoaux = nodoaux->Siguiente;
    }
    if (nodoaux != NULL)
    {
        if (nodoaux == *lista)
        {
            *lista = (*lista)->Siguiente;
        }
        else
        {
            nodoant->Siguiente = nodoaux->Siguiente;
        }
        nodoaux->Siguiente = NULL;
        return nodoaux;
    }

    return NULL;
}

// CAMBIAR ESTADO DE LAS TAREAS

void cambiarARealizada(TNodo **lista,TNodo **lista2)
{
    int idQUITAR;
    printf("\nIngrese el id de la tarea que desea cambiar:");
    scanf("%d",&idQUITAR);
    TNodo * nodoAMover = quitarNodoPorId(lista,idQUITAR);
    if (nodoAMover)
    {
        insertarNodo(lista2,nodoAMover);
        nodoAMover->T.estado = 2;
        printf("Tarea %d: Realizada.",nodoAMover->T.TareaID);
    }else
    {
        printf("El id(%d) no existe",idQUITAR);
    }
}

//cambiar a pendiente

void cambiarApendiente(TNodo **lista, TNodo **lista2){
int id;
printf("Ingrese el id de la tarea que desea cambiar: ");
scanf("%d",&id);
TNodo *nodoAquitar = quitarNodoPorId(lista,id);
if (nodoAquitar)
{
    insertarNodo(lista2,nodoAquitar);
    printf("Tarea %d:PENDIENTE\n",nodoAquitar->T.TareaID);
}else
{
    printf("Id no encontrado\n");
}


}


//CONSULTAR TAREAS POR ID

void consultarTareasPorId(TNodo *lista){
    int id;
    printf("Ingrese el id de la tarea: ");
    scanf("%d",&id);
    while (lista != NULL)
    {
        if (lista->T.TareaID == id)
        {
            printf("Id: %d | Descripcion: %s | Estado: %d | Duracion: %d",lista->T.TareaID,lista->T.Descripcion,lista->T.estado,lista->T.Duracion);
        }
        lista = lista->Siguiente;
    }
    
}

void eliminarNodo(TNodo *nodo){
    if (nodo)
    {
        free(nodo);
    }

}