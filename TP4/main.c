#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"
#include "controller.h"

int menu();

int main()
{

    char salir = 'n';
    char guardar;
    char aceptar;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaAux = NULL;
    LinkedList* deudores = ll_newLinkedList();
    FILE* pFile = fopen("data.csv", "r");

    if(parser_FromText(pFile, lista))
    {
        fclose(pFile);
    }
    else
    {
        printf("\n\n---- Error al parsear datos del archivo ----\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    listaAux = ll_clone(lista);

    do
    {
        switch(menu())
        {
        case 1:
            //alta;
            controller_addClient(lista);
            break;
        case 2:
            //modificar
            if(ll_isEmpty(lista)==1)
            {
                system("cls");
                printf("--- No hay elementos para mostrar ---\n\n");
                system("pause");
            }
            else
            {
                controller_editClient(lista);
            }

            break;
        case 3:
            //baja
            if(ll_isEmpty(lista)==1)
            {
                system("cls");
                printf("--- No hay elementos para realizar bajas ---\n\n");
                system("pause");
            }
            else
            {
                controller_removeClient(lista);
            }
            break;
        case 4:
            //listar
            if(ll_isEmpty(lista)==1)
            {
                system("cls");
                printf("--- No hay elementos para mostrar ---\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                listClients(lista);
                system("pause");
            }

            break;
        case 5:
            //ordenar
            if(ll_isEmpty(lista)==1)
            {
                system("cls");
                printf("--- No hay elementos para ordenar ---\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                ll_sort(lista, compareClientsById, 0);
                printf("--- Elementos ordenados por Id ---\n\n");
                system("pause");
            }

            break;
        case 6:
            controller_clientDebtor(lista, deudores);
            break;
        case 7:
            system("cls");
            printf("Confirma eliminado de todos los datos guardados? (Ingrese y/n): \n");
            fflush(stdin);
            scanf("%c", &aceptar);
            if(aceptar == 'y'){

                if((ll_clear(lista)) == 0){
                    printf("\n---- Datos eliminados ----\n\n");
                    system("pause");
                }else{
                    printf("\n---- Los datos no se eliminaron ----\n\n");
                    system("pause");
                }

            }else{

                printf("\n---- Accion cancelada ----\n\n");
                system("pause");

            }
            break;
        case 8:
            //salir
            system("cls");

            if(ll_containsAll(lista, listaAux)==0 || ll_len(lista)>ll_len(listaAux))
            {

                printf("Ha realizado cambios en los datos de clientes, desea guardarlos al salir?\n (ingrese y/n): ");
                fflush(stdin);
                scanf("%c", &guardar);
                if(guardar == 'y')
                {
                    if(controller_saveAsText("data.csv", lista))
                    {
                        printf("\n---- Cambios guardados con exito ----\n");
                        salir='y';
                    }
                    else
                    {
                        printf("\n---- Cambios no guardados ----\n");
                        salir='y';
                    }
                }
            }
            salir = 'y';
            break;
        default:
            system("cls");
            printf("\n---- Opcion invalida ----\n\n");
            system("pause");
        }
    }
    while(salir == 'n');

    return 0;
}

int menu()
{

    int opcion;

    system("cls");
    printf("***** Menu de Opciones *****\n\n");
    printf("1. Alta cliente\n");
    printf("2. Modificar datos de cliente\n");
    printf("3. Baja cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Ordenar clientes\n");
    printf("6. Clientes deudores\n");
    printf("7. Eliminar todos los clientes\n");
    printf("8. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
