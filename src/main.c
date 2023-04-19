#include "alumno.h"
#include <stdio.h>

/**
 * @file main.c 
 * @brief codigo principal de la apliacacion
*/

int main(void) {
    static const struct alumno_s yo ={//!<Defino una variable global adentro del main, esta se guardara en flash
        .apellido = "Andrada", //!< Defino los campos de mi struct, ya que a ser una variable global, esta no se puede modificar despues
        .nombre = "Luis Elian",
        .documento = 43362912,
    }; 
    char json[128];
    if (Serializar(&yo , json , sizeof(json)) >= 0){
        printf("%s\n", json);
    } else{
        printf("error al serializar");
    }
    return 0;
}