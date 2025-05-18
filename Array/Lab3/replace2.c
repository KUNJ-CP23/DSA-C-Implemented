//21. Replace

#include <stdio.h>
void main() {
    int n, a[100], i, x, y;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter number to replace and replacement: ");
    scanf("%d %d", &x, &y);
    for(i = 0; i < n; i++) {
        if(a[i] == x) {
            a[i] = y;
            printf("Index = %d ", i);
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
