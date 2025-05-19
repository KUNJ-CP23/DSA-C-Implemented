// 27. Delete in sorted
#include <stdio.h>

void main() {
    int a[100], n, i, val, found = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter value to delete: ");
    scanf("%d", &val);
    for(i = 0; i < n; i++) {
        if(a[i] == val) {
            found = 1;
            break;
        }
    }
    if(found) {
        for(; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }     
}
