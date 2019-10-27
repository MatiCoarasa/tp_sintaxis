#include "libreria.h"


char* string_substring(char* text, int start, int length) {
	char* new_string = calloc(1, length + 1);
	strncpy(new_string, text + start, length);
	return new_string;
}

void string_append(char** original, char* string_to_add) {
	*original = realloc(*original, strlen(*original) + strlen(string_to_add) + 1);
	strcat(*original, string_to_add);
}

void reporteDeRechazados(t_nodo* unNodo){
    char* valorRechazado = strdup(unNodo->valor);
    char* valorEnString[12];
    sprintf(valorEnString, "%d", valorRechazado);

    string_append(&valorRechazado,": Valor rechazado ");
    string_append(&valorRechazado,valorEnString);

    unNodo->valor=valorRechazado;

    //free(valorEnString);
    //free(unNodo->valor);
}

void agregarVariableDeclarada(char* nombre, char* tipo){

}
