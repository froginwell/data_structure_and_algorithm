#ifndef STACK_H
#define STACK_H

typedef struct{
    int elem_size;
    int size;
    int alloc_size;
    void *elems;
    void (*destroy)(void *elem);
}Stack;

void stack_init(Stack *stk, int elem_size, void (*destroy)(void *elem));
void stack_destroy(Stack *stk);
void stack_push(Stack *stk, const void *elem);
void stack_pop(Stack *stk, void *elem);
void stack_peek(Stack *stk, void *elem);
int stack_size(Stack *stk);

#endif
