#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


void menuInformes(eEmployee* vec, int len){

    char salir = 'n';
    int opcion;

    if(verifyEmployee(vec, len)==0){
    do{

    system("cls");
    printf("***** Informes *****\n\n");
    printf("1. Listar empleados\n");
    printf("2. Promedio de salarios y empleados que superan dicho promedio\n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
case 1:
    system("cls");
    printf("****Listado empleados****\n\n");
    sortEmployees(vec, len, 0);
    printEmployees(vec, len);
    system("pause");
    break;
case 2:
    system("cls");
    informSalaryAverage(vec, len);
    system("pause");
    break;
case 3:
    printf("¿Confirma salida? ingrese y/n: ");
    fflush(stdin);
    scanf("%c", &salir);
        }

    }while(salir=='n');
    }else{

    printf("ERROR. Aun no hay empleados en el sistema\n\n");

    }
}


void informSalaryAverage(eEmployee* vec, int len){

    float acumuladorSalarios=0;
    float promedioSalarios;
    int contador=0;
    int flag = 0;

    for(int i=0; i<len; i++){

        if(vec[i].isEmpty==0){
        acumuladorSalarios=acumuladorSalarios + vec[i].salary;
        contador++;
        }
    }

    promedioSalarios=(float)acumuladorSalarios/contador;

    printf("\n\nSumatoria salarios: %.2f\n", acumuladorSalarios);
    printf("Promedio salarios: %.2f\n", promedioSalarios);
    printf("\nEmpleados con sueldo superior al promedio: \n");

    for(int i=0; i<len; i++){

        if(vec[i].salary > promedioSalarios && vec[i].isEmpty == 0){

        printEmployee(vec[i]);
        flag=1;

        }
    }

    if(flag==0){

        printf("NO HAY EMPLEADOS QUE SUPEREN EL SALARIO PROMEDIO\n");

    }


}

void verifyString(char* auxString, char* string, int len, char* message){

    while(strlen(auxString)>len-1){

        printf(message);
        fflush(stdin);
        gets(auxString);

    }
    strcpy(string, auxString);


}


int menu(){

    int opcion;
    system("cls");
    printf("----- Menu de Opciones-----\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informe\n");
    printf("5. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    system("cls");

    return opcion;
}

int modifyEmployee(eEmployee* vec, int len, int index){

    int r=-1;
    int opcion;
    char continuar = 'y';
    char auxStr[100];
    char nombre[51];
    char apellido[51];
    float salary;
    int sector;

    if(index==-1){

        printf("Error, no se encuentra empleado\n\n");

    }else{

    do{
    system("cls");
    printf("***Modificar***\n\n");
    printEmployee(vec[index]);
    printf("\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
case 1:
    printf("Ingrese nuevo nombre: ");
    fflush(stdin);
    gets(auxStr);
    verifyString(auxStr, nombre, 51, "Error, nombre demasiado largo, ingrese nuevamente: ");
    strcpy(vec[index].name, nombre);
    break;
case 2:
    printf("Ingrese nuevo apellido: ");
    fflush(stdin);
    gets(auxStr);
    verifyString(auxStr, nombre, 51, "Error, apellido demasiado largo, ingrese nuevamente: ");
    strcpy(vec[index].lastName, apellido);
    break;
case 3:
    printf("Ingrese nuevo salario: ");
    scanf("%f", &salary);
    vec[index].salary=salary;
    break;
case 4:
    printf("Ingrese nuevo sector: ");
    scanf("%d", &sector);
    vec[index].sector=sector;
    break;
default:
    printf("---Opcion incorrecta---");
        }

    printf("\n¿Desea realizar otra operacion? ingrese y/n: ");
    fflush(stdin);
    scanf("%c", &continuar);

    }while(continuar=='y');

    r=0;

    }
    if(r==0){

        printf("\nModificacion realizada con exito\n\n");

    }else{

        printf("\nNo se han realizado las modificaciones");

    }

return r;
}

int verifyEmployee(eEmployee* vec, int len){

    int r=-1;
    for(int i=0; i<len; i++){

        if(vec[i].isEmpty==0){
            r=0;
            break;
        }

    }
    return r;
}


int initEmployees(eEmployee* vec, int len){

    int r=-1;
    for(int i=0; i<len; i++){
        vec[i].isEmpty = 1;
        r=0;
    }
    if(r==-1){

        printf("***ALERTA. No hay capacidad en base de datos***");

    }
    return r;
}



int addEmployee(eEmployee* vec, int len, int id, char* name, char* lastName, float salary, int sector){

    int r=-1;

    for (int i=0; i<len; i++){

        if(vec[i].isEmpty==1){

        vec[i].id=id;
        strcpy(vec[i].name, name);
        strcpy(vec[i].lastName, lastName);
        vec[i].salary=salary;
        vec[i].sector=sector;
        vec[i].isEmpty=0;
        r=0;
        break;
        }
    }
        if(r==-1){

            printf("***Error, no se ha podido realizar el alta***\n\n");

        }else{

        printf("***Alta realizada con exito***\n\n");
        }

    return r;

}

int removeEmployee(eEmployee* vec, int len, int id){

    int r=-1;
    for(int i=0; i<len; i++){

        if(vec[i].id==id){

            vec[i].isEmpty=1;
            r=0;
            break;

        }
    }
    if(r==0){

        printf("\nBaja realizada con exito");

    }else{

        printf("\nAlta realizada con exito");

    }



    return r;
}

int findEmployeeById(eEmployee* vec, int len, int id){

    int index=-1;

    for(int i=0; i<len; i++){

        if(vec[i].id==id  &&  vec[i].isEmpty==0){
            index=i;
        }
    }


return index;
}

int sortEmployees(eEmployee* vec, int len, int order){

    int swap;
    eEmployee auxiliar;

    for(int i=0; i<len-1; i++){

        for(int j=i+1; j<len; j++){
            swap = 0;
            if(order==1){

            if(vec[i].sector<vec[j].sector){

                swap=1;

            }else if(vec[i].sector==vec[j].sector && strcmp(vec[i].lastName,vec[j].lastName)>0){

            swap=1;

            }

            }else if(order==0){

            if(vec[i].sector>vec[j].sector){

                swap=1;

            }else if(vec[i].sector==vec[j].sector && strcmp(vec[i].lastName,vec[j].lastName)>0){

            swap=1;

            }
            }
            if(swap==1){

                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;

            }

        }
    }

    return 0;
}

int printEmployees(eEmployee* vec, int len){

    if(verifyEmployee(vec, len)==0){

    printf("  ID                Nombre           Apellido   Salario    Sector \n\n");

    for(int i=0; i<len; i++){

        if(vec[i].isEmpty==0){

        printEmployee(vec[i]);

        }

    }
    }else{

    printf("No hay empleados para mostrar\n\n");

    }
return 0;
}

void printEmployee(eEmployee x){

    printf("%5d    %15s     %15s    %6.2f   %2d\n", x.id, x.name, x.lastName, x.salary, x.sector);

}
