#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int t_uint;

typedef struct t_nodo {
    struct t_nodo* siguiente;
    char* valor;
} t_nodo;

t_nodo* agregarNodo(char* valor, t_nodo* lista);
char* string_substring(char* text, int start, int length);
int valorOctalADecimal(char* octalTexto);