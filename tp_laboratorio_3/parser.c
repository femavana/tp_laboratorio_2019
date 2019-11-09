#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile ,LinkedList* pArrayListEmployee)
{
	int ret=-1;
	char buffer[4][54];
	Employee* auxEmp;

	if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
	 fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
     while(!feof(pFile))
	{
	  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
	  auxEmp= employee_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
	  if(!ll_add(pArrayListEmployee,auxEmp))
	  {
	  ret++;
	  }
    }
    }

return ret;
}

int parser_EmployeeFromBinary(FILE* pFile ,LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int i;
	int size;
	Employee* auxEmp;

	if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
	 size=ll_len(pArrayListEmployee);
     while(!feof(pFile))
	{
	  for(i=0;i<size;i++)
	  {
		  auxEmp=ll_get(pArrayListEmployee,i);
		  fread(auxEmp,sizeof(Employee),1,pFile);
		  if(!ll_add(pArrayListEmployee,auxEmp))
		   {
		  	  ret++;
		   }
		  }
      }
	}
return ret;
}

