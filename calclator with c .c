#include<stdio.h>
#include<stdbool.h>
int main()
{
    int n1,n2;
    bool found=0;
    char ch;
    printf("Enter first number = ");
    scanf("%d",&n1);
    printf("Enter second number = ");
    scanf("%d",&n2);
    do
    {
       printf("Enter operator = ");
       scanf(" %c",&ch); //to input operator symbol 

    if(ch=='+')
    {
        printf("sum of two numbers = %d ",n1+n2);
        break;
    }
    else if(ch=='-')
    {
        printf("Difference of two numbers %d =",n1-n2);
        break;
    }
    else if(ch=='*')
    {
        printf("Product of two numbers = %d ",n1*n2);
        break;
    }
    else if(ch=='/')
    {
        printf("Division of two numbers = %d ",n1/n2);
        break;
    }
    else
    {
        printf("Enter correct operator symbol \n");
        found=1;
    }
    }while(found);
    return 0;
}