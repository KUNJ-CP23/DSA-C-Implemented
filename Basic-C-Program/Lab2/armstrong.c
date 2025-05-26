// 15.Armstrong
#include <stdio.h>

void main() {
    int i, num, sum, rem, temp;
    for(i = 1; i <= 1000; i++) {
        num = i;
        sum = 0;
        temp = num;
        while(temp != 0) {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }
        if(sum == num)
            printf("%d ", num);
    }
}
