// 28. Delete duplicate numbers from array
#include <stdio.h>

void main() {
    int a[100], n, i, j, k;
    printf("Enter size: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; ) {
            if(a[i] == a[j]) {
                for(k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
