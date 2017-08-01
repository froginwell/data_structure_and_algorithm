#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


/*
 * 大顶堆
 */
void heap_adjust_from_top_to_bottom(int a[], int length, int k){
    assert(k >= 0 && k < length);

    while((2 * k + 1) < length){
        int bigger = 2 * k + 1;
        if((bigger + 1) < length && a[bigger + 1] > a[bigger]){
            bigger = bigger + 1;
        }
        if(a[k] < a[bigger]){
            int temp = a[k];
            a[k] = a[bigger];
            a[bigger] = temp;
            k = bigger;
        }else{
            break;
        }
    }
}


void heap_adjust_from_bottom_to_top(int a[], int length, int k){
    assert(k >= 0 && k < length);

    while((k - 1) / 2 >= 0){
        int parent = (k - 1) / 2;
        if(a[parent] < a[k]){
            int temp = a[parent];
            a[parent] = a[k];
            a[k] = temp;
            k = parent;
        }else{
            break;
        }
    }
}


void heap_sort(int a[], int length){
    for(int i = (length - 2) / 2; i >= 0; i--){
        heap_adjust_from_top_to_bottom(a, length, i);
    }
    for(int i = length - 1; i > 0; i--){
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heap_adjust_from_top_to_bottom(a, i, 0);
    }
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    heap_sort(a, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
