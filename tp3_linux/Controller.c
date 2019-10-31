#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


// abrir el archivo en notepad para parsear por coma

void menu()
{
	printf("\n");
	printf("______________________");
	printf("\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
	printf("\n3-Alta de empleado.");
	printf("\n4-Modificar datos de empleado.");
	printf("\n5-Baja de empleado.");
	printf("\n6-Listar empleados.");
	printf("\n7-Ordenar empleados.");
	printf("\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto).");
	printf("\n9-Guardar los datos de los empleados en el archivo data.csv (modo binario).");
	printf("\n10-Salir");
	printf("\n____________________________________ ");
}

void subMenuChange()
{
	printf("\n");
	printf("__CHANGE___________________________");
	printf("\n1-Cambiar direccion");
	printf("\n2-Cambiar localidad");
	printf("\n3-Volver a menu principal");
	printf("\n_________________________________");
}

int controller_loadFromText(char* path,LinkedList* pArrayListEmployee)
{
	int ret=0;
	if(path !=NULL && pArrayListEmployee !=NULL)
	{
	FILE *pFile;
	if((pFile=fopen(path,"r"))==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
        ret=-1;
	}
	else if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
	{
	printf("\nEl archivo se abrio correctamente");
	}
	if((fclose(pFile))==-1)
	{
	printf("\nNo se pudo cerrar el archivo");
	ret=-2
	}
	else
	{
	printf("\nEl archivo se cerro exitosamente");
	}
	}
 return ret;
}

int controller_loadFromBinary(char* path,LinkedList* pArrayListEmployee)
{
	int ret=0;
	if(path !=NULL && pArrayListEmployee !=NULL)
	{
	FILE *pFile; 
	Employee* auxEmp;
	if((pFile=fopen(path,"rb"))==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
        ret=-1;
	}
	else if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
	{
	printf("\nEl archivo se abrio correctamente");
	}
	if((fclose(pFile))==-1)
	{
	printf("\nNo se pudo cerrar el archivo");
	ret=-2;
	}
	else
	{
	printf("\nEl archivo se cerro exitosamente");
	}
	}
 return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int size;
    Employee* emp;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
	
     emp= employee_new();
     size=ll_len(emp);
	
      if(emp!=NULL && size>0 )
	{
	   if(ll_isEmpty(emp)==1)
	   {
            getInt(id,"\nIngrese el ID del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_getId(emp,id);
	    getName(nombre,"\nIngrese el nombre de la empresa: ","Error!!.\n",3,128,2);
	    employee_getNombre(emp,nombre);
            getInt(horasTrabajadas,"\nIngrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_getHorasTrabajadas(emp,horasTrabajadas);   
	    getInt(sueldo,"\nIngrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2); 
	    employee_getSueldo(emp,sueldo);   
	   }
	   else
	   {
	   printf("\nNo hay mas lugar!!!");
	   }
    }
return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


