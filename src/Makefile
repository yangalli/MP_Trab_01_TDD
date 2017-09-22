GTEST_DIR = ../../../Gtest/googletest-master/googletest

USER_DIR = .


CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread -ftest-coverage -fprofile-arcs


TESTS = testa_soma_string

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

CXX = g++

IDIR =../include

ODIR = obj

LDIR = ../lib

LIBS = -lm

CFLAGS = -I.

_DEPS = string_soma.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = string_soma.o testa_soma_string.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

EX_FLAGS = -g -Wall -Wextra -Weffc++

_OBJS = string_soma.o testa_soma_string_stdin.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS)

testa_soma_string_stdin: $(OBJS)
	$(CXX) $(OBJS) $(EX_FLAGS) -lm -o $@

testa_soma_string : $(OBJ) gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

gcov:
	gcovr -r . --html -o coverage.html --html-details