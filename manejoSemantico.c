#include "libreria.h"
extern t_nodo* variablesRepetidas;
t_nodo* lineasDeErrorBinario = NULL;
t_nodo* lineasDeErrorAsignacion = NULL;
t_nodo* lineasDeErrorSintactico = NULL;

bool numeroEstaEnLaLista(int numero, t_nodo* lista)
{
    t_nodo* nodoDeLista = lista;

    while(nodoDeLista != NULL)
    {
        int* unNumero = nodoDeLista->valor;
        if(*unNumero == numero)
        {
            return true;
        }
        else
        {
            nodoDeLista = nodoDeLista->siguiente;
        }

    }
    return false;

}

t_nodo* agregarIntALista(int numero,t_nodo* lista){

    if(!numeroEstaEnLaLista(numero,lista))
    {
        int* numeroEnPuntero = malloc(sizeof(int));
        *numeroEnPuntero = numero;
        return agregarValorALista(numeroEnPuntero, lista);
    }
    else{
        return lista;
    }


}

void agregarErrorBinarioEnLinea(int linea)
{
    lineasDeErrorBinario = agregarIntALista(linea,lineasDeErrorBinario);
}

void agregarErrorAsignacionEnLinea(int linea){
    lineasDeErrorAsignacion = agregarIntALista(linea,lineasDeErrorAsignacion);
}

void agregarErrorSintactico(int linea){
    lineasDeErrorSintactico = agregarIntALista(linea,lineasDeErrorSintactico);
}

