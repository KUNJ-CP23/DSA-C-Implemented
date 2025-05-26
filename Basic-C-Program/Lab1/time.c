// 6.Convert time to second
#include <stdio.h>

void main() {
    int seconds, h, m, s;
    printf("Enter seconds: ");
    scanf("%d", &seconds);

    h = seconds / 3600;
    seconds = seconds % 3600;
    m = seconds / 60;
    s = seconds % 60;

    printf("Time : %02d:%02d:%02d", h, m, s);
}
