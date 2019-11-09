#include "libreria.h"
extern t_nodo* variablesRepetidas;
t_nodo* lineasDeErrorBinario = NULL;

void printearErroresSemanticos()
{
    printf("--ERRORES SEMANTICOS--\n\n");
    printearVariablesRepetidas();
    printf("\n--\n");
    printearErroresBinarios();
    printf("\n--\n");

}


void printearVariablesRepetidas()
{

    printf("-Doble declaracion de variables-\n");

    t_nodo* listaAux = variablesRepetidas;

    while(listaAux != NULL)
    {
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable);
        listaAux = listaAux->siguiente;
    }
}

void printearErroresBinarios(){
    printf("-Errores en operaciones binarias-\n");

    t_nodo* listaAux = lineasDeErrorBinario;

    while(listaAux != NULL){
        int* unaLinea = listaAux->valor;
        printf("Error en la linea %i\n",*unaLinea);
        listaAux = listaAux->siguiente;
    }
}

bool lineaEnLaLista(int linea)
{
    t_nodo* nodoDeLista = lineasDeErrorBinario;

    while(nodoDeLista != NULL)
    {
        int* unaLinea = nodoDeLista->valor;
        if(*unaLinea == linea)
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

void agregarErrorBinarioEnLinea(int linea)
{

    if(!lineaEnLaLista(linea))
    {
        int* lineaEnPuntero = malloc(sizeof(int));
        *lineaEnPuntero = linea;
        lineasDeErrorBinario = agregarValorALista(lineaEnPuntero, lineasDeErrorBinario);
    }

}
