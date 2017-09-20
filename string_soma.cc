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

bool valida_delimitaNo_virgula(const char * delimitaNo) {
  	char delimitador[1];
  	strcpy(delimitador, ",");
  	if (strcmp(delimitaNo, delimitador) == 0)
  		return true;
  	else
  		return false;
}

int conta_delimitaNo (const char *string_entrada) {
	int no_delimitadores = 0, tamanho_string = strlen(string_entrada);
	char delimitador = ',';
	for (int i = 0; i < tamanho_string; i++) {
		if (string_entrada[i] == delimitador) 
			no_delimitadores++;
		if(string_entrada[i] == delimitador && string_entrada[i+1] == delimitador)
			return -1;
	}	
	return no_delimitadores;
}

bool valida_virgulas_linha(const char * string_entrada){
	char * input = strdup(string_entrada);
	if (conta_delimitaNo(input) == -1)
		return false;
	return true;
}

bool valida_inicio(const char * string_entrada){
	char * input = strdup(string_entrada);
	int i = 0;
	if (verifica_numero(input[i]) || input[i] == '/' )
		return true;
	return false;
}

int valida_soma_um_algarismo(const char * string_entrada){
	int tamanho_string = strlen(string_entrada);
	int i, soma = 0;
	char output[20], ch;
	for (i = 0; i < tamanho_string; i++){
		ch = string_entrada[i];
		if (isdigit(ch)){
			output[0] = ch;
			soma = soma + atoi(output);
		}
	}
	return soma;
}

int valida_soma_dois_algarismos (const char * string_entrada){
	int tamanho_string = strlen(string_entrada);
	int i, soma = 0;
	char output[20], output1[20], ch, ch1;
	for (i = 0; i < tamanho_string; i++){
		ch = string_entrada[i];
		ch1 = string_entrada[i+1];
		if (isdigit(ch) && isdigit(ch1)){
			output[0] = ch;
			output1[0] = ch1;
			soma += 10*atoi(output) + atoi(output1);
			i++;
		}
		if(isdigit(ch) && !isdigit(ch1)){
			output[0] = ch;
			soma += atoi(output);
			i++;
		}
	}
	return soma;
}


int soma_string(const char * string_entrada){
	char delimitaNo[] = ","; 
	if(!valida_final(string_entrada))
		return -1;
	if(!valida_numeros_linha(string_entrada))
		return -1;
	if(!valida_delimitaNo_virgula(delimitaNo))
		return -1;
	if (!valida_virgulas_linha(string_entrada))
		return -1;
	if (!valida_inicio(string_entrada))
		return -1;
	return valida_soma_dois_algarismos (string_entrada);
}