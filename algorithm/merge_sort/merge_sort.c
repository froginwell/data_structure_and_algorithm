#include<stdio.h>
#include<stdlib.h>


void _merge(int a[], int start, int mid, int end){
    int length = end - start + 1;
    int *temp = (int *)malloc(sizeof(int) * length);
    int k = 0;
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= end){
        temp[k++] = a[j++];
    }
    for(i = 0; i < k; i++){
        a[start++] = temp[i];
    }
    free(temp);
}


void _merge_sort(int a[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        _merge_sort(a, start, mid);
        _merge_sort(a, mid + 1, end);
        _merge(a, start, mid, end);
    }
}


void merge_sort(int a[], int length){
    _merge_sort(a, 0, length - 1);
}


void merge_sort_from_bottom_to_top(int a[], int length){
    for(int step = 1; step < length; step *= 2){
        for(int i = 0; i < length - step; i += step * 2){
            int end = i + step * 2;
            if(end > length){
                end = length;
            }
            _merge(a, i, i + step - 1, end - 1);
        }
    }
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    // merge_sort(a, 5);
    merge_sort_from_bottom_to_top(a, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
