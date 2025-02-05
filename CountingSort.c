#include<stdio.h>
#include<stdlib.h>

int maximum(int A[], int n){
    int max = 0;
    for(int i= 0; i<n; i++){
        if (max< A[i]){
            max = A[i];
        }
    }
    return max;
}

void CountingSort(int * A,int n){
    int i, j;
    int max = maximum(A, n);
    int *count = (int *)malloc ((max+ 1)* sizeof(int));             // count array of size max; if max element= 100, size of count array will be 100
    for(i=0; i<n; i++){
        count[i] = 0;             // count array keeps track of number of occurrences of a number; initialised with 0
    }
    for(i=0; i<n; i++){
        count[A[i]]= count[A[i]] + 1;           
    }
    i= 0;
    j= 0;

    while(i<= max){
        if (count[i]> 0){
            A[i] = i;
            count[i] = count[i] -1;
            j++;
         }
         else{
            i++;
         }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {129, 56, 78, 32, 210, 3, 78, 321};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    CountingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

// Time Complexity= O(m+n) = O(n)     ; m= traversal of original array; n= traversal of count array
