/*VERSIÓN FINAL TERMINADA EL DÍA 29/11/2023*/
#ifndef	E_LIST
#define E_LIST
//_______________________________________________________

typedef struct element{
	char horaInicio[6];
	char horaFin[6];
	char materia[51];
	char profesor[51];
	char grupo[5];

	int tiempo_i;
	int tiempo_f;

	int cdg;
	char *nombre;
}element;

typedef element horario;

typedef struct nodeL{
	element e;
	struct nodeL *next;
}NodeL;

typedef struct list{
	NodeL *start;
}List;

typedef List Grupo;

//______________________________________________________

void create (List *ls);
void DeleteAllNodes(List *ls);

int is_EmptyLE (List ls);
void PrintListE (List ls);

NodeL *searchByNodeNumber(List ls, int nodeNumber);
NodeL *searchE (List ls, element e);

void InsertAtStart (List *ls, element e);
void InsertAtEnd (List *ls, element e);
void InsertAfterNode (List* ls, element e, NodeL *a);
element DeleteAtStart (List* ls);
element  DeleteAtEnd (List *ls);

//_______________________________________________________
#endif