// 26. Insert in sorted array 
#include <stdio.h>

void main() {
    int a[100], n, i, val, pos = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    while(pos < n && a[pos] < val)
        pos++;
    for(i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = val;
    n++;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
