#include <stdio.h>

// get the maximum value in the array to calculate how many times counting sort has to run
int Maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

//Counting Sort on a specific digit (e = 10^i, 1, 10, 100, 1000)
void countingSort(int arr[], int n, int e) {
    int output[n];          // Output array which i later overwrite on original array 
    int count[10] = {0};       // Count array of size 10 as digits vary from 0 to 9 

    // Count number of occurrences of each digit at that place value
    for (int i = 0; i < n; i++)
        count[(arr[i] / e) % 10] = count[(arr[i] / e) % 10] + 1;

    // Update count[i] to store the actual position of the digit in output[] by making cumulative addition of elements of count array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / e) % 10] - 1] = arr[i];
        count[(arr[i] / e) % 10] = count[(arr[i] / e) % 10] - 1;
    }

    // Copy the sorted values to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n) {
    int max = Maximum(arr, n); 

    // Apply Counting Sort for each digit(1, 10, 100, 1000)
    for (int e = 1; max / e > 0; e *= 10)
        countingSort(arr, n, e);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {789, 65, 4, 365, 45, 78, 614, 521, 2, 854, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}


// Time Complexity= O(d*(n+m))
// d: no. of digits (no. of times counting sort runs); n: number of elements in array; m: size of count array, i.e 10 here