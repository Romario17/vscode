#include <stdio.h>
#include "../include/menu.h"

short menu(const char *options_text, const short options_number)
{
    if(options_number <= 0)
        return 0;
    short option_selected = 0;
    char str_option_selected[5];

    printf("%s:", options_text);
    while (option_selected > options_number || option_selected < 1)
    {
        scanf("%hd",&option_selected);
        if (option_selected > options_number || option_selected < 1)
            printf("invalid option!\n");
    }
    return option_selected;
}