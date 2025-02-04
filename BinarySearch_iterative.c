#include <stdio.h>

// perform binary search iteratively
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            left = mid + 1;   //searching in the right half
        else
            right = mid - 1;    //searching in the left half
    }
    
    return -1; //elemant not found
}

int main() {
    int arr[] = {62, 91, 8, 7, 32, 67, 44, 34, 6, 527, 78, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binarySearch(arr, size, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}


// Time Complexity O(nlogn)
// T(n)= T(n/2)+1
