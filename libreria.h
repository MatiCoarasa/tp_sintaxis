#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int t_uint;

typedef struct t_nodo {
    struct t_nodo* siguiente;
    bool fueContado;
    char* valor;
} t_nodo;

t_nodo* agregarNodoAlFinal(char* valor, t_nodo* lista);
char* string_substring(char* text, int start, int length);
int valorOctalADecimal(char* octalTexto);
int obtenerParteEntera(double valorConComa);
int obtenerMantisa(double valorConComa);
void imprimirValoresDeLista(t_nodo* lista);
int hexadecimalADecimal(char* hexa);
void printListaAlFinalDeArchivo(t_nodo* lista, char* tipoLista, char* nombreArchivo);
void liberarLista(t_nodo* lista);
t_nodo* mapLista(t_nodo* lista, void func(t_nodo*));
int largoLista(t_nodo* lista);
void printListaEnArchivoConRepetidos(t_nodo* lista, char* tituloLista, char* nombreArchivo);