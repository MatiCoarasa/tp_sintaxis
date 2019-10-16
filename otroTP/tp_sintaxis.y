%{
#include <stdio.h>
#include "libreria.h"
#include "semantic.h"

defines "tp_sintaxis.h"
output "tp_sintaxis.c"

extern int yynerrs;
extern int contadorDeErroresSemanticos;
void yyerror(const char *);
extern FILE *yyin;
%}

%defines "parser.h"
%output "parser.c"
%define parse.error verbose


%token PROGRAMA VARIABLES DEFINIR CODIGO LEER ESCRIBIR FIN ID CDECIMAL CHEXA CREAL COCTAL ASIGNACION

%left '-' '+'
%left '*' '/'
%precedence NEG

%%

programa : PROGRAMA { inicioPrograma(); } cuerpoDelPrograma FIN { finPrograma(); if (yynerrs > 0 || contadorDeErroresSemanticos > 0) YYABORT; }
         ;

cuerpoDelPrograma : VARIABLES listaDeDeclaraciones CODIGO listaSentencias
               ;

listaDeDeclaraciones : listaDeDeclaraciones declaracion
                   | declaracion
                   ;

declaracion : DEFINIR ID '.' { if (!declararId($2)) YYERROR; }
            | error '.'
            ;

listaDeSentencias : listaDeSentencias sentencia
                | sentencia
                ;

sentencia : id ASIGNACION expresion '.' { asignacion($1, $3); }
          | LEER '(' listaDeId ')'  '.'
          | ESCRIBIR '(' listaDeExpresiones ')'  '.'  
          | error '.'
          ;

listaDeId : listaDeId ',' id { leerId($3); }
                     | id { leerId($1); }
                     ;

listaDeExpresiones : listaDeExpresiones ',' expresion { escribirId($3); }
                 | expresion { escribirId($1); }
                 ;

expresion :	expresion '+' expresion { $$ = suma($1, $3); }
		      | expresion '-' expresion { $$ = resta($1, $3); }
		      | expresion '/' expresion { $$ = dividision($1, $3); }
		      | expresion '*' expresion { $$ = multiplicacion($1, $3); }
		      | '-' expresion           { $$ = invertir($2); } %prec NEG
		      | '(' expresion ')'       { $$ = $2; }
		      | id           
		      | CDECIMAL
              | CHEXA
              | CREAL 
              | COCTAL             
		      ;

id : ID { $$ = $1; if (validarId($1)) YYERROR; } 

%%
int contadorDeErroresSemanticos = 0;
void yyerror(const char *msg) {
	printf("línea #%d: %s\n", yylineno, msg);
}

main ()
{
  yyin = fopen("entrada.txt","r+");
  yyparse ();
}