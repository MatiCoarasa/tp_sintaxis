%{
#include <stdio.h>
#include "libreria.h"
extern FILE *yyin;
extern int yylineno; 
%}

%union { 
	char* valor;
	int tipo;
}


%token CONSTANTE OPERADOR_RELACIONAL OPERADOR_IGUALDAD AND OR SIZEOF INCREMENTO LITERALCADENA RETURN FOR WHILE IF SWITCH DO ELSE OPERADOR_MULTIPLICATIVO ASIGNACION

%token <valor> IDENTIFICADOR
%token <valor> NOMBRETIPO
%type  <tipo>  expPrimaria expPostFijo expUnaria expMultiplicativa expAditiva expRelacional expIgualdad expAnd expOr expAsignacion expresion listaArgumentosOpcional listaArgumentos
%type  <valor> unaVarSimple
%%

codigo:	declaracion codigo
		| sentencia codigo
		| error ';' codigo
		|

//Expresiones

expresion:	expAsignacion {$$ = $1;}

expresionOpcional: expresion
		|

expAsignacion: expOr {$$ = $1;}
		| expUnaria operAsignacion expAsignacion {$$ = $1 && $3;}
		
operAsignacion: '='
				
expOr: expAnd {$$ = $1;}
		| expOr OR expAnd {$$ = $1 && $3;}

expAnd: expIgualdad {$$ = $1;}
		| expAnd AND expIgualdad {$$ = $1 && $3;}
		
expIgualdad: expRelacional {$$ = $1;}
		| expIgualdad OPERADOR_IGUALDAD expRelacional {$$ = $1 && $3;}
		
expRelacional: expAditiva	{$$ = $1;}
		| expRelacional OPERADOR_RELACIONAL expAditiva {$$ = $1 && $3;}

expAditiva: expMultiplicativa	{$$ = $1;}
		| expAditiva '+' expMultiplicativa {$$ = checkeoOperacionBinaria($1,$3);}
		| expAditiva '-' expMultiplicativa {$$ = checkeoOperacionBinaria($1,$3);}

expMultiplicativa: expUnaria	{$$ = $1;}
		| expMultiplicativa OPERADOR_MULTIPLICATIVO expUnaria {$$ = checkeoOperacionBinaria($1,$3);}
		
expUnaria: expPostFijo	{$$ = $1;}
		| INCREMENTO expUnaria	{$$ = $2;}
		| expUnaria INCREMENTO {$$ = $1;} //En el libro no estaba este.
		| operUnario expUnaria {$$ = $2;}
		| SIZEOF '('NOMBRETIPO')' {$$ = 1;}

operUnario: '-'
		| '!'

/* Contando punteros y direcciones. Si se quiere retomar esto hay que sacar el OPERADOR_MULTIPLICATIVO por la repeticion del '*'
operUnario: '&'
		| '*'
		| '-'
		| '!'
*/
		
expPostFijo: expPrimaria	{$$ = $1;}
		| expPostFijo '[' expresion ']'	{$$ = $1 && $3;}
		| expPostFijo '(' listaArgumentosOpcional ')' {$$ = $1 && $3;}

listaArgumentosOpcional: listaArgumentos {$$ = $1;}
		|	{$$ = 1;}

listaArgumentos: expAsignacion	{$$ = $1;}
		| listaArgumentos ',' expAsignacion {$$ = $1 && $3;}
		
expPrimaria: IDENTIFICADOR	{$$ = 2;}
		| CONSTANTE			{$$ = 1;}
		| LITERALCADENA		{$$ = 0;}
		| '(' expresion ')'	{$$ = $2;}
		
// Declaraciones //

declaracion: declaVarSimples {liberarBufferDeNombresDeVariables();}
		| declaFuncion		 {liberarBufferDeParametros();}

declaVarSimples: NOMBRETIPO listaVarSimples ';' {declararTodasLasVariablesEnBuffer($<valor>1);}

listaVarSimples: unaVarSimple				{agregarNombreDeVariableABuffer($<valor>1);}
		| listaVarSimples ',' unaVarSimple	{agregarNombreDeVariableABuffer($<valor>3);}
		
unaVarSimple: variable inicialOpcional {$$ = $<valor>1;}

variable: IDENTIFICADOR 

inicialOpcional: inicial
		|

inicial: '=' expOr //Esto esta cambiado del libro. 
		
declaFuncion: NOMBRETIPO IDENTIFICADOR '(' listaParametrosOpcional ')' '{' codigo '}' {agregarFuncionDeclarada($<valor>2,$<valor>1);}

listaParametrosOpcional: listaParametros
		|

listaParametros: unParametro
		| listaParametros ',' unParametro

unParametro: NOMBRETIPO unaVarSimple {agregarTipoDeParametroABuffer($<valor>1);}
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

int checkeoOperacionBinaria(int tipoPrimerTermino, int tipoSegundoTermino){
	if (tipoPrimerTermino && tipoSegundoTermino){
		return 1;
	}
	else{
		agregarErrorBinarioEnLinea(yylineno);
		return 0;
	}
}

int checkeoAsignacion(int tipoTerminoAsignado){
	if(tipoTerminoAsignado == 2){
		return 1; //En la asignacion se vuelve una constante
	}
	else{
		agregarErrorAsignacionEnLinea(yylineno);
		return 0;
	}
}

void yyerror() {
	agregarErrorSintactico(yylineno);
}

main ()
{
	yyin = fopen("entrada.c","r");
	yyparse ();
	reportar();
	return 0;
}