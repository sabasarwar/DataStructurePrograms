#include<stdio.h>
int main()
{
    int n,d,temp;
    printf("\nEnter your number: ");
    scanf("%d",&n);
    temp=n;
    d=sumdigits(n);
    printf("\nSum of digits in %d is %d",temp,d);
    return 0;
}
int sumdigits(int n)
{
    int sum=0;
    if(n==0)
        return(sum);
    sum=n%10+sumdigits(n/10);
}
