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
LIT  		\".*\"
TIPO		int|char|double|float|long|short|signed|unsigned|void
INCREMENTO	\+\+|--
RELACIONAL 	>=|<=|<|>
IGUALDAD	==|!=
ASIGNACION 	\+|\+=
OPERADORES	\+|-|\*|&|\/|%|!|,|\(|\)|\[|\]|\?|\:
ESTRUCTURAS while|if|do|for|else
%%
{TIPO} 		  				{return NOMBRETIPO;}
sizeof		  				{return SIZEOF;}
return                      {return RETURN;}
{ESTRUCTURAS}               {return ESTRUCTURAS;}
{CEDECIMAL}   				{return CONSTANTE;}
{CEOCTAL}     				{return CONSTANTE;}
{CEHEXA}      				{return CONSTANTE;}
{CREAL}       				{return CONSTANTE;}
{LIT}        				{return LITERALCADENA;}
{INCREMENTO}	  			{return PREINCREMENTO;}
{RELACIONAL}     			{return OPERADOR_RELACIONAL;}
{IGUALDAD}	      			{return OPERADOR_IGUALDAD;}
{ASIGNACION}		  		{return OPERADOR_ASIGNACION;}
{OPERADORES}				{return yytext[0];} //Como el string es de un solo char, se devuelve el primer elemento del string, que es el operador (tal vez hay una forma mejor?)
&&		   				    {return AND;}
"||"		      			{return OR;}
{ID}          				{return IDENTIFICADOR;}
[ \t\n]+          			/* se come los espacios en blanco */
(.)           				{listaDeRechazo = agregarNodoAlFinal(yytext,listaDeRechazo);}

%%
