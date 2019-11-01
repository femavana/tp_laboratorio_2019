#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"
#include "parser.h"
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

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* emp= employee_new();
	int id;
	int horasTrabajadas;
	int sueldo;
	if(emp != NULL)
	{
	 id=atoi(idStr);
	 horasTrabajadas=atoi(horasTrabajadasStr);
	 sueldo=atoi(sueldoStr);
	 employee_setId(emp,id);
	 employee_setNombre(emp,nombreStr);
	 employee_setHorasTrabajadas(emp,horasTrabajadas);
	 employee_setSueldo(emp,sueldo);
	}
return emp;
}

void employee_delete(Employee* this)
{
free(this);
}

int employee_setId(Employee* this,int id)
{
	int ret=-1;
	if(this != NULL && id > 0 )
	{
	this->id=id;
	ret=0;
	}
return ret;
}
int employee_getId(Employee* this,int* id)
{
	int ret=-1;
	if(this != NULL && id > 0 )
	{
	*id=this->id;
	ret=0;
	}
return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int ret=-1;
		   if(this != NULL && nombre > 0 )
		   {
			strcpy(this->nombre,nombre);
		    ret=0;
		   }
return ret;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int ret=-1;
	if(this != NULL && nombre > 0 )
	{
	strcpy(nombre,this->nombre);
	ret=0;
	}
return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
 int ret=-1;
		   if(this != NULL && horasTrabajadas > 0 )
		   {
		    this->horasTrabajadas=horasTrabajadas;
		    ret=0;
		   }
return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=-1;
	if(this != NULL && horasTrabajadas > 0 )
	{
	*horasTrabajadas=this->horasTrabajadas;
	ret=0;
	}
return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ret=-1;
	if(this != NULL && sueldo > 0 )
	{
	this->sueldo=sueldo;
	ret=0;
	}
return ret;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=-1;
	if(this != NULL && sueldo > 0 )
	{
    *sueldo=this->sueldo;
	ret=0;
	}
return ret;
}





