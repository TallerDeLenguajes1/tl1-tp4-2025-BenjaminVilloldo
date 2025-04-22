#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voids.h"

int main()
{
    TNodo *Start = NULL; // al hacer esto inicializamos la lista desde el principio, LA INICIALIZAMOS EN null;
    TNodo *StartRealizadas = NULL;

    int id, eleccion,idQuitar;
    char descripcion;
    int duracion, estado;

    while (eleccion != 6)
    {
        printf("\n---Elija una funcionalidad de la lista---\n");
        printf("1 - Cargar tarea pendiente\n2 - Consultar tareas\n3 - Cambiar el estado de una tarea\n4 - Quitar un nodo");
        scanf("%d", &eleccion);
        switch (eleccion)
        {
        case 1:
            printf("***CARGA DE TAREAS***\n");
            crearTarea(&Start);
            break;
        case 2:
            printf("***LISTA DE TAREAS***\n");

            if (Start == NULL)
            {
                printf("No hay tareas para mostrar.");
                break;
            }
            else
            {
                int eleccion;
                printf("1 - Ver todas las tareas \n 2 - Ver tareas pendientes \n 3 - Ver tareas realizadas\n4 - Consultar tarea por id");
                scanf("%d",&eleccion);

                if (eleccion == 1)
                {
                    mostrarTareas(Start);
                }
                if (eleccion == 2)
                {
                    printf("***Pendientes***\n");
                    mostrarTareasPendientes(Start,0);
                }
                if (eleccion == 4)
                {
                    consultarTareasPorId(Start);
                }
            }

            break;

        case 3:
        
        break;
        case 4:
        printf("Ingrese el id del nodo a quitar:");
        scanf("%d",&idQuitar);
        TNodo * Nodoquitado = quitarNodoPorId(&Start,idQuitar);
        if (Nodoquitado != NULL)
        {
            printf("La tarea de id fue quitado: %d",Nodoquitado->T.TareaID);
            free(Nodoquitado->T.Descripcion);
            free(Nodoquitado);
        }else
        {
            printf("La tarea no fue encontrada.");
        }
        
        break;
        default:
            break;
        }
    }

    return 0;
}
