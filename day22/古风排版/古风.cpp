#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int N,len=0,i,j,x;
        char s[1100];
        //memset(s,0,1100);
        scanf("%d",&N);
        getchar();
        while((s[len]=getchar())!='\n'){
            ++len;
        }
//         gets(s);
//         len = strlen(s);
        if(len%N!=0){
            for(i=0,x=len;i<N-len%N;i++) {
                 s[x++]=' ';
            }
        } else {
            x=len;
        } 
        for(i=0;i<N;i++){
            for(j=x/N-1;j>=0;j--) {
                printf("%c",s[j*N+i]);
            }
        printf("\n");
        }
}
