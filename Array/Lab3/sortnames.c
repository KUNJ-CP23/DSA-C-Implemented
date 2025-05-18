//23. Sort names
#include <stdio.h>
#include <string.h>

void main() {
    int n, i, j;
    char name[100][50], temp[50];
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%s", name[i]);
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strcmp(name[i], name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }
    for(i = 0; i < n; i++)
        printf("%s ", name[i]);
}
