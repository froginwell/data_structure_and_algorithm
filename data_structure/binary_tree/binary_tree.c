#include<stdlib.h>
#include<string.h>
#include "binary_tree.h"


static void node_destroy(Node *node, void (*destroy)(void *elem));
static void node_destroy_without_destroy(Node *node);


void binary_tree_init(
    BinaryTree *btree,
    int elem_size,
    void (*destroy)(void *elem),
    int (*compare)(const void *elem_1, const void *elem_2)
){

    btree -> root = NULL;
    btree -> size = 0;
    btree -> elem_size = elem_size;
    btree -> destroy = destroy;
    btree -> compare = compare;
}


void binary_tree_destroy(BinaryTree *btree){
    if(btree -> destroy){
        node_destroy(btree -> root, btree -> destroy);
    }else{
        node_destroy_without_destroy(btree -> root);
    }
    memset(btree, 0, sizeof(BinaryTree));
}


void binary_tree_insert(BinaryTree *btree, const void *elem){
    Node *root = btree -> root;
    Node **insert = NULL;
    if(root){
        while(root){
            if((btree -> compare)(root -> elem, elem) == 0){
                break;
            }else if((btree -> compare)(root -> elem, elem) > 0){
                insert = &(root -> left);
                root = root -> left;
            }else{
                insert = &(root -> right);
                root = root -> right;
            }
        }
    }else{
        insert = &(btree -> root);
    }
    if(insert){
        Node *node = (Node *)malloc(sizeof(Node));
        node -> left = NULL;
        node -> right = NULL;
        memcpy(node -> elem, elem, btree -> elem_size);
        *insert = node;
    }
}


void node_destroy(Node *node, void (*destroy)(void *elem)){
    if(node){
        node_destroy(node -> left, destroy);
        node_destroy(node -> right, destroy);
        destroy(node -> elem);
        free(node);
    }
}


void node_destroy_without_destroy(Node *node){
    if(node){
        node_destroy_without_destroy(node -> left);
        node_destroy_without_destroy(node -> right);
        free(node);
    }
}
