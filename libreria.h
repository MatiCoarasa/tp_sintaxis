#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int t_uint;
t_nodo* variablesDeclaradas;

typedef struct t_nodo {
    struct t_nodo* siguiente;
    bool fueContado;
    char* valor; //Cambiar a void* ?
} t_nodo;

typedef struct variableDeclarada{
    char* nombreVariable;
    char* tipoVariable; //Tal vez se podria hacer por enums?
}

t_nodo* agregarNodoAlFinal(char* valor, t_nodo* lista);
char* string_substring(char* text, int start, int length);
void string_append(char** original, char* string_to_add);
void printLista(t_nodo* lista);
void liberarLista(t_nodo* lista);
void mapLista(t_nodo* lista, void func(t_nodo*));
int largoLista(t_nodo* lista);
void reporteDeRechazados(t_nodo* unNodo);
