#include<iostream>
using namespace std;

int prime(int i)//�ж��Ƿ��������ĺ��������������򷵻�0 
{
	for (int j=2;j<i;j++)
	{
		if (i%j==0)
		{
			return 0;
		}
	}
	return i;
}
int main()
{
	int n,s=0,flag;
	scanf("%d",&n);
/*	for (int i=2;i<=n;i++)//��for����� 
	{
		flag=prime(i);
		s+=flag;
	}*/
/*	int i=n;//��while����� 
	while(i>=2)
	{
		flag=prime(i);
		s+=flag;
		i--;
	}*/
	int i=n;//��do while����� 
	do
	{
		flag=prime(i);//�ж��Ƿ������� 
		s+=flag;//��� 
		i--;//�ı����� 
	}
	while(i>1);
	cout<<s;
	return 0;
}
