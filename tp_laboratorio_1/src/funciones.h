/*
 * operaciones.h
 *
 *  Created on: 3 sep. 2019
 *      Author: femavana
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
void menu(float num1,float num2);
int getInt(int *pResultado,char *pMensaje,char *pMsjError,int minimo,int maximo,int reintentos);
int getFloat(float *pResultado,char *pMensaje,char *pMsjError,int minimo,int maximo,int reintentos);
int sumar(float num1,float num2,char *pMensaje);
int restar(float num1,float num2,char *pMensaje);
int division(float num1,float num2,char *pMensaje,char *pMsjError);
int multiplicacion(float num1, float num2,char *pMensaje);
long factorial(float num,char *pMensaje);

#endif /* FUNCIONES_H_ */
