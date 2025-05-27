// 98. Write a program to implement Radix Sort using Array. 

#include <stdio.h>

// Get maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort by digit (exp = 1, 10, 100, etc.)
void countingSortByDigit(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    // Count digit occurrences
    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (from end to maintain stability)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(arr, n, exp);
}

int main() {
    int arr[100], n;

    printf("Enter number of elements (non-negative integers): ");
    scanf("%d", &n);

    printf("Enter %d non-negative integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("Sorted array using Radix Sort:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
