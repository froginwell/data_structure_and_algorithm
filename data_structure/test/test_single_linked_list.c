#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "single_linked_list.h"


void test1(){
    SingleLinkedList sllist;
    single_linked_list_init(&sllist);

    for(int i = 0; i < 4; i++){
        single_linked_list_append(&sllist, (int *)i);
    }
    printf("size: %d\n", sllist.size);
    Node *head = sllist.head;
    while(head){
        printf("%d\n", (int)(head -> data));
        head = head -> next;
    }
    single_linked_list_free(&sllist);
}


void test2(){
    SingleLinkedList sllist;
    single_linked_list_init(&sllist);

    for(int i = 0; i < 4; i++){
        single_linked_list_append(&sllist, "aa");
    }
    printf("size: %d\n", sllist.size);
    Node *head = sllist.head;
    while(head){
        printf("%s\n", (char *)(head -> data));
        head = head -> next;
    }
    single_linked_list_free(&sllist);
}


int main(){
    test1();
    test2();
}
