#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
    eEmployee empleados[TAM];
    char salir = 'n';
    char nombre[51];
    char apellido[51];
    char auxStr[100];
    float salario;
    int sector;
    int id=1000;
    int idSearch;
    int index;

    initEmployees(empleados, TAM);

    do{
    switch(menu()){
    case 1:
        //altas
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxStr);

        verifyString(auxStr, nombre, 51, "Error. Nombre muy largo, ingrese nuevamente: ");


        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxStr);
        verifyString(auxStr, apellido, 51, "Error. Apellido muy largo, ingrese nuevamente: ");

        printf("Ingrese salario del empleado: ");
        scanf("%f", &salario);

        printf("Ingrese sector del empleado: ");
        scanf("%d", &sector);

        if(addEmployee(empleados, TAM, id, nombre, apellido, salario, sector)==0){
            id++;
        }
        system("pause");
        break;
    case 2:
        //modificaciones
        if(verifyEmployee(empleados, TAM)==-1){

            printf("Error. Aun no hay empleados en el sistema\n");

        }else{

        printf("Ingrese id a buscar: ");
        scanf("%d", &idSearch);
        index = findEmployeeById(empleados, TAM, idSearch);
        modifyEmployee(empleados, TAM, index);
        }

        system("pause");
        break;
    case 3:
        //baja
        if(verifyEmployee(empleados, TAM)==-1){

            printf("Error. Aun no hay empleados en el sistema\n");

        }else{

        printf("Ingrese Id del empleado a dar de baja: ");
        scanf("%d", &idSearch);
        removeEmployee(empleados, TAM, idSearch);
        }
        system("pause");
        break;
    case 4:
        //informes
        menuInformes(empleados, TAM);
        system("pause");
        break;
    case 5:
        printf("¿confirma salida? ingrese y/n ");
        fflush(stdin);
        scanf("%c", &salir);
        break;
    default:
        printf("opcion invalida\n");
        system("pause");
        fflush(stdin);

        }

    }while(salir=='n');

    return 0;
}
