%{

#include "libreria.h"

int acumuladorDecimal = 0;

t_nodo* listaDecimales,*listaOctales, *listaHexadecimales, *listaReales, *listaPalabrasReservadas, *listaComentarios, *listaIds, *listaComentariosLinea, *listaPuntuacion, *listaOperadores,*listaLiterales;

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

{CEDECIMAL}   {acumuladorDecimal += atoi(yytext); listaDecimales = agregarNodoAlFinal(yytext, listaDecimales);}
{CEOCTAL}     {int octalEnDecimal = valorOctalADecimal(yytext); listaOctales = agregarNodoAlFinal(yytext, listaOctales);}
{CEHEXA}      {listaHexadecimales = agregarNodoAlFinal(yytext, listaHexadecimales);}
{CREAL}       {listaReales = agregarNodoAlFinal(yytext, listaReales);}
{PRESERVADA}  {listaPalabrasReservadas = agregarNodoAlFinal(yytext, listaPalabrasReservadas);}
{ID}          {listaIds = agregarNodoAlFinal(yytext, listaIds);}
{COM}         {listaComentarios = agregarNodoAlFinal(yytext, listaComentarios);}
{COMLINEA}    {listaComentariosLinea = agregarNodoAlFinal(yytext, listaComentariosLinea);}
{PUNT}        {listaPuntuacion = agregarNodoAlFinal(yytext, listaPuntuacion);}
{LIT}         {listaLiterales = agregarNodoAlFinal(yytext, listaLiterales);}
{OPERATORS}   {listaOperadores = agregarNodoAlFinal(yytext, listaOperadores);}
[ \t\n]+          /* se come los espacios en blanco */

%%

void inicializarListas(){
        listaDecimales = listaOctales = listaHexadecimales = listaReales = listaPalabrasReservadas, listaIds, listaComentarios, listaComentariosLinea, listaPuntuacion, listaLiterales, listaOperadores = NULL;
}

void printTodasLasListas(){
    mapLista(listaDecimales,(void*)reporteDecimal);
    printListaAlFinalDeArchivo(listaDecimales, "Decimales", "salida.txt");
	mapLista(listaOctales,(void*)reporteDeOctal);
    printListaAlFinalDeArchivo(listaOctales, "Octales", "salida.txt");
	mapLista(listaHexadecimales,(void*)reporteDeHexa);
    printListaAlFinalDeArchivo(listaHexadecimales, "Hexadecimales", "salida.txt");
    printListaAlFinalDeArchivo(listaReales, "Reales", "salida.txt");
    printListaAlFinalDeArchivo(listaPalabrasReservadas, "Palabras reservadas", "salida.txt");
	mapLista(listaLiterales,(void*)reporteDeLiteralCadena);
	printListaAlFinalDeArchivo(listaLiterales, "Literales cadena", "salida.txt");
    printListaEnArchivoConRepetidos(listaIds, "Identificadores", "salida.txt");
    printListaEnArchivoConRepetidos(listaPuntuacion, "Carácteres de puntuación", "salida.txt");
    printListaEnArchivoConRepetidos(listaOperadores, "Operadores", "salida.txt");
}

int main(){

    inicializarListas();

    yyin = fopen("entrada.txt","r");
    yylex();

    printTodasLasListas();

    return 0;
}
