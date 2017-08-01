#include<stdio.h>
#include<stdlib.h>


int partation(int a[], int low, int high){
    int mid = a[low];
    int i = low + 1;
    int j = high;
    while(i <= j){
        while(i <= high && a[i] <= mid){
            i++;
        }
        while(j > low && a[j] > mid){
            j--;
        }
        if(j > i){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    int temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}


void _quick_sort(int a[], int low, int high){
    if(low >= high){
        return;
    }
    int mid = partation(a, low, high);
    _quick_sort(a, low, mid - 1);
    _quick_sort(a, mid + 1, high);
}


void quick_sort(int a[], int length){
    if(!a || length <= 1){
        return;
    }

    int low = 0;
    int high = length - 1;
    _quick_sort(a, low, high);
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    quick_sort(a, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
