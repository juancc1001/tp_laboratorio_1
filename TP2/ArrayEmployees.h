#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int menu();
int initEmployees(eEmployee* vec, int len);
int addEmployee(eEmployee* vec, int len, int id, char* name, char* lastName, float salary, int sector);
int findEmployeeById(eEmployee* vec, int len, int id);
int modifyEmployee(eEmployee* vec, int len, int id);
int verifyEmployee(eEmployee* vec, int len);
int removeEmployee(eEmployee* vec, int len, int id);
int sortEmployees(eEmployee* vec, int len, int order);
int printEmployees(eEmployee* vec, int len);
void menuInformes(eEmployee* vec, int len);
void printEmployee(eEmployee x);
void verifyString(char* auxString, char* string, int len, char* message);
void informSalaryAverage(eEmployee* vec, int len);
