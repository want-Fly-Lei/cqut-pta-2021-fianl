#include<stdio.h>
#include<string.h>
int main() {
    int len, i;
    scanf("%d",&len);
    char name[3];
    const int maxBreathe = 20, minBreathe = 15, maxPulse = 70, minPulse = 50;
    int breathe, pulse;
    for(i = 0; i < len; i++) {
        scanf("%s %d %d",&name,&breathe,&pulse);
        if(breathe > maxBreathe || breathe < minBreathe || pulse > maxPulse || pulse < minPulse) {
            printf("%s\n",name);
        }
    }
    return 0;
}