//97. Write a program to implement Counting Sort using Array. 

#include <stdio.h>
#include <string.h> // for memset

void countingSort(int arr[], int n) {
    int output[100];
    int count[100] = {0};
    int max = arr[0];

    // Find the maximum element
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Count occurrences
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Cumulative count
    for(int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[100], n;

    printf("Enter number of elements (non-negative integers): ");
    scanf("%d", &n);

    printf("Enter %d non-negative integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array using Counting Sort:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
