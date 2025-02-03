#include <stdio.h>

//recursive function for binary search
int binarySearchRecursive(int arr[], int left, int right, int target) {

    if (left<=right){
        int mid = left + (right - left)/2;
        if( arr[mid] == target ){
            return mid;
            }
        if( arr[mid]> target){
            return binarySearchRecursive(arr, left, mid - 1, target);    //search left half
        }
        return binarySearchRecursive(arr, mid+1, right, target);   //search right half
        
    }
    return -1;   // element not found
}

int main() {
    int arr[] = {45, 89, 12, 7, 35, 456, 75, 12, 1, 82};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 82;

    int result = binarySearchRecursive(arr, 0, size - 1, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}


// Time Complexity O(nlogn)
// T(n)= T(n/2)+1
