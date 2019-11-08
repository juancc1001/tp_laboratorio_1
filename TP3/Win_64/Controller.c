#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    if(path==NULL)
    {

        printf("Error, el archivo a leer no es valido\n\n");
        system("pause");
        return 0;

    }
    else
    {
        pFile = fopen(path, "r");
        if(parser_EmployeeFromText(pFile, pArrayListEmployee)==0)
        {
            fclose(pFile);
            return 0;
        }
        else
        {
            printf("Datos cargados exitosamente\n\n");
            system("pause");
            fclose(pFile);
        }
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    if(path==NULL)
    {

        printf("Error, el archivo a leer no es valido\n\n");
        system("pause");
        return 0;

    }
    else
    {
        pFile = fopen(path, "rb");
        if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)==0)
        {

            fclose(pFile);
            return 0;

        }
        else
        {
            system("cls");
            printf("Datos cargados correctamente\n\n");
            system("pause");
            fclose(pFile);
        }
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[120];
    int horasTrabajadas;
    int sueldo;
    Employee* aux = NULL;

    system("cls");
    printf("***** Alta Empleados *****\n\n");

    aux = employee_new();

    if(aux==NULL)
    {
        return 0;
    }

    printf("Ingrese ID del empleado: ");
    scanf("%d", &id);
    while(employee_setId(aux, id)==0 || employee_findById(pArrayListEmployee, id)!=-1)
    {
        printf("Error. Id no valido o ya en uso. Ingrese nuevamente: ");
        scanf("%d", &id);
    }
    printf("Ingrese nombre del empleado: ");
    fflush(stdin);
    scanf("%s", nombre);
    while(employee_setNombre(aux, nombre)==0)
    {
        printf("Error. Ingrese nombre nuevamente: ");
        fflush(stdin);
        scanf("%s", nombre);
    }
    printf("Ingrese horas trabajadas por el empleado: ");
    scanf("%d", &horasTrabajadas);
    while(employee_setHorasTrabajadas(aux, horasTrabajadas)==0)
    {
        printf("Error. Ingrese nuevamente: ");
        scanf("%d", &horasTrabajadas);
    }
    printf("Ingrese sueldo del empleado: ");
    scanf("%d", &sueldo);
    while(employee_setSueldo(aux, sueldo)==0)
    {
        printf("Error. Ingrese sueldo nuevamente: ");
        scanf("%d", &sueldo);
    }

    if(ll_add(pArrayListEmployee, aux) == 1)
    {
        system("cls");
        printf("***** Alta Empleados *****\n\n");
        printf("Error al realizar el alta\n\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("***** Alta Empleados *****\n\n");
    printf("Alta realizada con exito\n\n");
    system("pause");

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int opcion;
    char continuar = 'y';
    int horasT;
    int sueldo;
    char nombre[120];

    if(pArrayListEmployee == NULL)
    {
        printf("Error. Lista de empleados no valida\n\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese el ID del empleado que desea modificar: ");
    scanf("%d", &id);
    index = employee_findById(pArrayListEmployee, id);
    if(index==-1)
    {
        printf("No se ha encontrado el Id en la base de datos\n\n");
        system("pause");
        return 0;
    }
    else
    {
        employee_print((Employee*)ll_get(pArrayListEmployee, index));
        do
        {
            printf("\n1. Nombre \n");
            printf("2. Horas Trabajadas \n");
            printf("3. Sueldo \n");
            printf("Ingrese campo a modificar: \n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nombre);
                while(employee_setNombre((Employee*)ll_get(pArrayListEmployee, index), nombre)==0)
                {
                    printf("Error, nombre no valido, ingrese nuevamente: ");
                    scanf("%s", nombre);
                }
                break;
            case 2:
                printf("Ingrese nuevo valor de 'horas trabajadas': ");
                scanf("%d", &horasT);
                while(employee_setHorasTrabajadas((Employee*)ll_get(pArrayListEmployee, index), horasT)==0)
                {
                    printf("Error, valor no valido, ingrese nuevamente: ");
                    scanf("%d", &horasT);
                }
                break;
            case 3:
                printf("Ingrese nuevo valor de 'sueldo': ");
                scanf("%d", &sueldo);
                while(employee_setSueldo((Employee*)ll_get(pArrayListEmployee, index), sueldo)==0)
                {
                    printf("Error, valor no valido, ingrese nuevamente: ");
                    scanf("%d", &sueldo);
                }
                break;
            default:
                printf("Opcion invalida, intente nuevamente\n");
                break;
            }
            printf("Desea realizar otro cambio? (Ingrese y/n): ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
        while(continuar=='y');

    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int id;
    int index;
    char confirmar;

    if(pArrayListEmployee==NULL){
        printf("Error al realizar la baja\n\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("***** Baja Empleado *****\n\n");
    printf("Ingrese el ID del empleado que desea dar de baja: ");
    scanf("%d", &id);

    if(employee_findById(pArrayListEmployee, id)==-1){

        printf("Error, Id invalido");
        system("pause");
        return 0;

    }else{
    index = employee_findById(pArrayListEmployee, id);
    }
    empleado = (Employee*) ll_get(pArrayListEmployee, index);

    if(empleado==NULL){

        printf("Error al realizar la baja\n\n");
        system("pause");
        return 0;
    }

    employee_print(empleado);

    printf("Confirma baja? (Ingrese y/n): ");
    fflush(stdin);
    scanf("%c", &confirmar);

    if(confirmar == 'y'){
        employee_delete(empleado);
        if(ll_remove(pArrayListEmployee, index)){
            system("cls");
            printf("*** Error, la baja no pudo realizarse ***\n");
            system("pause");
            return 0;
        }else{
        system("cls");
        printf("*** Baja realizada con exito ***\n");
        system("pause");
        }
    }else if(confirmar == 'n'){
        system("cls");
        printf("*** Baja cancelada ***\n");
        system("pause");
        return 0;
    }else {
        system("cls");
        printf("*** Opcion no valida ***\n");
        system("pause");
        return 0;
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;

    if(pArrayListEmployee==NULL){
        printf("Error al listar empleados\n");
        system("pause");
        return 0;
    }

    printf("\nId      Nombre    Horas Trabajadas     Sueldo\n\n");

    for(int i=0; i<ll_len(pArrayListEmployee); i++){

        aux = (Employee*) ll_get(pArrayListEmployee, i);
        employee_print(aux);

    }
    printf("\n\n");
    system("pause");
    return 1;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int criterio;

    system("cls");
    printf("***** Ordenar Empleados *****\n\n");

    printf("Ordenar por: \n");
    printf("1. Id\n");
    printf("2. Nombre\n");
    printf("3. Horas Trabajadas\n");
    printf("4. Sueldo\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("Ingrese criterio: \n0-Descendente\n1-Ascendente  ");
    scanf("%d", &criterio);

    switch(opcion){
    case 1:
        if(!ll_sort(pArrayListEmployee, employee_compareById, criterio)){
            printf("*** Empleados ordenados por Id ***\n\n");
            system("pause");
        }else{
        printf("*** Error al ordenar ***1\n\n");
        system("pause");
        }
        break;
    case 2:
        if(!ll_sort(pArrayListEmployee, employee_compareByName, criterio)){
            printf("*** Empleados ordenados por Nombre ***\n\n");
            system("pause");
        }else{
        printf("*** Error al ordenar ***2\n\n");
        system("pause");
        }
        break;
    case 3:
        if(!ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, criterio)){
            printf("*** Empleados ordenados por horas trabajadas ***\n\n");
            system("pause");
        }else{
        printf("*** Error al ordenar ***3\n\n");
        system("pause");
        }
        break;
    case 4:
        if(!ll_sort(pArrayListEmployee, employee_compareBySueldo, criterio)){
            printf("*** Empleados ordenados por sueldos ***\n\n");
            system("pause");
        }else{
        printf("*** Error al ordenar ***4\n\n");
        system("pause");
        }
        break;
    default:
        printf("*** Opcion no valida ***\n\n");
        system("pause");
        break;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* aux;

    if(path==NULL || pArrayListEmployee==NULL)
    {
        printf("Error al guardar los datos\n\n");
        system("pause");
        return 0;
    }
    pFile = fopen(path, "w");

    if(pFile==NULL)
    {
        printf("Error al guardar los datos\n\n");
        system("pause");
        return 0;
    }

    fprintf(pFile, "Id, Nombre, HorasTrabajadas, Sueldo\n");

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {

        aux = (Employee*)ll_get(pArrayListEmployee, i);
        fprintf(pFile, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }
    fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    if(path==NULL || pArrayListEmployee==NULL)
    {
        printf("Error al guardar los datos\n\n");
        return 0;
    }
    pFile = fopen(path, "wb");

    if(pFile==NULL)
    {
        printf("Error al guardar los datos\n\n");
        return 0;
    }

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {

        fwrite((Employee*)ll_get(pArrayListEmployee, i), sizeof(Employee), 1, pFile);

    }

    fclose(pFile);
    return 1;
}

