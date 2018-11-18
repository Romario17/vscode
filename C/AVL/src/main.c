#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/avl.h"

// main menu
#define MAIN_MENU_SIZE 4
const char *MAIN_MENU_TEXT =
    "============ AVL ============\n"
    "1 - insert element\n"
    "2 - remove element\n"
    "3 - print tree\n"
    "4 - quit\n";

// print tree menu
#define PRINT_TREE_MENU_SIZE 3
const char *PRINT_TREE_MENU_TEXT = ((void *)0);

int main()
{
    short mMenu_optSelected = 0; // main menu option selected
    short ptMenu_optSelected = 0; // print tree menu option selected

    do
    {
        mMenu_optSelected = menu(MAIN_MENU_TEXT, MAIN_MENU_SIZE);
        switch (mMenu_optSelected)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    } while (mMenu_optSelected != MAIN_MENU_SIZE);

    return EXIT_SUCCESS;
}