// 8. Factorial

//without recursion
#include<stdio.h> 
 
void main(){ 
    int number; 
    int ans = 1; 
     
    printf("Enter Number = "); 
    scanf("%d",&number); 
     
    for(int i = number;i>=1;i--){ 
        ans = ans*i; 
    } 
     
    printf("Factorial of %d is = %d",number,ans); 
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
