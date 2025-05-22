// 16. Read and print the array

#include <stdio.h>

void main() {
    int n, i, a[100];
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array is: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
