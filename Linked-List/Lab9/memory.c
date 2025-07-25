// 49. WAP to allocate and de-allocate memory for int, char and float variable at runtime. 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *iptr = (int *)malloc(sizeof(int));
    char *cptr = (char *)malloc(sizeof(char));
    float *fptr = (float *)malloc(sizeof(float));

    if (iptr && cptr && fptr) {
        *iptr = 9;
        *cptr = 'K';
        *fptr = 15.25;

        printf("Integer: %d\n", *iptr);
        printf("Character: %c\n", *cptr);
        printf("Float: %.2f\n", *fptr);
        
        free(iptr);
        free(cptr);
        free(fptr);
    }
    else{
        printf("Memory Allocation Failed! \n");
    }
    return 0;
}