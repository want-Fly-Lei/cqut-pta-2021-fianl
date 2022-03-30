#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include<iostream>
#define MAX_N 500
using namespace std;

// 我觉得真麻烦，我vscode一键直接格式化了直接开抄；

// else及{} 特殊处理，其他的for、while、if可归为一种  均是for/while/if + () + { }
//采用边处理边输出的方式

//判断语句块类型
int judge_other(string dat, int i){
    int is;
    if (dat.find("if", i) == i && (dat[i + 2] == ' ' || dat[i + 2] == '(')) {
        is = 2;
    } else if (dat.find("while", i) == i && (dat[i + 5] == ' ' || dat[i + 5] == '(')) {
        is = 5;
    } else if (dat.find("for", i) == i && (dat[i + 3] == ' ' || dat[i + 3] == '(')) {
        is = 3;
    } else if (dat.find("else", i) == i && dat[i + 4] == ' ') {
        is = 4;
    } else if (dat.find("{", i) == i) {
        is = 1;
    } else {
        is = 0; //普通语句
    } 
    return is;
}

// print space
void print_space(int space){
    int z;
    for (z = 0; z < space; z++) {
        printf(" ");
    }  
}

//跳过多余空格
void ignore_space(string dat, int &i){
    while (dat[i] == ' ') {
        ++i;
    }
}

int main(){
    string dat;
    bool flag;
    getline(cin, dat);
    int i = 0, j = 0, m, idx, k, tmp, space = 0, debt = 0; // space 记录缩进

    //处理main函数 开端部分
    ignore_space(dat, i); //去除多余空格
    //从初始字符打印至)
    idx = dat.find(')', 0);
    for (j = i; j <= idx; j++) {
        putchar(dat[j]);
    }
    printf("\n{\n");

    //跳过字符串中的{, 因为上边已经直接打印
    space += 2;
    i = idx + 1;
    ignore_space(dat, i);
    ++i;

    while (i < dat.length()){
        ignore_space(dat, i);
        if ((tmp = judge_other(dat, i))){
            print_space(space);
            //处理{} 括号语句块  尤如{{{{}}}}
            if (tmp == 1){
                printf("{\n");
                ++i;
                space += 2;
                continue;
            }
            // else特殊处理，其他的for、while、if可归为一种  均是for/while/if + () + { }
            if (tmp == 4){
                for (j = 0; j < 4; j++) {
                    putchar(dat[i + j]);
                } 
                k = i + 3;
            } else{
                for (j = 0; j < tmp; j++) {
                    putchar(dat[i + j]);
                }
                printf(" ");
                i += tmp;
                ignore_space(dat, i);
                //因以 ) 作为处理标志，因此考虑 if(条件) 条件中也有()的情况
                k = i;
                int t = 0;
                while (true){
                    if (dat[k] == '('){
                        ++t;
                    } else if (dat[k] == ')'){
                        --t;
                        if (!t) {
                            break;
                        } 
                    }
                    ++k;
                }
                for (j = i; j <= k; j++) {
                    putchar(dat[j]);
                }
            }
            //找 {
            //此处分两种情况：一、源代码中没有{}，语句块仅有一条语句； 二、源代码中本身有{}
            m = k + 1;
            ignore_space(dat, m);
            if (dat[m] != '{'){
                printf(" {\n");
                flag = false; // flag 与debt 共同作用为处理上述情况一，因为要考虑何时应该输出 }(即配对的右大括号)
                ++debt;
                i = m;
            } else {
                printf(" {\n");
                flag = true;
                i = m + 1;
            }
            space += 2;
        } else if (dat[i] == '}'){
            space -= 2;
            print_space(space);
            printf("}\n");
            if (space == 0) {
                break; //字符串处理完毕——此处用意为考虑 可能在程序的最后有空格
            }
                
            ++i;

            //下边几行代码即为判断上述情况一，是否应该输出 }
            ignore_space(dat, i);
            while (debt && judge_other(dat, i) != 4){
                space -= 2;
                print_space(space);
                printf("}\n");
                --debt;
            }
        } else {
            //普通语句
            idx = dat.find(';', i);
            print_space(space);
            for (j = i; j <= idx; j++) {
                putchar(dat[j]);
            }
            putchar('\n');
            i = idx + 1;
            if (debt && !flag){
                space -= 2;
                print_space(space);
                printf("}\n");
                --debt;

                //下边几行代码同为判断上述情况一，是否应该输出 }
                ignore_space(dat, i);
                while (debt && judge_other(dat, i) != 4){
                    space -= 2;
                    --debt;
                    print_space(space);
                    printf("}\n");
                }
            }
        }
    }
    return 0;
}
