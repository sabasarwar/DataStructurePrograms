/*
Date:05-04-2019
Description:Reverse Number stored in a stack
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

int ReverseNumber(int num)
{
    PushStack(num);
    int reverse{0};
    int i=1;
    
    while(!stk.empty())
    {
        reverse=reverse+stk.top()*i;
        stk.pop();
        i=i*10;
    }
    return reverse;
}


int main()
{
    int n{23456};
    cout<<endl;
    cout<<"\nReverse of given number is : "<<ReverseNumber(n)<<endl;
    return 0;
}
