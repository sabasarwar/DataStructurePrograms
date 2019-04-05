/*
Date: 05-04-2019
Description:Array implementation without template
(insert,delete,display)
*/

#include<iostream>
#include<conio.h>
using namespace std;

class Array
{
    int *arr;
    int size;
    int length;
public:
    Array()
    {
        size=10;
        arr = new int[10];
        length=0;
    }
    
    Array(int sz)
    {
        size=sz;
        arr=new int[size];
        length=0;
    }
    void InsertElement(int index,int x);
    void DeleteElement(int index);
    void Display();
};

void Array::InsertElement(int index,int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
        {
            arr[i+1]=arr[i];
            
        }
        
        arr[index]=x;
        length++;
    }
}


void Array::Display()
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}


void Array::DeleteElement(int index)
{
    if(index>=0 && index<length)
    {
        for(int i=index;i<length-1;i++)
        {
            arr[i]=arr[i+1];
        }
        length--;
    }
}


int main()
{
    Array obj(5);
    obj.InsertElement(0,10);
    obj.InsertElement(1,20);
    obj.InsertElement(2,30);
    obj.Display();
    
    obj.InsertElement(3,40);
    obj.Display();
    
    obj.DeleteElement(2);
    obj.Display();
    return 0;
}
