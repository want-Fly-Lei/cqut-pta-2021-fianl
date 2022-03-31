#include <stdio.h>
#include<string.h>
#define maxn 1000005
typedef long long LL;
char s[maxn];
LL dp[maxn][4];
int pos[30];

int main(){
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int i, j, tmp;
    for (i = 0; i <= len; ++i) {
        dp[i][0] = 1;
    }
        
    for (i = 1; i <= len; ++i){
        tmp = pos[s[i] - 'a'];
        pos[s[i] - 'a'] = i;
        for (j = 1; j <= 3; ++j){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            if (j - (i - tmp) >= 0) {
                dp[i][j] -= dp[tmp - 1][j - (i - tmp)];
            } 
        }
    }
    
    printf("%lld\n", dp[len][0] + dp[len][1] + dp[len][2] + dp[len][3]);
    return 0;
}