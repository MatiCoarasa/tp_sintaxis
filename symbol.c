#include <string.h>

static char *diccionario[1000];
static int indiceDelDiccionario = 0;

void registrarId(char *id) {
	diccionario[indiceDelDiccionario] = id;
	indiceDelDiccionario++;
}

int existeId(char *id) {
	int i;
	for (i = 0; i < indiceDelDiccionario; i++) {
		if (strcmp(diccionario[i], id) == 0) {
			return 1;
		}
	}
	return 0;
}