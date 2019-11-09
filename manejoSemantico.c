#include "libreria.h"
extern t_nodo* variablesRepetidas;
t_nodo* lineasDeErrorBinario = NULL;
t_nodo* lineasDeErrorAsignacion = NULL;

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

void printearErroresDeAsignacion(){
    printf("-Errores de asignacion-\n");

    t_nodo* listaAux = lineasDeErrorAsignacion;

    while(listaAux != NULL){
        int* unaLinea = listaAux->valor;
        printf("Error en la linea %i\n",*unaLinea);
        listaAux = listaAux->siguiente;
    }
}

bool numeroEnLaLista(int numero, t_nodo* lista)
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

    if(!numeroEnLaLista(numero,lista))
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



void printearErroresSemanticos()
{
    printf("--ERRORES SEMANTICOS--\n\n");
    printearVariablesRepetidas();
    printf("\n--\n");
    printearErroresBinarios();
    printf("\n--\n");
    printearErroresDeAsignacion();
    printf("\n--\n");

}
