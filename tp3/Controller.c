#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"
#include "parser.h"
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
	printf("\n1-Cambiar_nombre");
	printf("\n2-Cambiar_horas_trabajas");
	printf("\n3-Cambiar_sueldo");
	printf("\n4-Volver a menu principal");
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
	ret=-2;
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

	if((pFile=fopen(path,"rb"))==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
        ret=-1;
	}
	else if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=-1)
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
    int  auxId;
    char auxNombre[128];
    int  auxHorasTrabajadas;
    int  auxSueldo;
	
     Employee* auxEmp;
     size=ll_len(pArrayListEmployee);
	
      if(pArrayListEmployee!=NULL && size>0 )
	  {
        getInt(&auxId,"\nIngrese el ID del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_setId(auxEmp,auxId);
	    getName(auxNombre,"\nIngrese el nombre del empleado: ","Error!!.\n",3,128,2);
	    employee_setNombre(auxEmp,auxNombre);
        getInt(&auxHorasTrabajadas,"\nIngrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
        employee_setHorasTrabajadas(auxEmp,auxHorasTrabajadas);
	    getInt(&auxSueldo,"\nIngrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_setSueldo(auxEmp,auxSueldo);
	    employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
	    employee_delete(auxEmp);
	    ret=0;
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
    int ret=-1;
    int size;
    int option;
    int auxId;
    int index;
    char auxNombre[128];
    int  auxHorasTrabajadas;
    int  auxSueldo;
          
	  Employee* auxEmp;
      size=ll_len(pArrayListEmployee);
      if(pArrayListEmployee!=NULL && size>0 )
      {
	     getInt(&auxId,"\nIngrese el id del empleado a editar: ","Error!!.Ingrese solo numeros\n",1,size,2);
	     if(index = ll_indexOf(pArrayListEmployee,auxId)==0)
    	 {
		 do{
        	   subMenuChange();
        	   getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,4,2);
        	   switch(option)
        	  {
        	  case 1:
        	   printf("\n__Cambiar_nombre__");
        	   getName(auxNombre,"\nIngrese el nuevo nombre del empleado: ","Error!!.\n",3,128,2);
        	   employee_setNombre(auxEmp,auxNombre);
        	   break;
        	  case 2:
        	   printf("\n__Cambiar_horas_trabajadas__");
        	   getInt(&auxHorasTrabajadas,"\nIngrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
        	   employee_setHorasTrabajadas(auxEmp,auxHorasTrabajadas);
	           break;
	          case 3:
        	   printf("\n__Cambiar_sueldo__");
        	   getInt(&auxSueldo,"\nIngrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
        	   employee_setSueldo(auxEmp,auxSueldo);
        	   break;
        	  }
		    }while(option!=4);
            }
    	    else
            {
        	printf("No existe el id ingresado!!");
            }
       }
return ret;	
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
int ret=-1;
int i;
int size;


    size=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!= NULL && size > 0)
	{
		printf("\n_______________________________EMPLOYEES____________________________________");
	for(i=0;i<size;i++)
       {

		printf("____________________________________________________________________\n");
		}
	}
return ret;
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
/*
FILE *parch;
char texto[ ]="Prueba de escritura";
int cant , longi;
if((parch=fopen("prueba.txt","w"))==NULL) //Se abre en modo escritura
{
printf("\nEl archivo no puede ser abierto");
exit (1);
}
longi=strlen (texto );
cant=fwrite ( texto , sizeof ( char ) , longi , parch ); //Se escribe al archivo
if (cant<longi)
printf("\nError al escribir el archivo");
else
printf("\nSe escribieron %d caracteres", cant);
fclose(parch);
*/
return 0;
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
/*
FILE *path;
struct  Employee;
path=fopen(path,"wb");
fwrite(&emp,sizeof(Employee),1,bin);
fclose(path);
*/
return 0;
}


