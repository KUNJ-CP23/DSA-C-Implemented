// 13. Prime Number in interval
#include <stdio.h> 
#include <math.h> 
 
int prime(int n){ 
    if(n<2) return 0; 
    int i = 2; 
    int root = (int)(pow(n,0.5)); 
    while(i <= root){ 
        if(n%i == 0){ 
            return 0; 
        } 
        i++; 
    } 
    return 1; 
} 
 
void primeRange(int low, int high){ 
    if(low > high){ 
        int temp = low; 
        low = high; 
        high = temp; 
    } 
    int count = 0; 
    while(low<=high){ 
        int isPrime = prime(low); 
        if(isPrime == 1){ 
            printf("%d, ",low); 
            count++; 
        } 
        low++; 
    } 
 
    if(count == 0){ 
        printf("\nNo prime number found!"); 
    } 
    else printf("\b\b "); 
} 
 
void main(){ 
    int high, low; 
    printf("Enter lowerBound and upperbound (space seperated):\n"); 
    scanf("%d %d",&low,&high); 
    primeRange(low,high); 
} 
