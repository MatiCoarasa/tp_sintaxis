#include "libreria.h"

t_nodo* agregarValorALista(void* valor, t_nodo* lista) //El puntero que se envia como valor, no se tiene que liberar
{

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));

    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->fueContado = false;

    if(lista == NULL)
    {
        return nuevoNodo;
    }

    t_nodo* aux = lista;

    while(aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    aux->siguiente = nuevoNodo;
    return lista;


}

void liberarLista(t_nodo* lista)
{

    t_nodo* aux;

    while(lista != NULL)
    {

        aux = lista;
        lista = lista->siguiente;

        free(aux->valor);
        free(aux);
    }
}
