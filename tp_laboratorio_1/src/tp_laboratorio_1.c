/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Navarro María Fernanda
 Version     :
 Copyright   : Original Code
 Description : tp_laboratorio_1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

int main()
{

    int option;
    float a;
    float b;

    do
    {
    	menu(a,b);
        getInt(&option,"\nIngrese una opción: ","<<ERROR.Ingrese una opción válida>>",1,10,3);

        switch(option)
        {
        case 1:
            getFloat(&a,"Ingrese un número: ","\t<<ERROR.Ingrese solo números>>",0,1000000,3);
            break;
        case 2:
        	  getFloat(&b,"Ingrese un número: ","\t<<ERROR.Ingrese solo números>>",0,1000000,3);
            break;
        case 3:
            sumar(a,b,"El resultado de la suma es:");
            break;
        case 4:
            restar (a,b,"El resultado de la resta es:");
            break;
        case 5:
            division(a,b,"El resultado de la división es:","\t<<ERROR.No se puede dividir entre 0>>\nReingrese 2º operando");
            break;
        case 6:
            multiplicacion(a,b,"El resultado de la multiplicación es:");
            break;
        case 7:
            factorial(a,"El factorial del 1er operando es:");
            break;
        case 8:
            factorial(b,"El factorial del 2do operando es:");
            break;
        case 9:
        	sumar(a,b,"El resultado de la suma es:");
            restar (a,b,"\nEl resultado de la resta es:");
            division(a,b,"\nEl resultado de la división es:","<<ERROR.No se puede dividir entre 0>>Reingrese 2º operando");
            multiplicacion(a,b,"\nEl resultado de la multiplicación es:");
            factorial(a,"\nEl factorial del 1er operando es:");
            factorial(b,"\nEl factorial del 2do operando es:");
            break;
        }
    }while(option!=10);
    return 0;
}
