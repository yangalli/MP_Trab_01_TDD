#include "string_soma.hpp"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>


TEST(TesteDaSoma, NosPositivos){
	ASSERT_EQ(2, soma_string_num(2));
	ASSERT_EQ(4, soma_string_num(4));
}

TEST(TesteDaSoma, ValidaChar){
	ASSERT_EQ(0, soma_string_char('a'));
	ASSERT_EQ(0, soma_string_char('b'));
}

TEST(TesteDaSoma, ValidaString){
	ASSERT_EQ(0, soma_string("gaucho"));
	ASSERT_EQ(0, soma_string("ronaldinho"));
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
	ASSERT_EQ(4, conta_delimitaNo(",,,,  "));
	ASSERT_EQ(3, conta_delimitaNo("/,,, "));
}

TEST(TesteDaSoma, ValidaNoAlgarismos){ 
	ASSERT_EQ(true, valida_algarismos_linha("1\n"));
	ASSERT_EQ(true, valida_algarismos_linha("14\n"));
	ASSERT_EQ(true, valida_algarismos_linha("123\n"));
	ASSERT_EQ(false, valida_algarismos_linha("1234\n"));
}

/*TEST(TesteDaSoma, CheckStack){
	ASSERT_EQ(3, test_stack(2));
}*/

TEST(TesteDaSoma, ValidaSomaUmAlgarismo){ 
	ASSERT_EQ(3, valida_soma_um_algarismo("2,2\n"));
	ASSERT_EQ(5, valida_soma_um_algarismo("1,4\n"));
	ASSERT_EQ(5, valida_soma_um_algarismo("1,2,2\n"));
	ASSERT_EQ(10, valida_soma_um_algarismo("1,2,3,4\n"));
}




int main(int argc, char **argv){
 	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}