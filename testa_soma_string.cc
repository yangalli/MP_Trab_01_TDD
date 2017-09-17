#include "string_soma.hpp"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <stdio.h>


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

TEST(TesteDaSoma, ValidaConjuntoNos){
	ASSERT_EQ(3, conta_numeros_string("123"));
	ASSERT_EQ(5, conta_numeros_string("24567"));
	ASSERT_EQ(2, conta_numeros_string("12"));
}

TEST(TesteDaSoma, ValidaDelimitador){ 
	ASSERT_EQ(true, valida_delimitaNo_virgula(","));
	ASSERT_EQ(false, valida_delimitaNo_virgula("/"));
}

TEST(TesteDaSoma, ValidaNoDelimitadores){ 
	ASSERT_EQ(4, conta_delimitadores(",,,,  "));
	ASSERT_EQ(3, conta_delimitadores("/,,, "));
}






int main(int argc, char **argv){
 	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}