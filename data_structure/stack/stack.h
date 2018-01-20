#ifndef STACK_H
#define STACK_H

typedef struct{
    int size;
    int alloc_size;
    void **datas;
}Stack;

void stack_init(Stack *stk);
void stack_free(Stack *stk);
void stack_push(Stack *stk, void *data);
void *stack_pop(Stack *stk);
void *stack_peek(Stack *stk);

#endif
