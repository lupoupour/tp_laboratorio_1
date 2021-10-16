/*
 * arrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: LPoupour
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

int menu()
{

    int opcion;
    system("cls");
    printf("   *** ABM Personas ***\n\n");
    printf("1- Alta Persona\n");
    printf("2- Baja Persona\n");
    printf("3- Modificacion Persona\n");
    printf("4- Ordenar Personas\n");
    printf("5- Listar Personas\n");
    printf("6- Salir\n");

    validaNumeros(&opcion,"Ingrese una opcion de menu (valores validos: de 1 a 6 y solo numeros):");

    return opcion;

}

int initEmployees(Employee* list, int len) //busco lugar vacio donde pueda ir una persona
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {

        for(int i = 0; i < len; i++) //mientras i sea menor a tam,o sea mientras el indice de la lista sea menor al tamaño de la lista
        {
            list[i].isEmpty = 1; //existe y está vacío, o sea disponible para cargarle info.
        }

        todoOk = 0;
    }
    return todoOk;

}

int searchFree(Employee list[], int len)
{
    int indice = -1;

    if(list != NULL && len >0)
    {

        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)  //no es necesario poner == // es un lugar libre, entonces a ese lugar le pongo el indice de la lista correspondiente.
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int pedirDatos(Employee list[], int len, int* pId)
{
    char name[51];
    char lastName[51];
    int sector;
    float salary;
    int id;

    id = *pId;
    (*pId)++;
    system("cls");
    printf("Ingrese nombre: "); //hay que hacer validaciones
    fflush(stdin);
    gets(name); //gets es solo para strings

    while(validaCadena(name))
    {
        printf("El nombre ingresado es incorrecto, ya que no puede contener caracteres numericos. Ingreselo nuevamente: ");
        fflush(stdin);
        gets(name);
    }

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(lastName);

    while(validaCadena(lastName))
    {
        printf("El apellido ingresado es incorrecto, ya que no puede contener caracteres numericos. Ingreselo nuevamente: ");
        fflush(stdin);
        gets(lastName);
    }

    validaNumeros(&sector,"Ingrese un sector (valores validos: de 1 a 10 y solo numeros):");

    while((sector < 1 || sector > 10))
    {
        validaNumeros(&sector,"El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
    }

    validaNumerosFloat(&salary,"Ingrese un salario (valores validos: de 30000 en adelante y solo numeros):");

    while(salary < 30000)
    {
        validaNumerosFloat(&salary,"El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
    }

    return addEmployee(list, len, id, name, lastName, salary, sector);

}

void printEmployee(Employee p) //recibe la estructura ePersona y no devuelve nada, es solo para mostrar y utilizar dsp
{
    printf("%d   %s   %s   %.2f   %d\n",
           p.id,
           p.name,
           p.lastName,
           p.salary,
           p.sector
          );

}

int printEmployees(Employee* list, int len)
{

    int todoOk = 0;
    int flag = 1;
    if(list != NULL && len > 0)
    {

        system("cls");
        printf("        LISTADO DE EMPLEADOS\n\n");
        printf("------------------------------------------------\n\n");
        printf("ID  Nombre   Apellido   Sueldo   Sector  \n");
        printf("------------------------------------------------\n\n");

        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty)  //es lo mismo que lista[i].isEmpty == 0 // o sea que tiene datos
            {
                printEmployee(list[i]); //llamo a mostrarPersona y le paso lista en el indice i
                flag = 0;
            }

        }

        if(flag == 1) //es decir que nunca entró al anterior if, o sea que no encontró nada con datos.
        {
            printf("No hay personas para mostrar.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}

int findEmployeeById(Employee* list, int len,int Id)//int buscarPersonaId(Employee lista[], int tam, int Id) //la creo para poder dar luego la baja
{
    int indice = -1;

    if(list != NULL && len > 0)
    {

        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty && list[i].id == Id)  //o sea que la lista tiene datos y ademas el id de la lista es igual al Id que ingreso ???
            {
                indice = i; //indice pasa a ser el mismo que el de la lista
                break;
            }
        }
    }
    return indice;
}

int removeEmployee(Employee* list, int len, int Id)
{
    int todoOk = -1;
    int indice;
    int id;
    char confirma;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    ***Baja Empleado***\n\n   ");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(list, len, id); //decimos que nuestro indice

        if(indice == -1)
        {
            printf("El ID: %d no esta registrado en el sistema.\n", id);
        }
        else
        {
            printEmployee(list[indice]);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {
                list[indice].isEmpty = 1;
                todoOk = 0;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;

}

int modifyEmployee(Employee list[], int len, int Id)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    ***Modificacion de Empleado***\n\n   ");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(list, len, id); //decimos que nuestro indice

        if(indice == -1)
        {
            printf("El ID: %d no esta registrado en el sistema. No hay empleado para modificar.\n", id);
        }
        else
        {
            printEmployee(list[indice]);
            printf("Esta seguro que desea modificar la informacion de este empleado?: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {
                do
                {
                    switch(menuModify())
                    {
                    case 1:
                        modifyName(list[indice], list, indice);
                        break;
                    case 2:
                        modifyLastName(list[indice], list, indice);
                        break;
                    case 3:
                        modifySalary(list[indice], list, indice);
                        break;
                    case 4:
                        modifySector(list[indice], list, indice);
                        break;
                    case 5:
                        printf("Selecciono salir.\n");
                        seguir = 'n';
                        break;
                    default:
                        printf("Opcion invalida.\n");
                    }
                    todoOk = 1;
                    system("pause");
                }
                while(seguir == 's');

            }
            else
            {
                printf("Modificacion cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}

int menuModify()
{
    int opcion;

    system("cls");
    printf("   *** Seleccione el dato del empleado que desea modificar. ***\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");
    printf("5- Cancelar modificacion / Dejar de modificar\n");
    validaNumeros(&opcion,"Ingrese una opcion de menu (valores validos: de 1 a 5 y solo numeros):");

    return opcion;
}

int modifyName(Employee p, Employee lista[], int indice)
{
    int todoOk = 0;

    if(lista != NULL)
    {
        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(p.name);

        while(validaCadena(p.name))
        {
            printf("El nombre ingresado es incorrecto, ya que no puede contener caracteres numericos. Ingreselo nuevamente: ");
            fflush(stdin);
            gets(p.name);
        }

        lista[indice] = p;

        todoOk = 1;
    }
    return todoOk;
}

int modifyLastName(Employee p, Employee lista[], int indice)
{
    int todoOk = 0;

    if(lista != NULL)
    {
        printf("Ingrese nuevo apellido: ");
        fflush(stdin);
        gets(p.lastName);

        while(validaCadena(p.lastName))
        {
            printf("El apellido ingresado es incorrecto, ya que no puede contener caracteres numericos. Ingreselo nuevamente: ");
            fflush(stdin);
            gets(p.lastName);
        }

        lista[indice] = p;

        todoOk = 1;
    }
    return todoOk;
}

int modifySalary(Employee p, Employee lista[], int indice)
{
    int todoOk = 0;

    if(lista != NULL)
    {
        printf("Ingrese nuevo salario: ");
        scanf("%f", &p.salary);

        validaNumerosFloat(&p.salary,"Ingrese un salario (valores validos: de 30000 en adelante y solo numeros):");

        while(p.salary < 30000)
        {
            validaNumerosFloat(&p.salary,"El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
        }

        lista[indice] = p;

        todoOk = 1;
    }
    return todoOk;
}

int modifySector(Employee p, Employee lista[], int indice)
{
    int todoOk = 0;

    if(lista != NULL)
    {
        printf("Ingrese nuevo sector: ");
        scanf("%d", &p.sector);

        validaNumeros(&p.sector,"Ingrese un sector (valores validos: de 1 a 10 y solo numeros):");

        while((p.sector < 1 || p.sector > 10))
        {
            validaNumeros(&p.sector,"El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
        }

        lista[indice] = p;

        todoOk = 1;
    }
    return todoOk;
}

int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;
    Employee aux;

    if(list != NULL && len > 0)
    {
        int valor;
        printf("Ingrese 1 si desea ordenar los empleados por sector de manera ascendente y 0 si desea ordenarlos por sector de manera descendente: ");
        scanf("%d", &order);

        if(order == 1)
        {
            for (int i = 0; i < len-1; i++)
            {
                for (int j = i+1; j < len; j++)
                {

                    valor = stricmp(list[i].lastName,list[j].lastName);
                    if(list[i].sector > list[j].sector || (list[i].sector == list[j].sector && valor > 0))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                }
            }
            todoOk = 0;
        }
        else if(order == 0)
        {
            for (int i = 0; i < len-1; i++)
            {
                for (int j = i+1; j < len; j++)
                {
                    valor = stricmp(list[i].lastName,list[j].lastName);
                    if(list[i].sector < list[j].sector || (list[i].sector == list[j].sector && valor > 0))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }


            }
            todoOk = 0;
        }

    }
    printEmployees(list,len);
    return todoOk;
}

int salaryAverage(Employee list[], int len)
{
    int todoOk = 0;
    int totalEmpleados = 0;
    int totalSalarios = 0;
    float promedioSalarios;
    int totalEmpleadosMayorSalario = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                totalEmpleados++;
                totalSalarios = (float)totalSalarios + list[i].salary;
            }
        }
        todoOk = 1;
    }

    if(totalEmpleados != 0 && totalEmpleados != 1)
    {
        promedioSalarios = (float)totalSalarios/totalEmpleados;

        if(list != NULL && len > 0)
        {
            for(int i = 0; i < len; i++)
            {
                if(list[i].isEmpty == 0)
                {
                    if(list[i].salary > promedioSalarios)
                    {
                        totalEmpleadosMayorSalario++;
                    }
                }
            }

        }

        printf("\nLa suma total de los salarios, considerando %d empleados, es de: %d\n", totalEmpleados, totalSalarios);
        printf("\nEl promedio de los salarios, considerando un total de %d empleados, es de: %2.f\n", totalEmpleados, promedioSalarios);
        printf("\nLa cantidad de empleados que superan el salario promedio es de %d\n", totalEmpleadosMayorSalario);
    }
    else if(totalEmpleados == 1)
    {
        printf("\nAl haber solo un empleado cargado, su salario es el salario promedio y no hay nadie que lo supere.\n");
    }
    else
    {
        printf("\nNo es posible calcular un total ni un promedio de salarios y tampoco calcular la cantidad de empleados que superan\n");
        printf("el salario promedio, debido a que no se ingresaron empleados.\n");
    }

    return todoOk;
}

int validaCadena(char cadena[])
{
    int todoOk = 0;
    int i = 0;
    while (cadena[i])
    {
        // Si no es del alfabeto y no es un espacio regresamos false o 0
        if (!isalpha(cadena[i]) && cadena[i] != ' ')// El espacio cuenta como válido, si no, simplemente quita la condición
        {
            todoOk = 1;
        }

        i++;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1 o true
    return todoOk;
}

void validaNumeros(int* pEntero, char* mensaje)
{
    int entero;
    int validaEntero;
    int noHayError = 1;

    do
    {
        fflush(stdin);
        if(noHayError == 1)
        {
            printf("%s", mensaje);
        }
        else
        {
            printf("El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
        }

        validaEntero = scanf("%d", &entero);
        noHayError = validaEntero;

    }
    while(validaEntero == 0);

    *pEntero = entero;
}

void validaNumerosFloat(float* pFloat, char* mensaje)
{
    float numeroFloat;
    int validaFloat;
    int noHayError = 1;

    do
    {
        fflush(stdin);
        if(noHayError == 1)
        {
            printf("%s", mensaje);
        }
        else
        {
            printf("El dato ingresado es incorrecto, ya que no puede contener letras ni estar fuera del rango indicado. Ingreselo nuevamente: ");
        }

        validaFloat = scanf("%f", &numeroFloat);
        noHayError = validaFloat;

    }
    while(validaFloat == 0);

    *pFloat = numeroFloat;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    int todoOk = -1;

    if(list != NULL && len > 0)
    {

        system("cls");
        printf("    ***Alta Empleado***    \n");
        indice = searchFree(list, len); //digo que mi indice va a ser igual al indice del lugar libre que busco en buscarLibre

        if(indice == -1) //porque -1 era que no estaba libre en buscarlibre.
        {
            printf("No hay lugar.\n");
        }
        else //lo que hago si el lugar esta libre --> puedo dar de alta a la persona
        {
            Employee auxPersona;

            auxPersona.id = id;
            strcpy(auxPersona.name, name); //auxPersona.name = name;
            strcpy(auxPersona.lastName, lastName);
            auxPersona.sector = sector;
            auxPersona.salary = salary;

            auxPersona.isEmpty = 0;
            list[indice] = auxPersona; //luego de guardarme todos los valores en auxPersona, los paso a lista[indice]

            todoOk = 0; //cuando se pudo dar de alta
        }


    }

    return todoOk;

}



