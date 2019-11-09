#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief  Shows the menu at screen.
 *   Don't receive or return anything
*/
void menu(void);
/** \brief  Shows the subMenuChange at screen.
 *   Don't receive or return anything
*/
void subMenuChange(void);
/** \brief  Shows the subMenuSort at screen.
 *   Don't receive or return anything
*/
void subMenuSort();
/** \brief Abre el archivo y lo lee en modo texto
 *
* \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int int (-1) si no se puede abrir
 * (-2) si no se pudo cerrar y  (0) si esta OK.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Abre el archivo y lo lee en modo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int int (-1) si no se puede abrir
 * (-2) si no se pudo cerrar y  (0) si esta OK.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) if an error and (0) if OK.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) if an error and (0) if OK.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int int (-1) if an error and (0) if OK.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int int (-1) if an error and (0) if OK.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) if an error and (0) if OK.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
* \return int int (-1) si no se puede abrir
 * (-2) si no se pudo cerrar y  (0) si esta OK.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
* \return int int (-1) si no se puede abrir
 * (-2) si no se pudo cerrar y  (0) si esta OK.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Compara los punteros pasados
 * como parametro por nombre
 *
 * \param void* arg1
* \param void* arg2
 * \return int Devuelve el resultado de la comparacion
 *
 */
int controller_orderByName(void* arg1,void* arg2);
/** \brief Solicita un ID y lo busca LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Devuelve la posicion del ID ,sino lo encuentra un -1
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
