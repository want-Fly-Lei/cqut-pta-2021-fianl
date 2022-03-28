#include<cstdio>
#include<vector>
#define MAXSIZE 100001
using namespace std;

//i dont know why have a test not pass

class NODE {
    public:
    int head, value, tail;

    //重写输出函数
    void toString() {
        if(this->tail != -1) {
            printf("%05d %d %05d\n",this->head,this->value,this->tail);
        } else {
            printf("%05d %d -1\n",this->head,this->value);
        }
    }

    //判断绝对值是否相等
    bool operator==(const NODE & n) const {
        if(n.value == this->value || n.value == -this->value) {
            return true;
        }
        return false;
    }
};

int main() {
    int fristHead, n;
    scanf("%d %d",&fristHead,&n);
    NODE newVn[n], outVn[n], vn[MAXSIZE];
    int newCount = 1, outCount = 0;
    NODE temp;
    int i, j, k;
    bool flag;
    for(i = 0; i < n; i++) {
        scanf("%d %d %d",&temp.head,&temp.value,&temp.tail);
        if(temp.head == fristHead) {
            newVn[0] = temp;
        }
        vn[temp.head] = temp;
    }

    for(i = 1; i < n ; i++) {
        flag = true;
       for(j = 0; j < newCount; j++) {
           if(vn[newVn[newCount - 1].tail] == newVn[j]) {
               flag = false;

                    outVn[outCount++] = vn[newVn[newCount - 1].tail];
                    newVn[newCount - 1].tail = outVn[outCount - 1].tail;
               
               if(outCount > 1) {
                   //outVn[outCount - 1].head = outVn[outCount - 2].tail;
                   outVn[outCount - 2].tail = outVn[outCount - 1].head;
               }
               break;
           }
       }
       if(flag) {
           newVn[newCount++] = vn[newVn[newCount - 1].tail];
       }
    }

    newVn[newCount - 1].tail = -1;
    for(i = 0; i < newCount; i++) {
        newVn[i].toString();
    }
    if(outCount > 0) {
        outVn[outCount - 1].tail = -1;
    }
    for(i = 0; i < outCount; i++) {
        outVn[i].toString();
    }
    return 0;
}