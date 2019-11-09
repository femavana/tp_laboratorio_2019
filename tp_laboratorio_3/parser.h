
#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados
 * desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Devuelve la cantidad de elementos
 * parseados y (-1) si hubo error.
 *
 */
int parser_EmployeeFromText(FILE* pFile ,LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
* \return int Devuelve la cantidad de elementos
 * parseados y (-1) si hubo error.
 *
*/
int parser_EmployeeFromBinary(FILE* pFile ,LinkedList* pArrayListEmployee);

#endif // parser_H_INCLUDED
