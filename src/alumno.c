#include "alumno.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


/**
 * @file alumno.c 
 * @brief Codigo fuente de alumno
 * 
*/
/**
 * @brief Codigo fuente de alumno
 * 
*/
//Declaracion de funciones locales

static int SerializarNumero(const char * campo,int * valor_campo, char * cadena_json,int  espacio);

static int SerializarCadena(const char * campo,char * valor_campo, char * cadena_json,int  espacio);

//Definicion de estructuras
/** @brief
 * @param: En este parametro almacenaremos el apellido del alumno
 * @param: En este parametro almacenaremos el nombre del alumno
 * @param: En este parametro almacenaremos el documento del alumno
*/
struct alumno_s
{
    char apellido[50];
    char nombre[50];
    uint32_t documento;
    bool libre;
};

struct alumno_s instancias[50]={0};



/** \brief Deficion de la funcion Serializar
 * Esta funcion se encargara de los datos de una estructura del tipo alumno_s(alumno) en un formato json(cadena_json) en un cierto espacio(espacio)
 * dado, y si no entra en el espacio dado, devolver un -1 y si entra, devolvera el espacio ocupado por la cadena generada.
 * 
*/
int SerializarAlumno(const struct alumno_s * alumno,char cadena_json[], uint32_t espacio){
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


//Creo alumno de manera dinamica
/*alumno_t CrearAlumno(char * apellido, char * nombre, int documento){
	/** @brief Creo un puntero para el objeto
	 * Con lo colocado a la izquierda de la igualdad estamos creando un puntero del tipo alumno_t llamado 
	 * resultado, el problema es que este puntero esta apuntando a un espacio vacio.
	 * Para cambiar esto usamos la funcion malloc, la cual nos devuelve una direccion de memoria a partir
	 * de la cual nos reservara una cantidad de memoria especificada. En nuestro caso la cantidad de memoria 
	 * que necesitamos es la que ocupa una esstructura del tipo alumno_s
	**/
	/*alumno_t resultado = malloc(sizeof(struct alumno_s));
	strcpy(resultado->nombre, nombre); //!< Escribo en el atributo nombre de mi estructura el nombre pasado por funcion
    strcpy(resultado->apellido, apellido);
    resultado->documento, documento;
	return resultado;
}*/

//Creo alumno de manera estatica
alumno_t CrearAlumno(const char * apellido,const char * nombre,const int documento){
    for (size_t i = 0; i < 50; i++)
    {
        if(instancias[i].libre==0){
        	strcpy(instancias[i].nombre, nombre); //!< Escribo en el atributo nombre de mi estructura el nombre pasado por funcion
            strcpy(instancias[i].apellido, apellido);
            instancias[i].documento=documento;
            instancias[i].libre= true;
	        return &instancias[i];
        }
    }
    return NULL;
}
