#include "libreria.h"
extern t_nodo* variablesRepetidas;
extern t_nodo* lineasDeErrorBinario;
extern t_nodo* lineasDeErrorAsignacion;
extern t_nodo* variablesDeclaradas;
extern t_nodo* funcionesDeclaradas;

void printearLineaDeArchivo(int lineaALeer){

    FILE* archivo = fopen("entrada.c","r+");

    for (int i = 0; i <= lineaALeer; i++) { //Se asume que la linea que se quiere leer existe.

		char buffer[MAXBUFFER];
		fgets(buffer, MAXBUFFER, archivo);

		if (i+1 == lineaALeer) {
			printf("%s",buffer);
			break;
		}

	}

	fclose(archivo);

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
        printf("Error en la linea %i: ",*unaLinea);
        printearLineaDeArchivo(*unaLinea);
        listaAux = listaAux->siguiente;
    }
}

void printearErroresDeAsignacion(){ //La logica esta repetida con la funcion de arriba. Tal vez se puede delegar.
    printf("-Errores de asignacion-\n");

    t_nodo* listaAux = lineasDeErrorAsignacion;

    while(listaAux != NULL){
        int* unaLinea = listaAux->valor;
        printf("Error en la linea %i\n",*unaLinea);
        printearLineaDeArchivo(*unaLinea);
        listaAux = listaAux->siguiente;
    }
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


void printearVariablesDeclaradas()
{

    printf("--VARIABLES DECLARADAS--\n\n");

    t_nodo* listaAux = variablesDeclaradas;

    while(listaAux != NULL)
    {
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable);
        listaAux = listaAux->siguiente;
    }

    printf("------\n\n");
}

void printearParametrosDeFuncion(t_funcionDeclarada* unaFuncion){
    t_nodo* listaAux = unaFuncion->tiposDeParametros;

    while(listaAux != NULL){
        if(listaAux->siguiente == NULL){
            printf("%s",listaAux->valor); //Por una cuestion estetica, si no quedaria por ejemplo "int, char, float, ".
        }
        else{
            printf("%s, ",listaAux->valor);
        }
        listaAux = listaAux->siguiente;
    }

}

void printearFuncionesDeclaradas(){
    printf("--FUNCIONES DECLARADAS--\n\n");

    t_nodo* listaAux = funcionesDeclaradas;

    while(listaAux != NULL){
        t_funcionDeclarada* unaFuncion = listaAux->valor;
        printf("%s %s (",unaFuncion->tipoDeReturn,unaFuncion->nombreFuncion);
        printearParametrosDeFuncion(unaFuncion);
        printf(");\n");
        listaAux = listaAux->siguiente;
    }
    printf("------\n\n");
}
