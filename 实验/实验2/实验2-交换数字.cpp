#include<iostream>
using namespace std;
void exchangeNum(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<' '<<"b="<<b<<endl;
}
void exchangeNum(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void exchangeNum(int *a,int &b)
{
	int temp;
	temp=*a;
	*a=b;
	b=temp;
}
int main()
{
	int a,b;
	cout<<"请输入两个用于交换的整数:";
	cin>>a>>b;	
	exchangeNum(a,b);
	exchangeNum(&a,&b);
	cout<<"a="<<a<<' '<<"b="<<b<<endl;
	exchangeNum(&a,b);
	cout<<"a="<<a<<' '<<"b="<<b<<endl;
	return 0;
} 
