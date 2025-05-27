// 93. Write a program to implement Insertion Sort using Array.

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, n);

    printf("Sorted array using Insertion Sort:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
