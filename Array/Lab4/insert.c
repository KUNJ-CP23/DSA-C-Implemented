// 24. insert in array
#include <stdio.h>

void main() {
    int a[100], n, i, pos, val;
    printf("Enter size: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter position and value: ");
    scanf("%d %d", &pos, &val);
    for(i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = val;
    n++;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
