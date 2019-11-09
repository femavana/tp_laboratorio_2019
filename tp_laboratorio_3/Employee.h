#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacio en memoria y verifica que el puntero
 *  devuelto por Malloc no sea Null.
 *  Incializa los elementos del puntero que devuelve.
 *  Devuelve el nuevo puntero a la struct
 *
 * \param
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief Resive los datos a cargar como parametros
 * y los carga en el nuevo puntero a struct
 *  Devuelve el nuevo puntero a la struct
 *
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* idStr
 * \param char* sueldoStr
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief Recibe un puntero a la struct y
 *  libera su espacio en memoria
 *
 * \param Employee* this
 * \return
 *
 */
void employee_delete(Employee* this);
/** \brief Recibe un puntero a la struct y una variable
 * Se carga el valor de la var en el puntero de la struct
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Recibe un puntero a la struct
 * y un puntero a una variable
 * Se toma el valor de la struct y se asigna al
 * puntero de la var
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Recibe un puntero a la struct y una variable
 * Se carga el valor de la var en el puntero de la struct
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Recibe un puntero a la struct
 * y un puntero a una variable
 * Se toma el valor de la struct y se asigna al
 * puntero de la var
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Recibe un puntero a la struct y una variable
 * Se carga el valor de la var en el puntero de la struct
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Recibe un puntero a la struct
 * y un puntero a una variable
 * Se toma el valor de la struct y se asigna al
 * puntero de la var
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Recibe un puntero a la struct y una variable
 * Se carga el valor de la var en el puntero de la struct
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Recibe un puntero a la struct
 * y un puntero a una variable
 * Se toma el valor de la struct y se asigna al
 * puntero de la var
 *  Devuelve o si se cargo bien y -1 si hubo error
 * \param Employee* this
 * \param int id
 * \return int (-1) if an error and (0) if OK.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
