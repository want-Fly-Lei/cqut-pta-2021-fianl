#include<cstdio>
using namespace std;
int main() {
    int m1, n1, m2, n2, i, j ,k;
    scanf("%d %d",&m1,&n1);
    int matrix1[m1][n1];
    for(i = 0; i < m1; i++ ) {
        for(j = 0; j < n1; j++) {
            scanf("%d",&matrix1[i][j]);
        }
    }

    scanf("%d %d",&m2,&n2);
    if(m2 != n1) {
        printf("Error: %d != %d\n",n1, m2);
    } else {
        int matrix2[m2][n2];
        for(i = 0; i < m2; i++) {
            for(j = 0; j < n2; j++) {
                scanf("%d",&matrix2[i][j]);
            }
        }

        printf("%d %d\n",m1, n2);
        int temp, len = m1 > n2 ? n2 : n1;
        for(i = 0; i < m1; i++) {
            for(j = 0; j < n2; j++) {
                temp = 0;
                for(k = 0; k < len; k++) {
                    temp += matrix1[i][k] * matrix2[k][j];
                }

                if(j != n2 - 1) {
                    printf("%d ",temp);
                } else {
                    printf("%d\n",temp);
                }
            } 
           
        }

    }
    return 0;
}