#include "libreria.h"


char* string_substring(char* text, int start, int length) {
	char* new_string = calloc(1, length + 1);
	strncpy(new_string, text + start, length);
	return new_string;
}

void string_append(char** original, char* string_to_add) {
	*original = realloc(*original, strlen(*original) + strlen(string_to_add) + 1);
	strcat(*original, string_to_add);
}

int obtenerMantisa(double valorConComa){
    int valorEntero = (int)valorConComa;
    double soloValorConComa = valorConComa - valorEntero;

    char* valorEnString = malloc(15);
    gcvt(soloValorConComa, 10, valorEnString);
    char* mantisaEnString = string_substring(valorEnString, 2, strlen(valorEnString));
    int valorMantisa = atoi(mantisaEnString);
    free(valorEnString);
    free(mantisaEnString);

    return valorMantisa;
}

int obtenerParteEntera(double valorConComa){
    int valorEntero = (int)valorConComa;
    return valorEntero;
}

t_nodo* agregarNodoAlFinal(char* valor, t_nodo* lista){

    t_nodo* nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));

    nuevoNodo->valor = strdup(valor);
    nuevoNodo->siguiente = NULL;
    nuevoNodo->fueContado = false;

    if(lista == NULL) {
    	lista = nuevoNodo;
        return nuevoNodo;
    }

    t_nodo* aux = lista;

    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }

    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    return lista;


}

void imprimirValoresDeLista(t_nodo* lista){

    int i = 1;

    while(lista != NULL){
        printf("%d: %s\n", i, lista->valor);
        lista = lista->siguiente;
        i++;
    }
}

int valorOctalADecimal(char* octalTexto){

    //Remuevo el 0 de la constante octal.
    char* textoDecimal = string_substring(octalTexto, 1, strlen(octalTexto));
    //Transformo la cadena de caracteres en un entero para poder sumarlo.
    int octalSinCero = atoi(textoDecimal);
    free(textoDecimal);

    int i = 0;
    int valorDecimal = 0;
    //Transformo el valor octal a decimal.
    while (octalSinCero != 0){
        valorDecimal += (octalSinCero % 10) * pow(8, i++);
        octalSinCero /= 10;
    }

	return valorDecimal;
}

int hexadecimalADecimal(char* hexa){
    int decimal = 0;
    int i = 0, valor, len;
    len = strlen(hexa);
    len--;

    for(i=0; hexa[i]!='\0'; i++){
        if(hexa[i]>='0' && hexa[i]<='9'){
                valor = hexa[i] - 48;
            }
            else if(hexa[i]>='a' && hexa[i]<='f'){
                valor = hexa[i] - 97 + 10;
            }
            else if(hexa[i]>='A' && hexa[i]<='F'){
                valor = hexa[i] - 65 + 10;
            }
            decimal += valor * pow(16, len);
            len--;
        }

    return decimal;
}

void printListaAlFinalDeArchivo(t_nodo* lista, char* tituloLista, char* nombreArchivo){

    FILE* archivo = fopen(nombreArchivo, "a");

    int i = 1;

    if(archivo != NULL){

        fprintf(archivo, "%s: \n", tituloLista);

        while(lista != NULL){
            fprintf(archivo, "\t%d) %s\n", i, lista->valor);
            i++;
            lista = lista->siguiente;
        }
    }

    fclose(archivo);


}

void printListaEnArchivoConRepetidos(t_nodo* lista, char* tituloLista, char* nombreArchivo){

    FILE* archivo = fopen(nombreArchivo, "a");

    int i = 1;

    if(archivo != NULL){

        fprintf(archivo, "%s: \n", tituloLista);

        while(lista != NULL){

                if(!(lista->fueContado)){
                t_nodo* child = lista->siguiente;
                int numeroRepeticiones = 1;
                while(child != NULL){
                    if(strcmp(lista->valor, child->valor) == 0 && !(child->fueContado)) {
                        numeroRepeticiones++;
                        child->fueContado = true;
                    }

                    child = child->siguiente;

                }
                fprintf(archivo, "\t%d) %s - %d repeticiones\n", i, lista->valor, numeroRepeticiones);
            }
            lista->fueContado = true;
            lista = lista->siguiente;
        }
    }

    fclose(archivo);

}

int largoLista(t_nodo* lista){

    int i = 0;

    while(lista != NULL){
        i++;
        lista = lista->siguiente;
    }

    return i;
}

t_nodo* mapLista(t_nodo* lista, void funcionAAplicar(t_nodo*)){

    t_nodo* aux = lista;

    while(aux != NULL){

        funcionAAplicar(aux);

        aux = aux->siguiente;
    }

    return lista;
}

void liberarLista(t_nodo* lista){

    t_nodo* aux;

    while(lista != NULL){

        aux = lista;
        lista = lista->siguiente;

        free(aux->valor);
        free(aux);
    }

}

void reporteDeLiteralCadena(t_nodo* unNodo){
    char* literalCadena = strdup(unNodo->valor);
    int longitudDeCadena = strlen(literalCadena)-2; // "-2" por las comillas
    char* longitudDeCadenaEnString[12];
    sprintf(longitudDeCadenaEnString, "%d", longitudDeCadena);

    string_append(&literalCadena,": Longitud ");
    string_append(&literalCadena,longitudDeCadenaEnString);

    unNodo->valor = literalCadena;

    //free(longitudDeCadenaEnString);
    //free(unNodo->valor);

}

void reporteDeOctal(t_nodo* unNodo){
    char* valorOctal = strdup(unNodo->valor);
    int valorDecimal = valorOctalADecimal(valorOctal);
    char* valorDecimalEnString[12];
    sprintf(valorDecimalEnString, "%d", valorDecimal);

    string_append(&valorOctal,": Valor decimal ");
    string_append(&valorOctal,valorDecimalEnString);

    unNodo->valor=valorOctal;

    //free(valorDecimalEnString);
    //free(unNodo->valor);
}

void reporteDeHexa(t_nodo* unNodo){
    char* valorHexa = strdup(unNodo->valor);
    int valorDecimal = hexadecimalADecimal(valorHexa);
    char* valorDecimalEnString[12];
    sprintf(valorDecimalEnString, "%d", valorDecimal);

    string_append(&valorHexa,": Valor decimal ");
    string_append(&valorHexa,valorDecimalEnString);

    unNodo->valor=valorHexa;

    //free(valorDecimalEnString);
    //free(unNodo->valor);
}
void reporteDeRechazados(t_nodo* unNodo){
    char* valorRechazado = strdup(unNodo->valor);
    char* valorEnString[12];
    sprintf(valorEnString, "%d", valorRechazado);

    string_append(&valorRechazado,": Valor rechazado ");
    string_append(&valorRechazado,valorEnString);

    unNodo->valor=valorRechazado;

    //free(valorEnString);
    //free(unNodo->valor);
}
/*int main(){

    t_nodo* lista = NULL;

    lista = agregarNodoAlFinal("hola", lista);
    lista = agregarNodoAlFinal("hola", lista);
    lista = agregarNodoAlFinal("hola", lista);
    lista = agregarNodoAlFinal("hola", lista);
    lista = agregarNodoAlFinal("hola", lista);
    lista = agregarNodoAlFinal("tu hermana", lista);
    lista = agregarNodoAlFinal("tu hermana", lista);
    lista = agregarNodoAlFinal("pato el pez", lista);

    printListaEnArchivoConRepetidos(lista, "Tu vieja", "tuvieja.txt");
    imprimirValoresDeLista(lista);

    liberarLista(lista);

    return 0;
}*/
