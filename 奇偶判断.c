/* 判断一个数是奇数还是偶数 */

#include <stdio.h>
int main()
{
    int n;
    printf("Please enter a number.");   //输入
    scanf("%d", &n);   //读取用户输入的整数
    if ( n%2==0 )   //判断：对2取余等于0，就是偶数
    {
        printf(" It is an even number. ");   //输出：这是偶数
    }
    else
    {
        printf(" It is an odd number. ");   //输出：这是奇数
    }
    return 0;

}