#include <stdio.h>

// to merge two sorted subarrays
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;      //size of left array
    int n2 = end - mid;         //size of right array
    
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary array so original array is not altered
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the two sorted subarray back into arr[]
    int i = 0, j = 0, k = start;                      //i= pointer for left array; j= pointer for right array; k= pointer for original array
    while (i < n1 && j < n2) {                 // while i< mid &&  j< end
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];             // add element from left array to original array, so i++
            i++;
        } else {
            arr[k] = rightArr[j];              // add element from right array to original array, so j++
            j++;
        }
        k++;
    }

    // Copy any remaining elements from leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int start, int end) {
    if (start < end) {                         //when more than one elements left in the divided subarray; if s=e then only one element is left in divided half
        int mid = start + (end - start) / 2;

        // Sort left and right halves
        mergeSort(arr, start, mid);                      //base case when single elements left in divided halves, as single element is always sorted
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves
        merge(arr, start, mid, end);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {65, 98, 101, 12, 67, 325};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}


// time complexity= O(n*log n)
//log n because each time array dividen in half
//n divisions to get base case
