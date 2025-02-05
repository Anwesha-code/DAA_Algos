#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for(i =0 ; i< n-1; i++){            //i= tracks sorted part; j= tracks unsorted part; minindex= minimum element found yet in unsorted part
        minIndex = i;
        for(j= i+1; j<n; j++){                    //finds minimum element in unsorted part
            if(arr[j]< arr[minIndex]){ 
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex]= arr[i];            // swaps minimum element with current element arr[i]
        arr[i]= temp;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {78, 91, 45, 12, 56, 985, 32, 123, 65, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}


// Time complexity= O(n^2)
//Best case= O(n^2)
//Average case= O(n^2)
//worst case= O(n^2)
