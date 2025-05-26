//2. Check number is even or odd
#include<stdio.h>
void main(){
	int num;
	printf("Enter the value of num = ");
	scanf("%d",&num);
	if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}