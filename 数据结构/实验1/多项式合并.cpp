#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//定义结构体，内含两个数据域，分别用于储存系数和指数 
{
	int coe;
	int pow;
	struct Link * next;
}link;

link * createLink(int a1[],int a2[],int len)//新建链表 
{
	link * p=(link*)malloc(sizeof(link));
	link * temp=p;
	for (int i=0;i<len;i++)
	{
		link * a=(link*)malloc(sizeof(link));
		a->coe=a1[i];
		a->pow=a2[i];
		a->next=NULL;
		temp->next=a;
		temp=a;
	}
	return p;
}

void show(link * p)//输出链表 
{
	link * temp=p;
	while(temp->next)
	{
		temp=temp->next;
		cout<<temp->coe<<"x^"<<temp->pow<<' ';
	}
	cout<<endl;
}
link * combLink(link * foo,link * bar)//合并链表 
{
	link * temp1 =foo->next;
	link * temp2 =bar->next;
	link * ans=(link*)malloc(sizeof(link));
	link * p=ans;
	while(temp1||temp2)//判断是否每一个元素都处理了 
	{
		while(temp1&&temp2)//判断是否每一个应该比较的元素都比较了 
		{
			if (temp1->pow<temp2->pow)//比较指数大小从而合并 
			{
//				link * a=(link*)malloc(sizeof(link));
				p->next=temp1;
				p=p->next;
				temp1=temp1->next;
			}
			else if (temp1->pow==temp2->pow)
			{
				temp1->coe+=temp2->coe;
				p->next=temp1;
				p=p->next;
				temp1=temp1->next;
				temp2=temp2->next; 
			}
			else
			{
				p->next=temp2;
				p=p->next;
				temp2=temp2->next;
			}
		}
		if (temp1)//处理剩余的数据 
		{
			p->next=temp1;
			p=p->next;
			temp1=temp1->next;
		}
		if (temp2)
		{
			p->next=temp2;
			p=p->next;
			temp2=temp2->next;
		}
	}
	return ans;
}
int main()
{
	int a1[]={7,3,9,5};
	int a2[]={0,1,8,17};
	int b1[]={8,22,-9};
	int b2[]={1,7,8};//录入需要求和的多项式数据 
	link * foo=createLink(a1,a2,sizeof(a1)/sizeof(a1[0]));
	link * bar=createLink(b1,b2,sizeof(b1)/sizeof(b1[0]));//新建链表储存多项式 
	show (foo);
	show (bar);//验证储存是否成功 
	link * flag=combLink(foo,bar);//调用函数求和 
	show (flag); //验证结果 
	return 0;
}
