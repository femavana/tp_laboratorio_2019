#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
	Employee* emp=(Employee*)malloc(sizeof(Employee));
	if(emp != NULL)
	{
	    emp->id = 0;
	    strcpy(emp->nombre," ");
	    emp->horasTrabajadas=0;
	    emp->sueldo = 0;
	}
return emp;
}

Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,int* sueldo)
{
	Employee* emp=(Employee*)malloc(sizeof(Employee));
	if(emp != NULL)
	{
	    emp->id=*idStr;
	    strcpy(emp->nombre,nombreStr);
	    emp->horasTrabajadas=*horasTrabajadasStr;
	    emp->sueldo=*sueldo;
	}
return emp;
}

void employee_delete()
{

}

int employee_setId(Employee* this,int id)
{

return 0;
}
int employee_getId(Employee* this,int* id)
{
return 0;
}

int employee_setNombre(Employee* this,char* nombre)
{
return 0;
}
int employee_getNombre(Employee* this,char* nombre)
{
return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
return 0;
}

int employee_setSueldo(Employee* this,int sueldo)
{
return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
return 0;
}


