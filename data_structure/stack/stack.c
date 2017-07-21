#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"


static void stack_grow(Stack *stk);


void stack_grow(Stack *stk){
    stk -> alloc_size *= 2;
    stk -> elems = realloc(stk -> elems, stk -> alloc_size);
    assert(stk -> elems != NULL);
}


void stack_init(Stack *stk, int elem_size, void (*destroy)(void *data)){
   assert(stk != NULL && elem_size > 0);

   stk -> elem_size = elem_size;
   stk -> size = 0;
   stk -> alloc_size = 8;
   stk -> destroy = destroy;
   stk -> elems = malloc(stk -> elem_size * stk -> alloc_size);

   assert(stk -> elems != NULL);
}


void stack_destroy(Stack *stk){
    assert(stk != NULL);

    if(stk -> destroy){
        for(int i = 0; i < stk -> size; i++){
            void *target = (char *)(stk -> elems) + i * (stk -> elem_size);
            stk -> destroy(target);
        }
    }
    free(stk -> elems);
}


void stack_push(Stack *stk, const void *elem){
    assert(stk != NULL && elem != NULL);

    if(stk -> size == stk -> alloc_size){
        stack_grow(stk);
    }
    void *target = (char *)(stk -> elems) + (stk -> size) * (stk -> elem_size);
    memcpy(target, elem, stk -> elem_size);
    stk -> size++;
}
    

void stack_pop(Stack *stk, void *elem){
    assert(stk != NULL && elem != NULL && stk -> size > 0);

    stk -> size--;
    void *source = (char *)(stk -> elems) + (stk -> size) * (stk -> elem_size);
    memcpy(elem, source, stk -> elem_size);
}


void stack_peek(Stack *stk, void *elem){
    assert(stk != NULL && elem != NULL && stk -> size > 0);
    void *source = (char *)(stk -> elems) + (stk -> size - 1) * (stk -> elem_size);
    memcpy(elem, source, stk -> elem_size);
}


int stack_size(Stack *stk){
    assert(stk != NULL);
    return stk -> size;
}
