// 14. Sum of pattern 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n)
#include <stdio.h> 
 
void main() { 
    int num; 
    int totalSum = 0; 
 
    printf("Enter the value of n: "); 
    scanf("%d", &num); 
    int j=0;
    for (int i = 1; i <= num; i++) { 
        int sum = 0; 
        for (j = 1; j <= i; j++) { 
            sum += j;   
        } 
        totalSum += sum; 
    } 
         
    printf("Sum of the series is: %d\n", totalSum); 
} 
 