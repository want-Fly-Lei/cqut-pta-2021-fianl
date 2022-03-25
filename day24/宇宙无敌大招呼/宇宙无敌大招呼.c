#include<stdio.h>
#include<string.h>
char name[1024];
int main() {
    fgets(name,1024,stdin);
    printf("Hello %s",name);
    return 0;
}