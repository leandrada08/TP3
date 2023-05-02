
#ifndef ALUMNO_H

#define ALUMNO_H

/**
 * @file alumno.h 
 * @brief codig
*/


/** @brief Declaracion publicas del modulo de alumno
 * En este archivo nos centramos en hacer las declaracion publicas de 
 * las estructura y funciones que defineremos en el modulo alumno.c
*/

//# Definicion de macros
#include <stdint.h>
#include <stdio.h> 
#define FIELD_SIZE 50

// Declaracion de datos tipo publico
/** @brief Declaro la estructura de datos alumno_s 
 * En C no es posible hacer funciones privadas como se pide, es por ello
 * que lo haremos es ocultar detalles de implementación de una estructura 
 * de datos o una función, de modo que solo las partes del código que necesitan 
 * interactuar con esa estructura o función tengan acceso a ella. Para hacer esto creamos
 * una estructura incompleta en el archivo .h y definir la estructura completa en el archivo .c
 **/
 
 typedef struct alumno_s * alumno_t;

// Declaracion publica de funciones
/** \brief Declaracion de la funcion serializar
 * Esta funcion se encargara de los datos de una estructura del tipo alumno_s(alumno) en un formato json(cadena_json) en un cierto espacio(espacio)
 * dado, y si no entra en el espacio dado, devolver un -1 y si entra, devolvera el espacio ocupado por la cadena generada.
 * #### Observaciones:
 * - Poniendo el asterisco entre el tipo de y el dato, le estoy avisando que el dato es un puntero y no la estructura completa
 * - Con el const estoy aclarando que la estructura es constante. 
*/
int SerializarAlumno(const struct alumno_s * alumno,char cadena_json[], uint32_t espacio); 

/** @brief Declaro la funcion crear un alumno
 * Esta funcion crea un alumno a partir de sus parametro.
 * Le debemos dar el apellido,nombre y documento del alumno y nos devuelve un puntero a la estructura de datos asignada para almacenar los datos
 * del alumno, o el puntero nulo si no se pudo crear la estructura
*/

alumno_t CrearAlumno(const char * apellido,const char * nombre,const int documento);


#endif