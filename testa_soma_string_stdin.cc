#include <stdio.h>
#include <stdlib.h>
#include <string_soma.hpp>


int main(int argc, char const *argv[])
{

    char elementos_string;
    int resultado_string_soma;
    char input[50];

    int i = 0;
    while (ch = getchar() != EOF){
        input[i] = elementos_string;
        i++;
    }
    input[i] = '\0';

    resultado_string_soma = soma_string(input);

    printf("%d\n", resultado_string_soma);


    return 0;
}