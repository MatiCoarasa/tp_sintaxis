#include "libreria.h"
extern t_nodo* variablesRepetidas;
extern t_nodo* lineasDeErrorBinario;
extern t_nodo* lineasDeErrorAsignacion;
extern t_nodo* lineasDeErrorSintactico;
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

void printearListaDeErrores(t_nodo* lista){

    while(lista != NULL){
        int* unaLinea = lista->valor;
        printf("->Error en la linea %i\n",*unaLinea);
        printearLineaDeArchivo(*unaLinea);
        lista = lista->siguiente;
    }
}

void printearVariablesRepetidas()
{
    printf("__Doble declaracion de variables__\n\n");

    t_nodo* listaAux = variablesRepetidas;

    while(listaAux != NULL)
    {
        t_variableDeclarada* unaVariable = listaAux->valor;
        printf("->%s %s;\n", unaVariable->tipoVariable, unaVariable->nombreVariable);
        listaAux = listaAux->siguiente;
    }
}

void printearErroresBinarios(){
    printf("__Errores en operaciones binarias__\n\n");
   printearListaDeErrores(lineasDeErrorBinario);
}

void printearErroresDeAsignacion(){
    printf("__Errores de asignacion__\n\n");
    printearListaDeErrores(lineasDeErrorAsignacion);
}
void printearErroresSemanticos()
{
    printf("--ERRORES SEMANTICOS--\n\n");
    printearVariablesRepetidas();
    printf("\n\n");
    printearErroresBinarios();
    printf("\n\n");
    printearErroresDeAsignacion();

}

void printearErroresSintacticos(){
    printf("--ERRORES SINTACTICOS--\n\n");
    printearListaDeErrores(lineasDeErrorSintactico);
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
}

void printearParametrosDeFuncion(t_funcionDeclarada* unaFuncion){
    t_nodo* listaAux = unaFuncion->tiposDeParametros;

    while(listaAux != NULL){
        if(listaAux->siguiente == NULL){ //Por una cuestion estetica, si no quedaria por ejemplo "int, char, float, ".
            printf("%s",listaAux->valor);
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
}

void reportar(){
    printearVariablesDeclaradas();
    printf("\n\n\n");
    printearFuncionesDeclaradas();
    printf("\n\n\n");
    printearErroresSemanticos();
    printf("\n\n\n");
    printearErroresSintacticos();

}
