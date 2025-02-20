#include <stdio.h>

void swap(int *a, int *b) {                 // Function to swap two elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that chooses a pivot and partitions the array into right and left half, it also assigns pivot the right position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];                     // Choosing the last element as the pivot
    int i = low - 1;             // Index of smaller element; makes space for smaller elements

    for (int j = low; j < high; j++) {               // Traverse through all elements, compare each with the pivot
        if (arr[j] <= pivot) {
            i++;                             //takes i pointer to the actual smaller element
            swap(&arr[i], &arr[j]);            //swaps and pushes all smaller elements to left
        }
    }
    swap(&arr[i + 1], &arr[high]);                   //swaps the pivot with the element next to left half and takes it to the right spot in array
    return i + 1;                                  // Return the partition index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {                         // when low = high; base case, as only one element left to sort
        
        int pi = partition(arr, low, high);            // selects pivot and partitions into right and left half and puts pivot on right spot
        
        quickSort(arr, low, pi - 1);              //quicksort on left half recursively
        quickSort(arr, pi + 1, high);                //quicksort on right half recursively
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {36, 10, 87, 24, 9, 76, 324, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}


// works on pivot and partition
// Time complexity
//Average Case: O(n log n)  ;The partitioning takes O(n) at each level of recursion;  The depth of recursion is O(log n) on average.
//Worst Case: O(n²)    ; when the pivot element is repeately smallest or largest element

