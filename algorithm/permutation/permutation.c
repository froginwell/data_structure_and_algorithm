#include<stdio.h>


void swap(char a[], int i, int j){
    if(i != j){
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}


void permutation(char a[], int length, int start){
    if(a == NULL || length < 0 || start < 0){
        return;
    }

    if(start == length - 1){
        printf("%s\n", a);
    }

    for(int i = start; i < length; i++){
        int has_seen = 0;
        for(int k = start; k < i; k++){
            if(a[i] == a[k]){
                has_seen = 1;
            }
        }
        if(has_seen == 0){
            swap(a, start, i);
            permutation(a, length, start + 1);
            swap(a, start, i);
        }
    }
}


int main(){
    char a[] = {'A', 'A', 'B', 'B'};
    permutation(a, 4, 0);
}
