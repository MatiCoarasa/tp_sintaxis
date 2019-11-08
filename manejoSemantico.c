#include "libreria.h"
extern t_nodo* variablesRepetidas;

void printearErroresSemanticos(){
    printf("--ERRORES SEMANTICOS--\n\n");
    printearVariablesRepetidas();
    printf("------\n\n");

}


void printearVariablesRepetidas(){
    printf("--\n");
    printf("-Doble declaracion de variables-\n\n");

    t_nodo* listaAux = variablesRepetidas;

    while(listaAux != NULL){
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable);
        listaAux = listaAux->siguiente;
    }
    printf("--\n");


}
