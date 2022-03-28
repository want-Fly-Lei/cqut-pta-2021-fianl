#include <stdio.h>
int main(){
    int week, hour, min, n, i;
    int newWeek, newHour, newMin, myTime;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d %d:%d", &week, &hour, &min);
        if (week == 0){
            printf("%d %02d:%02d\n", week, hour, min);
        } else {
            //第一天并未满一天，所以减一
            myTime = ((week - 1) * 24 + hour) * 30 + min / 2;
            newWeek = myTime / 1440;
            myTime -= newWeek * 1440;
            newHour = myTime / 60;
            newMin = myTime - newHour * 60;
            //同样需要补一天
            printf("%d %02d:%02d\n", newWeek + 1, newHour, newMin);
        }
    }
    return 0;
}