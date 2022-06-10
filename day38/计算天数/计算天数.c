#include <stdio.h>
int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    int year, month, day;
    int i;
    scanf("%d %d",&year, &month);
    if (month < 2) {
        printf("%d",months[0]);
    } else {
        for (i = 0; i < month; i++) {
            day += months[i];
        }
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            ++day;
        }
        printf("%d",day);
    }
    return 0;
}