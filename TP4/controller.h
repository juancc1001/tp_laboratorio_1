#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int parser_FromText(FILE* pFile, LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayList);
int controller_addClient(LinkedList* pArrayList);
int controller_clientDebtor(LinkedList* listaClientes, LinkedList* listaDeudores);
int controller_editClient(LinkedList* pArrayList);
int controller_removeClient(LinkedList* pArrayList);
