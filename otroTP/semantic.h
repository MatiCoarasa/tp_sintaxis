#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

extern int contadorDeErroresSemanticos;

void inicioDelPrograma();
void finDelPrograma();

int declararId(char *id);

void leerId(char *id);
void escribirId(char *id);

char * generarVariableTemporal();

int validarId(char *id);

char * invertir(char *id);
char * multiplicacion(char *numeroUno, char *numeroDos);
char * dividision(char* numero1, char* numero2);
char * resta(char* numero1, char* numero2);
char * suma(char* numero1, char* numero2);
void asignacion(char* id, char* valor);

#endif