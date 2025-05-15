// 7. Convert days into year,month and day
#include <stdio.h>
void main() {
    int days, years, weeks;
    printf("Enter number of days: ");
    scanf("%d", &days);

    years = days / 365;
    days = days % 365;
    weeks = days / 7;
    days = days % 7;

    printf("%d year, %d weeks, %d days", years, weeks, days);
}
