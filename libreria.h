#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int t_uint;


typedef struct t_nodo {
    struct t_nodo* siguiente;
    bool fueContado;
    void* valor;
} t_nodo;

typedef struct {
    char* nombreVariable;
    char* tipoVariable; //Tal vez se podria hacer por enums?
} t_variableDeclarada;

typedef struct{
    char* nombreFuncion;
    char* tipoDeReturn;
    t_nodo* tipoDeParametros; //Lista de strings
} t_funcionDeclarada;


t_nodo* agregarValorALista(void* valor, t_nodo* lista);
char* string_substring(char* text, int start, int length);
void string_append(char** original, char* string_to_add);
void printListaDeStrings(t_nodo* lista);
void liberarLista(t_nodo* lista);
void mapLista(t_nodo* lista, void func(t_nodo*));
int largoLista(t_nodo* lista);
void reporteDeRechazados(t_nodo* unNodo);
