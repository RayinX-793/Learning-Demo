/* 输出九九乘法表 */

#include <stdio.h> 

int main()
{
	int i,j;
	for (i=1;i<=9;i++)   //外层循环控制行
	{
		for (j=1;j<=i;j++)   //内层循环控制列
		{
			printf("%d*%d=%-2d\t",j,i,j*i);   //\t为制表符,%-2d左对齐
		}
		printf("\n");
	}
	return 0;
}