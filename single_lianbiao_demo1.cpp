#include <iostream>
using namespace std;
template <typename T>
class Node
{
	public:
	T data;
	Node *next;
};
template <typename T>
class SList
{
	Node<T> *head,*last,*node;
	
	public:
		unsigned length;
		SList();//构造函数，初始化
		void add(T x);//表尾添加元素 
		void traversal(); //遍历整个链表并打印
		bool isEmpty();//判断链表是否为空
		Node<T>* find(T x);//查找第一个值为x的节点，返回节点的地址
		void Delete(T x);//删除第一个值为x的节点 
		void insert(T x,Node<T>* p); //在p节点后插入值为x的节点 
		void insertHead(T x);//在链表的头部插入节点
};
int main()
{
    int n,x;
    SList<int> list;
    while(true)
    {
    	cout<<"请输入数字代表操作类型：\n\
1.插入结点;\n\
2.删除结点;\n\
3.打印结点；";
		int op;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"输入待插入数据（从头插入）：";
				cin>>x;
				list.insertHead(x);
				break;
			case 2:
				cout<<"输入待删除数据：";
				cin>>x;
				list.Delete(x) ;
				break;
			case 3:
				cout<<"当前表长度："<<list.length<<endl; 
				list.traversal();
				break;
		}		
    }
//    cout<<"请输入结点数：";
//    cin>>n;
//    cout<<"请输入"<<n<<"个结点:"<<endl;
//    for(int i=0;i<n;i++)
//    {
//    	cin>>x;
//    	list.add(x);
//	}
//	list.traversal();
//	cout<<"当前长度："<<list.length<<endl; 
//	cout<<"请输入要删除的结点值:";
//	cin>>x;
//	list.Delete(x);
//	list.traversal();
//	cout<<"当前长度："<<list.length<<endl; 
//	cout<<"请输入要插入到头结点的值:";
//	cin>>x;
//	list.insertHead(x);
//	list.traversal();
//	cout<<"当前长度："<<list.length<<endl; 
	return 0; 
}

template<typename T>
SList<T>::SList()
{
	last=NULL;
	head=NULL;
	length=0;
}

template<typename T>
void SList<T>::add(T x)
{
	node=new Node<T>();
	node->data=x;
	if(last==NULL)//如果没有尾节点，则表示链表为空，node既为头结点，又为尾结点
	{
		head=node;
		last=node; 
	}
	else//如果链表非空
	{
	    last->next=node;//node为尾节点的下一个节点 
	    last=node;//node变成尾节点 
    }
    length++; 
}
template<typename T>
void SList<T>::traversal()
{
    node=head;
    while(node!=NULL)
    {
        cout<<node->data<<ends;
        node=node->next;
    }
    cout<<endl;
}
template<typename T>
bool SList<T>::isEmpty()
{
    return length==0;
}
template<typename T>
Node<T>* SList<T>::find(T x)
{
    node=head;
    while(node!=NULL&&node->data!=x)
    {
        node=node->next;
    }
    return node;
}
template<typename T>
void SList<T>::Delete(T x)
{
    Node<T>* temp=head;
    if(temp==NULL)return ;
    if(temp->data==x)
    {
        head=temp->next;
        if(temp->next==NULL)last=NULL;
        delete(temp);
        length--;
        return;
    }
    while(temp->next!=NULL&&temp->next->data!=x)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)return ;
    if(temp->next==last)
    {
        last=temp;
        delete(temp->next);
        length--;
        temp->next=NULL;
    }
    else
    {
        node=temp->next;
        temp->next=node->next;
        delete(node);
        length--;
        node=NULL;
    }
}
template<typename T>
void SList<T>::insert(T x,Node<T>* p)
{
    if(p==NULL)return;
    node=new Node<T>();
    node->data=x;
    node->next=p->next;
    p->next=node;
    if(node->next==NULL)last=node;
    length++; 
}
template<typename T>
void SList<T>::insertHead(T x)
{
    node=new Node<T>();
    node->data=x;
    if(isEmpty())
    {
        head=node;
        last=node;        
    }
    else
    {
        node->next=head;
        head=node;
    }
    length++;
}
