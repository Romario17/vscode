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

    int key;
    AVL_Tree* avl_tree = avl_create();
    do
    {
        mMenu_optSelected = menu(MAIN_MENU_TEXT, MAIN_MENU_SIZE);
        switch (mMenu_optSelected)
        {
        case 1:
            printf("Enter an integer key value: ");
            scanf("%d", &key);
            if(avl_insert(avl_tree, key, NULL))
            {
                printf("Node successfully inserted!!!\n");
                getchar();
            }
            break;
        case 2:
            printf("Enter an integer key value: ");
            scanf("%d", &key);
            if(avl_remove(avl_tree, key))
            {
                printf("Node successfully removed!!!\n");
                getchar();
            }
            break;
        case 3:
            printf("\n\n");
            avl_print(avl_tree);
            getchar();
            printf("\n\n");
            break;
        }
    } while (mMenu_optSelected != MAIN_MENU_SIZE);

    return EXIT_SUCCESS;
}