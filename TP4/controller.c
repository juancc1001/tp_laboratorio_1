#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "cliente.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer [4][51];
    int cantidad = 0;
    eCliente* aux = NULL;

    if(pArrayList == NULL || pFile == NULL)
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
            aux = cliente_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            if(aux != NULL)
            {
                ll_add(pArrayList, aux);
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
            printf("Error. No se pudo conseguir los valores de clientes\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    eCliente* aux;

    if(path==NULL || pArrayList==NULL)
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

    fprintf(pFile, "Id, Nombre, genero, numeroDeTarjeta\n");

    for(int i=0; i<ll_len(pArrayList); i++)
    {

        aux = (eCliente*)ll_get(pArrayList, i);
        fprintf(pFile, "%d,%s,%c,%lu\n", aux->id, aux->nombre, aux->genero, aux->nroTarjeta);

    }
    fclose(pFile);

    return 1;
}

int controller_addClient(LinkedList* pArrayList)
{
    int id;
    char aceptar;
    eCliente* aux = NULL;

    system("cls");
    printf("***** Alta nuevo cliente *****\n\n");

    aux = cliente_new();

    if(aux==NULL)
    {
        return 0;
    }

    printf("Ingrese ID: ");
    scanf("%d", &id);
    while(setId(aux, id)==0)
    {
        printf("Error. Id no valido. Ingrese nuevamente: ");
        scanf("%d", &id);
    }
    if(findClientById(pArrayList, id)!=-1)
    {

        printf("Id ya en uso, desea sobreescribirlo (ingrese y/n): ");
        fflush(stdin);
        scanf("%c", &aceptar);
        if(aceptar == 'y')
        {
            settersAddClient(aux);
            if(ll_set(pArrayList, findClientById(pArrayList, id), aux)==0)
            {
                system("cls");
                printf("***** Alta Cliente *****\n\n");
                printf("Alta realizada con exito\n\n");
                system("pause");
                return 1;
            }
            else
            {
                system("cls");
                printf("***** Alta Cliente *****\n\n");
                printf("Error al realizar el alta\n\n");
                system("pause");
                return 0;
            }
        }
        else if(aceptar == 'n')
        {

            while(setId(aux, id) == 0 || findClientById(pArrayList, id)!=-1)
            {
                printf("Ingrese ID en desuso: ");
                scanf("%d", &id);
            }
            settersAddClient(aux);

            if(ll_add(pArrayList, aux) == -1)
            {
                system("cls");
                printf("***** Alta Cliente *****\n\n");
                printf("Error al realizar el alta\n\n");
                system("pause");
                return 0;
            }

            system("cls");
            printf("***** Alta Cliente *****\n\n");
            printf("Alta realizada con exito\n\n");
            system("pause");

            return 1;
        }
    }
    else
    {
        settersAddClient(aux);

        if(ll_add(pArrayList, aux) == -1)
        {
            system("cls");
            printf("***** Alta Cliente *****\n\n");
            printf("Error al realizar el alta\n\n");
            system("pause");
            return 0;
        }

        system("cls");
        printf("***** Alta Cliente *****\n\n");
        printf("Alta realizada con exito\n\n");
        system("pause");

        return 1;
    }
    return 1;
}

int controller_clientDebtor(LinkedList* listaClientes, LinkedList* listaDeudores)
{

    int opcion;
    int id;
    eCliente* aux = NULL;

    system("cls");
    printf("****** Clientes Deudores *****\n\n");
    printf("1. Agregar cliente a lista de deudores\n");
    printf("2. Quitar cliente de la lista de deudores\n");
    printf("3. Listar deudores\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
case 1:
    system("cls");
    printf("****** Clientes Deudores *****\n\n");
    printf("Ingrese Id del cliente a agregar a la lista: ");
    scanf("%d", &id);
    if(findClientById(listaClientes, id)== -1){
        printf("---- Cliente no encontrado ----");
        system("pause");
        break;
    }else{
        aux = ll_pop(listaClientes, findClientById(listaClientes, id));
        if(ll_add(listaDeudores, aux)==0){
            printf("---- Cliente aniadido con exito ----\n\n");
            system("pause");
        break;
        }
    }

    break;
case 2:
    system("cls");
    printf("****** Clientes Deudores *****\n\n");
    printf("Ingrese Id del cliente a eliminar de la lista: ");
    scanf("%d", &id);
    if(findClientById(listaDeudores, id)== -1){
        printf("---- Cliente no encontrado ----");
        system("pause");
        break;
    }else{
        aux = ll_pop(listaDeudores, findClientById(listaDeudores, id));
        if(ll_push(listaClientes, findClientById(listaClientes, id-1)+1, aux)==0){
            printf("---- Cliente extraido con exito ----\n\n");
            system("pause");
        break;
        }
    }

    break;
case 3:
    if(ll_isEmpty(listaDeudores)==1)
            {
                system("cls");
                printf("--- No hay elementos para mostrar ---\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                listClients(listaDeudores);
                system("pause");
            }
    break;
default:
    printf("Opcion no valida\n\n");
    }
    return 1;
}

int controller_editClient(LinkedList* pArrayList)
{
    int id;
    int index;
    int opcion;
    char continuar = 'y';
    char genre;
    unsigned long nroTarjeta;
    char nombre[51];

    if(pArrayList == NULL)
    {
        printf("Error. Lista no valida\n\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("***** Modificar datos cliente *****\n\n");
    printf("Ingrese el ID: ");
    scanf("%d", &id);
    index = findClientById(pArrayList, id);
    if(index==-1)
    {
        printf("No se ha encontrado el Id en la base de datos\n\n");
        system("pause");
        return 0;
    }
    else
    {
        printClient((eCliente*)ll_get(pArrayList, index));
        do
        {
            printf("\n1. Nombre \n");
            printf("2. Genero\n");
            printf("3. Numero de tarjeta \n");
            printf("Ingrese campo a modificar: \n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nombre);
                while(setNombre((eCliente*)ll_get(pArrayList, index), nombre)==0)
                {
                    printf("Error, nombre no valido, ingrese nuevamente: ");
                    scanf("%s", nombre);
                }
                break;
            case 2:
                printf("Ingrese nuevo genero: ");
                scanf("%c", &genre);
                while(setGenre((eCliente*)ll_get(pArrayList, genre), genre)==0)
                {
                    printf("Error, no valido, ingrese nuevamente: ");
                    scanf("%c", &genre);
                }
                break;
            case 3:
                printf("Ingrese nuevo numero de tarjeta: ");
                scanf("%lu", &nroTarjeta);
                while(setNroTarjeta((eCliente*)ll_get(pArrayList, index), nroTarjeta)==0)
                {
                    printf("Error, valor no valido, ingrese nuevamente: ");
                    scanf("%lu", &nroTarjeta);
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

int controller_removeClient(LinkedList* pArrayList)
{
    eCliente* aux;
    int id;
    int index;
    char confirmar;

    if(pArrayList==NULL)
    {
        printf("Error al realizar la baja\n\n");
        system("pause");
        return 0;
    }

    system("cls");
    printf("***** Baja Cliente *****\n\n");
    printf("Ingrese el ID: ");
    scanf("%d", &id);

    index = findClientById(pArrayList, id);

    if(index==-1)
    {

        printf("Error, Id invalido\n\n\n");
        system("pause");
        return 0;

    }
    aux = (eCliente*) ll_get(pArrayList, index);

    if(aux==NULL)
    {

        printf("Error al realizar la baja\n\n");
        system("pause");
        return 0;
    }

    printClient(aux);

    printf("Confirma baja? (Ingrese y/n): ");
    fflush(stdin);
    scanf("%c", &confirmar);

    if(confirmar == 'y')
    {
        free(aux);
        if(ll_remove(pArrayList, index))
        {
            system("cls");
            printf("*** Error, la baja no pudo realizarse ***\n");
            system("pause");
            return 0;
        }
        else
        {
            system("cls");
            printf("*** Baja realizada con exito ***\n\n");
            system("pause");
        }
    }
    else if(confirmar == 'n')
    {
        system("cls");
        printf("*** Baja cancelada ***\n\n");
        system("pause");
        return 0;
    }
    else
    {
        system("cls");
        printf("*** Opcion no valida ***\n\n");
        system("pause");
        return 0;
    }

    return 1;
}
