#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class ArrayException
{
	char *s;
	public:

		ArrayException(char *x)
		{
			s = new char[strlen(x) + 1];
			strcpy(s, x);
		}

		friend ostream &operator<<(ostream &abc, ArrayException a)
		{
			abc << a.s;
			return abc;
		}
};

class Array
{
	int *a, length, size;
	public:
		Array(int n);
		int getSize();
		void insert(int x, int index);
		int del(int index);
		void display();
		int getElement(int index);
};

Array::Array(int n)
{
	length = n;
	a = new int[n];
	size = 0;
}

void Array::insert(int x, int index)
{
	if(index < 0 || index > size)
    {
		throw ArrayException("Invalid index in insertion operation");
	}
	for(int i = size - 1; i >= index; i--)
	   a[i+1] = a[i];
	a[index] = x;
	size++;
}

void Array::display()
{
	cout <<"[";
	for(int i = 0;  i < size; i++)
	   cout <<a[i] <<", ";
	cout <<"\b\b]";
}

int Array::getSize()
{
	return size;
}

int Array::del(int index)
{
	if(index<0 || index>=size)
		throw ArrayException("Invalid in deletion operation");
		int x=a[index];
		for(int i=index; i<size-1; i++)
			a[i]=a[i+1];
			size--;
			return x;
}


void getPattern(Array a,int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            a.insert(i,a.getSize());

    a.display();
}


int main()
{
    Array a(10);
    /*for(int i = 0; i < 10; i++)
    {
        try
        {
            if(i < 5)
                a.insert(10*(i+1), i);
            else
            a.insert(90, 6);
        }

        catch(ArrayException x)
        {
            cout << x;
        }
    }
    a.display();
*/

    int n;
    cout<<"\nEnter the number upto which you want to print the pattern: ";
    cin>>n;

    getPattern(a,n);
    getch();
}



