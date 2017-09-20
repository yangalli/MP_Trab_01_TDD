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


TEST(TesteDaSoma, ValidaNoDelimitadores){ 
	ASSERT_EQ(3, conta_delimitaNo(",/,/,  "));
	ASSERT_EQ(3, conta_delimitaNo("1,2,3,4 "));
	ASSERT_EQ(-1, conta_delimitaNo("1,,3,4 "));
	ASSERT_EQ(-1, conta_delimitaNo("1,2,3,4,,"));
	ASSERT_EQ(4, conta_delimitaNo("/,2,/,1,"));
}

TEST(TesteDaSoma, TesteSomaDoisAlgarismos){ 
	ASSERT_EQ(27, valida_soma_dois_algarismos("1,2,21,3\n"));
	ASSERT_EQ(3, valida_soma_dois_algarismos("1,2\n"));
	ASSERT_EQ(25, valida_soma_dois_algarismos("1,21,3\n"));
	ASSERT_EQ(66, valida_soma_dois_algarismos("12,21,33\n"));
	ASSERT_EQ(57, valida_soma_dois_algarismos("1,21,33,2\n"));
	ASSERT_EQ(79, valida_soma_dois_algarismos("1,21,33,2,22\n"));
}

TEST(TesteDaSoma, TesteGeralSomaVirgulaDelimitador){ 
	ASSERT_EQ(3, soma_string("1,2\n"));
	ASSERT_EQ(6, soma_string("3,2,1\n"));
	ASSERT_EQ(-1, soma_string(",2\n"));
	ASSERT_EQ(-1, soma_string("1,,2\n"));
	ASSERT_EQ(-1, soma_string(",\n"));
	//ASSERT_EQ(-1, soma_string("1;2\n"));
	ASSERT_EQ(-1, soma_string("1,2"));
	ASSERT_EQ(3, soma_string("1\n,2\n"));
	ASSERT_EQ(5, soma_string("1\n\n\n,4\n"));
	ASSERT_EQ(4, soma_string("1\n\n\n,\n\n\n3\n"));
	ASSERT_EQ(-1, soma_string("1,2,3,4\n"));
	ASSERT_EQ(10, soma_string("1,2,3\n,4\n"));
}



TEST(TesteDaSoma, TesteGeralSomaDoisAlgarismos){ 
	//ASSERT_EQ(-1, soma_string("1;2\n"));
	ASSERT_EQ(15, soma_string("12,3\n"));
	ASSERT_EQ(104, soma_string("99,5\n"));
	ASSERT_EQ(19, soma_string("12,3,4\n"));
	ASSERT_EQ(26, soma_string("12,13,4\n"));

}






int main(int argc, char **argv){
 	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}