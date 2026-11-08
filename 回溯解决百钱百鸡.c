/*
 *         百钱百鸡（回溯）
 *  设公鸡x只、母鸡y只、小鸡z只，则
 *  x+y+z=100
 *  5x+3y+z/3=100即15x+9y+z=300
 */

#include <stdio.h>

static const int price[3]={15,9,1};   //此处static主要为了规范写法, const表示这是常量
/* 公鸡、母鸡、小鸡的价格(放大为了整数，避免浮点数运算) */

static int solution[3];   //C语言数组下标从0开始
/* solution[0]公鸡，solution[1]母鸡，solution[2]小鸡 */

static int result=0;   //解的总数，现在还没找到答案

static void backtrack(int kind,int left_number,int left_money)
/* backtrack是回溯函数，用于递归地寻找所有可能的解，
意思是要选第kind种鸡，还剩left_number只鸡，还剩left_money这么多钱，继续往下选 */
{
    if(kind==2)   //选到最后一种鸡
    {
        if(left_number>=0 && left_number==left_money)
        {
            solution[2]=left_number;
            result++;
            printf("第%2d种解:公鸡=%2d,母鸡=%2d,小鸡=%2d\n",result,solution[0],solution[1],solution[2]);
        }
        return;   //void函数没有返回值，return只是结束函数的执行
    }
    
    int max_number = left_money/price[kind];
    if(max_number > left_number)
    {
        max_number = left_number;
    }
    /* 剪枝————把不可能的情况砍掉 */

    for(int n=0;n<=max_number;n++)
    {
        solution[kind]=n;
        backtrack(kind+1,left_number-n,left_money-price[kind]*n);
    }
    /* 循环枚举，递归往下选 */
}

int main(void)
{
    backtrack(0,100,300);
    printf("\n总计找到%2d种合法解法\n",result);
    return 0;
    
}