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
		cout<<"��ѡ��Ҫ�Ƚϵ�����:"<<endl;
		cout<<"a.�������� b.�������� c.���������� d.һ��������һ��������"<<endl;
		cin>>sec;
		if (sec=='a')
		{
			cout<<"��������������:";
			cin>>a>>b;
			max_value(a,b);
		}
		else if (sec=='b')
		{
			cout<<"��������������:";
			cin>>a>>b>>c;
			max_value(a,b,c);
		}
		else if (sec=='c')
		{
			cout<<"����������������:";
			cin>>p>>q;
			max_value(p,q);
		}
		else if (sec=='d')
		{
			cout<<"������һ��������һ��������:";
			cin>>a>>p;
			max_value(a,p);
		}
		else
		{
			cout<<"������������������"<<endl;
		}
	}
	return 0;
}
