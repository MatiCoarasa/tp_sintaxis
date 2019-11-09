#include "libreria.h"

t_nodo* variablesDeclaradas = NULL;
t_nodo* variablesRepetidas = NULL;
t_nodo* bufferDeNombreDeVariables = NULL;


void agregarNombreDeVariableABuffer(char* nombre)
{
    bufferDeNombreDeVariables = agregarValorALista(strdup(nombre), bufferDeNombreDeVariables);
}

bool variableEstaEnLista(char* nombre, char* tipo,t_nodo* listaDeVariables)
{
    t_nodo* nodoDeLista = listaDeVariables;

    while(nodoDeLista != NULL)
    {
        t_variableDeclarada* unaVariable = nodoDeLista->valor;

        if(!strcmp(nombre,unaVariable->nombreVariable) && !strcmp(tipo,unaVariable->tipoVariable))
        {
            return true;
        }
        nodoDeLista = nodoDeLista->siguiente;
    }
    return false;
}

bool variableYaFueDeclarada(char* nombre, char* tipo)
{
    return variableEstaEnLista(nombre,tipo,variablesDeclaradas);
}

bool variableYaFueRepetida(char* nombre,char* tipo){
    return variableEstaEnLista(nombre,tipo,variablesRepetidas);
}

void liberarBufferDeNombresDeVariables()
{
    liberarLista(bufferDeNombreDeVariables);
    bufferDeNombreDeVariables = NULL;
}

void declararTodasLasVariablesEnBuffer(char* tipoDeVariables)
{

    t_nodo* listaAux = bufferDeNombreDeVariables;
    while(listaAux != NULL)
    {
        agregarVariableDeclarada(listaAux->valor,tipoDeVariables);
        listaAux = listaAux->siguiente;
    }
    liberarBufferDeNombresDeVariables();

}

void agregarVariableRepetida(t_variableDeclarada* variableRepetida){
    if (!variableYaFueRepetida(variableRepetida->nombreVariable,variableRepetida->tipoVariable)){
        variablesRepetidas = agregarValorALista(variableRepetida, variablesRepetidas);
    }
    //Si ya fue repetida no se agrega en la lista.
}

void agregarVariableDeclarada(char* nombre, char* tipo)
{

        t_variableDeclarada* nuevaVariable = malloc(sizeof(t_variableDeclarada));

        nuevaVariable->nombreVariable = strdup(nombre);
        nuevaVariable->tipoVariable = strdup(tipo);

        if(variableYaFueDeclarada(nombre,tipo)){
            agregarVariableRepetida(nuevaVariable); //Este pasa manos puede ser un poco innecesario.
        }
        else{
            variablesDeclaradas = agregarValorALista(nuevaVariable, variablesDeclaradas);
        }


}
