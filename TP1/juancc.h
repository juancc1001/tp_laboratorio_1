#ifndef JUANCC_H_INCLUDED
#define JUANCC_H_INCLUDED
/** \brief Crea manu de opciones para calculadora con dos parametros.
 *
 * \param flag bandera, verifica el ingreso de parametros.
 * \param A primer operando
 * \param B segundo operando
 * \return opcion.
 *
 */
int menu(int flag, int A, int B);
/** \brief Suma dos enteros
 *
 * \param A primer operando tipo interer
 * \param B segundo operando tipo interer
 * \return Resultado tipo interer
 *
 */

int sumar(int A, int B);
/** \brief resta dos enteros
 *
 * \param A primer operando entero
 * \param B segundo operando tipo interer
 * \return Resultado tipo interer
 *
 */
int restar(int A, int B);
/** \brief divide dos enteros
 *
 * \param A primer operando entero
 * \param B segundo operando tipo interer
 * \return Resultado tipo float
 *
 */
void dividir (int A, int B, char* mensaje, char* mensajeError);
/** \brief multiplica dos enteros
 *
 * \param A primer operando entero
 * \param B segundo operando tipo interer
 * \return Resultado tipo interer
 *
 */
int multiplicar(int A, int B);
/** \brief Encuentra factorial de un entero
 *
 * \param Operando tipo entero
 * \param string mensaje resultado
 * \param string mensaje error
 * \return Resultado tipo interer
 *
 */
void GetFactorial(int A, char* msj, char* msjError);




#endif // JUANCC_H_INCLUDED
