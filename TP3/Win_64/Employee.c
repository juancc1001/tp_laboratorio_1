#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


/** \brief Elimina datos del empleado de la memoria
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this){

    free(this);

}

/** \brief Crea nuevo empleado
 *
 * \return Employee* puntero al nuevo empleado
 *
 */
Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

/** \brief Crea nuevo empleado y lo carga con los parametros dados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* parametrizado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevo = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    if(nuevo != NULL)
    {

        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);

        if((employee_setId(nuevo, id) &&
                employee_setNombre(nuevo,nombreStr) &&
                employee_setSueldo(nuevo, sueldo) &&
                employee_setHorasTrabajadas(nuevo, horasTrabajadas))==0)
        {
            printf("error en atoi");
            system("pause");
            nuevo=NULL;
        }
    }

    return nuevo;
}

/** \brief Guarda Id en el empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{

    int ok=0;
    Employee* e = this;

    if(e != NULL && id>0 && id<9999)
    {

        e->id = id;
        ok=1;

    }

    return ok;
}

/** \brief Obtiene el Id del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{

    int ok=0;
    Employee* e = this;

    if(e != NULL && id!=NULL)
    {

        *id = e->id;
        ok=1;

    }

    return ok;
}

/** \brief Guarda nombre en empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int ok=0;
    Employee* e = this;

    if(e != NULL && nombre != NULL && strlen(nombre)>0 && strlen(nombre)<128)
    {
        strcpy(e->nombre, nombre);
        ok=1;
    }

    return ok;
}

/** \brief Obtiene el nombre de una estructura empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    Employee* e = this;
    int ok=0;

    if(e != NULL && nombre!=NULL)
    {

        strcpy(nombre, e->nombre);
        ok=1;

    }

    return ok;
}

/** \brief Guarda horas trabajadas en estructura empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    Employee* e = this;
    int ok=0;

    if(e != NULL && horasTrabajadas>0)
    {

        e->horasTrabajadas = horasTrabajadas;
        ok=1;

    }
    return ok;
}

/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int ok=0;
    Employee* e = this;

    if(e != NULL && horasTrabajadas!=NULL)
    {

        *horasTrabajadas = e->horasTrabajadas;
        ok=1;

    }

    return ok;
}

/** \brief Guarda valor de sueldo en estructura empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{

    int ok=0;
    Employee* e = this;

    if(e != NULL && sueldo>0)
    {
        e->sueldo = sueldo;
        ok=1;
    }

    return ok;
}

/** \brief Obtiene el valor de sueldo de una estructura empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{

    int ok=0;
    Employee* e = this;


    if(e != NULL && sueldo!=NULL)
    {

        *sueldo = e->sueldo;
        ok=1;

    }

    return ok;
}


/** \brief Encuentra empleado con el Id dado
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int indice (Error: -1)
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id)
{
    Employee* aux = NULL;
    int index = -1;

    if(pArrayListEmployee == NULL)
    {
        return -1;
    }

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {

        aux = (Employee*) ll_get(pArrayListEmployee, i);
        if(aux->id == id)
        {
            index = i;
        }
    }
    return index;
}


/** \brief muestra en consola los datos de un empleado
 *
 * \param employee Employee*
 * \return int
 *
 */
int  employee_print(Employee* employee)
{

    if(employee==NULL)
    {
        return 0;
    }
    else
    {

        printf("%04d  %25s   %4d   %6d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

    }
    return 1;
}


/** \brief Compara dos empleados
 *
 * \param employee1 void*
 * \param employee2 void*
 * \return int
 *
 */
int employee_compareById(void* employee1, void* employee2)
{

    Employee* empleado1 = (Employee*) employee1;
    Employee* empleado2 = (Employee*) employee2;

    int id1;
    int id2;

    employee_getId(empleado1, &id1);
    employee_getId(empleado2, &id2);

    if(id1 == id2)
    {
        return 0;
    }
    else if(id1 > id2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/** \brief Compara dos empleados
 *
 * \param employee1 void*
 * \param employee2 void*
 * \return int
 *
 */
int employee_compareByName(void* employee1, void* employee2)
{

    Employee* empleado1 = (Employee*) employee1;
    Employee* empleado2 = (Employee*) employee2;

    char nombre1[100];
    char nombre2[100];

    employee_getNombre(empleado1, nombre1);
    employee_getNombre(empleado2, nombre2);

    return strcmp(nombre1, nombre2);
}

/** \brief Compara dos empleados
 *
 * \param employee1 void*
 * \param employee2 void*
 * \return int
 *
 */
int employee_compareBySueldo(void* employee1, void* employee2)
{

    Employee* empleado1 = (Employee*) employee1;
    Employee* empleado2 = (Employee*) employee2;

    int sueldo1;
    int sueldo2;

    employee_getSueldo(empleado1, &sueldo1);
    employee_getSueldo(empleado2, &sueldo2);

    if(sueldo1 == sueldo2)
    {
        return 0;
    }
    else if(sueldo1 > sueldo2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/** \brief Compara dos empleados
 *
 * \param employee1 void*
 * \param employee2 void*
 * \return int
 *
 */
int employee_compareByHorasTrabajadas(void* employee1, void* employee2)
{

    Employee* empleado1 = (Employee*) employee1;
    Employee* empleado2 = (Employee*) employee2;

    int h1;
    int h2;

    employee_getHorasTrabajadas(empleado1, &h1);
    employee_getHorasTrabajadas(empleado2, &h2);

    if(h1 == h2)
    {
        return 0;
    }
    else if(h1 > h2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


