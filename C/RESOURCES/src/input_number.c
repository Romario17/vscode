#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "../include/input_number.h"
#include "../include/str_limits.h"

bool is_ushort_overflow(char str_number[USHRT_NDIGITS + 1])
{
    if (strlen(str_number) < strlen(STR_USHORT_MAX))
        return false;
    for (short i = 0; i < USHRT_NDIGITS; i++)
    {
        if (str_number[i] < STR_USHORT_MAX[i])
            return false;
        if (str_number[i] > STR_USHORT_MAX[i])
            return true;
    }
    return false;
}

unsigned short in_ushort()
{
    int number = 0;
    char input = ' ';
    char str_number[USHRT_NDIGITS + 1] = "";

    short iterator = 0;
    do
    {
        input = _getch();
        if (iterator < USHRT_NDIGITS && isdigit(input))
        {
            _putch(input);
            str_number[iterator] = input;
            iterator++;
        }
    } while (iterator == 0 || input != 13);
    str_number[iterator] = '\0';
    printf("\n");

    if (is_ushort_overflow(str_number))
        fprintf(stderr, "unsigned short overflow!!! Max value permitted: %s\n", STR_USHORT_MAX);

    number = atoi(str_number);
    return (unsigned short)number;
}