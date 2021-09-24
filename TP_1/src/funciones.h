/*
 * funciones.h
 *
 *  Created on: 22 sep. 2021
 *      Author: LPoupour
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief funcion que muestra las opciones de menu que el usuario tiene disponibles para ingresar.
 *
 * \param a int* a es la variable puntero que guarda el valor del primer operando.
 * \param b int* b es la variable puntero que guarda el valor del segundo operando.
 * \return int el retorna la opcion seleccionada por el usuario.
 *
 */
int menu(int* a, int* b);


/** \brief funcion que suma los dos operandos ingresados por el usuario
 *
 * \param a int primer operando ingresado por el usuario
 * \param b int segundo operando ingresado por el usuario
 * \param c int* resultado de la suma de los operandos
 * \return int returna 0 si no pudo realizarse la operacion (direccion de memoria NULL) y 1 si pudo realizarse la operacion.
 *
 */
int sumar(int a, int b, int* c);


/** \brief funcion que resta los dos operandos ingresados por el usuario
 *
 * \param a int primer operando ingresado por el usuario
 * \param b int segundo operando ingresado por el usuario
 * \param c int* resultado de la resta de los operandos
 * \return int returna 0 si no pudo realizarse la operacion (direccion de memoria NULL) y 1 si pudo realizarse la operacion.
 *
 */
int restar(int a, int b, int* c);


/** \brief divide los operandos ingresados por el usuario, validando división por 0.
 *
 * \param a int primer operando ingresado por el usuario.
 * \param b int segundo operando ingresado por el usuario.
 * \param c float* resultado de la división.
 * \return int retorna 0 si no pudo reailzarse la division y retorna 1 si pudo realizarse correctamente.
 *
 */
int dividir(int a, int b, float* c);


/** \brief multiplica los dos operandos ingresados por el usuario.
 *
 * \param a int primer operando ingresado por el usuario.
 * \param b int segundo operando ingresado por el usuario.
 * \param c int* resultado de la multiplicación.
 * \return int retorna 0 si no pudo realizarse la division y retorna 1 si pudo realizarse correctamente.
 *
 */
int multiplicar(int a, int b, int* c);


/** \brief funcion para calcular el factorial de un numero
 *
 * \param a int numero del que se quiere calcular el factorial
 * \return int retorna 0 si no pudo calcularse el factorial y retorna 1 si pudo calcularse el factorial.
 *
 */
int factorial(int a);

#endif // FUNCIONES_H_INCLUDED


#endif /* FUNCIONES_H_ */
