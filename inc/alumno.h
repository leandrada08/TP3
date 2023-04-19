
#ifndef ALUMNO_H

#define ALUMNO_H

// Uso documentacion doxygen
/**
 * @file alumno.h 
 * @brief codig
*/


/** \brief Declaracion publicas del modulo de alumno
 * En este archivo nos centramos en hacer las declaracion publicas de 
 * las estructura y funciones que defineremos en el modulo alumno.c
 *
*/

//# Definicion de macros
#include <stdint.h>
#include <stdio.h> //Los include se deben hacer con <> no con comillas
#define FIELD_SIZE 50

// Declaracion de datos tipo publico
/** \brief Declaro la estructura de datos alumno_s 
 * @param :Nombre del alumno
 * @param :Apellido del alumno 
 * @param :Documento del alumno
 * #### Observaciones:
 * - Defino como uint64_t y no como int ya que el primero tiene mayor rango, que necesitamos para escribir un documento 
 * - Declaro la estructura directamente con punteros ya que casi siempre manejaremos la misma con punteros
*/
typedef struct alumno_s {
    char nombre[FIELD_SIZE];
    char apellido[FIELD_SIZE];
    uint64_t documento;
} * alumno_t;

// Declaracion publica de funciones
/** \brief Declaracion de la funcino serializar
 * Esta funcion se encargara de los datos de una estructura del tipo alumno_s(alumno) en un formato json(cadena_json) en un cierto espacio(espacio)
 * dado, y si no entra en el espacio dado, devolver un -1 y si entra, devolvera el espacio ocupado por la cadena generada.
 * #### Observaciones:
 * - Poniendo el asterisco entre el tipo de y el dato, le estoy avisando que el dato es un puntero y no la estructura completa
 * - Con el const estoy aclarando que la estructura es constante. 
*/
int Serializar(const struct alumno_s * alumno,char cadena_json[], uint32_t espacio); 


#endif