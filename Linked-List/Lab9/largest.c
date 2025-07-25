// 52. WAP to find the largest element in the array using Pointer. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    int max = *arr;
    for (int i = 0; i < n; i++)
        if (*(arr + i ) > max)
            max = *(arr + i);

    printf("Largest element: %d\n", max);

    free(arr);
    
    return 0;
}