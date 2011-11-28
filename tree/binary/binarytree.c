/*  Feuvrier "manny" Louis
 *  Date: 07/11/11
 *  Binary Tree:
 *      Declaration of simple binary tree datatype */

#include <stdio.h>
#include <stdlib.h>
#include <binarytree.h>

tree create_tree(void* value, tree fg, tree fd) {
    tree output = malloc(sizeof(node));

    output->key = value;
    output->fg = fg;
    output->fd = fd;

    return output;
}

void delete_tree(tree current) {
    if (current != NULL) {
        delete_tree(current->fg);
        delete_tree(current->fd);
        free(current);
    }
}

int length_tree(tree current) {
    if (current == NULL)
        return 0;
    return length_tree(current->fg) + length_tree(current->fd) + 1;
}

tree max_tree(tree current) {
    if (current != NULL)
        if (current->fd == NULL)
            return current;
        return max_tree(current->fd);
    return NULL;
}

tree min_tree(tree current) {
    if (current != NULL)
        if (current->fg == NULL)
            return current;
        return max_tree(current->fd);
    return NULL;
}

int isempty_tree(tree current) {
    return current == NULL;
}
