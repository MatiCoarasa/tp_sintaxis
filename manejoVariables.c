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
        t_variableDeclarada* unaVariable = t_nodoDeLista->valor;

        if(!strcmp(nombre,unaVariable->nombreVariable) && !strcmp(tipo,unaVariable->tipoVariable)){
            return true;
        }
    }
    return false;
}
