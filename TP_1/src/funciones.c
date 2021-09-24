/*
 * funciones.c
 *
 *  Created on: 22 sep. 2021
 *      Author: LPoupour
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu(int* a, int* b){
    int opcion;

            system("cls"); //para limpiar pantalla. cls: clear screen
            printf("Menu de opciones:\n\n");
            printf("1. Ingresar 1er operando (A=%d)\n", *a);
            printf("2. Ingresar 2do operando (B=%d)\n", *b);
            printf("3. Calcular todas las operaciones.\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!) y (B!)\n");
            printf("4. Informar resultados.\n");
            printf("5. Salir.\n");
            printf("\nIndique opcion: ");
            scanf("%d", &opcion);

            return opcion;
}

int sumar(int a, int b, int* c){
    int ok = 0;

    if( c != NULL ){
        *c = a + b;
        ok = 1;
    }

    return ok;
}

int restar(int a, int b, int* c){
    int ok = 0;

    if( c != NULL ){
        *c = a - b;
        ok = 1;
    }
    return ok;
}

int dividir(int a, int b, float*c){
int ok = 0;

if(c != NULL && b != 0){
  *c = (float)a/b;
    ok = 1;
}else{
ok = 0;
}
return ok;
}

int multiplicar(int a, int b, int* c){
    int ok = 0;

if( c!=NULL){
    *c = a * b;
    ok = 1;
}

return ok;
}

int factorial(int a){
int fact = 0;

    if(a == 0){
    fact = 1;
    }else
    if(a >= 1){
    fact = a * factorial(a - 1);
    }else{
    fact = 0;
    }
return fact;
}


