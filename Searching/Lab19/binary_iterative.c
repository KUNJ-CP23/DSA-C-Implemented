//binary_iterative Write a program to implement a Binary Search using Array.

#include <stdio.h>

int binarySearchIterative(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int main() {
    int arr[100], n, key, result;

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearchIterative(arr, n, key);
    if(result != -1)
        printf("Element found at index : %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
