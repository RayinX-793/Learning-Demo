//数组逆置
#include <stdio.h>
#define N 10

void fan(int n,int p[])   //n=N，int p[]自动翻译为*p,p=&xy[0]
{
    int *a=p;
    int *b=p+n-1;
    /*
     *指针运算规则：
     *指针+指针、指针++、&(数组名+1)：NO
     *指针-指针：YES，得到两个指针间相隔的元素个数
     *指针+整数、指针++、数组名+1、*(数组名+1)：YES
    注意：数组名实质是指针常量
     */
    int c;
    while (a<b)
    {
        c=*a;
        *a=*b;   
        //把后者指向位置的数据赋值给前者，间接访问更灵活，支持动态内存
        //a=b：指针互相赋值，拷贝的是地址
        *b=c;
        a++;
        b--;
    }
}

int main()
{
    int i,xy[N];
    for (i=0;i<N;i++)
    scanf ("%d",&xy[i]);
    fan (N,xy);   //数组xy自动转化为&xy[0]
    //数组名只有在sizeof(数组名)、&数组名这两种情况代表整个数组，其余场景数组名自动转化为数组首元素地址
    for (i=0;i<N;i++)
    printf("%d\n",xy[i]);
    return 0;
}