#include<iostream>
#include <math.h>
#include<conio.h>
using namespace std;

class binarytree
{
    char *a;
    int h,i;
    char ans;
public:
    binarytree(int height)
    {
        h=height;
        a=new char[(int) pow(2,h)-1];
        for(i=0;i<pow(2,h)-1;i++)
            a[i]='\0';
    }
    
    void build(int);
    void inorder(int);
    void preorder(int);
    void postorder(int);
    void levelorder();
    
};

void binarytree::build(int i)
{
    if(i==0)
    {
        cout<<"\nEnter root node:  ";
    }
        
    else if(i%2==1)
    {
        cout<<"\nEnter left child of the node  "<<a[(i-1)/2]<<" : ";
    }
        
    else
    {
        cout<<"\nEnter right child of the node  "<<a[(i-1)/2]<<" : ";
    }
        
    cin>>a[i];
        
    cout<<"\nDoes"<<"\t"<<a[i]<<"  has left child(y/n) : ";
    cin>>ans;
    if(ans=='y' && (2*(i+1)-1) < pow(2,h)-1)
        build(2*(i+1)-1);
            
            
            
    cout<<"\nDoes"<<"\t"<<a[i]<<"  has right child(y/n) : ";
    cin>>ans;
    if(ans=='y' && (2*(i+1)) < pow(2,h)-1)
        build(2*(i+1));
}


void binarytree::inorder(int i)
{
    if((2*(i+1)-1) < (2^h-1) && a[2*(i+1)-1]!='\0')
        inorder(2*(i+1)-1);
        
    if(a[i]!='\0')
        cout<<a[i];
        
    if( (2*(i+1)) < (2^h-1) && a[2*(i+1)]!='\0')
        inorder(2*(i+1));
}

void binarytree::preorder(int i)
{
    if(a[i]!='\0')
        cout<<a[i];
        
    if( (2*(i+1)-1) < (2^h-1) && a[2*(i+1)-1]!='\0')
        preorder(2*(i+1)-1);
        
    if( (2*(i+1)) < (2^h-1) && a[2*(i+1)]!='\0')
        inorder(2*(i+1));
}

int main()
{
    binarytree obj(6);
    obj.build(0);
    obj.inorder(0);
    obj.preorder(0);
}