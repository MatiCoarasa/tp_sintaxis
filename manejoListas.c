#include "libreria.h"

t_nodo* agregarNodoAlFinal(char* valor, t_nodo* lista)
{

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));

    nuevoNodo->valor = strdup(valor);
    nuevoNodo->siguiente = NULL;
    nuevoNodo->fueContado = false;

    if(lista == NULL)
    {
        lista = nuevoNodo;
        return nuevoNodo;
    }

    t_nodo* aux = lista;

    while(aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    return lista;


}

void printLista(t_nodo* lista)
{
    for(int i = 1; lista != NULL; i++)
    {
        printf("%d: %s\n", i, lista->valor);
        lista = lista->siguiente;
    }

}

int largoLista(t_nodo* lista)
{

    int longitud = 0;

    while(lista != NULL)
    {
        longitud++;
        lista = lista->siguiente;
    }

    return longitud;
}

void mapLista(t_nodo* lista, void funcionAAplicar(t_nodo*))
{

    t_nodo* unNodo = lista;

    while(unNodo != NULL)
    {

        funcionAAplicar(unNodo);

        unNodo = unNodo->siguiente;
    }
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
