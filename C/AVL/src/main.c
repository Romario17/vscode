#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/avl.h"

// main menu
#define MAIN_MENU_SIZE 5
const char *MAIN_MENU_TEXT =
    "============ AVL ============\n"
    "1 - insert element\n"
    "2 - remove element\n"
    "3 - print tree\n"
    "4 - tree information\n"
    "5 - quit\n";

// print tree menu
#define PRINT_TREE_MENU_SIZE 5
const char *PRINT_TREE_MENU_TEXT =
    "======= PRINT AVL MENU =======\n"
    "1 - in level\n"
    "2 - pre order\n"
    "3 - in order\n"
    "4 - post order\n"
    "5 - quit\n";

int main()
{
    short mMenu_optSelected = 0;  // main menu option selected
    short ptMenu_optSelected = 0; // print tree menu option selected

    int key;
    AVL_Tree *avl_tree = avl_create();
    
    do
    {
        mMenu_optSelected = menu(MAIN_MENU_TEXT, MAIN_MENU_SIZE);
        switch (mMenu_optSelected)
        {
            case 1:
                printf("Enter an integer key value: ");
                scanf("%d", &key);
                if (avl_insert(avl_tree, key, NULL))
                    printf("Node successfully inserted!!!\n");
                break;
            case 2:
                printf("Enter an integer key value: ");
                scanf("%d", &key);
                if (avl_remove(avl_tree, key))
                    printf("Node successfully removed!!!\n");
                break;
            case 3:
                ptMenu_optSelected = menu(PRINT_TREE_MENU_TEXT, PRINT_TREE_MENU_SIZE);
                switch (ptMenu_optSelected)
                {
                    case 1:
                        avl_print_inlevel(avl_tree);
                        break;
                    case 2:
                        avl_print_preorder(avl_tree);
                        break;
                    case 3:
                        avl_print_inorder(avl_tree);
                        break;
                    case 4:
                        avl_print_postorder(avl_tree);
                        puts("\n");
                        break;
                }
                break;
            case 4:
                break;
        }
    } while (mMenu_optSelected != MAIN_MENU_SIZE);

    avl_destroy(avl_tree);

    return EXIT_SUCCESS;
}