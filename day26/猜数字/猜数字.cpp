#include<cstdio>
using namespace std;
using ull = unsigned long long;

class student {
    public:
    char name[10];
    int guessNum;
};

int abs(ull num1, ull num2) {
    return num1 > num2 ? num1 - num2 : num2 - num1;
}

int main() {
    int n, i, j = 0;
    scanf("%d",&n);
    student s[n];
    ull sum = 0, min;
    for(i = 0; i < n;i++) {
        scanf("%s %d",&s[i].name,&s[i].guessNum);
        sum += s[i].guessNum;
    }
    
    sum /= 2;
    min = abs(sum, s[0].guessNum * n);

    for(i = 1;i < n; i++) {
        if(min > abs(s[i].guessNum * n,sum)) {
            min = abs(s[i].guessNum * n,sum);
            j = i;
        }
    }
    printf("%llu %s",sum / n,s[j].name);
    return 0;
}