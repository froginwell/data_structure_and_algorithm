#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _Node{
    void *elem;
    struct _Node *left;
    struct _Node *right;
}Node;

typedef struct _BinaryTree{
    Node *root;
    int size;
    int elem_size;
    void (*destroy)(void *elem);
    int (*compare)(const void *elem_1, const void *elem_2);
}BinaryTree;

void binary_tree_init(
    BinaryTree *btree,
    int elem_size,
    void (*destroy)(void *elem),
    int (*compare)(const void *elem_1, const void *elem_2)
);
void binary_tree_destroy(BinaryTree *btree);
void binary_tree_insert(BinaryTree *btree, const void *elem);
void binary_tree_delete(BinaryTree *btree, const void *elem);
int binary_tree_search(BinaryTree *btree, const void *elem);

#endif
