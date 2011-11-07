#include <stdio.h>
#include <stdlib.h>
#include "binarytree.c"

tree cti(int value, tree fg, tree fd);

int main() {
    tree leaf = cti(15, NULL, NULL);
    tree root = cti(4, cti(3, cti(1, NULL, NULL), 
                cti(2, NULL, NULL)), cti(10, cti(7, 
                cti(5, NULL, NULL), cti(9, NULL, NULL)), 
                cti(8, NULL, NULL)));

    printf("length_tree on root (9): %d\n", length_tree(root));
    printf("length_tree on leaf (1): %d\n", length_tree(leaf));
    printf("length_tree on null (0): %d\n", length_tree(NULL));

    printf("max_tree on root (10): %d\n", *(int*)max_tree(root));
    printf("max_tree on leaf (15): %d\n", *(int*)max_tree(leaf));
    printf("max_tree on null segfault (expected behavior)\n");

    printf("min_tree on root (9): %d\n", *(int*)min_tree(root));
    printf("min_tree on leaf (1): %d\n", *(int*)min_tree(leaf));
    printf("min_tree on null segfault (expected behavior)\n");

    printf("isempty_tree on root (0): %d\n", isempty_tree(root));
    printf("isempty_tree on leaf (0): %d\n", isempty_tree(leaf));
    printf("isempty_tree on null (1): %d\n", isempty_tree(NULL));

    delete_tree(root);

    return 0;
}

/* function cti : create_tree_int */
tree cti(int value, tree fg, tree fd) {
    int* tmp = malloc(sizeof(int));
    *tmp = value;

    tree output = malloc(sizeof(node));
    output->key = tmp;
    output->fg = fg;
    output->fd = fd;

    return output; 
}
