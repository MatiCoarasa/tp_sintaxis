#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
    t_nodo* tiposDeParametros; //Lista de strings
} t_funcionDeclarada;


t_nodo* agregarValorALista(void* valor, t_nodo* lista);
void liberarLista(t_nodo* lista);
void printearVariablesDeclaradas();
void declararTodasLasVariablesEnBuffer(char* tipoDeVariables);
bool variableYaFueRepetida(char* nombre,char* tipo);
void agregarNombreDeVariableABuffer(char* nombre);
t_nodo* agregarValorALista(void* valor, t_nodo* lista);
void liberarLista(t_nodo* lista);
void agregarErrorBinarioEnLinea(int linea);
