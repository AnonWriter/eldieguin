/*VERSIÓN FINAL TERMINADA EL DÍA 29/11/2023*/
#ifndef	E_LIST
	#define E_LIST
//_______________________________________________________
	typedef struct Element{
		char dia[26];
        char horaInicio[26];
        char horaFin[26];
        char materia[50];
        char profesor[50];
		char *cdg;
		char *nombre;
	}element;
	typedef element Horario;
	

	typedef struct nodeL{
		element e;
		struct nodeL *next;
	}NodeL;

	typedef struct list{
		NodeL *start;
	}List;

	/*typedef struct horario{
        char dia[26];
        char horaInicio[26];
        char horaFin[26];
        char materia[50];
        char profesor[50];
    }Horario;*/

    typedef struct nodeHorario{
        Horario h;
        struct nodeHorario *next;
    }NodoHorario;

    typedef struct{
        NodoHorario *start;
    }ListaHorarios;


//______________________________________________________

	void create (List *ls);
		int is_EmptyLE (List ls);
			void InsertAtStart (List *ls, element e);
				void InsertAtEnd (List *ls, element e);
					NodeL *searchE (List ls, element e);
						void InsertAfterNode (List* ls, element e, NodeL *a);
							element DeleteAtStart (List* ls);
								element  DeleteAtEnd (List *ls);
									void PrintListE (List ls);
										void DeleteAllNodes(List *ls);
                                            void agregarHorario(ListaHorarios *lista, Horario nuevoHorario);
                                                void mostrarHorario(ListaHorarios *lista);
                                                    void liberarLista(ListaHorarios *lista);
														NodeL *searchByNodeNumber(List ls, int nodeNumber);
//_______________________________________________________
	#include "e_listas.c"
#endif