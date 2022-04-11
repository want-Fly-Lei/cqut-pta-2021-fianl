#include <stdio.h>
#include <string.h>
#define SIZE 82

int main() {
    int N;
    scanf("%d\n", &N);
    char psw[SIZE];
    int ln, zm, sz, di, yu, i;
    while (N--){
        fgets(psw, SIZE, stdin);
        ln = strlen(psw) - 1;
        if (ln < 6) {
            puts("Your password is tai duan le.");
        } else {
            zm = sz = di = yu = 0;
            for (i = 0; i < ln; i++) {
                if ((psw[i] >= 'a' && psw[i] <= 'z') || (psw[i] >= 'A' && psw[i] <= 'Z')) {
                    ++zm; //有字母
                } else if (psw[i] >= '0' && psw[i] <= '9') {
                    ++sz; //有数字
                } else if (psw[i] == '.') {
                    ++di; //有点
                } else {
                    ++yu; //有杂质
                }
            }

            if (yu) {
                puts("Your password is tai luan le.");
            } else if (sz == 0) {
                puts("Your password needs shu zi.");
            } else if (zm == 0){
                puts("Your password needs zi mu.");
            } else {
                puts("Your password is wan mei.");
            }
        }
    }

    return 0;
}