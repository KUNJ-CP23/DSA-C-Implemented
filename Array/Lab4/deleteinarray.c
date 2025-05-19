// 25. Delete
#include <stdio.h>
void main() {
    int a[100], n, i, pos;
    printf("Enter size: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    for(i = pos; i < n - 1; i++){
        a[i] = a[i + 1];
    }
    n--;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
