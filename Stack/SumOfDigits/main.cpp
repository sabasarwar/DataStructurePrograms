/*
Date:05-04-2019
Description:SUm of digits stored in a stack
*/

#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;

stack<int> stk;

void PushStack(int num)
{
    while(num>0)
    {
        stk.push(num%10);
        num=num/10;
    }
}

int SumOfDigits(int num)
{
    PushStack(num);
    int sum{0};
    
    while(!stk.empty())
    {
        sum+=stk.top();
        stk.pop();
    }
    return sum;
}


int main()
{
    int n{23456};
    cout<<endl;
    cout<<"\nSum of digits is : "<<SumOfDigits(n)<<endl;
    return 0;
}
