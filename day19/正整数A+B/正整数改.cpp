#include <iostream>
using namespace std;

char A[20], B[20];

int main(){
    int a = 0, b = 0;
    int fa = 1, fb = 1;
    scanf("%s", &A);
    getchar();
    cin.getline(B, 100);
    for(int i = 0; A[i] != '\0'; i++)
        if(A[i] < '0' || A[i] > '9'){
            fa = 0;
            break;
        }
    for(int i = 0; B[i] != '\0'; i++)
        if(B[i] < '0' || B[i] > '9'){
            fb = 0;
            break;
        }
    if(fa){
        for(int i = 0; A[i] != '\0'; i++)
            a = a * 10 + (A[i] - '0');
        if(a < 1 || a > 1000) fa = 0;
    }
    if(fb){
        for(int i = 0; B[i] != '\0'; i++)
            b = b * 10 + (B[i] - '0');
        if(b < 1 || b > 1000) fb = 0;
    }
    if(fa && fb) printf("%d + %d = %d", a, b, a+b);
    else if(fa) printf("%d + ? = ?", a);
    else if(fb) printf("? + %d = ?", b);
    else printf("? + ? = ?");
    return 0;
}
