#include "alumno.h"
#include <stdio.h>

/**
 * @file main.c 
 * @brief codigo principal de la apliacacion
*/

int main(void) {
    char json[128];
    alumno_t yo = CrearAlumno("Andrada","Luis Elian",43362912);
    if (SerializarAlumno(yo , json , sizeof(json)) >= 0){
        printf("%s\n", json);
    } else{
        printf("error al serializar");
    }
    return 0;
}