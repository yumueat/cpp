#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//����ṹ�壬�ں����������򣬷ֱ����ڴ���ϵ����ָ�� 
{
	int coe;
	int pow;
	struct Link * next;
}link;

link * createLink(int a1[],int a2[],int len)//�½����� 
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

void show(link * p)//������� 
{
	link * temp=p;
	while(temp->next)
	{
		temp=temp->next;
		cout<<temp->coe<<"x^"<<temp->pow<<' ';
	}
	cout<<endl;
}
link * combLink(link * foo,link * bar)//�ϲ����� 
{
	link * temp1 =foo->next;
	link * temp2 =bar->next;
	link * ans=(link*)malloc(sizeof(link));
	link * p=ans;
	while(temp1||temp2)//�ж��Ƿ�ÿһ��Ԫ�ض������� 
	{
		while(temp1&&temp2)//�ж��Ƿ�ÿһ��Ӧ�ñȽϵ�Ԫ�ض��Ƚ��� 
		{
			if (temp1->pow<temp2->pow)//�Ƚ�ָ����С�Ӷ��ϲ� 
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
		if (temp1)//����ʣ������� 
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
	int b2[]={1,7,8};//¼����Ҫ��͵Ķ���ʽ���� 
	link * foo=createLink(a1,a2,sizeof(a1)/sizeof(a1[0]));
	link * bar=createLink(b1,b2,sizeof(b1)/sizeof(b1[0]));//�½����������ʽ 
	show (foo);
	show (bar);//��֤�����Ƿ�ɹ� 
	link * flag=combLink(foo,bar);//���ú������ 
	show (flag); //��֤��� 
	return 0;
}
