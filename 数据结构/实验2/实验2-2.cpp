#include<iostream>
using namespace std;
typedef struct Linklist//����ṹ�壬�����½����� 
{
	char a;
	struct Linklist *next;
}LinkList;
LinkList * create_LinkList(char b,LinkList * p)//�½�����ĺ��� 
{
	LinkList * temp=(LinkList*)malloc(sizeof(LinkList));
	temp->a=b;
	temp->next=NULL;
	p->next=temp;
	return temp;
}
LinkList* ReverseLinkList(LinkList * p)//��������ĺ��� 
{
	LinkList * temp=p->next;//��λ 
	
	LinkList * temp1=temp->next;//���λ�� 
	p->next->next=NULL;
	LinkList * temp2;
	LinkList * temp3;//��������ָ�����ڽ��� 
	while(temp1)//���н��� 
	{
		temp2=temp;
		temp3=temp1;
		temp=temp1;
		temp1=temp->next;
		temp3->next=temp2;
	}
	
	return temp;
}
show (LinkList*p)//������� 
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
	cin>>n;//�������ݸ��� 
	LinkList * p=(LinkList*)malloc(sizeof(LinkList));

//	LinkList L=*p;
	
	LinkList * temp=p;
	for (i=0;i<n;i++)//ѭ���������� 
	{
		cin>>b;
		temp=create_LinkList(b,temp);
	}
	show (p->next);//��֤�����Ƿ�ɹ� 
	LinkList * new_p=ReverseLinkList(p);//���� 
	show (new_p);//��֤�Ƿ��óɹ� 
	return 0;
}
