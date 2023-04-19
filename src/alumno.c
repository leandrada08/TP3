#include "alumno.h"
#include <stdio.h>
#include <stdint.h>


/**
 * @file alumno.c 
 * @brief Codigo fuente de alumno
*/

/** \brief Modulo alumno
 * En este modulo nos encargaremos de definir el modulo alumno, con sus respectivas funciones publicas y privadas
 * 
*/

/** \brief Declaracion de funciones locales
 * Declaramos las funciones locales que usaremos, para nuestro caso son 2:
 * - SerializarNumero: Se encargar de acomodar un numero con su respectivo campo de la siguiente manera ""campo":"valor_campo""
 * - SerializarCadena: Igual que SerializarNumero solo que ahora el valor del campo sera una cadena de caracteres
*/
static int SerializarNumero(const char * campo,int * valor_campo, char * cadena_json,int  espacio);

static int SerializarCadena(const char * campo,char * valor_campo, char * cadena_json,int  espacio);


/** \brief Deficion de la funcion Serializar
 * Esta funcion se encargara de los datos de una estructura del tipo alumno_s(alumno) en un formato json(cadena_json) en un cierto espacio(espacio)
 * dado, y si no entra en el espacio dado, devolver un -1 y si entra, devolvera el espacio ocupado por la cadena generada.
 * 
*/
int Serializar(const struct alumno_s * alumno,char cadena_json[], uint32_t espacio){
    
    int disponible=espacio;
    cadena_json[0] = '{'; //!< Introduzco { en el lugar 0 de json para cumplir con el formato
    cadena_json++; //!< Le sumo 1 a cadena para que no se sobre escriba la comilla 
    disponible--; //!< Resto un lugar de los disponibles
    int resultado = SerializarCadena("apellido",(alumno->apellido),cadena_json, disponible); //<! Coloco en la cadena apellido en formato json
    if(resultado>0){//<! Verifico si lo colocado entro en la cadena
        cadena_json=cadena_json+resultado;
        disponible=disponible-resultado;
        resultado = SerializarCadena("nombre",(alumno->nombre),cadena_json,disponible);//<! Coloco en la cadena nombre en formato json
    }
    if(resultado>0){//<! Verifico si lo colocado entro en la cadena
        cadena_json=cadena_json+resultado;
        disponible=disponible-resultado;
        resultado = SerializarNumero("documento",(alumno->documento),cadena_json,disponible); //<! Coloco en la cadena documento en formato json
    }
    if(resultado>0){//<! Verifico si lo colocado entro en la cadena
        cadena_json=cadena_json+resultado;
        disponible=disponible-resultado;
        cadena_json[-1]='}';
        resultado=espacio-disponible;
    }
    return resultado;
}

/** \brief Definicion de funciones locales
 * SerializarNumero: Se encargara de colocar un numero dado en una cadena dada
 * SerializarCadena: Se encargara de colocar una cadena de caracteres dada en una cadena en memoria
*/
static int SerializarNumero(const char * campo,int * valor_campo, char * cadena_json,int  espacio){
    return snprintf(cadena_json,espacio,"\"%s\":\"%d\",",campo,valor_campo);
}
static int SerializarCadena(const char * campo,char * valor_campo, char * cadena_json,int  espacio){
    return snprintf(cadena_json,espacio,"\"%s\":\"%s\"",campo,valor_campo);
}
// Porque se usa puntero en la primera variable?
