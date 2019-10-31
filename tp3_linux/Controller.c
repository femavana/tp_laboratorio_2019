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
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
	
     Employee* emp= employee_new();;
     size=ll_len(emp);
	
      if(emp!=NULL && size>0 )
	{
	   if(ll_isEmpty(emp)==0)
	   {
            getInt(id,"\nIngrese el ID del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_getId(emp,id);
	    getName(nombre,"\nIngrese el nombre del empleado: ","Error!!.\n",3,128,2);
	    employee_getNombre(emp,nombre);
            getInt(horasTrabajadas,"\nIngrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	    employee_getHorasTrabajadas(emp,horasTrabajadas);   
	    getInt(sueldo,"\nIngrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2); 
	    employee_getSueldo(emp,sueldo);
	    ll_add(pArrayListEmployee,emp)
	    employee_delete(emp);
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
    int ret=-1;
    int size;
    int option;
    int id;
    int index;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
          
	  Employee* auxEmp;
          size=ll_len(auxEmp);
          if(auxEmp!=NULL && size>0 )
    	   {
	     getInt(id,"\nIngrese el id del empleado a editar: ","Error!!.Ingrese solo numeros\n",1,size,2); 
	     if(index=ll_indexOf(auxEmp,id)!=-1)
    	    {
		   do{
        	   subMenuChange();
        	   getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,4,2);
        	   switch(option)
        	  {
        	  case 1:
        	   printf("\n__Cambiar_nombre__");
        	   getName(nombre,"\nIngrese el nuevo nombre del empleado: ","Error!!.\n",3,128,2);
	           employee_getNombre(auxEmp[index],nombre);
        	   break;
        	  case 2:
        	   printf("\n__Cambiar_horas_trabajadas__");
                   getInt(horasTrabajadas,"\nIngrese la nueva cantidad de horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	           employee_getHorasTrabajadas(auxEmp[index],horasTrabajadas);
	           break;
	          case 3:
        	   printf("\n__Cambiar_sueldo__");
                   getInt(sueldo,"\nIngrese el nuevo sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2); 
	           employee_getSueldo(auxEmp[index],sueldo);  
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
	   if(ll_isEmpty(pArrayListEmployee)==0)
		{
		printf("\nID:%d \nNombre:%s \nHorasTrabajadas:%d \nSueldo:%d\n",
			pArrayListEmployee->id,pArrayListEmployee->nombre,
			pArrayListEmployee->horasTrabajadas,pArrayListEmployee->sueldo);
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


