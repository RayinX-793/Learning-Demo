/* 找阿姆斯特朗数 */

#include <stdio.h>
int main()
{
    int n,a,b,c;
    for (n=100;n<=999;n++)
    {
        a=n/100;        // 取出百位
        b=n/10%10;      // 取出十位
        c=n%10;         // 取出个位
        if(a*a*a+b*b*b+c*c*c==n)
            printf("%d\n",n);
    }
    return 0;
    
}