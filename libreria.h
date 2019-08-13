#include <math.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int t_uint;

typedef struct t_nodo_contador {
    t_nodo_contador* siguiente;
    t_uint cantidad;
    char* valor;
} t_nodo_contador;

typedef struct t_nodo {
    t_nodo* siguiente;
    char* valor;
} t_nodo;

void agregarNodoOSumarContador(char* valor, t_nodo_contador* lista);
void agregarNodo(char* valor, t_nodo* lista);