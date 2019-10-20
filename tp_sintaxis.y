%{
#include <stdio.h>
#include "libreria.h"
extern FILE *yyin;
%}

%token ID CDECIMAL CHEXA CREAL COCTAL

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