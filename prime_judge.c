/*
 * 程序：质数判断器（试除法）
 * 流程：
 * 读入区间端值
 * -> 自动区分上下限
 * -> 逐个判断
 */

#include <stdio.h>
#include <stdlib.h>   //提供system()函数，用于暂停窗口等待按键

/*
 * 函数 is_prime(n)：
 * 返回 1 = 是质数，返回 0 = 不是质数
 * 试除顺序：
 * <2 排除
 * -> ==2
 * -> 偶数排除
 * -> 奇数试除
 */
int is_prime(long long n)
{
    if(n<2)
    return 0;

    if(n==2)
    return 1;

    if(n%2==0)
    return 0;

    //用i<=n/i代替i*i<=n，避免i*i相乘溢出；也可以用i<=sqrt(n)，但要包含math.h库
    for(long long i=3;i<=n/i;i+=2)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}

/* 函数 factorize(n)：把 n（合数）分解成质因数并打印 */
void factorize(long long n)
{
    int first=1;   //1=还没打印过*，0=已经打印过

    while(n%2==0)
    {
        if(!first)   //!first取反，即不是第一个时才打印
        printf("*");

        printf("2");
        n/=2;
        first=0;   //标记打印过了
    }

    for(long long i=3;i<=n/i;i+=2)
    {
        while(n%i==0)
        {
            if(!first)
            printf("*");

            printf("%lld",i);
            n/=i;
            first=0;
        }
    }

    //若除到最后n还大于1，剩下的n本身必为质数
    if(n>1)
    printf("*%lld",n);

    printf("\n");
}

int main(void)
{
    long long a,b;   //long long范围比int大

    printf("欢迎使用RayinX的质数判断程序！\n");
    printf("本程序接下来会接收你的区间输入，如果你只想判断单个数字，请将两个端值设为相同。\n\n");
    printf("请输入你想判断的区间端值（两个整数，用一个空格分隔）：");

    if(scanf("%lld %lld",&a,&b)!=2)   //scanf返回成功读入的个数
    {
        printf("输入无效，请正确输入，谢谢配合。\n");
        system("pause");   //暂停，让用户看清错误信息
        return 1;   //1表示出错，立刻结束main
    }

    //自动区分上下限
    long long low,high;
    if(a<=b)
    {
        low=a;
        high=b;
    }
    else
    {
        low=b;
        high=a;
    }

    //两端相同即只判断这一个数
    if(low==high)
        printf("判断%lld：\n\n",low);
    else
        printf("区间［%lld，%lld］的判断结果：\n\n",low,high);

    for(long long n=low;n<=high;n++)
    {
        if(n<2)
            printf("%lld 既非质数也非合数哦！\n",n);
        else if(is_prime(n))
            printf("%lld 是质数。\n",n);
        else
        {
            printf("%lld 是合数，%lld = ",n,n);
            factorize(n);
        }
    }

    system("pause");   //暂停，防止双击运行时窗口一闪而过（只在 Windows 有效）

    return 0;   //0表示正常结束main
}
