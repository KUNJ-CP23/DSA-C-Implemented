// 8. Factorial

//without recursion
#include <stdio.h>
void main() {
    int n, i;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        fact *= i;
    }
    printf("Factorial = %d", fact);
}

// with recursion

// #include <stdio.h>

// int factorial(int n) {
//     if(n == 0 || n == 1)
//         return 1;
//     else
//         return n * factorial(n - 1);
// }

// void main() {
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     printf("Factorial = %d", factorial(n));
// }
