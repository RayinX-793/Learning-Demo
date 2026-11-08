/* This is a simple four-function calculator */

#include <stdio.h>
#include <math.h>   //fabs() function is defined in math.h
int main()
{
    float a,b;
    char c;
    printf("Enter a simple calculation formula. e.g.1.23+4.56\n");
    scanf("%f%c%f",&a,&c,&b);
    switch(c)
    {
        case '+':
            printf("%.2f\n",a+b);   //%.2f means print the float number with 2 decimal places
            break;
        case '-':
            printf("%.2f\n",a-b);
            break;
        case '*':
            printf("%.2f\n",a*b);
            break;
        case '/':
            if(fabs(b)>1e-6)   
    /* Under the condition of b!=0, 
    we can use fabs(b)>1e-6 to avoid the error of floating point number comparison */
                printf("%.2f\n",a/b);
            else
                printf("Division by zero error!\n");
            break;
        default:
            printf("Invalid operator!\n");
    }
    return 0;

}