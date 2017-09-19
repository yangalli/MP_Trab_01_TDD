#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


int soma_string_num(int numero){
    return numero;
}

int soma_string_char(char string_entrada){
	return 0;
}

//garante que apenas numeros positivos sao validos

bool verifica_numero(char ch) {
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		return true;
	return false;
}

bool valida_final(const char *string_entrada){
	int tamanho_string = strlen(string_entrada);
	if (string_entrada[tamanho_string-1] != '\n') 
		return false;
	return true;
}

bool valida_numeros_linha(const char * string_entrada) {
	int no_algarismos;
	int tamanho_string = strlen(string_entrada);
	for (int i = 0; i < tamanho_string; i++) {
		no_algarismos = 0;
		while (string_entrada[i] != '\n') {
			if (verifica_numero(string_entrada[i]) == true) 
				no_algarismos++;
			i++;
		}
		if (no_algarismos > 3) 
			return false;
	}
	return true;
}

bool valida_delimitaNo_virgula(const char *delimitaNo) {
  	char delimitador[1];
  	strcpy(delimitador, ",");
  	if (strcmp(delimitaNo, delimitador) == 0)
  		return true;
  	else
  		return false;
}

int soma_string(const char * string_entrada){
	char delimitaNo[] = ",";
	if(!valida_final(string_entrada))
		return -1;
	if(!valida_numeros_linha(string_entrada))
		return -1;
	if(!valida_delimitaNo_virgula(delimitaNo))
		return -1;
	return 0;
}









