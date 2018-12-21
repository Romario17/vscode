#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int resto(int dividendo, int divisor)
{
    return dividendo % divisor;
}

int hash_dobra(int key)
{
    if (key > 99999999)
    {
        printf("chave possui mais de 8 digitos!\n");
        return -1;
    }

    int dividendo = key;
    int vetor[8];
    for (int i = 0; i < 8; i++)
        vetor[i] = 0;

    int i = 7;
    while (dividendo > 0)
    {
        vetor[i] = dividendo % 10;
        dividendo = dividendo / 10;
        i--;
    }

    for(i = 0; i < 8; i++)
        printf("%d", vetor[i]);
    printf("\n");

    return 0;
}

int main()
{
    int key = 813459;
    int table_size = 128;

    int num_bits = 7;
    int parte1 = key >> num_bits;
    parte1 = parte1 & (table_size - 1);
    int parte2 = key & (table_size - 1);
    printf("parte 1 = %d\n parte 2 = %d\np1 xor p2 = %d\n", parte1, parte2, parte1 ^ parte2);

    return EXIT_SUCCESS;
}