#include<stdlib.h>
#include<stdio.h>


void shell_sort(int a[], int length){
    // 采用 (3^k - 1) / 2 {k = 1, 2, 3, ...} 序列，即 An = 3 * An-1 + 1, A0 = 1
    int step = 1;
    while(step < length){
        step = step * 3 + 1;
    }
    while(step /= 3){
        for(int start = step; start < length; start++){
            int temp = a[start];
            int i = start - step;
            for(; i >= 0 && temp < a[i]; i -= step){
                a[i + step] = a[i];
            }
            a[i + step] = temp;
        }
    }
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    shell_sort(a, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
