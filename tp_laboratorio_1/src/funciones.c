/*
 * operaciones.c
 *
 *  Created on: 3 sep. 2019
 *      Author: femavana
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"


/**1  \brief  Solicita un numero al usuario y lo valida
     * \param pResultado Puntero del numero ingresado
     * \param pMensaje  Puntero del mensaje a ser mostrado
     * \param pMsjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMsjError,
			int minimo,
			int maximo,
			int reintentos)
{
	int ret = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",pMsjError);
		reintentos--;
		}
	}while(reintentos >= 0);
	return ret;
}

/**2   \brief Solicita un numero al usuario y lo valida
     * \param pResultado Puntero del numero ingresado
     * \param pMensaje  Puntero del mensaje a ser mostrado
     * \param pMsjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */

int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMsjError,
			 int minimo,
			 int maximo,
			 int reintentos)
{
    int ret = -1;
	float buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%f",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",pMsjError);
		reintentos--;
		}
	}while(reintentos >= 0);
	return ret;
}

/**3  \brief  Solicita dos numeros al usuario y los suma
     * \param  float num1 Pasa el valor de un numero
     * \param  float num2 Pasa el valor de un numero
     * \param  pMensaje  Puntero del mensaje a ser mostrado
     * \return Devuelve 0 si la operación es exitosa
     */
int sumar(float num1,
		  float num2,
		  char *pMensaje)
{
 float resultado;
			resultado=num1+num2;
			printf("%s %.2f",pMensaje,resultado);
 return 0;
}
/**4 \brief  Solicita dos numeros al usuario y los resta
     * \param  float num1 Pasa el valor de un numero
     * \param  float num2 Pasa el valor de un numero
     * \param  pMensaje  Puntero del mensaje a ser mostrado
     * \return Devuelve 0 si la operación es exitosa
     */
int restar(float num1,
		   float num2,
		    char *pMensaje)
{
 float resultado;
			resultado=num1-num2;
			printf("%s %.2f",pMensaje,resultado);
 return 0;
}

/**5 \brief  Solicita dos numeros al usuario y los divide
     * \param  float num1 Pasa el valor de un numero
     * \param  float num2 Pasa el valor de un numero
     * \param  pMensaje  Puntero del mensaje a ser mostrado
     * \return Devuelve 0 si la operación es exitosa y sino -1
     */

int division(float num1,
	         float num2,
	         char *pMensaje,
			 char *pMsjError)
{
  float resultado;
  int ret=-1;

    if(num2 != 0)
     {
       resultado=num1/num2;
       printf("%s %.2f",pMensaje,resultado);
       ret=0;
      }
    else
    {
    	printf("%s",pMsjError);
    }
 return ret;
}

/**6 \brief  Solicita dos numeros al usuario y los multiplica
     * \param  float num1 Pasa el valor de un numero
     * \param  float num2 Pasa el valor de un numero
     * \param  pMensaje  Puntero del mensaje a ser mostrado
     * \return Devuelve 0 si la operación es exitosa
     */
int multiplicacion(float num1,
		           float num2,
				   char *pMensaje)
{
 float resultado;
    	resultado=num1*num2;
    	printf("%s %.2f",pMensaje,resultado);
 return 0;
}
/**7 \brief  Solicita un numero al usuario y lo factorea
     * \param  float num1 Pasa el valor de un numero
     * \param  pMensaje  Puntero del mensaje a ser mostrado
     * \return Devuelve 0 si la operación es exitosa
     */

long factorial(float num,
		       char *pMensaje)
{
    float resultado=1;
    int i;

    for(i=num; i>0; i--)
    {
        resultado= resultado*i;
    }
    printf("%s %.2f",pMensaje,resultado);
    return 0;
}

void menu(float num1,float num2)
{
        printf("\n");
    	printf("\n");
        printf("\t<><><><><>CALCULADORA<><><><><>");
        printf("\n\t1-Ingrese 1er operando: %.2f\n\t",num1);
        printf("2-Ingrese 2do operando: %.2f\n\t",num2);
        printf("3-Sumar \n\t");
        printf("4-Restar \n\t");
        printf("5-Division \n\t");
        printf("6-Multiplicacion \n\t");
        printf("7-Factorial 1er operando \n\t");
        printf("8-Factorial 2do operando \n\t");
        printf("9-Calcular todas las operaciones\n\t");
        printf("10-Salir \n");
        printf("\t<><><><><><><><><><><><><><><><>");
}
