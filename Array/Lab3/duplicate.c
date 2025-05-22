//20. Write a program to find whether the array contains a duplicate number or not
#include <stdio.h>
void main() {
    int n, a[100], i, j, found = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                found = 1;
                break;
            }
        }
    }
    if(found==1)
        printf("Duplicate found");
    else
        printf("No duplicate");
}
