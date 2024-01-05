#include "e_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


login_admin(Grupo *grupos){
    int opc;
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        int elegir_grupo;
        scanf("%d", &elegir_grupo);
        // validar que existe el grupo
        printf("Ingrese los datos: ");

        horario nuevo_horario;

        printf("Nombre de la materia: ");
        fgets(&nuevo_horario.materia, sizeof(nuevo_horario.materia), stdin);
        printf("Hora final: ");
        fgets(&nuevo_horario.horaFin, sizeof(nuevo_horario.horaFin), stdin);
        printf("Hora inicio: ");
        fgets(&nuevo_horario.horaInicio, sizeof(nuevo_horario.horaInicio), stdin);
        printf("Nombre del profesor : ");
        fgets(&nuevo_horario.profesor, sizeof(nuevo_horario.profesor), stdin);
        printf("Grupo: ");
        fgets(&nuevo_horario.grupo, sizeof(nuevo_horario.grupo), stdin);

        agregarHorario(grupos, nuevo_horario);
        break;
    // ...
    default:
        break;
    }

    return 0;
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

    char s_num_grupo[1] = h.grupo[4];
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