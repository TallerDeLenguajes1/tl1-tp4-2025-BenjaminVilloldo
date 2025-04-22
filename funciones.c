#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voids.h"

int main()
{
    TNodo *Start = NULL; // Lista de tareas pendientes
    TNodo *StartRealizadas = NULL; // Lista de tareas realizadas

    int eleccion, idQuitar,eleccionEstado;

    while (1)
    {
        printf("\n--- Elija una funcionalidad de la lista ---\n");
        printf("1 - Cargar tarea pendiente\n");
        printf("2 - Consultar tareas\n");
        printf("3 - Cambiar el estado de una tarea\n");
        printf("4 - Quitar un nodo\n");
        printf("5 - Salir\n");
        printf("Opción: ");
        scanf("%d", &eleccion);

        switch (eleccion)
        {
        case 1:
            printf("\n*** CARGA DE TAREAS ***\n");
            crearTarea(&Start);
            break;

        case 2:
            if (Start == NULL && StartRealizadas == NULL)
            {
                printf("No hay tareas para mostrar.\n");
            }
            else
            {
                int subopcion;
                printf("\n*** CONSULTA DE TAREAS ***\n");
                printf("1 - Ver todas las tareas\n");
                printf("2 - Solo pendientes\n");
                printf("3 - Solo realizadas\n");
                printf("4 - Consultar tarea por ID\n");
                printf("Opción: ");
                scanf("%d", &subopcion);

                switch (subopcion)
                {
                case 1:
                    printf("\n-- PENDIENTES --\n");
                    if (Start != NULL)
                        mostrarTareas(Start);
                    else
                        printf("Lista de pendientes vacía.\n");

                    printf("\n-- REALIZADAS --\n");
                    if (StartRealizadas != NULL)
                        mostrarTareas(StartRealizadas);
                    else
                        printf("Lista de realizadas vacía.\n");
                    break;

                case 2:
                    printf("\n-- TAREAS PENDIENTES --\n");
                    mostrarTareasPendientes(Start, 1); // Estado 1 = pendiente
                    break;

                case 3:
                    printf("\n-- TAREAS REALIZADAS --\n");
                    mostrarTareasPendientes(StartRealizadas, 2); // Estado 2 = realizada
                    break;

                case 4:
                    consultarTareasPorId(Start);
                    break;

                default:
                    printf("Opción no válida.\n");
                    break;
                }
            }
            break;

        case 3:
        
            printf("¿Que desea hacer?\n1 - Cambiar a realizada\n2 - Cambiar a pendiente\nOpcion: ");
            scanf("%d",&eleccionEstado);
            switch (eleccionEstado)
            {
            case 1:
            cambiarARealizada(&Start, &StartRealizadas);//1 cammbiar a realizada 2 cambiar a pendiente
                break;
            case 2:
            cambiarApendiente(&StartRealizadas,&Start);
            break;
            default:
                break;
            }
            break;

        case 4:
            printf("Ingrese el ID del nodo a quitar: ");
            scanf("%d", &idQuitar);
            TNodo *Nodoquitado = quitarNodoPorId(&Start, idQuitar);
            if (Nodoquitado != NULL)
            {
                printf("La tarea fue quitada. ID: %d\n", Nodoquitado->T.TareaID);
                free(Nodoquitado->T.Descripcion);
                free(Nodoquitado);
            }
            else
            {
                printf("La tarea no fue encontrada.\n");
            }
            break;

        case 5:
            printf("Saliendo del programa...\n");
            return 0;

        default:
            printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    }

    return 0;
}
