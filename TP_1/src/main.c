/*
 ============================================================================
 Name        : TP_1.c
 Author      : Lucia Poupour
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define VACIO 0
#define OPERANDOA 1
#define OPERANDOB 2
#define OPERACIONES 3

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int a = 0;
    int b = 0;

    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int factA;
    int factB;
    int flag = VACIO;
    float resultadoDivision;


    do{
        system("cls");
    switch(menu(&a, &b)){
    case 1:
        printf("Ingrese un numero para su operando A: ");
        scanf("%d", &a);
        flag = OPERANDOA;
    break;
    case 2:
        if(flag == OPERANDOA){
        printf("Ingrese un numero para su operando B: ");
        scanf("%d", &b);
        flag = OPERANDOB;
        }else{
        printf("Antes de ingresar el operando B, debe ingresar el operando A.\n");
        }
    break;
    case 3:
        if(flag == OPERANDOB){
        sumar(a, b, &resultadoSuma);
        restar(a, b, &resultadoResta);
        dividir(a, b, &resultadoDivision);
        multiplicar(a, b, &resultadoMultiplicacion);
        factA = factorial(a);
        factB = factorial(b);
        flag = OPERACIONES;
        }else{
        printf("No puede realizar las operaciones sin haber ingresado ambos operandos.\n");
        }
    break;
    case 4:
        if(flag == OPERACIONES){
        printf("El resultado de %d+%d es: %d\n", a, b, resultadoSuma);
        printf("El resultado de %d-%d es: %d\n", a, b, resultadoResta);
        if(b != 0){
        printf("El resultado de %d/%d es: %.2f\n", a, b, resultadoDivision);
        }else{
        printf("No es posible dividir por 0.\n");
        }
        printf("El resultado de %d*%d es: %d\n", a, b, resultadoMultiplicacion);
        if(a < 0){
            printf("El operando A es un numero negativo y no es posible calcular el factorial de un numero negativo.\n");
        }else{
            printf("El factorial de %d es %d.\n", a, factA);
        }
        if(b < 0){
            printf("El operando B es un numero negativo y no es posible calcular el factorial de un numero negativo.\n");
        }else{
            printf("El factorial de %d es %d\n", b, factB);
        }
        flag = VACIO;
        }else{
        printf("Para mostrar los resultados, es necesario haber realizado las operaciones.\n");
        }
    break;
    case 5:
    printf("Usted selecciono salir. Desea cancelar la salida? Pulse s para si y n para no.\n");
    fflush(stdin);
    scanf("%c", &seguir);
    break;
    default:
        printf("La opcion ingresada no es valida.\n");
    }

    system("pause");

    }while( seguir == 's');

    return 0;

    }
