%{
#include <stdio.h>
#include "libreria.h"
extern FILE *yyin;
extern t_nodo* listaDeRechazo;
%}

%token CONSTANTE IDENTIFICADOR OPERADOR_RELACIONAL OPERADOR_IGUALDAD AND OR OPERADOR_ASIGNACION NOMBRETIPO SIZEOF PREINCREMENTO LITERALCADENA RETURN FOR WHILE IF SWITCH DO ELSE OPERADOR_MULTIPLICATIVO
%%

codigo:	declaracion codigo
		| sentencia codigo
		|

//Expresiones

expresion:	expAsignacion

expresionOpcional: expresion
		|

expAsignacion: expCondicional
		| expUnaria operAsignacion expAsignacion
		
operAsignacion: '='
		| '+='
				
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
		| expMultiplicativa OPERADOR_MULTIPLICATIVO expUnaria
		
expUnaria: expPostFijo
		| expUnaria PREINCREMENTO //En el libro esto estaba al revez. 
		| operUnario expUnaria
		| SIZEOF '('NOMBRETIPO')'

operUnario: '-'
		| '!'

/* Contando punteros y direcciones. Si se quiere retomar esto hay que sacar el OPERADOR_MULTIPLICATIVO por la repeticion del '*'
operUnario: '&'
		| '*'
		| '-'
		| '!'
*/
		
expPostFijo: expPrimaria
		| expPostFijo '[' expresion ']'
		| expPostFijo '(' listaArgumentosOpcional ')'

listaArgumentosOpcional: listaArgumentos
		|

listaArgumentos: expAsignacion
		| listaArgumentos ',' expAsignacion
		
expPrimaria: IDENTIFICADOR
		| CONSTANTE
		| LITERALCADENA
		| '(' expresion ')'
		
// Declaraciones //

declaracion: declaVarSimples
		| declaFuncion

declaVarSimples: NOMBRETIPO listaVarSimples ';'

listaVarSimples: unaVarSimple
		| listaVarSimples ',' unaVarSimple
		
unaVarSimple: variable inicialOpcional

variable: IDENTIFICADOR

inicialOpcional: inicial
		|

inicial: '=' CONSTANTE //Esto no considera otros identificadores o cosas como 2+2 o returns de funciones (tal vez poniendo expOR?)
		
declaFuncion: NOMBRETIPO IDENTIFICADOR '(' listaParametrosOpcional ')' '{' codigo '}'

listaParametrosOpcional: listaParametros
		|

listaParametros: unParametro
		| listaParametros ',' unParametro

unParametro: NOMBRETIPO unaVarSimple 
		| NOMBRETIPO


//Sentencias//

sentencia: sentCompuesta
		| sentExpresion
		| sentSeleccion
		| sentIteracion
		| sentSalto

sentCompuesta: '{' listaDeclaracionesOpcional listaSentenciasOpcional '}'

listaDeclaracionesOpcional: listaDeclaraciones
		|

listaSentenciasOpcional: listaSentencias
		|

listaDeclaraciones: declaracion
		| listaDeclaraciones declaracion

listaSentencias: sentencia
		| listaSentencias sentencia

sentExpresion: expresionOpcional ';'

sentSeleccion: IF '(' expresion ')' sentencia
		| IF '(' expresion ')' sentencia ELSE sentencia
		| SWITCH '(' expresion ')' sentencia
		
sentIteracion: WHILE '(' expresion ')' sentencia
		| DO sentencia WHILE '(' expresion ')' ';'
		| FOR '(' expresionOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia //No se puede declarar adentro del for, esta mal??????
		
sentSalto: RETURN expresionOpcional ';'
%%

void inicializarListas(){
        listaDeRechazo = NULL;
}

void printearRechazados(){
    mapLista(listaDeRechazo,(void*)reporteDeRechazados);
	printf("--RECHAZADOS--\n\n");
    //printLista(listaDeRechazo);
}

yyerror (s)  /* Llamada por yyparse ante un error */
     char *s;
{
  printf ("%s\n", s);
}

main ()
{
  inicializarListas();
  yyin = fopen("entrada.c","r");
  yyparse ();
  
  //printearRechazados();
  
  return 0;
}