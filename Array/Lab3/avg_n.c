//18. Write a program to calculate average of first n numbers. 
#include <stdio.h>

void main() {
    int n, i, sum = 0;
    float avg;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        sum += i;
    avg = (float)sum / n;
    printf("Average = %.2f", avg);
}
