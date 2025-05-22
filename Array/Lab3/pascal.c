//22. Pascal
#include <stdio.h>

void main() {
    int n, i, j, num, spc;
    printf("Enter rows: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        for(spc = 0; spc < n - i - 1; spc++)
            printf("  ");
        num = 1;
        for(j = 0; j <= i; j++) {
            printf("%4d", num);
            num = num * (i - j) / (j + 1);
        }
        printf("\n");
    }
}
