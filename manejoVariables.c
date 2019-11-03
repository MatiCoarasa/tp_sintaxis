#include "libreria.h"

t_nodo* variablesDeclaradas;

void agregarVariableDeclarada(char* nombre, char* tipo)
{

    t_variableDeclarada* nuevaVariable = malloc(sizeof(t_variableDeclarada));

    agregarValorALista(nuevaVariable, variablesDeclaradas);

}

bool variableYaFueDeclarada(char* nombre, char* tipo)
{
    t_nodo* nodoDeLista = variablesDeclaradas;

    while(nodoDeLista != NULL)
    {
        t_variableDeclarada* unaVariable = nodoDeLista->valor;

        if(!strcmp(nombre,unaVariable->nombreVariable) && !strcmp(tipo,unaVariable->tipoVariable)){
            return true;
        }
    }
    return false;
}


void printearVariablesDeclaradas(){

    printf("--VARIABLES DECLARADAS--\n\n");

    t_nodo* listaAux = variablesDeclaradas;

    while(listaAux != NULL){
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable); //Si se cambia por enum los tipos hay que cambiar aca. (Hacer funcion de enum->string)
        listaAux->siguiente;
    }

    printf("------\n\n");


}
