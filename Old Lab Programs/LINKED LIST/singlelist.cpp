#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *link;

};

Node *create(int x)
{
    Node *first,*curr;
    for(int i=1;i<=x;i++)
    {
        if(i==1)
        {
            first=curr=new Node;
        }
        else
        {
            curr->link=new Node;
            curr=curr->link;
        }
        cout<<"\nEnter data: ";
        cin>>curr->data;
    }
    curr->data=NULL;
    return first;
}
void display(Node *first)
{
    Node *curr=first;
    cout<<"[";
    while(curr!=NULL)
    {
        cout<<curr->data<<",";
        curr=curr->link;
    }
    cout<<"\b\b";
}

int main()
{
    int n;
    cout<<"\nEnter number of nodes";
    cin>>n;

    Node *first=create(n);
    display(first);
    return 0;
}
