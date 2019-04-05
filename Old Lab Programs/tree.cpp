#include<iostream.h>
#include<conio.h>
#include<math.h>
using namespace std;
class binarytree
{
	char *a;
	int h;
	
	public:
	binarytree(int hi)
	
	{
		h=hi;
		a=new char[(int)pow(2,h)-1];
		for(int i=0;i<pow(2,h)-1;i++)
		a[i]='\0';
	}
	void build(int i)
	{
		char ans;
		if(i==0)
		{
			cout<<"enter root node ";
		}
		else if(i%2==1)
		{
			cout<<"enter the left child of the node "<<a[(i-1)/2]<<" ";
		}
		else
		{
			cout<<"enter the right child of the node "<<a[(i-1)/2]<<" ";
		}
		cin>>a[i];
		cout<<"does "<<a[i]<<" has left child(y/n) ";
		cin>>ans;
		if(ans=='y' && 2*(i+1)-1 < pow(2,h)-1)
		build(2*(i+1)-1);
		cout<<"does "<<a[i]<<" has right child(y/n) ";
		cin>>ans;
		if(ans=='y' && 2*(i+1)< pow(2,h)-1)
		build(2*(i+1));
	}
	void inorder(int);
	void preorder(int);
};
void binarytree::inorder(int i)
{
	if(2*(i+1)-1 < pow(2,h)-1 && a[2*(i-1)-1]!='\0')
	inorder(2*(i+1)-1);
	if(a[i]!='\0')
	cout<<a[i];
	if(2*(i+1)< pow(2,h)-1 && a[2*(i-1)]!='\0')
	inorder(2*(i+1));
}
void binarytree::preorder(int i)
{
	if(a[i]!='\0')
	cout<<a[i];
	if(2*(i+1)-1<pow(2,h)-1 && a[2*(i+1)-1]!='\0')
	preorder(2*(i+1)-1);
	if(2*(i+1) < pow(2,h)-1 && a[2*(i+1)]!='\0')
	preorder(2*(i+1));
}
int main()
{
	binarytree ob(3);
	ob.build(0);
	ob.inorder(0);
	ob.preorder(0);
}
