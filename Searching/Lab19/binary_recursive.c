// binary_recursive 90. Write a program to implement a Binary Search using Array.

#include <stdio.h>
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
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

    result = binarySearchRecursive(arr, 0, n - 1, key);
    if(result != -1)
        printf("Element found at index : %d\n", result);
    else
        printf("Element not found \n");

    return 0;
}
