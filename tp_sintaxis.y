%{
#include <stdio.h>
#include "libreria.h"
%}

%token ID CDECIMAL CHEXA CREAL COCTAL ASIGNACION

%%

expresion :	expresion '+' expresion
		      | expresion '-' expresion
		      | expresion '/' expresion
		      | expresion '*' expresion
		      | '-' expresion
		      | '(' expresion ')'
		      | ID
		      | CDECIMAL
              | CHEXA
              | CREAL
              | COCTAL
		      ;
%%
main ()
{
  yyin = fopen("entrada.txt","r");
  yyparse ();
}