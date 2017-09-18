#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>

//using namespace std;

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
	int tamanho_string = strlen(string_entrada);
	for (int i = 0; i < tamanho_string; i++) {
		if (verifica_numero(string_entrada[i]) == true) {
			while (verifica_numero(string_entrada[i+j] == true)) {
				i++;
			}
			contador++;
		}
	}
	return contador;
}

bool valida_delimitaNo_virgula(const char *delimitaNo) {
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
	}
	return no_delimitadores;
}


bool valida_algarismos_linha(const char * string_entrada) {
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

//prototipo da funcao para uma soma de numeros com um algarismo

int valida_soma_um_algarismo(const char * string_entrada){
	int tamanho_string = strlen(string_entrada);
	int j = 0, i = 0, soma = 0;
	char output[10];
	for (i = 0; i < tamanho_string; i++) {
		for (j = 0; j < 10; j++){
			while (string_entrada[i] != '\n') {
				if (verifica_numero(string_entrada[i]) == true){
					if (string_entrada[i] != ','){
						output[j] = string_entrada[i];
						j++;
					}
					i++;
				}
			}
		}
	}
	for (j = 0; j < 10; j++) {
		soma = soma + output[j];
	}
	return soma;
}



/*int test_stack(int valor){
	int rolando;
	stack <int> cards;
	cards.push(1);
	cards.push(2);
	cards.push(3);
	rolando = cards.top();

	return rolando;
}*/


int soma_string(const char * string_entrada){
	return 0;
}




