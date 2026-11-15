#include <stdio.h>
#include <string.h>   //用了strlen
#include <ctype.h>   //用了isdigit

#define MAX 20   //最多允许输入的数字位数
#define LINE_SIZE  256   //输入缓冲区大小为2^8

/* 显示欢迎界面 */
void panel(void)
{
    printf("\n");
    printf("=================================\n");
    printf("       各 位 数 字 求 和 器\n");
    printf("=================================\n\n");
    printf("欢迎使用RayinX的求和器哦!━(*^-^*)ノ\n\n");
    printf(" 【功能说明】\n");
    printf("  1. 输入一个非负整数（最多 %d 位）\n", MAX);
    printf("     程序会算出它每一位数字相加的结果\n");
    printf("     例如：输入1234 → 1+2+3+4=10\n");
    printf("  2. 输入负数即可退出程序\n");
    printf("=================================\n");
}

/* 清空输入缓冲区 */
void clearInput(void)
{
    int c;   //char装不下-1，c!=EOF（文件结束标志）永远为真，循环可能永远不结束
    /* 
     *一个一个字符读出来扔掉，直到遇到换行符或文件结束
     *因为一行输入以\n结束，读到\n说明这一行清干净了
     *文件结束也要停，不停的话会死循环
     *c=getchar()外面的括号能不能省，因为=（赋值）的优先级低于!=（不等于）
     */
    while ((c=getchar())!='\n' && c!=EOF)
    {
       //空循环体
    }
}

int main(void)
{
    char line[LINE_SIZE];   //存放用户输入的盒子
    /*
     *char存ASCII编码
     *数组：
     *char 1字节
     *int、float 4字节
     *double、long long 8字节 
     *字符串必须多1格放\0 
     */
    int  length;   //输入长度（字符个数）,存普通数字
    panel();

    while (1)   //死循环，直到用户输入负数或遇到文件结束
    {
        printf("\n请输入数字（输入负数退出）：");
        /* 
         * scanf("%d")遇到字母会读取失败，而且字符会一直卡在缓冲区里，很容易造成死循环
         * fgets每次读一整行，不会溢出，遇到换行符就结束，缓冲区不会残留
         */
        if (fgets(line,sizeof(line),stdin)==NULL) 
       /*
        *char *fgets【返回值类型是 char *】(char *s【字符指针】, int size, FILE *stream【文件指针】)
        *line即&line[0]，把首元素地址传进去，fgets内部拿到这个地址，就从这个地址开始，一个字节一个字节地往后读取，然后放入line的内存里
        *sizeof是运算符，求某个东西占多少字节，告诉fgets上限，防止越界放入
        *stdin本身就是指针，可以直接传，不能写&stdin
        *stdin是“标准输入流”，类型是一个已经帮你打开好的、指向键盘输入的FILE*，对应函数fgets、getchar、scanf
        *NULL就是指针版的0，代表空，意思是这个指针不指向任何有效内存
        */
        {
            printf("\n[提示] 检测到输入结束（EOF），程序退出。\n");   //读不到内容，通常是用户文件结束输入
            break; 
        }
        length=(int)strlen(line);    
        /* 
         *size_t【返回值，从起始地址到第一个'\0'之间的字符个数，不包含'\0'本身】 strlen(const char *s【参数，一个字符指针，从哪个地址开始数，加const只是承诺不改传入的内容】)
         *strlen返回的是size_t，它是无符号整数，坑是0-1在无符号里会回绕成一个极大的正数，判断全乱
         *加(int)强制转换的上限约21亿，256并没有超
         *strlen返回无符号，和0比较或做减法之前最好先转int，这是一个经典防御习惯
         */
        if (length>0 && line[length-1]!='\n') 
        /*
         *先保证长度至少1，才敢取length-1，避免越界访问
         *如果最后一个字符不是'\n'，说明这一行太长了，fgets没读完
         *此时缓冲区里还有残留，需要清掉，否则会影响下一次输入 
         */
        {
            clearInput();
        }
        while (length>0 && (line[length-1]=='\n' || line[length-1]=='\r')) 
        /*
         *fgets停止读取只有读到\n，读满size-1个字符和遇到EOF或出错。
         *\r就是一个普通字符，fgets不会因为看到\r就停下来，被读进line便成为行尾的脏字符
         *键盘输入\r只可能出现在行尾，用户按回车产生的行尾是\n或\r\n
         */
        {
            length--; 
            line[length]='\0';   //被“删掉”的\n / \r还留在内存里,length是自己维护的变量，\0才是在内存里的真实结束标志，两者必须同步，注意此时length-1在length--之后变成了length
        }
        if (length==0) 
        {
            printf("\n[错误] 你没有输入任何内容，请重新输入！\n");
            continue;   //continue指结束本轮循环
        }
        if (line[0]=='-') 
        {
            int negative=1;   //假设真的是负数
            if (length==1) 
            {
                negative=0;   //只输入了一个"-"，不是负数
            } 
            else 
            {
                for (int i=1;i<length;i++)   //line[0]是-，所以从i=1开始。line[length]是\0,所以不是i<=length
                {
                    /* 
                     *isdigit判断字符是不是'0'~'9'
                     *强制转换成unsigned char，保证传进去的值在0~255，这是标准防御写法
                     */
                    if (!isdigit((unsigned char)line[i])) 
                    {
                        negative=0;
                        break;
                    }
                }
            }

            if (negative) 
            {
                printf("\n[退出] 你输入了负数，程序结束。\n");   
                printf("\n感谢使用，再见！\n\n");
                break;
            } 
            else 
            {
                printf("\n[错误] “%s”不是合法的整数，请重新输入！\n", line);   //%s输出字符串
                continue;
            }
        }
        int compliance=1;   //假设真的是合规输入
        for (int i=0;i<length;i++) 
        {
            if (!isdigit((unsigned char)line[i])) 
            {
                compliance=0; 
                break; 
            }
        }
        if (!compliance) 
        {
            printf("\n[错误] 输入中包含了非法字符！（正数不要输入“+”，不支持哦！）\n");
            printf("\n只允许输入0~9的数字，空格、小数点等等都不可以哦！\n");
            continue;
        }
        if (length>MAX) 
        {
            printf("\n[错误] 位数太多啦！最多支持%d位，请重新输入！\n",MAX);
            continue;
        }
        int sum = 0; 
        for (int i=0;i<length;i++) 
        {
            sum+=line[i]-'0';   //不减'0'直接加，加的是ASCII码，结果是错的
        }
        printf("\n你输入的数字：%s\n",line);
        printf("\n位数共%d位\n",length);
        printf("\n加法过程：");
        for (int i=0;i<length;i++) 
        {
            if (i>0) 
            {
                printf(" + ");
            }
            printf("%c",line[i]);
        }
        printf("\n");
        printf("\n各位数字之和：%d\n",sum);
    }

    return 0;
}