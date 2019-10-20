%{

#include "libreria.h"
#include "tp_sintaxis.tab.h"

t_nodo* listaDeRechazo;
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
{CEDECIMAL}   {}
{CEOCTAL}     {}
{CEHEXA}      {}
{CREAL}       {}
{PRESERVADA}  {}
{ID}          {}
{COM}         {}
{COMLINEA}    {}
{PUNT}        {}
{LIT}         {}
{OPERATORS}   {}
[ \t\n]+          /* se come los espacios en blanco */
(.)           {listaDeRechazo = agregarNodoAlFinal(yytext,listaDeRechazo);}

%%

void inicializarListas(){
        listaDeRechazo = NULL;
}

void printearRechazados(){
    mapLista(listaDeRechazo,(void*)reporteDeRechazados);
	printf("--RECHAZADOS--\n\n");
    printLista(listaDeRechazo);
}

int mainVIEJO(){

    inicializarListas();

    yyin = fopen("entrada.txt","r");
    yylex();

    printearRechazados();

    return 0;
}
