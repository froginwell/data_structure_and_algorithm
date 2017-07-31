#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

typedef struct _Node{
    void *elem;
    struct _Node *next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
    int elem_size;
    void (*destroy)(void *elem);
    int (*compare)(const void *elem_1, const void *elem_2);
}SingleLinkedList;

void single_linked_list_init(
    SingleLinkedList *sllist,
    int elem_size,
    void (*destroy)(void *elem),
    int (*compare)(const void *elem_1, const void *elem_2)
);
void single_linked_list_destroy(SingleLinkedList *sllist);
void single_linked_list_insert(
    SingleLinkedList *sllist,
    const void *elem,
    int position);
void single_linked_list_delete(SingleLinkedList *sllist, const void *elem);
int single_linked_list_search(SingleLinkedList *sllist, const void *elem);

#endif
