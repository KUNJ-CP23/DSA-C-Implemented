// 9. Power
#include <stdio.h>

void main() {
    int base, exp, i;
    // lld is for long long digit
    long long result = 1;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    for(i = 1; i <= exp; i++) {
        result *= base;
    }
    printf("Result = %lld\n", result);
}
