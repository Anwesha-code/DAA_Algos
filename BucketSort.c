#include <stdio.h>

#define BUCKETS 10       // Number of buckets
#define MAX 100      // Maximum value that an element the array can have

void bucketSort(int arr[], int n) {
    int buckets[BUCKETS][MAX];      // Buckets as a 2D array, where each row is bucket storing elements
    int count[BUCKETS] = {0};            // number or count of elements in each bucket, initialised with 0

    // to determine the range for each bucket
    int max = arr[0];        // max value in array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int range = (max/ BUCKETS) + 1;          //computes range of value each bucketb will hold; ensures that the values are evenly distributed

    // Insert elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / range;                //  Finds the bucket index ; in which bucket element must be inserted
        buckets[bucketIndex][count[bucketIndex]++] = arr[i];    //insert element in that bucket    ; also increments value of count
    }

    // Sort each bucket using INSERTION SORT
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 1; j < count[i]; j++) {
            int key = buckets[i][j];                  //stores the current element
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];             //moves elements greater than key one position forward
                k--;
            }
            buckets[i][k + 1] = key;           // insert key to right place
        }
    }

    // Iterates through each bucket and moves the sorted values back into arr[]
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
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
    int arr[] = {65, 98, 78, 12, 4, 23, 52, 106, 91, 86};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

//Time complexity
//Best Case (ohm(n + k))  n= no. of elements; k= number of buckets
//input elements are uniformly distributed across the buckets. Each bucket contains very few elements. Insertion Sort (or any sorting method) runs in O(1) per bucket.


//Average Case (theta(n + k))

//Worst Case (O(n^2))
//If all elements fall into a single bucket, Bucket Sort degrades to Insertion Sort. Sorting one large bucket with n elements takes O(n²).