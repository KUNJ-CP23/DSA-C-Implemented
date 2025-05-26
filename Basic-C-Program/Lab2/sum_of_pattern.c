// 14. Sum of pattern 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n)
#include <stdio.h>

void main() {
    int n, i, j, sum = 0, temp;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        temp = 0;
        for(j = 1; j <= i; j++) {
            temp += j;
        }
        sum += temp;
    }
    printf("Sum = %d", sum);
}
