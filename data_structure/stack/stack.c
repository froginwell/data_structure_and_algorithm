#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"


static void stack_grow(Stack *stk);


void stack_grow(Stack *stk){
    stk -> alloc_size *= 2;
    stk -> datas = (void **)realloc(stk -> datas, stk -> alloc_size);
}


void stack_init(Stack *stk){
   stk -> size = 0;
   stk -> alloc_size = 1;
   stk -> datas = (void **)malloc(sizeof(void *) * stk -> alloc_size);
}


void stack_free(Stack *stk){
    free(stk -> datas);
}


void stack_push(Stack *stk, void *data){
    if(stk -> size == stk -> alloc_size){
        stack_grow(stk);
    }
    stk -> datas[stk -> size] = data;
    stk -> size++;
}
    

void *stack_pop(Stack *stk){
    stk -> size--;
    return stk -> datas[stk -> size];
}


void *stack_peek(Stack *stk){
    return stk -> datas[stk -> size - 1];
}
