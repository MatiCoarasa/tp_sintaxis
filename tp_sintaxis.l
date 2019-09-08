%{

/* Se necesita esto para la llamada a atof() , atoi mas abajo */

#include "libreria.h"
int acum = 0;

%}

CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?
ID       	[a-zA-Z_][a-zA-Z0-9_]*
COMLINEA    \/\/(.)*
COM 		\/\*([^*]|[\r\n])*\*\/
LIT  		\".*\"
PUNT		[-\\(-~]|\\[0ntvafbr]
OPERATORS	(\+\+|--|==|>=|<=|!=|<|>|!=|\+=|-=|\*=|\/=|%=|\+|-|\*|%|=|&&|\|\||!)
PRESERVADA	while|do|if|else|for|int|char|return|case|switch|auto|break|const|continue|default|double|enum|extern|float|goto|long|register|short|signed|sizeof|static|struct|typedef|union|unsigned|void|volatile
%%

{CEDECIMAL}   {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{CEOCTAL}     {printf("La cadena %s representa una constante entera octal\n", yytext);}
{CEHEXA}      {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{CREAL}       {printf("La cadena %s representa una constante real\n", yytext);}
{PRESERVADA}  {printf("La cadena %s representa una palabra reservada\n", yytext);}
{ID}          {printf("La cadena %s representa un identificador\n", yytext);}
{COM}         {printf("La cadena %s representa un comentario\n", yytext);}
{COMLINEA}    {printf("La cadena %s representa un comentario de linea\n", yytext);}
{PUNT}        {printf("La cadena %s representa un caracter de puntuacion\n", yytext);}
{LIT}         {printf("La cadena %s representa un literal cadena\n", yytext);}
{OPERATORS}   {printf("La cadena %s representa un operador\n", yytext);}
[ \t\n]+          /* se come los espacios en blanco */

%%

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    return 0;
}
