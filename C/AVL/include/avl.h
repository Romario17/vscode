#ifndef AVL_H
#define AVL_H
    #include <stdbool.h>

    typedef struct avl_node* AVL_Tree;

    AVL_Tree* avl_create();
    bool avl_insert(AVL_Tree* avl_tree, int key, void* data);
    bool avl_remove(AVL_Tree* avl_tree, int key);
    void* avl_search(AVL_Tree* avl_tree, int key);
    int avl_height(AVL_Tree* avl_tree);
    void avl_print(AVL_Tree* avl_tree);
    void avl_destroy(AVL_Tree* avl_tree);

#endif /* AVL_H */