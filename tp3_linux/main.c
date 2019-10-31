#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}

*/
int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    		menu();
    	    getInt(&option,"\nIngrese una opcion: ","\nERROR!!.Opcion no valida!.",1,10,2);
    	switch(option)
    		{
    		case 1:
    			printf("\n\t______Cargar_datos_de_empleado_desde_archivo-data.csv(modo texto)______________________");
    			controller_loadFromText("data.csv",listaEmpleados);
    			break;
    		case 2:
    			printf("\n\t______Cargar_datos_de_empleado_desde_archivo-data.csv(modo binario)_____________________");
    			controller_loadFromBinary("data.csv",listaEmpleados);
    			break;
    		case 3:
    		    printf("\n\t______Alta_de_empleado_________________________________");
    //		    controller_addEmployee(listaEmpleados);
    		    break;
    		case 4:
    		    printf("\n\t______Modificar_dato_de_empleado_________________________________");
    //		    controller_editEmployee(listaEmpleados);
    		    break;
    		case 5:
    			printf("\n\t______Baja_de_empleado_________________________________");
    //			controller_removeEmployee(listaEmpleados);
    			break;
    		case 6:
    			printf("\n_________Listar_empleados__________________ ");
    //			controller_ListEmployee(listaEmpleados);
    			break;
    		case 7:
    			printf("\n\t________Ordenar_empleados____________________________");
    //			controller_sortEmployee(listaEmpleados);
    			break;
    		case 8:
    			printf("\n\t________Guardar_datos_de_empleados_en_archivo-dataTexto.csv(modo texto)____________________________");
    //			controller_saveAsText("data.csv",listaEmpleados);
    			break;
    		case 9:
    			 printf("\n\t_______Guardar_datos_de_empleados_en_archivo-dataBinario.csv(modo binario)__________________");
    //			 controller_saveAsBinary("data.csv",listaEmpleados);
    		     break;
    		}
    	}while(option!=10);
    return 0;
}

