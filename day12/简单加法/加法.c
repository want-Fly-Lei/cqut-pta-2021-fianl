#include<stdio.h>
#include<string.h>

// 预处理数值,去除前导0
void prefix(char num[]){
    if (num[0] != '0') {  //没有前导0，不用处理
        return;
    }
    char *p = num;
    for (; *p == '0' && *p != 0; p++);  //使p移位指向第一个不为0的数位上
    if (*p == 0){
        num[0] = '0';
        num[1] = 0;
    } else {
        num[0] = *p;
        for (char *q = num; *p != 0; *(++q) = *(++p));
    }
}

int main(){
    int flag=0;
    char a[1001],b[1001];   //数字存储器
    int ans[1001]={0};      //和存储器
    int n=0;                //迭代次数
    //获取变量
    scanf("%d",&n);
    //迭代
    for(int p=1;p<=n;p++){
        flag++;
        //读取两个数
        scanf("%s%s",a,b);
        //前导0的去除
        prefix(a);
        prefix(b);
        //获取两个字符串的长度
        int lena=strlen(a);
        int lenb=strlen(b);
        //使pa存储长度更大的字符串
        char *pa,*pb;
        if(lena<lenb){
            lena+=lenb;
            lenb=lena-lenb;
            lena-=lenb;
            //交换lena与lenb的目的是使pa指向的数长度更长
            pa=b;
            pb=a;
        } else {
            pa=a;
            pb=b;
        }
        //计算开始
        int upa=0;//进位器
        int r=0;//存储数据数组的枚举
        for(int i=lena,j=lenb;i>0;) {
            //获取两个数当前的位数
            int na=pa[--i]-'0';
            int nb=j>0 ? pb[--j]-'0' : 0;   //pb指向的数位更短，以此计算时可能位数不够则为0
            //得到当前位的和
            int sum=na+nb+upa;
            //获得进位,比如9+8=17>10,则视为相应位为7,前一位进1
            upa=sum/10;
            //存储当前位
            ans[r++]=sum%10; 
        }
        
        //检测最后一位是否存在进位
        if(upa>0) {
             ans[r++]=upa;
        }
         //输出结果
         while(r>0){
            printf("%d",ans[--r]);
        } 
        
        //换行
        printf("\n");
    } 
    return 0;
}
