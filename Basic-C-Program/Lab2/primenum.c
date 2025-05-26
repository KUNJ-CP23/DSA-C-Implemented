// 12. Prime number
#include <stdio.h>

void main() {
    int n, i, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i = 2; i <= n / 2; i++) {
        if(n % i == 0)
            count++;
    }
    if(n <= 1)
        printf("Not a prime number\n");
    else if(count == 0)
        printf("Prime number\n");
    else
        printf("Not a prime number\n");
}
