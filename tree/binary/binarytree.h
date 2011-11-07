#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

/*  Feuvrier "manny" Louis
 *  Date: 07/11/11
 *  Binary Tree:
 *      Declaration of simple binary tree datatype */

typedef struct node node;
struct node {
    void* key;
    node* fg;
    node* fd;
};

/* We define tree as a pointer to a node */
typedef node* tree;

/* Creator & Destructor */
tree create_tree(void* value, tree fg, tree fd);
void delete_tree(tree current);
/* Accessor */
int length_tree(tree current);
tree max_tree(tree current);
tree min_tree(tree current);
int isempty_tree(tree current);

#endif /* BINARYTREE_H_INCLUDED */
