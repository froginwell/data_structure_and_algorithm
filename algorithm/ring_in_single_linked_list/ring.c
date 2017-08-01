#include<stdlib.h>
#include<stdio.h>
#include "single_linked_list.h"


void ring(SingleLinkedList *sllist){
    if(sllist -> head == NULL){
        return;
    }

    Node *slow = sllist -> head;
    int i = 0;
    Node *fast = sllist -> head;
    int j = 0;

    int has_ring = 0;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        i++;

        fast = fast -> next -> next;
        j += 2;

        if(slow == fast){
            has_ring = 1;
            break;
        }
    }

    if(has_ring == 1){
        printf("ring: %d\n", *(int *)(slow -> elem));
    }

    // 环长
    int k = 0;
    while(1){
        slow = slow -> next;
        fast = fast -> next -> next;
        k++;
        if(slow == fast){
            break;
        }
    }
    printf("ring_length: %d\n", k);

    // 非环部分长度
    int m = 0;
    // 相交点
    Node *temp = sllist -> head;
    fast = sllist -> head;
    while(slow != fast){
        m++;
        slow = slow -> next;
        fast = fast -> next;
        temp = fast;
    }
    printf("non_ring_length: %d\n", m);
    printf("intersection_point: %d\n", *(int *)(temp -> elem));
}


void destroy(void *elem){
    free(elem);
}


int main(){
    SingleLinkedList sllist;
    single_linked_list_init(&sllist, sizeof(int), destroy, NULL);
    for(int i = 0; i < 100; i++){
        single_linked_list_insert(&sllist, &i, -1);
    }
    Node *head = sllist.head;
    Node *temp = NULL;
    int i = 0;
    while(head){
        i++;
        if(i == 50){
            temp = head;
        }
        printf("%d ", *(int *)(head -> elem));
        head = head -> next;
    }
    printf("\n");
    sllist.tail -> next = temp;
    ring(&sllist);
}
