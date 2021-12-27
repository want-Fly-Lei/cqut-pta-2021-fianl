#include<stdio.h>
#define SIZE 101
#define LEN 3
int main(){
    int n,i,j,count;
    int arr[SIZE];
    while(scanf("%d",&n) != EOF){
        for(i = 0; i < n;i++) {
            arr[i] = i + 1;
        }
        count = 0;
        i = -1;
        while(1) {
            for(j = 0; j < LEN; j++) {
                i = (i + 1) % n;
                while(arr[i] == 0) {
                 i = (i + 1) % n;
                }
            }
            if (count == n - 1) {
               printf("%d\n",arr[i]);
               break;
           }
           arr[i] = 0;
           //printf("%d out ", i + 1);
            ++count;
        }
    }
    return 0;
}