//19. Position 
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
    printf("MinPos = %d MaxPos = %d", minPos, maxPos);
}
