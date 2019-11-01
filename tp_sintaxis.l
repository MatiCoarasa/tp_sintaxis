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
TIPO		int|char|double|float
INCREMENTO	\+\+|--
RELACIONAL 	>=|<=|<|>
IGUALDAD	==|!=
ASIGNACION 	\+|\+=
OPERADORES	\+|-|!|,|\?|\:|\=
PARENTESIS \(|\)|\[|\]|\{|\}
MULTIPLICATIVO \*|%|\/
%%
{TIPO} 		  				{return NOMBRETIPO;}
sizeof		  				{return SIZEOF;}
return                      {return RETURN;}
while                       {return WHILE;}
if                          {return IF;}
do                          {return DO;}
for                         {return FOR;}
else                        {return ELSE;}
";"							{return ';';}
{CEDECIMAL}   				{return CONSTANTE;}
{CEOCTAL}     				{return CONSTANTE;}
{CEHEXA}      				{return CONSTANTE;}
{CREAL}       				{return CONSTANTE;}
{LIT}        				{return LITERALCADENA;}
{INCREMENTO}	  			{return PREINCREMENTO;}
{RELACIONAL}     			{return OPERADOR_RELACIONAL;}
{IGUALDAD}	      			{return OPERADOR_IGUALDAD;}
{ASIGNACION}		  		{return OPERADOR_ASIGNACION;}
{OPERADORES}				{return yytext[0];} //Como el string es de un solo char, se devuelve el primer elemento del string, que es el operador
{PARENTESIS}                {return yytext[0];}
&&		   				    {return AND;}
"||"		      			{return OR;}
{ID}          				{return IDENTIFICADOR;}
[ \t\n]+          			/* se come los espacios en blanco */
(.)           				{}

%%
