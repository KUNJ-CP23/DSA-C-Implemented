//19. Write a program to find position of mallest number & largest number from given n numbers.
#include <stdio.h>

void main() {
    int n, a[100], i, min, max, minPos, maxPos;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    min = max = a[0];
    minPos = maxPos = 0;
    for(i = 1; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
            minPos = i;
        }
        if(a[i] > max) {
            max = a[i];
            maxPos = i;
        }
    }
    //gives zero based index position
    printf("MinPosition = %d MaxPosition = %d", minPos, maxPos);
}
