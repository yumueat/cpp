#include<iostream>
using namespace std;

int prime(int i)//判断是否是素数的函数，若是素数则返回0 
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
/*	for (int i=2;i<=n;i++)//用for来编程 
	{
		flag=prime(i);
		s+=flag;
	}*/
/*	int i=n;//用while来编程 
	while(i>=2)
	{
		flag=prime(i);
		s+=flag;
		i--;
	}*/
	int i=n;//用do while来编程 
	do
	{
		flag=prime(i);//判断是否是素数 
		s+=flag;//求和 
		i--;//改变数字 
	}
	while(i>1);
	cout<<s;
	return 0;
}
