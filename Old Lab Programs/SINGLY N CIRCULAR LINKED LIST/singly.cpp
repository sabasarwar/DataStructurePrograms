#include<iostream>
#include<conio.h>
using namespace std;
class Node
{

    public:
    int data,index;
    Node *link,*first,*curr,*prev;
    bool Isempty();
    int Getsize();
    void Insert(int x, int index);
    int Delete(int index);
    int Get(int index);
    int Indexof(int x);
    void Display();

};

/*
class LinkedList
{
    Node *first,*curr;
public:
    LinkedList()
    {
        first=NULL;
    }


};
*/

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
    curr->link=NULL;
    return first;
}

bool Node::Isempty()
{
    if(first==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Node::Getsize()
{

    int size=0;
    curr=first;
    while(curr!=NULL)
    {
        size=size+1;
        curr=curr->link;
    }
    return size;
}

void Node::Insert(int x, int index)
{
    Node *prev;
    if(index<0 || index>Getsize())
    {

        cout<<"\nInvalid index...";
    }

    curr=create(x);
    curr->data=x;
    if(index=0)
    {
        curr->link=first;
        first=curr;
    }
    else
    {
        prev=first;
        for(int i=0;i<=index-1;i++)
        {
            prev=prev->link;
        }
        curr->link=prev->link;
        prev->link=curr;
    }

}

int Node::Delete(int index)
{
    int x;
    Node *del;
    if(index<0 || index>=Getsize())
    {
        cout<<"\nInvalid index...";
    }

    if(index==0)
    {
        del=first;
        first=del->link;
        x=del->data;
        del->link=NULL;
        delete del;
    }

    else
    {
        prev=first;
        for(int i=0;i<=index-1;i++)
        {
            prev=prev->link;
            del=prev->link;
            prev->link=del->link;
            x=del->data;
            del->link=NULL;
            delete del;
        }
        return x;
    }
}

int Node::Get(int index)
{
    if(index<0 || index>=Getsize())
    {
        cout<<"\nInvalid index...";
    }

    curr=first;
    for(int i=0;i<index;i++)
    {
        curr=curr->link;
    }

    return (curr->data);
}


int Node::Indexof(int x)
{
    int i=0;
    if (index=-1)
    {
        curr=first;
    }

    while(curr!=NULL)
    {
        if(curr->data=x)
        {
            index=i;
            break;
        }
        else
        {
            i=i+1;
            curr=curr->link;
        }
    }
    return (index);

}


void Display(Node *first)
{
    Node *curr=first;
    cout<<"[";
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->link;
    }
    cout<<" \b\b ]";
}


int main()
{
    Node obj;
    int n;
    cout<<"\nEnter number of nodes";
    cin>>n;

    Node *first=create(n);
    Display(first);
    obj.Insert(5,1);
    Display(first);
    return 0;
}
