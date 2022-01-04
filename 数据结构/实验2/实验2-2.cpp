#include<iostream>
using namespace std;
typedef struct Linklist//定义结构体，用于新建链表 
{
	char a;
	struct Linklist *next;
}LinkList;
LinkList * create_LinkList(char b,LinkList * p)//新建链表的函数 
{
	LinkList * temp=(LinkList*)malloc(sizeof(LinkList));
	temp->a=b;
	temp->next=NULL;
	p->next=temp;
	return temp;
}
LinkList* ReverseLinkList(LinkList * p)//倒置链表的函数 
{
	LinkList * temp=p->next;//定位 
	
	LinkList * temp1=temp->next;//标记位置 
	p->next->next=NULL;
	LinkList * temp2;
	LinkList * temp3;//设置两个指针用于交换 
	while(temp1)//进行交换 
	{
		temp2=temp;
		temp3=temp1;
		temp=temp1;
		temp1=temp->next;
		temp3->next=temp2;
	}
	
	return temp;
}
show (LinkList*p)//输出链表 
{
	LinkList * temp=p;
	while(temp)
	{
//		cout<<1;
		cout<<temp->a<<' ';
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	int n,i;
	char b;
	cin>>n;//输入数据个数 
	LinkList * p=(LinkList*)malloc(sizeof(LinkList));

//	LinkList L=*p;
	
	LinkList * temp=p;
	for (i=0;i<n;i++)//循环输入数据 
	{
		cin>>b;
		temp=create_LinkList(b,temp);
	}
	show (p->next);//验证创建是否成功 
	LinkList * new_p=ReverseLinkList(p);//倒置 
	show (new_p);//验证是否倒置成功 
	return 0;
}
