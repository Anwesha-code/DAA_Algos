#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;    // largest element is supposed to be root
    int left = 2 * i + 1;    // to access Left child
    int right = 2 * i + 2;    // to accessRight child

    if (left < n && arr[left] > arr[largest]){         // If left child is larger than root
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]){     // If right child is larger than largest 
        largest = right;
    }

    if (largest != i) {              // If largest is not root, then swap it and make it root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);         // heapify the affected subtree (recursively)
    } 
}


void heapSort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--){            // Build max heap
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {         // Extract elements from heap one by one, starting from last element and moving to first       
        int temp = arr[0];
        arr[0] = arr[i];                     // swap root with last element and reduce heap size everytime 
        arr[i] = temp;

        heapify(arr, i, 0);       // heapify the tree
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {62, 91, 20, 9, 234, 45, 37, 57};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}


// Heap Construction	O(n)      (Each heapify() operation takes O(log n) time. There are O(n) nodes to heapify.)
// Heap Extraction	O(n log n)     (Each extraction involves swapping the root with the last element and calling heapify(), which takes O(log n) time)
// Total time complexity     O(n log n)