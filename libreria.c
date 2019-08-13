#include "libreria.h"


void agregarNodoOSumarContador(char* valor, t_nodo_contador* lista){

    if(lista == NULL){

        t_nodo_contador* nuevoNodo = (t_nodo_contador*)malloc(sizeof(t_nodo_contador));

        nuevoNodo->valor = valor;
        nuevoNodo->cantidad = 1;
        nuevoNodo->siguiente = NULL;

        lista = nuevoNodo;
        return;

    } else {
        
        t_nodo_contador* aux = lista;

        while(aux){
            if(aux->valor == valor){
                (aux->cantidad)++;
                return;
            }
            aux = aux->siguiente;
        }

    }
      
}

void agregarNodo(char* valor, t_nodo* lista){

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));


    if(lista){
        lista->siguiente = nuevoNodo;
        
    }
      
}