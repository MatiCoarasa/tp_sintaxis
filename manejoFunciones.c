#include "libreria.h"

t_nodo* bufferDeTipoDeParametros = NULL; //Tal vez ponerle "buffer" es exagerado, pero es como la misma idea maso

t_nodo* funcionesDeclaradas = NULL;


void agregarFuncionDeclarada(char* nombreFuncion,char* tipoReturn){
    t_funcionDeclarada* nuevaFuncion = malloc(sizeof(t_funcionDeclarada));

    nuevaFuncion->nombreFuncion = strdup(nombreFuncion);
    nuevaFuncion->tipoDeReturn = strdup(tipoReturn);
    nuevaFuncion->tiposDeParametros = bufferDeTipoDeParametros;
    liberarBufferDeParametros();

    funcionesDeclaradas = agregarValorALista(nuevaFuncion,funcionesDeclaradas);

}

void liberarBufferDeParametros(){ //La funcionDeclarada toma el buffer como estaba y lo usa, asi que no hay que liberarla, simplemente "hacer una nueva". Basicamente hay que dejar esto como esta.
    bufferDeTipoDeParametros = NULL;
}

void agregarTipoDeParametroABuffer(char* tipoDeParametro){
    bufferDeTipoDeParametros = agregarValorALista(strdup(tipoDeParametro),bufferDeTipoDeParametros);
}
