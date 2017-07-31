#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include "single_linked_list.h"


void single_linked_list_init(
    SingleLinkedList *sllist,
    int elem_size,
    void (*destroy)(void *elem),
    int (*compare)(const void *elem_1, const void *elem_2)
){

    sllist -> head = NULL;
    sllist -> tail = NULL;
    sllist -> size = 0;
    sllist -> elem_size = elem_size;
    sllist -> destroy = destroy;
    sllist -> compare = compare;
}


void single_linked_list_destroy(SingleLinkedList *sllist){
    if(sllist -> head){
        Node *head = sllist -> head;
        Node *next = NULL;
        while(head){
            next = head -> next;
            if(sllist -> destroy){
                sllist -> destroy(head -> elem);
            }
            free(head);
            head = next;
        }
        sllist -> head = NULL;
        sllist -> tail = NULL;
        sllist -> size = 0;
    }
}


void single_linked_list_insert(
    SingleLinkedList *sllist,
    const void *elem,
    int position)
{
    assert(position >= -1 && position < sllist -> size);

    Node *insert_position = NULL;
    Node *next_position = NULL;
    if(position == -1){
        insert_position = sllist -> tail;
    }else{
        next_position = sllist -> head;
        while(position-- > 0){
            insert_position = next_position;
            next_position = next_position -> next;
        }
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> elem = malloc(sllist -> elem_size);
    new_node -> next = NULL;
    memcpy(new_node -> elem, elem, sllist -> elem_size);

    if(sllist -> head == NULL){ // 链表为空
        sllist -> head = new_node;
        sllist -> tail = new_node;
    }else if(insert_position == NULL){ // 插在头节点前面
        new_node -> next = sllist -> head;
        sllist -> head = new_node;
    }else{
        insert_position -> next = new_node;
        new_node -> next = next_position;
        if(next_position == NULL){
            sllist -> tail = new_node;
        }
    }

    sllist -> size++;
}
