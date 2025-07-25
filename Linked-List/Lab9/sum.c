// 51. WAP to calculate the sum of n numbers using Pointer.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i); 

    for (int i = 0; i < n; i++)
        sum += *(arr + i);

    printf("Sum = %d\n", sum);

    free(arr);

    return 0;
}