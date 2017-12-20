#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
node *head,*last;
void add(int x)
{
	node *p=new node();
	p->data=x;
	p->next=NULL;
	if(last==NULL)
	{
		head=p;
		last=p;
	}
	else
	{
		last->next=p;
		last=p;
	}
}
void travel(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}
int main()
{
	int x;
	for(int i=0;i<5;i++)
	{
		cin>>x;
		add(x);
	}
	travel(head);
	return 0;
}
