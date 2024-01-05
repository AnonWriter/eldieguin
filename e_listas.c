/*VERSIÓN FINAL TERMINADA EL DÍA 29/11/2023*/
#include "e_lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create (List *ls){
	ls -> start = NULL;
}

int is_EmptyLE (List ls){
	if (ls.start == NULL){
		printf("LISTA VACIA\n");
		return 1;
	}else{
		return 0;
	}
}

void InsertAtStart (List *ls, element e){
	NodeL*new = (NodeL*)malloc(sizeof (NodeL));
	new -> next = ls -> start;
	ls -> start = new;
	new -> e = e;
}

void InsertAtEnd (List *ls, element e){

	if (is_EmptyLE(*ls)){
		InsertAtStart(ls, e);
	}else{
		NodeL *aux = ls -> start;
		while (aux -> next != NULL){
			aux = aux -> next;
		}
		NodeL *new=(NodeL*)malloc(sizeof(NodeL));
		new -> next = NULL;
		new -> e = e;
		aux -> next = new;
	}
}

NodeL *searchE (List ls, element e){
	NodeL *aux;
	aux = ls.start;
	while(aux != NULL && e.cdg != aux -> e.cdg){
		aux = aux -> next;
	}
	return aux;
}

void InsertAfterNode (List* ls, element e, NodeL *a){
	NodeL*new = (NodeL*)malloc(sizeof(NodeL));
	new -> next = a -> next;
	a -> next = new;
	new -> e = e;
}

element DeleteAtStart (List* ls){
	element aux_e;
	aux_e.cdg = -666; //ERROR=-666
	if (is_EmptyLE(*ls) == 1){
			printf("Esta vacia\n");
			return aux_e;
	}else{
		NodeL *aux;
		aux = ls -> start;
		aux_e = aux -> e;
		ls -> start = aux -> next;
		free(aux);
		return aux_e;
	}
}

element  DeleteAtEnd (List *ls){
	if (!is_EmptyLE(*ls)){
		if (!(ls -> start -> next == NULL)){
			NodeL *aux1 = ls -> start;
			NodeL *aux2 = aux1 -> next;
			while(aux2 -> next != NULL){
				aux1 = aux1 -> next;
				aux2 = aux2 -> next;
			}
			element aux_e;
			aux_e = aux2 -> e;
			aux1 -> next = NULL;
			free(aux2);
			return aux_e;
		}else{
			element aux_e;
			NodeL *aux;
			aux_e = ls -> start -> e;
			aux = ls -> start;
			ls -> start = NULL;
			free(aux);
			return aux_e;
		}
	}else{
		printf("Lista vacia\n");
	}
}

void PrintListE (List ls){
	NodeL *aux;
	aux = ls.start;

		while(aux != NULL){
			printf("Codigo: %d 	Nombre: %s \n", aux -> e.cdg, aux -> e.nombre);
			aux = aux -> next;
		}
}

void DeleteAllNodes(List *ls) {
	while (!is_EmptyLE(*ls)) {
		DeleteAtEnd(ls);
	}
}


NodeL *searchByNodeNumber(List ls, int nodeNumber) {
	NodeL *aux = ls.start;
	int currentNumber = 1;

	while (aux != NULL && currentNumber != nodeNumber) {
		aux = aux->next;
		currentNumber++;
	}

    if (aux != NULL && currentNumber == nodeNumber) {
    	return aux;
    } else {
    	printf("Nodo no encontrado\n");
    	return NULL;
    }
}


	
