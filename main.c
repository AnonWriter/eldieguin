#include "e_lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login_admin(Grupo *grupos);
// 1 agregar horario
// 2 modificar
// 3 eliminar
// 4 consultar
// 5 salir

int main(int argn, char *args[]){
    Grupo _2CV[5];

    printf("Iniciando grupos...\n");
    for(int k = 0; k < 5; k++){
        create(&_2CV[k]);
    }
    printf("Grupos creados.\n");

    if (1)
        login_admin(_2CV);
}