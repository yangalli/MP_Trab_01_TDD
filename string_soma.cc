#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <ctype.h>


int soma_string_num(int numero){
    return numero;
}

int soma_string_char(char string_entrada){
	return string_entrada;
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

//analisa se a string de entrada possui o inicio valido, ou seja, se comeca em numero ou '/'

bool valida_inicio(const char * string_entrada){
	char * input = strdup(string_entrada);
	int i = 0;
	if (verifica_numero(input[i]) || input[i] == '/' )
		return true;
	return false;
}

/*****************************************************************************
* 
* Retorna o total de numeros por linha, que é de no máximo 3.
* Enquanto o char verificado não for o final da string_entrada,
* ocorre primeiro uma checagem se o char contido na string é um
* número. Se o char verificado for um número, ocorre mais uma checagem
* se o próximo char é numero. Se este segundo char for um número, ocorre mais
* uma checagem se o terceiro char é também um número. Se os três primeiros 
* forem números, quer dizer que é um número de três algarismos; se os dois 
* primeiros forem numeros, o numero possui 2 algarismos; se apenas o primeiro 
* for algarismo, o número possui apenas um algarismo.
*
******************************************************************************/

int conta_numeros_linha(const char * string_entrada) {
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
			return -1;
	}
	return no_algarismos;
}

//valida o total de numeros por linha

bool valida_numeros_linha(const char * string_entrada){
	char * input = strdup(string_entrada);
	if (conta_numeros_linha(input) == -1)
		return false;
	return true;
}

/**************************************************************************
*
* Encontra o numero de delimitadores na função, por meio do strtok_r, 
* que delimita tokens (delimitadores) dentro da string_entrada, que no
* caso é o "\n". A partir disso consegue contar o numero de delimitadores
* presentes na string_entrada.
*
**************************************************************************/

int conta_delimitaNo(const char *string_entrada, char * delimitaNo){
    char *input = strdup(string_entrada);
    int no_delimitadores = 0;
    if (string_entrada[1] == '/')
        strtok_r(input, "\n", &input);
    input = strpbrk(input+1, delimitaNo);
    while (input != NULL){
        no_delimitadores++;
        input = strpbrk(input+1, delimitaNo);
    }
    return (no_delimitadores/strlen(delimitaNo));
}

/**************************************************************************
*  
* Essa função valida os delimitadores que são passados na string_entrada. 
* Se não tiver delimitadores passados pela string, a virgula é o delimitador.
* Quando existem mais delimitadores que número, a string_entrada deve ser 
* invalidada.
*
**************************************************************************/

bool valida_delimitaNo_Geral(const char *string_entrada, char * delimitaNo) {
	char *input = strdup(string_entrada);
	int no_numeros = conta_numeros_linha(input), soma_n, tamanho_string = strlen(input);
	if (string_entrada[1] == '/'){
        if ((*(strrchr(string_entrada, ']') + 1)) != '\n')
        	return false;
    else if (!(strpbrk(input, delimitaNo))) 
    	return true;
    else if (!(strpbrk(string_entrada, delimitaNo))) 
    	return true;
    }for (int i = 0; i < tamanho_string; i++){
  		if(input[i] == '\n')
  			soma_n++;
  	}
  	if(soma_n >= no_numeros)
  		return true;
	if (!(conta_delimitaNo(input, delimitaNo)+1 == no_numeros)) 
		return false;
  	return true;
}


/*********************************************************************************
*  
*  Essa função faz a verificação do '\n' no final da declaração de delimitadores
*  na string de entrada. As únicas possibilidades de chars na string após um ']'
*  são um '\n' e um '['. Se não houver um 'n' no final do último delimitador
*  a ser criado a função principal deve retornar -1. 
*
**********************************************************************************/

bool valida_barran_final_delimitaNo(const char *string_entrada){
	char *input = strdup(string_entrada);
	char tamanho_string = strlen(input);
	if (input[0] == '/') {
		for (int i = 0; i < tamanho_string; i++){
			if(input[i] == ']'){
				if(input[i+1] == '[')
					i++;
				else if(input[i+1] != '\n')
					return false;
			}
		}
	}
	return true;
}

/*********************************************************************************
*  
*  Essa função é a responsável por gerar os delimitadores que são escritos na 
*  string_entrada. Ela usa o malloc para alocar dinamicamente os delimitadores e 
*  os gera ao analisar os requisitos para que um delimitador seja válido, que são
*  começar com "//[" e terminar com ']'. O método de delimitador por tokens também 
*  é utilizado nessa função para alcançar esse objetivo.
*
**********************************************************************************/

char *cria_delimitaNo(const char *string_entrada) {
	char *input = strdup(string_entrada);
	char numeros_n_vir[] = "01234556789\n,";
	unsigned int requisito_delimitador = strspn(input, "//[");
	unsigned int fim_requisito_delimitador = strcspn(input, "]");
	char *delimitador = (char *) malloc(fim_requisito_delimitador-requisito_delimitador); 
	if (requisito_delimitador == 3 && fim_requisito_delimitador != strlen(input)){
		sscanf(input, "//[%s\n%*s", delimitador);
		delimitador = strtok_r(delimitador, "]", &delimitador);
		return delimitador;
	}else if (requisito_delimitador == 0 && fim_requisito_delimitador == strlen(input)) {
		if (strspn(input, numeros_n_vir) == strlen(input))
	  		return strdup(",");
  	}
	free(delimitador);
	return NULL;
}

//se houver mais de uma virgula seguida o programa retorna -1

bool valida_delimitador_linha(const char * string_entrada, char * delimitaNo){
	char * input = strdup(string_entrada);
	if (conta_delimitaNo(input, delimitaNo) == -1)
		return false;
	return true;
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

//possibilita a soma entre numeros com tres algarismos e delimitadores variaveis entre eles.
/*********************************************************************************
*  
*  Essa função utiliza um método similiar a conta_numeros_linha(). Ocorre uma 
*  verificação dos números, de modo que três números seguidos forem encontrados,
*  o primeiro número significa a centena, o segundo a dezena e o terceiro a unidade.
*  Sendo assim, a conta é validada multiplicando o algarismo da centena por 100, o 
*  da dezena por 10 e o da unidade por 1.
*
**********************************************************************************/


int valida_soma_tres_algarismos (const char * string_entrada){
	int tamanho_string = strlen(string_entrada);
	int soma = 0;
	char output[3], output1[3], output2[3], ch, ch1, ch2;
	for (int i = 0; i < tamanho_string; i++){
		ch = string_entrada[i];
		ch1 = string_entrada[i+1];
		ch2 = string_entrada[i+2];
		if (isdigit(ch) && isdigit(ch1) && isdigit(ch2)){
			output[0] = ch;
			output1[0] = ch1;
			output2[0] = ch2;
			soma += 100*atoi(output) + 10*atoi(output1) + atoi(output2);
			i += 2;
		}
		else if (isdigit(ch) && isdigit(ch1) && !isdigit(ch2)){
			output[0] = ch;
			output1[0] = ch1;
			soma += 10*atoi(output) + 1*atoi(output1);
			i++;
		}
		else if (isdigit(ch) && !isdigit(ch1) && !isdigit(ch2)){
			output[0] = ch;
			soma += atoi(output);
			i+=2;
		}
		else if (isdigit(ch) && !isdigit(ch1)){
			output[0] = ch;
			soma += atoi(output);
			i++;
		}
		else if (isdigit(ch) && !isdigit(ch1) && ch1 == '\n'){
			output[0] = ch;
			soma += atoi(output);
		}
	}
	return soma;
}

/***************************************************************************************************
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
	char *delimitaNo = cria_delimitaNo(string_entrada);
	if(!valida_inicio(string_entrada))
		return -1;
	if(!valida_final(string_entrada))
		return -1;
	if (!(delimitaNo))
		return -1;
	if(!valida_numeros_linha(string_entrada))
		return -1;
	if(!valida_barran_final_delimitaNo(string_entrada))
		return -1;
	if(!valida_delimitaNo_Geral(string_entrada, delimitaNo))
		return -1;
	if(!valida_delimitador_linha(string_entrada, delimitaNo))
		return -1;
	return valida_soma_tres_algarismos (string_entrada);
}