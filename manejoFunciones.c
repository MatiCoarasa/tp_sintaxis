#include "libreria.h"

t_nodo* bufferDeTipoDeParametros = NULL; //Tal vez ponerle "buffer" es exagerado, pero es como la misma idea maso

t_nodo* funcionesDeclaradas = NULL;


void agregarFuncionDeclarada(char* nombreFuncion,char* tipoReturn, t_nodo* tiposDeParametros){
    t_funcionDeclarada* nuevaFuncion = malloc(sizeof(t_funcionDeclarada));

    nuevaFuncion->nombreFuncion = strdup(nombreFuncion);
    nuevaFuncion->tipoDeReturn = strdup(tipoReturn);
    nuevaFuncion->tiposDeParametros = bufferDeTipoDeParametros;
    liberarBuffer();

    agregarValorALista(nuevaFuncion,funcionesDeclaradas);

}

void liberarBuffer(){
    bufferDeTipoDeParametros = NULL;
}

void agregarTipoDeParametroABuffer(char* tipoDeParametro){
    agregarValorALista(strdup(tipoDeParametro),bufferDeTipoDeParametros);
}