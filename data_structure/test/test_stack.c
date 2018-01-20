#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"


void test_int(){
    Stack stk;
    stack_init(&stk);
    stack_push(&stk, (void *)1);
    stack_push(&stk, (void *)2);
    printf("stack_size: %d\n", stk.size);
    printf("%d\n", (int)stack_pop(&stk));
    printf("%d\n", (int)stack_pop(&stk));
    printf("stack_size: %d\n", stk.size);
    stack_free(&stk);
}


void test_string(){
    Stack stk;
    stack_init(&stk);
    stack_push(&stk, "abc");
    stack_push(&stk, "def");
    printf("stack_size: %d\n", stk.size);
    printf("%s\n", (char *)stack_pop(&stk));
    printf("%s\n", (char *)stack_pop(&stk));
    printf("stack_size: %d\n", stk.size);
    stack_free(&stk);
}


int main(){
    test_int();
    test_string();
}
