#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAXBUFFER 500

typedef struct t_nodo {
    struct t_nodo* siguiente;
    bool fueContado;
    void* valor;
} t_nodo;

typedef struct {
    char* nombreVariable;
    char* tipoVariable;
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
void liberarBufferDeNombresDeVariables();
void liberarBufferDeParametros();
void agregarFuncionDeclarada(char* nombreFuncion,char* tipoReturn);
void agregarTipoDeParametroABuffer(char* tipoDeParametro);
void agregarErrorAsignacionEnLinea(int linea);
void agregarErrorSintactico(int linea);
void reportar();
