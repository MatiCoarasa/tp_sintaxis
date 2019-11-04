%{
#include <stdio.h>
#include "libreria.h"
extern FILE *yyin;
%}

%union { 
	char* valor;
}


%token CONSTANTE OPERADOR_RELACIONAL OPERADOR_IGUALDAD AND OR OPERADOR_ASIGNACION SIZEOF INCREMENTO LITERALCADENA RETURN FOR WHILE IF SWITCH DO ELSE OPERADOR_MULTIPLICATIVO

%token <valor> IDENTIFICADOR
%token <valor> NOMBRETIPO

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
		| INCREMENTO expUnaria
		| expUnaria INCREMENTO //En el libro no estaba este.
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
		| expPostFijo '[' expresion ']' //Que se supone que es esto?
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

variable: IDENTIFICADOR {printf("Se declaro la variable: %s\n",$<valor>1);}  //Temporal para testear el funcionamiento del union

inicialOpcional: inicial
		|

inicial: '=' expCondicional //Esto esta cambiado del libro. 
		
declaFuncion: NOMBRETIPO IDENTIFICADOR '(' listaParametrosOpcional ')' '{' codigo '}' {printf("Se declaro la funcion: %s %s()\n",$<valor>1,$<valor>2);} //Temporal para testear el funcionamiento del union

listaParametrosOpcional: listaParametros
		|

listaParametros: unParametro
		| listaParametros ',' unParametro

unParametro: NOMBRETIPO unaVarSimple
		//| NOMBRETIPO


//Sentencias//

sentencia: sentCompuesta
		| sentExpresion
		| sentSeleccion
		| sentIteracion
		| sentSalto


		
sentCompuesta: '{' codigo '}' 

/*
sentCompuesta: '{' listaDeclaracionesOpcional listaSentenciasOpcional '}' //Esto no reconoce declaraciones despues de sentencias


listaDeclaracionesOpcional: listaDeclaraciones
		|

listaSentenciasOpcional: listaSentencias
		|

listaDeclaraciones: declaracion
		| listaDeclaraciones declaracion

listaSentencias: sentencia
		| listaSentencias sentencia
*/

sentExpresion: expresionOpcional ';'

sentSeleccion: IF '(' expresion ')' sentencia
		| IF '(' expresion ')' sentencia ELSE sentencia
		| SWITCH '(' expresion ')' sentencia
		
sentIteracion: WHILE '(' expresion ')' sentencia
		| DO sentencia WHILE '(' expresion ')' ';'
		| FOR '(' expresionOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia //No se puede declarar adentro del for, esta mal??????
		
sentSalto: RETURN expresionOpcional ';'
%%

main ()
{
  yyin = fopen("entrada.c","r");
  yyparse ();
  
  return 0;
}