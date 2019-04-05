#include<stdio.h>
int main()
{
    int n,temp,d;
    printf("\nEnter your number: ");
    scanf("%d",&n);
    temp=n;
    d=digits(n);
    printf("\nSum of digits in %d is %d",temp,d);
    return 0;
}

int digits(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    return(sum);
}
