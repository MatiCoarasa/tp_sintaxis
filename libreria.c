#include "libreria.h"



void agregarNodo(char* valor, t_nodo* lista){

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));

    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if(lista == NULL) {
        lista = nuevoNodo;
        return;
    }

    t_nodo* aux = lista;

    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }

    aux->siguiente = nuevoNodo;
      
}

void agregarNodoOSumarContador(char* valor, t_nodo_contador* lista){

    t_nodo_contador* nuevoNodo = (t_nodo_contador*)malloc(sizeof(t_nodo_contador));

    nuevoNodo->valor = valor;
    nuevoNodo->cantidad = 1;
    nuevoNodo->siguiente = NULL;

    if(lista == NULL){
        lista = nuevoNodo;
        return;
    }

    t_nodo_contador* aux = lista;

    while(aux != NULL){
        if(strcmp(aux->valor,valor)){
            //Caso coincide valor con elemento de lista.
            aux->cantidad++;
            free(nuevoNodo->valor);
            free(nuevoNodo);
            return;
        } else if(aux->siguiente != NULL){
            //Caso no coincidió valor y hay siguiente elemento para recorrer.
            aux = aux->siguiente;
        } else {
            //Caso no coincidió valor y no hay más elementos para recorrer.
            aux->siguiente = nuevoNodo;
        }
    }
}