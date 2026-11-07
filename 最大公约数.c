/* 求2个数的最大公约数 */

#include<stdio.h>   //头文件引入输入输出库
int main()   //程序入口
{
    int a,b,r;
    scanf("%d%d",&a,&b);   //输入
    while(b!=0)   //循环结构之一
    {
        r=a%b;   //欧几里得算法：gcd(a,b)=gcd(b,a mod b)
        a=b;
        b=r;
    }
    printf("%d\n",a);   //输出
    return 0;

}