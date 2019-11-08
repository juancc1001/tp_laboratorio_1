#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int menu();

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char salir='n';

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(ll_isEmpty(listaEmpleados)==1)
            {
                controller_loadFromText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Ya se realizo la carga de datos anteriormente\n\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            if(ll_isEmpty(listaEmpleados)==1)
            {
                controller_loadFromBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Ya se realizo la carga de datos anteriormente\n\n");
                system("pause");
            }
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados)==1){
                system("cls");
                printf("--- No hay empleados cargados en sistema ---\n\n");
                system("pause");
            }else{
            controller_editEmployee(listaEmpleados);
            }
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados)==1){
                system("cls");
                printf("--- No hay empleados cargados en sistema ---\n\n");
                system("pause");
            }else{
            controller_removeEmployee(listaEmpleados);
            }
            break;
        case 6:
            if(ll_isEmpty(listaEmpleados)==1){
                system("cls");
                printf("--- No hay empleados cargados en sistema ---\n\n");
                system("pause");
            }else{
            system("cls");
            printf("--- Listado de empleados ---\n\n");
            controller_ListEmployee(listaEmpleados);
            }
            break;
        case 7:
            if(ll_isEmpty(listaEmpleados)==1){
                system("cls");
                printf("--- No hay empleados cargados en sistema ---\n\n");
                system("pause");
            }else{
            controller_sortEmployee(listaEmpleados);
            }
            break;
        case 8:
            if(ll_isEmpty(listaEmpleados)==1)
            {
                system("cls");
                printf("--- No hay datos para guardar ---\n\n");
                system("pause");
            }
            else
            {
                if(controller_saveAsText("data.csv", listaEmpleados))
                {
                    system("cls");
                    printf("---Datos guardados correctamente---\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("--- Error al guardar los datos ---\n\n");
                    system("pause");

                }
            }
            break;
        case 9:
            //guardar binario
            if(ll_isEmpty(listaEmpleados)==1)
            {
                system("cls");
                printf("--- No hay datos para guardar ---\n\n");
                system("pause");
            }
            else
            {
                if(controller_saveAsBinary("data.bin", listaEmpleados))
                {
                    system("cls");
                    printf("--- Datos guardados correctamente ---\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("--- Error al guardar los datos ---\n\n");
                    system("pause");
                }
            }
            break;
        case 10:
            printf("Confirma salida? (ingrese y/n) ");
            fflush(stdin);
            scanf("%c", &salir);
            ll_deleteLinkedList(listaEmpleados);
            break;
        default:
            printf("Opcion invalida\n\n");
            system("pause");
            break;
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
    printf("1. Cargar datos de empleados desde el archivo de texto\n");
    printf("2. Cargar datos de empleados desde el archivo binario\n");
    printf("3. Alta empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar datos de empleados en modo texto\n");
    printf("9. Guardar datos de empleados en binario\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
