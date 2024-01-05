#include "e_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void login_admin(Grupo *grupos);
void agregarHorario(Grupo *grupos, horario h);

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void login_admin(Grupo *grupos){
    printf("*********[MENU]***********\n");
    printf("1) Agregar un horario.\n");
    printf("2) Modificar un horario\n");
    printf("3) Eliminar un horario\n");
    printf("4) Consultar horarios\n");
    printf("5) Salir\n");
    printf("Seleccione una opción: ");

    int opc;
    scanf("%d", &opc);
    limpiarBuffer();

    switch (opc)
    {
    case 1:
        // validar que existe el grupo
        horario nuevo_horario;

        char materia[51];
        char horaInicio[6];
        char horaFin[6];
        char profesor[51];
        char grupo[6];

        printf("Nombre de la materia: ");
        fgets(materia, 51, stdin);

        printf("Hora inicio: ");
        fgets(horaInicio, 6, stdin);

        printf("Hora final: ");
        limpiarBuffer();
        fgets(horaFin, 6, stdin);

        printf("Nombre del profesor : ");
        limpiarBuffer();
        fgets(profesor, 51, stdin);

        printf("Grupo: ");
        fgets(grupo, 5, stdin);

        strcpy(nuevo_horario.materia, materia);
        strcpy(nuevo_horario.horaFin, horaFin);
        strcpy(nuevo_horario.horaInicio, horaInicio);
        strcpy(nuevo_horario.profesor, profesor);
        strcpy(nuevo_horario.grupo, grupo);

        agregarHorario(grupos, nuevo_horario);
        break;
    // ...
    default:
        break;
    }
}

void agregarHorario(Grupo *grupos, horario h){
    // si las listas estan vacias, agregar horario
    char boolean = 0;
    for (int k = 0; k < 5; k++){
        if (!is_EmptyLE(grupos[k])){
            char boolean = 1;
        }
    }

    // validacion
    h.horaFin;
    h.horaInicio;

    char s_horas_i[2];
    char s_horas_f[2];
    char s_min_i[2];
    char s_min_f[2];
    // 15:00
    for (int k = 0; k < 2; k++){
        s_horas_i[k] = h.horaInicio[k];
        s_min_i[k] = h.horaInicio[3 + k];

        s_horas_f[k] = h.horaFin[k];
        s_min_f[k] = h.horaFin[3 + k];
    }

    int horas_i = 60 * atoi(s_horas_i);
    int min_i = atoi(s_min_i);

    int horas_f = 60 * atoi(s_horas_f);
    int min_f = atoi(s_min_f);

    int tiempo_i = horas_i + min_i; // total de minutos hasta la hora de inicio
    int tiempo_f = horas_f + min_f; // total de minutos hasta el fin

    h.tiempo_i = tiempo_i;
    h.tiempo_f = tiempo_f;

    char s_num_grupo[1];
    s_num_grupo[0] = h.grupo[4];
    int num_grupo = atoi(s_num_grupo);

    if (boolean == 0){
        InsertAtStart(&grupos[num_grupo], h);
        return;
    }

    for (int k = 0; k < 5; k++){
        // si las listas estan vacias no compares con esos grupos
        if (!is_EmptyLE(grupos[k]) || k != num_grupo){
            if (strcmp(grupos[k].start->e.profesor, grupos[num_grupo].start->e.profesor)){
                char t_dentro = grupos[num_grupo].start->e.tiempo_i >= grupos[k].start->e.tiempo_i && grupos[num_grupo].start->e.tiempo_f <= grupos[k].start->e.tiempo_f; // esta metido dentro de un horario
                char t_izquierda = grupos[num_grupo].start->e.tiempo_i >= grupos[k].start->e.tiempo_i && grupos[num_grupo].start->e.tiempo_i <= grupos[k].start->e.tiempo_f; // esta traslapado por la izquierda
                char t_derecha = grupos[num_grupo].start->e.tiempo_f <= grupos[k].start->e.tiempo_f && grupos[num_grupo].start->e.tiempo_f >= grupos[k].start->e.tiempo_i; // esta traslapado por la derecha
                char t_fuera = grupos[num_grupo].start->e.tiempo_i <= grupos[k].start->e.tiempo_i && grupos[num_grupo].start->e.tiempo_f >= grupos[k].start->e.tiempo_f; // esta metido dentro de un horario

                if (t_dentro || t_derecha || t_izquierda || t_fuera){
                    printf("El horario se traslapa con otro grupo.\n");
                    return;
                }
                else{
                    InsertAtEnd(&grupos[num_grupo], h);
                }
            }
        } 
    }

    /* validar que no se traslapen horario
        - que un grupo no tenga horarios sobrepuestos
            - 2vc1 y 2cv2
                - 2vc1 tiene 14:00 15:30     [14:00 - 15:30]
                - 2cv2 tiene 15:00 16:30                [15:00 - 16:30]
                - ana belem tiene clase con 2cv1 y seguido con 2cv2
        - que un profesor no tenga dos clases al mismo tiempo
    */
}