%{

/* Se necesita esto para la llamada a atof() , atoi mas abajo */

#include "libreria.h"
int acum = 0;

%}

CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	        [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?
ID       	[a-zA-Z_][a-zA-Z0-9_]*
PRESERVADA	while|do|if|else|for|int|char|return|case|switch

%%

{CEDECIMAL}   {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{CEOCTAL}     {printf("La cadena %s representa una constante entera octal\n", yytext);}
{CEHEXA}      {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{CREAL}       {printf("La cadena %s representa una constante real\n", yytext);}
{PRESERVADA}  {printf("La cadena %s representa una palabra reservada\n", yytext);}
{ID}          {printf("La cadena %s representa un identificador\n", yytext);}

%%

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    return 0;
}
