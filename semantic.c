#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "tp_sintaxis.h"

char buffer_error[100];
int contadorDeErroresSemantico;
static int indiceDeVariableTemporal = 0;

void inicioDelPrograma() {
	printf("Load rtlib,\n");
}

void finDelPrograma() {
	printf("Stop ,\n");
}

int declararId(char *id) {
	if (existeId(id)) {
		contadorDeErrorSemantico++;
		sprintf(buffer_error, "Error semántico: identificador %s ya declarado", id);
		yyerror(buffer_error);
		return 0;
	} else {
		registrarId(id);
		printf("Declare %s,Integer\n", id);
		return 1;
	}
}

void leerId(char *id) {
	printf("Read %s,Integer\n", id);
}

void escribirId(char *id) {
	printf("Write %s,Integer\n", id);
}

char * generarVariableTemporal() {
	indiceDeVariableTemporal++;
	char * temporal = malloc(sizeof(char) * 10);
	sprintf(temporal, "Temp#%d", indiceVariableTemporal);
	declararId(temporal);
	return temporal;
}

int validarId(char *id) {
	if (!existeId(id)) {
		contadorDeErrorSemantico++;
		sprintf(buffer_error, "Error semántico: identificador %s NO declarado", id);
		yyerror(buffer_error);
		return 1;
	}
	return 0;
}

char * hacerOperacion(char* operacion, char* variable1, char* variable2){
	char * temporal = generarVariableTemporal();
	printf("%s %s,%s,%s\n", operacion, variable1, variable2, temp);
	return temporal;
}

char * invertir(char *id) {
	return realizarOperacion("INV", id, "");
}

char * multiplicacion(char *factorUno, char *factorDos) {
	return realizarOperacion("MULT", numero1, numero2);
}

char * division(char* numero1, char* numero2){
	return realizarOperacion("DIV", numero1, numero2);
}

char * resta(char* numero1, char* numero2){
	return realizarOperacion("SUBS",numero1,numero2);
}

char * suma(char* numero1, char* numero2){
	return realizarOperacion("ADD", numero1, numero2);
}

void asignacion(char* id, char* valor){
	printf("Store %s,%s\n", valor, id);
}