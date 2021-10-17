/*
 * arrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: LPoupour
 */

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief funcion que muestra las opciones de menu que el usuario tiene disponibles par ingresar.
 *
 * \return int retorna la opcion seleccionada por el usuario.
 *
 */
int menu();


/** \brief funcion que muestra las opciones de menu que el usuario tiene disponibles par ingresar y seleccionar que dato modificar.
 *
 * \return int retorna la opcion seleccionada por el usuario.
 *
 */
int menuModify();


/** \brief funcion que permite al usuario modificar el nombre del empleado, si previamente selecciono esa opcion.
 *
 * \param p Employee variable estrctura donde se guardara el nuevo nombre.
 * \param lista[] Employee variable para indicar la posicion del array donde se guardara p.
 * \param indice int posicion del array.
 * \return int retorna 1 si pudo hacerse la modificacion. Retorna 0 si no pudo hacerse la modificacion.
 *
 */
int modifyName(Employee p, Employee lista[], int indice);



/** \brief indica que todas las posiciones del array estan vacias.
 *
 * \param list Employee*  puntero al array de empleados.
 * \param len int tamaño del array.
 * \return int retorna 1 si pudieron inicializarse las posiciones en vacio. Retorna 0 si no pudieron inicializarse.
 *
 */
int initEmployees(Employee* list, int len);


/** \brief busca una posicion libre en mi array de empleados.
 *
 * \param list[] Employee array de empleados.
 * \param len int tamaño del array de empleados.
 * \return int retorna el indice de la primera posicion libre. Si no la encuentra, retorna -1.
 *
 */
int searchFree(Employee list[], int len); //-1 si está lleno y sino nos devuelve el indice de la primer estructura vacía


/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.
 *
 * \param list Employee* puntero al array.
 * \param len int tamaño del array.
 * \param id int id del empleado.
 * \param name[] char nombre del empleado.
 * \param lastName[] char apellido del empleado.
 * \param salary float salario del empleado.
 * \param sector int sector del empleado.
 * \return int retorna 0 si se pudo agregar el empleado. Retorna -1 si no se pudo agregar el empleado.
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);



/** \brief pide los datos del empleado para su carga.
 *
 * \param list[] Employee array de empleados.
 * \param len int tamaño del array.
 * \param pId int* puntero al id del empleado.
 * \return int retorna addEmployee: 0 si se pudo agregar el empleado, -1 si no se pudo agregar el empleado.
 *
 */
int pedirDatos(Employee list[], int len, int* pId);


/** \brief imprime la informacion de un empleado.
 *
 * \param p Employee variable estructura para guardar los datos.
 * \return void
 *
 */
void printEmployee(Employee p);


/** \brief imprime la informacion de todos mis empleados.
 *
 * \param list Employee* puntero al array de empleados.
 * \param len int tamaño del array
 * \return int retorna 1 si pudo imprimir correctamente. Retorna 0 si no pudo imprimir correctamente.
 *
 */
int printEmployees(Employee* list, int len);


/** \brief elimina un empleado recibiendo como parametro su Id.
 *
 * \param list Employee* puntero al array de empleados.
 * \param len int tamaño del array.
 * \param Id int
 * \return int retorna 0 si pudo realizarse la baja. Retorna -1 si no pudo realizarse la baja.
 *
 */
int removeEmployee(Employee* list, int len, int Id);


/** \brief busca un empleado recibiendo como parametro su Id.
 *
 * \param list Employee* puntero al array de empleados.
 * \param len int tamaño del array.
 * \param Id int
 * \return int retorna el indice del empleado si se encontro. Si no se encontro retorna -1.
 *
 */
int findEmployeeById(Employee* list, int len,int Id);


/** \brief solicita la modificacion de un empleado recibiendo como parametro su Id.
 *
 * \param lista[] Employee array de empleados.
 * \param tam int tamaño del array.
 * \param Id int
 * \return int retorna 1 si pudo realizarse la solicitud correctamente. Retorna 0 si no pudo realizarse la solicitud de modificacion.
 *
 */
int modifyEmployee(Employee lista[], int tam, int Id);


/** \brief modifica el apellido del empleado.
 *
 * \param p Employee variable estructura donde se guarda el nuevo apellido.
 * \param lista[] Employee array de empleados.
 * \param indice int tamaño del array de empleados.
 * \return int retorna 1 si pudo modificarse el apellido. Retorna 0 si no pudo modificarse el apellido.
 *
 */
int modifyLastName(Employee p, Employee lista[], int indice);


/** \brief modifica el salario del empleado.
 *
 * \param p Employee variable estructura donde se guarda el nuevo salario.
 * \param lista[] Employee array de empleados.
 * \param indice int tamaño del array de empleados.
 * \return int retorna 1 si pudo modificarse el salario. Retorna 0 si no pudo modificarse el salario.
 *
 */
int modifySalary(Employee p, Employee lista[], int indice);



/** \brief modifica el sector del empleado.
 *
 * \param p Employee variable estructura donde se guarda el nuevo sector.
 * \param lista[] Employee array de empleados.
 * \param indice int tamaño del array de empleados.
 * \return int retorna 1 si pudo modificarse el sector. Retorna 0 si no pudo modificarse el sector.
 *
 */
int modifySector(Employee p, Employee lista[], int indice);


/** \brief ordena el array de empelados por sector ascendente o descendente y de forma alfabetica en ambos casos.
 *
 * \param list Employee* puntero a array de empleados.
 * \param len int tamaño del array de empelados.
 * \param order int 1 indica ordenar sectores de manera ascendente y 0 indica ordenarlos de manera descendente.
 * \return int retorna 0 si se pudo realizar el ordenamiento. Retorna 1 si no se pudo realizar el ordenamiento.
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief calcula el total de empleados, el total de la suma de los salarios y el salario promedio.
 *
 * \param list[] Employee array de empleados.
 * \param len int tamaño del array.
 * \return int retorna 1 si el total de empleados y el total de salarios pudieron calcularse. Retorna 0 si los totales no pudieron calcularse.
 *
 */
int salaryAverage(Employee list[], int len);


/** \brief valida que el dato ingresado sea una cadena de solo caracteres.
 *
 * \param cadena[] char array de caracteres.
 * \return int retorna 1 si encuentra un caracter que no es del alfabeto ni un espacio. Retorna 0 si todos los caracteres de la cadena son del alfabeto o espacios.
 *
 */
int validaCadena(char cadena[]);


/** \brief verifica que el dato ingresado sea un entero validando el retorno de scanf.
 *
 * \param pEntero int* puntero al entero.
 * \param mensaje char* array de caracteres.
 * \return void
 *
 */
void validaNumeros(int* pEntero, char* mensaje);


/** \brief verifica que el dato ingresado sea un float validando el retorno de scanf.
 *
 * \param pFloat int* puntero al float.
 * \param mensaje char* array de caracteres.
 * \return void
 *
 */
void validaNumerosFloat(float* pFloat, char* mensaje);
