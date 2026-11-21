/* 题目：有n个学生，每个学生有学号、成绩，按分数从高到低排序，分数相同学号小的排在前面。 */
#include <stdio.h>
#define N 105

//采用冒泡排序解决
int main(void)
{
    int n;
    int student[N][2];
    int i,j;
    int temporarySN,temporaryGrade;   //学号，分数
    printf ("输入学生个数（仅输入数字）：");
    scanf ("%d",&n);
    printf ("以学号+【一个空格】+分数输入，一个学生输入一行\n\n");
    for (i=0;i<n;i++)
    {
        scanf ("%d %d",&student[i][0],&student[i][1]);
    }
    for (i=0;i<n-i;i++)   //n-1轮排序
    {
        for (j=0;j<n-1-i;j++)   //每轮相邻比较和交换
        {
            if (student[j][1]<student[j+1][1] || (student[j][1]==student[j+1][1]&&student[j][0]>student[j+1][0]))
            {
                temporarySN=student[j][0];
                temporaryGrade=student[j][1];

                student[j][0]=student[j+1][0];
                student[j][1]=student[j+1][1];

                student[j+1][0]=temporarySN;
                student[j+1][1]=temporaryGrade;
            }
        }
    }
    printf ("\n如下是排序：\n");
    for (i=0;i<n;i++)
    {
        printf ("%d %d\n",student[i][0],student[i][1]);
    }
    return 0;
}
