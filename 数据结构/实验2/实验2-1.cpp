#include<iostream>
using namespace std;
typedef struct Sqlist//����ṹ�壬�����½�˳��� 
{
	char a[255];
	int len;
}SqList;
void ReverseSqList(SqList &L)//����˳���ĺ��� 
{
	char temp;
	for (int i=0;i<=L.len/2;i++)
	{
		temp=L.a[i];
		L.a[i]=L.a[L.len-1-i];
		L.a[L.len-1-i]=temp;
	}
}
void show(SqList &L)//���˳��� 
{
	for (int i=0;i<L.len;i++)
	{
		cout<<L.a[i]<<' ';
	}
	cout<<endl;
}
int main()
{
	int n,i;
	cin>>n;//�������ݸ��� 
	SqList L;
	for (i=0;i<n;i++)
	{
		cin>>L.a[i];//�����������ݲ���ֵ 
	}
	L.len=i;//��¼���ݸ��� 
	show (L); 
	ReverseSqList(L);//���� 
	show(L);//��֤��� 
	return 0;
}
