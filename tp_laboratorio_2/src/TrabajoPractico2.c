/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Navarro María Fernanda
 Version     :
 Copyright   : Original Code
 Description : TrabajoPractico2
 ============================================================================
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "getInput.h"
#define SIZE 1000
#define CANT 51
#define TRUE 0
#define FALSE 1

int main(void)
{
	Employee personalData[SIZE];
	int opcion;
	int contadorId=0;
	 initEmployees(personalData,SIZE);
	do{
		menu();
	    getInt(&opcion,"\nIngrese una opcion: ","\nERROR!!.Opcion no valida!.",1,5,2);
	switch(opcion)
		{
		case 1:
			printf("\n\t__Alta_______");
			addEmployees(personalData,SIZE,&contadorId);
			break;
		case 2:
			printf("\n\t__Modificar____");
			changeEmployee(personalData,SIZE,contadorId);
			break;
		case 3:
			printf("\n\t__Baja________");
			removeEmployee(personalData,SIZE,&contadorId);
		    break;
		case 4:
			 printf("\n\t__Informar____");
			 reportEmployee(personalData,SIZE,contadorId);
		     break;
		}
	}while(opcion!=5);
return EXIT_SUCCESS;
}
