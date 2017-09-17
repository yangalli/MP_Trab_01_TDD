#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int soma_string_num(int numero){
    return numero;
}

int soma_string_char(char string_entrada){
	return 0;
}

bool verifica_numero(char ch) {
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		return true;
	return false;
}

int conta_numeros_string(const char * string_entrada){
	int j = 1, contador = 0;
	int tamanho = strlen(string_entrada);
	for (int i = 0; i < tamanho; i++) {
		if (verifica_numero(string_entrada[i]) == true) {
			while (verifica_numero(string_entrada[i+j] == true)) {
				i++;
			}
			contador++;
		}
	}
	return contador;
}

bool valida_delimitaNo_virgula(char *delimitaNo) {
  	char delimitador[] = ",";
  	if (strcmp(delimitaNo, delimitador) == 0)
  		return true;
  	else
  		return false;
}

int conta_delimitadores(const char *string_entrada) {
	int contador = 0, tamanho = strlen(string_entrada);
	char delimitador = ',';
	for (int i = 0; i < tamanho; i++) {
		if (string_entrada[i] == delimitador) 
			contador++;
	}
	return contador;
}

int soma_string(const char * string_entrada){
	return 0;
}




