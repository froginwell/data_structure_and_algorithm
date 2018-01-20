#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include "single_linked_list.h"


void single_linked_list_init(SingleLinkedList *sllist){
    sllist -> head = NULL;
    sllist -> tail = NULL;
    sllist -> size = 0;
}


void single_linked_list_free(SingleLinkedList *sllist){
    Node *cur = sllist -> head;
    Node *next = NULL;
    while(cur){
        next = cur -> next;
        free(cur);
        cur = next;
    }
}


void single_linked_list_append(
    SingleLinkedList *sllist,
    void *data
){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;

    if(sllist -> tail){
        sllist -> tail -> next = new_node;
    }
    sllist -> tail = new_node;

    if(!sllist -> head){
        sllist -> head = new_node;
    }
    sllist -> size += 1;
}
