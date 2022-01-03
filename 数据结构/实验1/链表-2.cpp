#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//定义链表 
{
	char elem;
	struct Link * next;
}link;
link * createLink(char flag[],int len)//创建链表的函数 
{
	link * p =(link*)malloc(sizeof(link));
	link * temp=p;
	for (int i=0;i<len;i++)
	{
		link * a=(link*)malloc(sizeof(link));
		a->elem=flag[i];
		a->next=NULL;
		temp->next=a;
		temp=a;
	}
	return p;
}
void show(link * p)//输出链表的函数 
{
	while(p->next)
	{
		p=p->next;
		cout<<p->elem<<' ';
	}
	cout<<endl;
}
link * combLink(link*a,link*b)//合并链表的函数 
{
	a=a->next;
	b=b->next;
	link * c=(link*)malloc(sizeof(link));//新建头节点 
	link * temp=c;//新建标记指针 
	while(a||b)
	{
		while(a&&b)//比较大小来决定数据放置顺序 
		{
			if (a->elem<=b->elem)
			{
				temp->next=a;
				temp=temp->next;
				a=a->next;
			}
			else
			{
				temp->next=b;
				temp=temp->next;
				b=b->next;
			}
		}
		if (a)//处理剩余数据 
		{
			temp->next=a;
			temp=temp->next;
			a=a->next;
		}
		if (b)
		{
			temp->next=b;
			temp=temp->next;
			b=b->next;
		}
	}
	return c;//返回合并后链表的头节点 
} 
int main()
{
	char a[]="adfi";
	char b[]="cefi";
	link * foo=createLink(a,strlen(a));
	link * bar=createLink(b,strlen(b));//新建链表 
	show(foo);
	show(bar);//验证 
	link * flag=combLink(foo,bar);//合并链表 
	show(flag);//验证 
	return 0;
}
