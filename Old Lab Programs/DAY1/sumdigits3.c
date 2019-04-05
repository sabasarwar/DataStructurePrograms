#include<stdio.h>
int main()
{
    int n,temp,d;
    printf("\n enter your number: ");
    scanf("%d",&n);
    temp=n;
    d=sumofdigits(n);
    printf("\n sum of digits in %d is %d",temp,d);
    return 0;
}

int sumofdigits(n)
{
    int i,sum=0,p=0;
    size_t size=0;
    size=floor(log10(n))+1;
    for(i=1;i<=size;i++)
    {
        sum=sum+((int)floor(n/pow(10,i-1))%10);
    }
    return sum;

}
