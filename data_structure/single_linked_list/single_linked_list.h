#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

typedef struct _Node{
    void *data;
    struct _Node *next;
}Node;
typedef struct {
    Node *head;
    Node *tail;
    int size;
} SingleLinkedList;

void single_linked_list_init(SingleLinkedList *sllist);
void single_linked_list_free(SingleLinkedList *sllist);
void single_linked_list_append(
    SingleLinkedList *sllist,
    const void *data
);

#endif
