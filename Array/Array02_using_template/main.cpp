/*
Date: 05-04-2019
Description:Array implementation without template
(insert,delete,display)
*/

#include<iostream>
#include<conio.h>
using namespace std;

template <class T>  //generic class array
class Array
{
    T *arr;     //array of type T
    int size;
    int length;
public:
    Array()
    {
        size=10;
        arr = new T[10];
        length=0;
    }
    
    Array(int sz)
    {
        size=sz;
        arr=new T[size];
        length=0;
    }
    void InsertElement(int index,T x);
    void DeleteElement(int index);
    void Display();
};


template<class T>
void Array<T>::InsertElement(int index,T x)
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

template<class T>
void Array<T>::Display()
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}


template<class T>
void Array<T>::DeleteElement(int index)
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
    Array<int> obj(5);
    obj.InsertElement(0,10);
    obj.InsertElement(1,20);
    obj.InsertElement(2,30);
    obj.Display();
    
    obj.InsertElement(3,40);
    obj.Display();
    
    obj.DeleteElement(2);
    obj.Display();
    cout<<endl;
    cout<<endl;
    
    
    Array<float> objf(5);
    objf.InsertElement(0,10.234);
    objf.InsertElement(1,20.345);
    objf.InsertElement(2,30.456);
    objf.Display();
    
    objf.InsertElement(3,40.567);
    objf.Display();
    
    objf.DeleteElement(2);
    objf.Display();
    cout<<endl;
    cout<<endl;
    
    
    Array<char> objc(5);
    objc.InsertElement(0,'a');
    objc.InsertElement(1,'b');
    objc.InsertElement(2,'c');
    objc.Display();
    
    objc.InsertElement(3,'d');
    objc.Display();
    
    objc.DeleteElement(2);
    objc.Display();
    cout<<endl;
    cout<<endl;
    return 0;
}
