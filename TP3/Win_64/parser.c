#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char buffer [4][120];
    int cantidad = 0;
    Employee* auxEmployee = NULL;

    if(pArrayListEmployee == NULL || pFile == NULL)
    {
        printf("Error al parsear archivo. NULL1\n\n");
        system("pause");
        return 0;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {

        cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if(cantidad==4)
        {
            auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            if(auxEmployee != NULL)
            {

                ll_add(pArrayListEmployee, auxEmployee);

            }
            else
            {

                printf("Error. No se pudo conseguir memoria para parsear empleados\n");
                system("pause");
                return 0;

            }
        }
        else
        {

            printf("Error. No se pudo conseguir los valores de empleados\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int okRead = 0;
    Employee* auxEmployee = NULL;

    if(pArrayListEmployee == NULL || pFile == NULL)
    {

        printf("Error al parsear archivo. Path no valido\n\n");
        system("pause");
        return 0;
    }

    while(!feof(pFile))
    {

        auxEmployee = employee_new();
        if(auxEmployee != NULL)
        {
            okRead = fread(auxEmployee, sizeof(Employee), 1, pFile);
        }
        else
        {

            printf("Error. No se pudo conseguir memoria para parsear empleados\n");
            system("pause");
            return 0;

        }
        if(okRead==1)
        {
            ll_add(pArrayListEmployee, auxEmployee);
        }
    }
    return 1;
}
