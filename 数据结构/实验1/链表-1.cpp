#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//定义结构体，用于新建链表 
{
	char elem;
	struct Link * next;
}link;
link * createLink(char flag[],int len)//新建链表 
{
	link * p=(link*)malloc(sizeof(link));
	link * temp=p;
	int i=0;
	for (;i<len;i++)
	{
		link * a=(link*)malloc(sizeof(link));
		a->elem=flag[i];
		a->next=NULL;
		temp->next=a;
		temp=temp->next;
	}
	return p;
}
void show(link * p)//输出链表 
{
	link * temp=p;
	while(temp->next)
	{
		temp=temp->next;
		cout<<temp->elem<<' ';
	}
	cout<<endl;
}
void insertElem(int loc,char newElem,link * p)
{
	link * temp=p;
	link * a=(link*)malloc(sizeof(link));
	a->elem=newElem;
	for (int i=1;i<loc;i++)
	{
		temp=temp->next;
	}
	a->next=temp->next;
	temp->next=a;
}
void delElem(int loc,link * p)
{
	link * temp=p;
	for (int i=1;i<loc;i++)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
}
int main()
{
	char a[]="asdfghjkl";
	link * foo;
	foo=createLink(a,strlen(a));//新建链表 
	show (foo);//检验链表是否新建成功
	insertElem(4,'z',foo);//插入值 
	show(foo);//检验插入是否成功 
	delElem(4,foo);//删除值 
	show(foo);//检验删除是否成功 
	return 0;
} 
