#include "libreria.h"


char* string_substring(char* text, int start, int length) {
	char* new_string = calloc(1, length + 1);
	strncpy(new_string, text + start, length);
	return new_string;
}

t_nodo* agregarNodo(char* valor, t_nodo* lista){

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));

    nuevoNodo->valor = strdup(valor);
    nuevoNodo->siguiente = NULL;

    if(lista == NULL) {
    	lista = nuevoNodo;
        return nuevoNodo;
    }

    t_nodo* aux = lista;

    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }

    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    return nuevoNodo;


}

int valorOctalADecimal(char* octalTexto){

    //Remuevo el 0 de la constante octal.
    char* textoDecimal = string_substring(octalTexto, 1, strlen(octalTexto));
    //Transformo la cadena de caracteres en un entero para poder sumarlo.
    int octalSinCero = atoi(textoDecimal);
    free(textoDecimal);

    int i = 0;
    int valorDecimal = 0;
    //Transformo el valor octal a decimal.
    while (octalSinCero != 0){
        valorDecimal += (octalSinCero % 10) * pow(8, i++);
        octalSinCero /= 10;
    }

	return valorDecimal;
}

int main(){

    t_nodo* listaPrueba = NULL;
    char* string = strdup("hola");
    listaPrueba = agregarNodo(string, listaPrueba);
    printf("%s\n", listaPrueba->valor);
    return 0;

}