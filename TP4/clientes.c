#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"


eCliente* cliente_new()
{
    eCliente* nuevo = (eCliente*) malloc( sizeof(eCliente));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->genero = ' ';
        nuevo->nroTarjeta = 0;
    }
    return nuevo;
}



eCliente* cliente_newParametros(char* idStr,char* nombreStr,char* generoStr, char* nroTarjetaStr)
{

    eCliente* nuevo = cliente_new();
    int id;
    unsigned long nroTarjeta;
    char genero = generoStr[0];

    if(nuevo != NULL)
    {

        id = atoi(idStr);
        nroTarjeta = atol(nroTarjetaStr);

        if((setId(nuevo, id) && setGenre(nuevo, genero) && setNombre(nuevo, nombreStr) && setNroTarjeta(nuevo, nroTarjeta)) == 0)
        {

            nuevo = NULL;

        }

    }

    return nuevo;
}


int setId(eCliente* this,int id)
{

    int ok=0;
    eCliente* c = this;

    if(c != NULL && id>0)
    {

        c->id = id;
        ok=1;

    }

    return ok;
}

int setNombre(eCliente* this,char* nombre)
{

    int ok=0;
    eCliente* c = this;

    if(c != NULL && nombre != NULL && strlen(nombre)>0 && strlen(nombre)<51)
    {
        strcpy(c->nombre, nombre);
        ok=1;

    }

    return ok;
}


int setGenre(eCliente* this, char genero)
{

    int ok=0;
    eCliente* c = this;

    if(c != NULL && (genero == 'm' || genero == 'f' || genero == 'M' || genero == 'F'))
    {

        c->genero = genero;
        ok=1;

    }

    return ok;
}

int setNroTarjeta(eCliente* this,unsigned long numeroTarjeta)
{

    int ok=0;
    eCliente* c = this;

    if(c != NULL || numeroTarjeta >= 0)
    {

        c->nroTarjeta = numeroTarjeta;
        ok = 1;

    }

    return ok;
}

int findClientById(LinkedList* pArrayList, int id)
{
    eCliente* aux = NULL;
    int index = -1;

    if(pArrayList == NULL)
    {
        return -1;
    }

    for(int i=0; i<ll_len(pArrayList); i++)
    {

        aux = (eCliente*) ll_get(pArrayList, i);
        if(aux->id == id)
        {
            index = ll_indexOf(pArrayList, aux);
        }
    }
    return index;
}

int printClient(eCliente* c)
{

    printf("%04d    %12s    %1c     %12lu\n", c->id, c->nombre, c->genero, c->nroTarjeta);

    return 1;
}

int listClients(LinkedList* this)
{

    eCliente* aux;
    int returnAux = 0;

    printf("  ID         Nombre     G      Nro de Tarjeta\n\n");
    for(int i=0; i<ll_len(this); i++)
    {
        aux = ll_get(this, i);
        printClient(aux);
        returnAux = 1;
    }

    return returnAux;
}

int compareClientsById(void* cliente1, void* cliente2)
{

    eCliente* c1 = (eCliente*) cliente1;
    eCliente* c2 = (eCliente*) cliente2;

    if(c1->id > c2->id)
    {
        return 1;
    }
    else if(c1->id < c2->id)
    {
        return -1;
    }
    return 0;
}

int settersAddClient(eCliente* this)
{
    char nombre[51];
    char genero;
    unsigned long nroTarjeta;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", nombre);
    while(setNombre(this, nombre)==0)
    {
        printf("Error. Ingrese nombre nuevamente: ");
        fflush(stdin);
        scanf("%s", nombre);
    }
    printf("Ingrese genero del cliente (m o f): ");
    fflush(stdin);
    scanf("%c", &genero);
    while(setGenre(this, genero)==0)
    {
        printf("Error. Ingrese nuevamente: ");
        scanf("%c", &genero);
    }
    printf("Ingrese el numero de tarjeta del cliente: ");
    scanf("%lu", &nroTarjeta);
    while(setNroTarjeta(this, nroTarjeta)==0)
    {
        printf("Error. Ingrese nuevamente: ");
        scanf("%lu", &nroTarjeta);
    }
    return 1;
}

