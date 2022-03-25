#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode{
    ElementType Data;
    Position parent;
    BinTree Left;
    BinTree Right;
};

void InsertTree(BinTree &T, int k){
    if (!T){
        T = (BinTree)malloc(sizeof(TNode));
        T->Data = k;
        T->Left = T->Right = T->parent = NULL;
        // printf("%d\n",T->Data);
    } else{
        // printf("1111111111111111\n");
        Position p = T;
        Position pre = NULL;

        while (p){
            pre = p;
            if (p->Data < k) {
                p = p->Right;
            } else {
                p = p->Left;
            }   
        }

        p = (Position)malloc(sizeof(TNode));
        p->Data = k;
        p->Left = p->Right = NULL;
        p->parent = pre;
        if (pre->Data > k) {
            pre->Left = p;
        } else if (pre->Data < k) {
            pre->Right = p;
        } else {
            return;
        }  
    }
}

Position Search(BinTree T, int k){
    Position p = T;
    while (p){
        if (p->Data > k) {
            p = p->Left;
        } else if (p->Data < k) {
            p = p->Right;
        } else {
            return p;
        }  
    }
    return NULL;
}

int GetNumber(BinTree T, int k){
    int sum = 1;
    Position p = T;
    while (p){
        if (p->Data > k) {
            p = p->Left;
        } else if (p->Data < k) {
            p = p->Right;
        } else {
            return sum;
        }   
        sum++;
    }
    return INF;
}

int main(){
    BinTree T = NULL;
    int n, m;
    scanf("%d", &n);
    int v;
    for (int i = 0; i < n; i++){
        scanf("%d", &v);
        InsertTree(T, v);
    }

    scanf("%d", &m);
    getchar();
    char s[110];
    int v1, v2;
    for (int i = 0; i < m; i++){
        scanf("%d %s", &v1, s);
        if (!strcmp(s, "is")){
            scanf("%s", s);
            scanf("%s", s);

            if (!strcmp(s, "root")){
                if (T && T->Data == v1) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
                continue;
            } else if (!strcmp(s, "left")){
                Position p1 = Search(T, v1);
                scanf("%s", s);
                scanf("%s %d", s, &v2);
                Position p2 = Search(T, v2);
                if (p2 && p1 && p2->Left == p1) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }   
            } else if (!strcmp(s, "right")){
                Position p1 = Search(T, v1);
                scanf("%s", s);
                scanf("%s %d", s, &v2);
                Position p2 = Search(T, v2);
                if (p2 && p1 && p2->Right == p1) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }   
            } else if (!strcmp(s, "parent")){
                Position p1 = Search(T, v1);
                scanf("%s %d", s, &v2);
                Position p2 = Search(T, v2);
                if (p2 && p1 && p2->parent == p1) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        } else if (!strcmp(s, "and")){
            scanf("%d %s", &v2, s);
            scanf("%s", s);
            if (!strcmp(s, "siblings")){
                Position p1 = Search(T, v1);
                Position p2 = Search(T, v2);
                if (p1 && p2 && p1->parent == p2->parent) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                } 
            } else if (!strcmp(s, "on")){
                scanf("%s", s);
                scanf("%s", s);
                scanf("%s", s);
                int n1 = GetNumber(T, v1);
                // printf("%d\n",n1);
                int n2 = GetNumber(T, v2);
                if (n1 == n2 && n1 != INF) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}