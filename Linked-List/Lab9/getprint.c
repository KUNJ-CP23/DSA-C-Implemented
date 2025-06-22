// 50. WAP to get and print the array elements using Pointer.

#include <stdio.h>

int main() {
    int arr[5], *ptr = arr;

    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    printf("Array elements are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
