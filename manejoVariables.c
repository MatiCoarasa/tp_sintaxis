#include "libreria.h"

t_nodo* variablesDeclaradas = NULL;
t_nodo* bufferDeNombreDeVariables = NULL;

void agregarNombreDeVariableABuffer(char* nombre){
    bufferDeNombreDeVariables = agregarValorALista(strdup(nombre), bufferDeNombreDeVariables);
}

void liberarBufferDeNombresDeVariables(){
    liberarLista(bufferDeNombreDeVariables);
    bufferDeNombreDeVariables = NULL;
}

void declararTodasLasVariablesEnBuffer(char* tipoDeVariables){

    t_nodo* listaAux = bufferDeNombreDeVariables;
    while(listaAux != NULL){
        agregarVariableDeclarada(listaAux->valor,tipoDeVariables);
        listaAux = listaAux->siguiente;
    }
    liberarBufferDeNombresDeVariables();

}

void agregarVariableDeclarada(char* nombre, char* tipo)
{

    t_variableDeclarada* nuevaVariable = malloc(sizeof(t_variableDeclarada));
    nuevaVariable->nombreVariable = strdup(nombre);
    nuevaVariable->tipoVariable = strdup(tipo);

    variablesDeclaradas = agregarValorALista(nuevaVariable, variablesDeclaradas);

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
        listaAux = listaAux->siguiente;
    }

    printf("------\n\n");


}

void printearVariablesNoDeclaradas(){

    printf("--VARIABLES NO DECLARADAS--\n\n");

    t_nodo* listaAux = variablesDeclaradas;

    while(listaAux != NULL){
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable); //Si se cambia por enum los tipos hay que cambiar aca. (Hacer funcion de enum->string)
        listaAux->siguiente;
    }

    printf("------\n\n");


}

int declararId(char* nombre, char* tipo) {
	if (variableYaFueDeclarada(nombre,tipo)) {
		printearVariablesDeclaradas();
		yyerror(variablesDeclaradas);
		return 0;
	} else {
		agregarVariableDeclarada(nombre, tipo);
		printf("Declare %s,Integer\n", nombre);
		return 1;
	}
}

int validarId(char* nombre, char* tipo) {
	if (!variableYaFueDeclarada(nombre,tipo)) {
		printearVariablesNoDeclaradas();
		yyerror(variablesDeclaradas);
		return 1;
	}
	return 0;
}
