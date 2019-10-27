%{
#include <stdio.h>
#include "libreria.h"
extern FILE *yyin;
extern t_nodo* listaDeRechazo;
%}

%token CONSTANTE IDENTIFICADOR OPERADOR_RELACIONAL OPERADOR_IGUALDAD AND OR OPERADOR_ASIGNACION NOMBRETIPO SIZEOF PREINCREMENTO LITERALCADENA RETURN FOR WHILE IF SWITCH DO ELSE
%%

codigo: expresion codigo //Algo asi?
		| declaracion codigo
		| sentencia codigo
		| 

//Expresiones//
expresion:	expAsignacion

expAsignacion: expCondicional
		| expUnaria OPERADOR_ASIGNACION expAsignacion
				
expCondicional: expOr
		| expOr '?' expresion ':' expCondicional

expOr: expAnd
		| expOr OR expAnd

expAnd: expIgualdad
		| expAnd AND expIgualdad
		
expIgualdad: expRelacional
		| expIgualdad OPERADOR_IGUALDAD expRelacional
		
expRelacional: expAditiva
		| expRelacional OPERADOR_RELACIONAL expAditiva

expAditiva: expMultiplicativa
		| expAditiva '+' expMultiplicativa
		| expAditiva '-' expMultiplicativa

expMultiplicativa: expUnaria
		| expMultiplicativa '*' expUnaria
		| expMultiplicativa '/' expUnaria
		| expMultiplicativa '%' expUnaria
		
expUnaria: expPostFijo
		| PREINCREMENTO expUnaria
		| operUnario expUnaria
		| SIZEOF '('NOMBRETIPO')'

operUnario: '&'
		| '*'
		| '-'
		| '!'
		
expPostFijo: expPrimaria
		| expPostFijo '[' expresion ']'
		| expPostFijo '(' listaArgumentos ')'

listaArgumentos: expAsignacion
		| listaArgumentos ',' expAsignacion
		
expPrimaria: IDENTIFICADOR
		| CONSTANTE
		| LITERALCADENA
		| '(' expresion ')'
		
// Declaraciones //

declaracion: declaVarSimples

declaVarSimples: NOMBRETIPO listaVarSimples ';'

listaVarSimples: unaVarSimple
		| listaVarSimples ',' unaVarSimple
		
unaVarSimple: variable inicial

inicial: '=' CONSTANTE //Falta completar aca

variable: IDENTIFICADOR
		

//Sentencias//

sentencia: sentCompuesta
		| sentExpresion
		| sentSeleccion
		| sentIteracion
		| sentSalto

sentCompuesta: '{' listaDeclaraciones listaSentencias '}'

listaDeclaraciones: declaracion
		| listaDeclaraciones declaracion

listaSentencias: sentencia
		| listaSentencias sentencia

sentExpresion: expresion ';'

sentSeleccion: IF '(' expresion ')' sentencia
		| IF '(' expresion ')' sentencia ELSE sentencia //Esto tira warning
		| SWITCH '(' expresion ')' sentencia
		
sentIteracion: WHILE '(' expresion ')' sentencia
		| DO sentencia WHILE '(' expresion ')' ';'
		| FOR '(' expresion ';' expresion ';' expresion ')' sentencia //Que pasa con los tokens opcionales?
		
sentSalto: RETURN expresion ';'
%%

void inicializarListas(){
        listaDeRechazo = NULL;
}

void printearRechazados(){
    mapLista(listaDeRechazo,(void*)reporteDeRechazados);
	printf("--RECHAZADOS--\n\n");
    printLista(listaDeRechazo);
}

main ()
{
  inicializarListas();
  yyin = fopen("entrada.txt","r");
  yyparse ();
  
  printearRechazados();
  
  return 0;
}