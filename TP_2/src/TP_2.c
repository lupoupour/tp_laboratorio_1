/*
 ============================================================================
 Name        : TP_2.c
 Author      : Lucia Poupour
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

#define LEN 1000
#define VACIO 0
#define EMPLEADOINGRESADO 1

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int nextId = 1;
    Employee list[LEN];
    int order = -1;
    int flag = VACIO;

    if(!initEmployees(list, LEN))
    {
        printf("Problema al inicializar.\n");
    }

    do
    {
        switch(menu())
        {
        case 1:
            if(pedirDatos(list, LEN, &nextId))
            {
                printf("No se pudo realizar el alta.\n");
            }
            else
            {
                printf("Alta exitosa.\n");
                flag = EMPLEADOINGRESADO;
            }
            break;
        case 2:
            if(flag == EMPLEADOINGRESADO)
            {
                if(removeEmployee(list, LEN, nextId))
                {
                    printf("No se pudo realizar la baja.\n");
                }
                else
                {
                    printf("Baja exitosa.\n");
                }
            }
            else
            {
                printf("No puede seleccionar esta opcion sin haber dado de alta un empleado.\n");
            }
            break;
        case 3:
            if(flag == EMPLEADOINGRESADO)
            {
                modifyEmployee(list, LEN, nextId);
            }
            else
            {
                printf("No puede seleccionar esta opcion sin haber dado de alta un empleado.\n");
            }
            break;
        case 4:
            if(flag == EMPLEADOINGRESADO)
            {
                sortEmployees(list, LEN, order);
            }
            else
            {
                printf("No puede seleccionar esta opcion sin haber dado de alta un empleado.\n");
            }
            break;
        case 5:
            printEmployees(list, LEN);
            salaryAverage(list, LEN);
            break;
        case 6:
            printf("Selecciono salir.\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida.\n");

        }

        system("pause");
    }
    while(seguir == 's');


    return 0;
}
