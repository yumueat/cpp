#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//�������� 
{
	char elem;
	struct Link * next;
}link;
link * createLink(char flag[],int len)//��������ĺ��� 
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
void show(link * p)//�������ĺ��� 
{
	while(p->next)
	{
		p=p->next;
		cout<<p->elem<<' ';
	}
	cout<<endl;
}
link * combLink(link*a,link*b)//�ϲ�����ĺ��� 
{
	a=a->next;
	b=b->next;
	link * c=(link*)malloc(sizeof(link));//�½�ͷ�ڵ� 
	link * temp=c;//�½����ָ�� 
	while(a||b)
	{
		while(a&&b)//�Ƚϴ�С���������ݷ���˳�� 
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
		if (a)//����ʣ������ 
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
	return c;//���غϲ��������ͷ�ڵ� 
} 
int main()
{
	char a[]="adfi";
	char b[]="cefi";
	link * foo=createLink(a,strlen(a));
	link * bar=createLink(b,strlen(b));//�½����� 
	show(foo);
	show(bar);//��֤ 
	link * flag=combLink(foo,bar);//�ϲ����� 
	show(flag);//��֤ 
	return 0;
}
