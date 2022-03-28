#include <stdio.h>
#include <string.h>

int s[25][25], a[25], v[25], n, f = 0;

void dfs(int t, int id){
    if (f == 1) {
        return ;
    }
        
    a[id] = t;
    if (id == n - 1){
        if (s[t][0] == 1) {
            f = 1;
        } 
        return ;
    }

    int f = 1, i;
    for (i = 1; i < n; i++) {
        if (!v[i] && s[i][0]) {
            f = 0;
        }  
    }
        
    if (f) {
        return ;
    }
        
    for (i = 1; i < n; i++) {
        if (v[i] == 0 && s[t][i] == 1) {
             v[i] = 1, dfs(i, id + 1), v[i] = 0;
        }
    }     
}

int main(){
    int i, i1;
    char ss[21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", ss);
        for (int j = 0; j < n; j++) {
            if (ss[j] == 'W') {
                 s[i][j] = 1;
            }else if (ss[j] == 'L') {
                 s[j][i] = 1;
            }
        }
            
    }

    v[0] = 1, dfs(0, 0);
    if (f == 1){
        printf("%d", a[0] + 1);
        for (i = 1; i < n; i++) {
            printf(" %d", a[i] + 1);
        }
    } else {
        printf("No Solution");
    }
    return 0;
}
