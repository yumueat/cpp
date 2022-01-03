#include<iostream>
#include<string.h>
using namespace std;
typedef struct Link//����ṹ�壬�����½����� 
{
	char elem;
	struct Link * next;
}link;
link * createLink(char flag[],int len)//�½����� 
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
void show(link * p)//������� 
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
	foo=createLink(a,strlen(a));//�½����� 
	show (foo);//���������Ƿ��½��ɹ�
	insertElem(4,'z',foo);//����ֵ 
	show(foo);//��������Ƿ�ɹ� 
	delElem(4,foo);//ɾ��ֵ 
	show(foo);//����ɾ���Ƿ�ɹ� 
	return 0;
} 
