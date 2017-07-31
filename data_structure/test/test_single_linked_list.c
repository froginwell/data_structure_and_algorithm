#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "single_linked_list.h"


void destroy(void *elem){
    free(elem);
}


void test(){
    SingleLinkedList sllist;
    single_linked_list_init(&sllist, sizeof(int), destroy, NULL);
    for(int i = 0; i < 4; i++){
        single_linked_list_insert(&sllist, &i, -1);
    }
    int j = 100;
    printf("size: %d\n", sllist.size);
    single_linked_list_insert(&sllist, &j, 0);
    printf("size: %d\n", sllist.size);
    Node *head = sllist.head;
    while(head){
        printf("%d\n", *(int *)(head -> elem));
        head = head -> next;
    }
    single_linked_list_destroy(&sllist);
}


int main(){
    test();
}
