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

/** \brief give an options menu
 *
 * \return int return the chosen option
 *
 */
int menu();
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* vec, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(eEmployee* vec, int len, int id, char* name, char* lastName, float salary, int sector);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* vec, int len, int id);
/** \brief give a menu to do changes in any existing employee
 *
 * \param vec eEmployee*
 * \param len int
 * \param id int
 * \return int return (-1) if Error [cannot find the given employee]
 - (0) if Ok
 *
 */
int modifyEmployee(eEmployee* vec, int len, int id);
/** \brief verifies if there are employees in the data base
 *
 * \param vec eEmployee*
 * \param len int
 * \return int return (-1) if there aren't employees - (0) if amount of employees > 0
 *
 */
int verifyEmployee(eEmployee* vec, int len);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* vec, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* vec, int len, int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* vec, int len);
/** \brief give an options menu
 *
 * \param vec eEmployee*
 * \param len int
 * \return void
 *
 */
void menuInformes(eEmployee* vec, int len);
/** \brief print the content of an employee structure
 *
 * \param x eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee x);
/** \brief verifies if a string can be charged in a variable
 *
 * \param auxString char*
 * \param string char*
 * \param len int
 * \param message char*
 * \return void
 *
 */
void verifyString(char* auxString, char* string, int len, char* message);
/** \brief gives the salary average of an employee array
 *
 * \param vec eEmployee*
 * \param len int
 * \return void
 *
 */
void informSalaryAverage(eEmployee* vec, int len);
