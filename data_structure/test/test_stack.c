#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"


void destroy_string(void *elem){
    free(*(char **)elem);
}


void test_stack(){
    char *str[] = {"ab", "cd", "ef"};
    Stack stk;
    stack_init(&stk, sizeof(char *), destroy_string);
    for(int i = 0; i < 3; i++){
        char *temp = strdup(str[i]);
        stack_push(&stk, &temp);
        printf("stack_size: %d\n", stack_size(&stk));
    }
    char *temp = NULL;
    for(int i = 0; i < 3; i++){
        stack_pop(&stk, &temp);
        printf("%s\n", temp);
        printf("stack_size: %d\n", stack_size(&stk));
        free(temp);
    }
    stack_destroy(&stk);
}


int main(){
    test_stack();
}
