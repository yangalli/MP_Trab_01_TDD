#include "string_soma.hpp"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>


TEST(TesteDaSoma, NosPositivos){
	ASSERT_EQ(2, soma_string_num(2));
	ASSERT_EQ(4, soma_string_num(4));
}

TEST(TesteDaSoma, ValidaChar){
	ASSERT_EQ(0, soma_string_char('a'));
	ASSERT_EQ(0, soma_string_char('b'));
}


TEST(TesteDaSoma, ValidaNo){
	ASSERT_EQ(0, verifica_numero(1));
	ASSERT_EQ(0, verifica_numero(2));
	ASSERT_EQ(0, verifica_numero('a'));
}

TEST(TesteDaSoma, ValidaDelimitador){ 
	ASSERT_EQ(true, valida_delimitaNo_virgula(","));
	ASSERT_EQ(false, valida_delimitaNo_virgula("/"));
}

TEST(TesteDaSoma, ValidaFinal){ 
	ASSERT_EQ(false, valida_final(""));
	ASSERT_EQ(true, valida_final("\n"));
}


TEST(TesteDaSoma, ValidaNoAlgarismos){ 
	ASSERT_EQ(true, valida_numeros_linha("1\n"));
	ASSERT_EQ(true, valida_numeros_linha("14\n"));
	ASSERT_EQ(true, valida_numeros_linha("123\n"));
	ASSERT_EQ(false, valida_numeros_linha("1234\n"));
}

TEST(TesteDaSoma, TesteGeralSoma){ 
	ASSERT_EQ(0, soma_string("1,2\n"));
	ASSERT_EQ(-1, soma_string("14"));
	ASSERT_EQ(-1, soma_string("12334,2\n"));
	ASSERT_EQ(0, soma_string("12,3\n"));
	ASSERT_EQ(0, soma_string("12,,3\n"));
	ASSERT_EQ(0, soma_string("1,2,3\n"));
}




int main(int argc, char **argv){
 	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}