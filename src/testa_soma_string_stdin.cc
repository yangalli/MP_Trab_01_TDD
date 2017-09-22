#include <stdio.h>
#include <stdlib.h>
#include <string_soma.hpp>


int main(int argc, char const *argv[])
{

    char elementos_string;
    int resultado_string_soma;
    char input[50], output[50];
    FILE * entrada_string_soma;
    FILE * saida_string_soma;
    entrada_string_soma = fopen(input, "r");

    int i = 0;
    while (elementos_string = fgetc() != EOF){
        output[i] = elementos_string;
        i++;
        elementos_string = fgetc(entrada_string_soma);
    }

    resultado_string_soma = soma_string(input);
    resultado_string_soma = fopen("output.txt", "w");
    fprintf(resultado_string_soma, "%d\n", resultado_string_soma);



    fclose(entrada_string_soma);
    fclose(saida_string_soma);


    return 0;
}