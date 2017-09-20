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

//verifica se o final sera o \n

bool valida_final(const char *string_entrada){
	int tamanho_string = strlen(string_entrada);
	if (string_entrada[tamanho_string-1] != '\n') 
		return false;
	return true;
}

//valida o total de numeros por linha, que e de no maximo 3

bool valida_numeros_linha(const char * string_entrada) {
	int no_algarismos, tamanho_string = strlen(string_entrada);
	char * input = strdup(string_entrada);
	for (int i = 0; i < tamanho_string; i++) {
		no_algarismos = 0;
		while (input[i] != '\n') {
			if (verifica_numero(input[i]) && verifica_numero(input[i+1]) && verifica_numero(input[i+2])){ 
				no_algarismos++;
				i += 2;
			}
			else if (verifica_numero(input[i]) && verifica_numero(input[i+1]) && !verifica_numero(input[i+2])){
				no_algarismos++;
				i++;
			}
			else if (verifica_numero(input[i]) && verifica_numero(input[i+1]) && !verifica_numero(input[i+2]) && input[i+2] == '\n')
				no_algarismos++;
			else if (verifica_numero(input[i]) && !verifica_numero(input[i+1]) && verifica_numero(input[i+2])){
				no_algarismos++;
				i++;
			}
			else if (verifica_numero(input[i]) && !verifica_numero(input[i+1]) && input[i+1] == '\n') 
				no_algarismos++;
			else if (verifica_numero(input[i]) && !verifica_numero(input[i+1])){ 
				no_algarismos++;
				i++;
			}
			i++;
		}
		if (no_algarismos > 3) 
			return false;
	}
	return true;
}

//valida a virgula como delimitador para a funcao soma_string

bool valida_delimitaNo_virgula(const char * delimitaNo) {
  	char delimitador[1];
  	strcpy(delimitador, ",");
  	if (strcmp(delimitaNo, delimitador) == 0)
  		return true;
  	else
  		return false;
}

//encontra o numero de delimitadores na funcao e verifica se as virgulas estao seguidas 

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

//se houver mais de uma virgula seguida o programa retorna -1

bool valida_virgulas_linha(const char * string_entrada){
	char * input = strdup(string_entrada);
	if (conta_delimitaNo(input) == -1)
		return false;
	return true;
}

//analisa se a string de entrada possui o inicio valido, ou seja, se comeca em numero ou '/'

bool valida_inicio(const char * string_entrada){
	char * input = strdup(string_entrada);
	int i = 0;
	if (verifica_numero(input[i]) || input[i] == '/' )
		return true;
	return false;
}

//funcao base para a soma de um algarismo, que deu origem as outras funcoes de soma

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
	char output[3], output1[3], ch, ch1;
	for (i = 0; i < tamanho_string; i++){
		ch = string_entrada[i];
		ch1 = string_entrada[i+1];
		if (isdigit(ch) && isdigit(ch1)){
			output[0] = ch;
			output1[0] = ch1;
			soma += 10*atoi(output) + atoi(output1);
			i++;
		}
		else if(isdigit(ch) && !isdigit(ch1)){
			output[0] = ch;
			soma += atoi(output);
			i++;
		}
	}
	return soma;
}

int valida_soma_tres_algarismos (const char * string_entrada){
	int tamanho_string = strlen(string_entrada);
	int i, soma = 0;
	char output[3], output1[3], output2[3], ch, ch1, ch2;
	for (i = 0; i < tamanho_string; i++){
		ch = string_entrada[i];
		ch1 = string_entrada[i+1];
		ch2 = string_entrada[i+2];
		if (isdigit(ch) && isdigit(ch1) && isdigit(ch2)){
			output[0] = ch;
			output1[0] = ch1;
			output2[0] = ch2;
			soma += 100*atoi(output) + 10*atoi(output1) + atoi(output2);
			i += 3;
		}
		else if (isdigit(ch) && isdigit(ch1) && !isdigit(ch2)){
			output[0] = ch;
			output1[0] = ch1;
			soma += 10*atoi(output) + 1*atoi(output1);
			i += 2;
		}
		else if (isdigit(ch) && !isdigit(ch1) && isdigit(ch2)){
			output[0] = ch;
			soma += atoi(output);
			i++;
		}
		else if (isdigit(ch) && !isdigit(ch1)){
			output[0] = ch;
			soma += atoi(output);
			i++;
		}
	}
	return soma;
}

/****************************************************************************************************
* Para que a funcao principal retorne um valor valido, e necessario que:
* -seu inicio seja valido;
* -seu final seja valido;
* -os numeros por linha sejam validos;
* -o numero de delimitadores seja menor em 1 unidade em relacao aos numeros;
* -os numeros possuam no maximo 3 algarismos(a funcao pode possuir retorno nesse caso)
* -nenhum numero seja negativo
* -os delimitadores variaveis estejam no inicio do codigo, iniciados por "//[" e finalizados por ']'
****************************************************************************************************/

int soma_string(const char * string_entrada){
	char delimitaNo[] = ",";
	if (!valida_inicio(string_entrada))
		return -1;
	if(!valida_final(string_entrada))
		return -1;
	if(!valida_numeros_linha(string_entrada))
		return -1;
	if(!valida_delimitaNo_virgula(delimitaNo))
		return -1;
	if (!valida_virgulas_linha(string_entrada))
		return -1;
	
	return valida_soma_tres_algarismos (string_entrada);
}