#include<stdio.h>
#define MAXSIZE 101
int main(){
    int arr[MAXSIZE][MAXSIZE];
    int m,n,i,j,k;
    int flag,flag2;
    while(scanf("%d %d",&m,&n) != EOF) {
        flag = 0;
      for(i = 0; i < m; i++) {
          for(j = 0; j < n; j++) {
              scanf("%d",&arr[i][j]);
          }
      }

      for(i = 0; i < m; i++) {
          for(j = 0; j < n; j++) {
              flag2 = 0;
              //同一列对比
              for(k = 0; k < m; k++){
                  if(arr[i][j] > arr[k][j]){
                      flag2 = 1;
                      break;
                  }
              }
              //同一行对比
              for(k = 0; k < n; k++) {
                  if(flag2) {
                      break;
                  }
                  if(arr[i][j] < arr[i][k]) {
                      flag2 = 1;
                      break;
                  }
              }
              if(!flag2) {
                  printf("%d %d %d\n",arr[i][j],i,j);
                  flag = 1;
              }
          }
      }  
      if(flag == 0) {
          printf("Not\n");
      }
    }
    return 0;
}
