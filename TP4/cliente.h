#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{

    int id;
    char nombre[50];
    char genero;
    unsigned long nroTarjeta;

} eCliente;


#endif // CLIENTE_H_INCLUDED


eCliente* cliente_new();
eCliente* cliente_newParametros(char* idStr,char* nombreStr,char* generoStr, char* nroTarjetaStr);
int setId(eCliente* this,int id);
int setNombre(eCliente* this,char* nombre);
int setGenre(eCliente* this, char genero);
int setNroTarjeta(eCliente* this,unsigned long numeroTarjeta);
int findClientById(LinkedList* pArrayList, int id);
int printClient(eCliente* c);
int listClients(LinkedList* this);
int compareClientsById(void* cliente1, void* cliente2);
int settersAddClient(eCliente* this);
