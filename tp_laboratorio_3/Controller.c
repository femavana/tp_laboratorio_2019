#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
	printf("\n9-Guardar los datos de los empleados en el archivo dataBin.csv (modo binario).");
	printf("\n10-Salir");
	printf("\n_________________");

}

void subMenuChange()
{
	printf("\n");
	printf("_______________CHANGE_______________");
	printf("\n1-Cambiar_nombre");
	printf("\n2-Cambiar_horas_trabajas");
	printf("\n3-Cambiar_sueldo");
	printf("\n4-Volver_a_menu_principal");
	printf("\n_________________________________");
}

void subMenuSort()
{
	printf("\n");
	printf("_______________SORT_______________");
	printf("\n1-Por_nombre_de_forma_ascendente");
	printf("\n2-Por_nombre_de_forma_descendente");
	printf("\n3-Volver_a_menu_principal");
	printf("\n_________________________________");
}

int controller_loadFromText(char* path,LinkedList* pArrayListEmployee)
{
int ret;
FILE *pFile;

	if(path !=NULL && pArrayListEmployee !=NULL)
	{
	if((pFile=fopen(path,"r"))==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
    ret=-1;
	}
	else
	{
	 ret=parser_EmployeeFromText(pFile,pArrayListEmployee);
	 printf("\nSe leyeron del archivo %d elementos en modo texto",ret);
	 if((fclose(pFile))==-1)
	 {
	 printf("\nNo se pudo cerrar el archivo");
	 ret=-2;
	 }
	 }
	}
 return ret;
}

int controller_loadFromBinary(char* path,LinkedList* pArrayListEmployee)
{
	int ret=0;
	FILE *pFile;

	if(path !=NULL && pArrayListEmployee !=NULL)
	{
	if((pFile=fopen(path,"rb"))==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
    ret=-1;
	}
	else
	{
	 ret=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
	 printf("\nSe leyeron del archivo %d elementos en modo binario",ret);
	 if((fclose(pFile))==-1)
	 {
	 printf("\nNo se pudo cerrar el archivo");
	 ret=-2;
	 }
	 }
	}
return ret;
}

int controller_findEmployeeById(LinkedList* pArrayListEmployee)
{
int ret=-1;
int size;
int i;
int auxId;
Employee* emp;

  size=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!= NULL)
	{
	  getInt(&auxId,"\n\nIngrese el ID del empleado: ","Error!!.Ingrese solo numeros\n",1,size,2);
	   for(i=0;i<size;i++)
	   {
		emp=ll_get(pArrayListEmployee,i);
		if(emp->id == auxId)
		{
		 ret=i;
		 printf("\t|ID: %d"
				 "\n\t|Nombre:%s"
				 "\n\t|Horas_trabajadas:%d"
				 "\n\t|Sueldo:%d\n",emp->id,emp->nombre,
				 emp->horasTrabajadas,emp->sueldo);
		 break;
		}
	   }
	}
return ret;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int index;
    int size;
    char auxNombre[128];
    int  auxHorasTrabajadas;
    int auxSueldo;
	Employee* emp=employee_new();

      if(emp!=NULL)
	  {
    	size=ll_len(pArrayListEmployee);
    	index=size+1;
        getName(auxNombre,"\nIngrese el nombre del empleado: ","Error!!.\n",3,128,2);
        getInt(&auxHorasTrabajadas,"Ingrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,63,2);
	    getInt(&auxSueldo,"Ingrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,1000000,2);
	    employee_setNombre(emp,auxNombre);
	    employee_setSueldo(emp,auxSueldo);
	    employee_setId(emp,index);
	    employee_setHorasTrabajadas(emp,auxHorasTrabajadas);
	    ll_add(pArrayListEmployee,emp);
	    ret=0;
	   }
return ret;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int option;
    int index;
    char auxNombre[128];
    int  auxHorasTrabajadas;
    int  auxSueldo;
    Employee* emp=employee_new();

      if(pArrayListEmployee!=NULL)
      {
    	 controller_ListEmployee(pArrayListEmployee);
         index=controller_findEmployeeById(pArrayListEmployee);
    	 if(index != -1)
		{
         emp=ll_get(pArrayListEmployee,index);
		 do{
        	   subMenuChange();
        	   getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,4,2);
        	   switch(option)
        	  {
        	  case 1:
        	   printf("\n__Cambiar_nombre__");
        	   getName(auxNombre,"\nIngrese el nuevo nombre del empleado: ","Error!!.\n",3,128,2);
        	   employee_setNombre(emp,auxNombre);
        	   break;
        	  case 2:
        	   printf("\n__Cambiar_horas_trabajadas__");
        	   getInt(&auxHorasTrabajadas,"\nIngrese las horas Trabajadas del empleado: ","Error!!.Ingrese solo numeros\n",1,63,2);
        	   employee_setHorasTrabajadas(emp,auxHorasTrabajadas);
	           break;
	          case 3:
        	   printf("\n__Cambiar_sueldo__");
        	   getInt(&auxSueldo,"\nIngrese el sueldo del empleado: ","Error!!.Ingrese solo numeros\n",1,1000000,2);
        	   employee_setSueldo(emp,auxSueldo);
        	   break;
        	  }
		    }while(option!=4);
		 ret=0;
          }
    	   else
            {
        	printf("No existe el ID ingresado!!");
            }
      }
return ret;	
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	char seguir;
	int index;
	Employee* emp=employee_new();

	      if(pArrayListEmployee!=NULL)
	      {
	    	 controller_ListEmployee(pArrayListEmployee);
	         index=controller_findEmployeeById(pArrayListEmployee);
	         if(index != -1)
	        {
	         emp=ll_get(pArrayListEmployee,index);
	         getSeguir(&seguir,"\nDesea continuar con la eliminacion? (s|n): ","Error!!.Ingrese solo s o n\n",'s','n',2);
	         if(seguir=='s')
	         {
	          employee_delete(emp);
	          index=ll_indexOf(pArrayListEmployee,emp);
	          ll_remove(pArrayListEmployee,index);
	          printf("La eliminacion fue exitosa!!");
	         }
	         else
	         {
	          printf("Se cancela eliminacion!!");
	         }
	        }
	         else
	         {
	          printf("No existe el ID ingresado!!");
	         }
	      }
return ret;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int i;
	int size;
	int  auxId;
	char auxNombre[128];
	int  auxHorasTrabajadas;
	int  auxSueldo;
	Employee* emp;

	    size=ll_len(pArrayListEmployee);
		if(pArrayListEmployee!= NULL)
		{
	 printf("\n\n__________________________EMPLOYEES____________________________________\n");
	 printf("\nID \tNOMBRE \tHORAS_TRABAJADAS \tSUELDO\n");
	 printf("----------------------------------------------------------------------------");
	 for(i=0;i<size;i++)
	       {
			emp=ll_get(pArrayListEmployee,i);
			employee_getId(emp,&auxId);
			employee_getNombre(emp,auxNombre);
			employee_getHorasTrabajadas(emp,&auxHorasTrabajadas);
			employee_getSueldo(emp,&auxSueldo);
			printf("\n%d,%s,%d,%d",
		    auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
			}
		}
return ret;
}

int controller_orderByName(void* arg1,void* arg2)
{
	int ret=-1;
	Employee* emp1=(Employee*)arg1;
	Employee* emp2=(Employee*)arg2;
    ret=strcmp(emp1->nombre,emp2->nombre);
return ret;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
	int option;

		     if(pArrayListEmployee!=NULL)
		      {
				 do{
		        	   subMenuSort();
		        	   getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,3,2);
		        	   switch(option)
		        	  {
		        	  case 1:
		        	   printf("\n__Por_nombre_de_forma_ascendente__");
		        	   	ll_sort(pArrayListEmployee,controller_orderByName,1);
		        	   controller_ListEmployee(pArrayListEmployee);
		        	   break;
		        	  case 2:
		        	   printf("\nPor_nombre_de_forma_descendente");
		        	    ll_sort(pArrayListEmployee,controller_orderByName,0);
		        	   controller_ListEmployee(pArrayListEmployee);
		        	   break;
		        	   }

				    }while(option!=3);

				 ret=0;
		          }
return ret;
}

int controller_saveAsText(char* path,LinkedList* pArrayListEmployee)
{
int ret=0;
int i;
int size;
FILE *pFile;
Employee* auxEmp;

if(path !=NULL && pArrayListEmployee !=NULL)
{
   if((pFile=fopen(path,"w"))==NULL)
   {
   printf("\nEl archivo no puede ser abierto");
   ret=-1;
   }
   else
   {
   size=ll_len(pArrayListEmployee);
	for(i=0;i<size;i++)
    {
	 auxEmp=ll_get(pArrayListEmployee,i);
	 fwrite(auxEmp,sizeof(Employee),1,pFile);
	 }
	 if((fclose(pFile))==-1)
	 {
		printf("\nNo se pudo cerrar el archivo");
		ret=-2;
	 }
     else
	 {
      printf("\nEl archivo de texto se guardo correctamente");
	 }
	 }
}
return ret;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=0;
	int i;
	int size;
	FILE *pFile;
	Employee* auxEmp;

	size=ll_len(pArrayListEmployee);
	if(path !=NULL && pArrayListEmployee !=NULL)
	{
	   if((pFile=fopen(path,"wb"))==NULL)
	   {
	    printf("\nEl archivo no puede ser abierto");
        ret=-1;
	    }
	   for(i=0;i<size;i++)
	   {
	    auxEmp=ll_get(pArrayListEmployee,i);
	    fwrite(auxEmp,sizeof(Employee),1,pFile);
	   }
	   if((fclose(pFile))==-1)
	   {
	    printf("\nNo se pudo cerrar el archivo");
	    ret=-2;
	    }
	   else
	   {
	    printf("\nEl archivo binario se guardo correctamente");
	   }
     }
return ret;
}

