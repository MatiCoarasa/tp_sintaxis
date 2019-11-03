#include "libreria.h"

enum tipos {Int, Float, Char, Double};

char* tipo_numeroAString(int tipoEnNumero)
{

    switch(tipoEnNumero)
    {
    case Int:
        return "int";
    case Float:
        return "float";
    case Char:
        return "char";
    case Double:
        return "double";
    default:
        return NULL;
    }
}

int tipo_stringANumero(char* tipoEnString){

    char* tipos[] = {"int","float","char","double"};




}
