#include<iostream>
using namespace std;
void max_value(int a,int b)
{
	if (a>=b)
	{
		cout<<a<<endl;
	}
	else
	{
		cout<<b<<endl;
	}
}
void max_value(int a,int b,int c)
{
	if (a>=b)
	{
		if (a>=c)
		{
			cout<<a<<endl;
		}
		else 
		{
			cout<<c<<endl;
		}
	}
	else
	{
		if (b>=c)
		{
			cout<<b<<endl;
		}
		else
		{
			cout<<c<<endl;
		}
	}
}
void max_value(double a,double b)
{
	if (a>=b)
	{
		cout<<a<<endl;
	}
	else
	{
		cout<<b<<endl;
	}
}
void max_value(int a,double b)
{
	if (a>=b)
	{
		cout<<a<<endl;
	}
	else
	{
		cout<<b<<endl;
	}
}
int main()
{
	int i;
	cin>>i;
	while(i--)
	{
		char sec;
		int a,b,c;
		double p,q;
		cout<<"请选择要比较的类型:"<<endl;
		cout<<"a.两个整数 b.三个整数 c.两个浮点数 d.一个整数和一个浮点数"<<endl;
		cin>>sec;
		if (sec=='a')
		{
			cout<<"请输入两个整数:";
			cin>>a>>b;
			max_value(a,b);
		}
		else if (sec=='b')
		{
			cout<<"请输入三个整数:";
			cin>>a>>b>>c;
			max_value(a,b,c);
		}
		else if (sec=='c')
		{
			cout<<"请输入两个浮点数:";
			cin>>p>>q;
			max_value(p,q);
		}
		else if (sec=='d')
		{
			cout<<"请输入一个整数和一个浮点数:";
			cin>>a>>p;
			max_value(a,p);
		}
		else
		{
			cout<<"输入有误，请重新输入"<<endl;
		}
	}
	return 0;
}
