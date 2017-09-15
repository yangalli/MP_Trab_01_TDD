#include "string_soma.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <stdio.h>


TEST(TesteDaSoma, NosPositivos){
	ASSERT_EQ(2, soma_string(2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}