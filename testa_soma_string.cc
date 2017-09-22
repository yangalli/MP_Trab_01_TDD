#include "string_soma.hpp"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

//Testes básicos para setar o ambiente de desenvolvimento

TEST(TesteDaSoma, NosPositivos){
	ASSERT_EQ(2, soma_string_num(2));
	ASSERT_EQ(4, soma_string_num(4));
}

TEST(TesteDaSoma, ValidaChar){
	ASSERT_EQ('a', soma_string_char('a'));
	ASSERT_EQ('b', soma_string_char('b'));
}

//Esse teste verifica se a função valida final funciona corretamente

TEST(TesteDaSoma, ValidaFinal){ 
	ASSERT_EQ(false, valida_final(""));
	ASSERT_EQ(true, valida_final("\n"));
}

//Essa função checa se a função valida_soma_dois_algarismos retorna os valores corretamente
//Essas funções básicas foram utilizadas para uma melhor depuração dos erros que resultam das funções 

TEST(TesteDaSoma, TesteSomaDoisAlgarismos){ 
	ASSERT_EQ(3, valida_soma_dois_algarismos("1,2\n"));
	ASSERT_EQ(25, valida_soma_dois_algarismos("1,21,3\n"));
	ASSERT_EQ(66, valida_soma_dois_algarismos("12,21,33\n"));
	ASSERT_EQ(57, valida_soma_dois_algarismos("1,21,33,2\n"));
	ASSERT_EQ(79, valida_soma_dois_algarismos("1,21,33,2,22\n"));
}

//Checa se os tipos de strings dados nas especificações são válidos
//Nesses casos o delimitador só podia ser a vírgula

TEST(TesteDaSoma, TesteGeralSomaVirgulaDelimitador){ 
	ASSERT_EQ(3, soma_string("1,2\n"));
	ASSERT_EQ(6, soma_string("3,2,1\n"));
	ASSERT_EQ(-1, soma_string(",2\n"));
	ASSERT_EQ(-1, soma_string(",\n"));
	ASSERT_EQ(-1, soma_string("1;2\n"));
	ASSERT_EQ(-1, soma_string("1,2"));
	ASSERT_EQ(3, soma_string("1\n,2\n"));
	ASSERT_EQ(5, soma_string("1\n\n\n,4\n"));
	ASSERT_EQ(4, soma_string("1\n\n\n,\n\n\n3\n"));
	ASSERT_EQ(-1, soma_string("1,2,3,4\n"));
	ASSERT_EQ(10, soma_string("1,2,3\n,4\n"));
}

TEST(TesteDaSoma, TesteSomaTresAlgarismos){ 
	ASSERT_EQ(14, valida_soma_tres_algarismos("12\n,2\n"));
	ASSERT_EQ(5, valida_soma_tres_algarismos("1\n\n\n,4\n"));
	ASSERT_EQ(300, valida_soma_tres_algarismos("100,200\n"));
	ASSERT_EQ(221, valida_soma_tres_algarismos("10,211\n"));
	ASSERT_EQ(104, valida_soma_tres_algarismos("99,5\n"));
	ASSERT_EQ(321, valida_soma_tres_algarismos("1,20,300\n"));
	ASSERT_EQ(117, valida_soma_tres_algarismos("1,2,4,10,100\n"));
}

//Teste para validar a funcao valida_soma_tres_algarismos dentro da funçaõ principal soma_string
//Verifica que 4 numeros na string antes do '\n' retorna -1

TEST(TesteDaSoma, TesteGeralSomaDoisAlgarismos){ 
	ASSERT_EQ(40, soma_string("12,3,25\n"));
	ASSERT_EQ(104, soma_string("99,5\n"));
	ASSERT_EQ(19, soma_string("12,3,4\n"));
	ASSERT_EQ(29, soma_string("12,13,4\n"));
	ASSERT_EQ(-1, soma_string("12,13,4,20\n"));
}

//Mais testes verificando as somas entre números, mas com valores maiores 

TEST(TesteDaSoma, TesteGeralSomaTresAlgarismos){ 
	ASSERT_EQ(110, soma_string("100,10\n"));
	ASSERT_EQ(30, soma_string("10,20\n"));
	ASSERT_EQ(124, soma_string("1,12,111\n"));
	ASSERT_EQ(111, soma_string("100,10,1\n"));
}

//verifica a criação de novos delimitadores

TEST(TesteDaSoma, TesteDelimitadoresGeral){ 
	ASSERT_STREQ("@", cria_delimitaNo("//[@]\n\n"));
	ASSERT_STREQ("&", cria_delimitaNo("//[&]\n\n"));
	ASSERT_STREQ("....", cria_delimitaNo("//[....]\n\n"));
	ASSERT_STREQ(";", cria_delimitaNo("//[;]\n\n"));
	ASSERT_STREQ("~", cria_delimitaNo("//[~]\n"));
}

//Confirma que os delimitadores criados são validos

TEST(TesteDaSoma, TesteGeralDelVariavel){ 
	ASSERT_EQ(33, soma_string("//[$]\n1$12$20\n"));
	ASSERT_EQ(33, soma_string("//[*]\n1*12*20\n"));
	ASSERT_EQ(-1, soma_string("//[$]\n1$12$20$100\n"));
	ASSERT_EQ(22, soma_string("//[&&&][**]\n1&&&1**20\n"));
	ASSERT_EQ(-1, soma_string("//[$$]1$$12$$20\n"));
	ASSERT_EQ(33, soma_string("//[$$]\n1$$12$$20\n"));
	ASSERT_EQ(3, soma_string("//[@]\n1@2\n"));
}



int main(int argc, char **argv){
 	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}