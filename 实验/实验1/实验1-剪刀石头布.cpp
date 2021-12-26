#include<iostream>
#include<time.h>
#include<stdlib.h> 
using namespace std;
char com()//电脑出手势的函数 
{
	srand((unsigned)time(NULL));//设置随机数种子 
	int a=rand()%3+1;//产生1-3之间的种子 
	if (a==1)
	{
		cout<<"电脑出了剪刀"<<' ';
		return 'a';
	}
	else if (a==2)
	{
		cout<<"电脑出了石头"<<' ';
		return 'b';
	}
	else
	{
		cout<<"电脑出了布"<<' ';
		return 'c';
	}
}
void pan(char hum,char com)//判断输赢的函数 
{
	if (hum=='a')
	{
		if (com=='a')
		{
			cout<<"平局"<<endl;
		}
		else if (com=='b')
		{
			cout<<"你输了"<<endl;
		}
		else
		{
			cout<<"你赢了"<<endl; 
		}
	}
	if (hum=='b')
	{
		if (com=='b')
		{
			cout<<"平局"<<endl;
		}
		else if (com=='c')
		{
			cout<<"你输了"<<endl;
		}
		else
		{
			cout<<"你赢了"<<endl; 
		}
	}
	if (hum=='c')
	{
		if (com=='c')
		{
			cout<<"平局"<<endl;
		}
		else if (com=='a')
		{
			cout<<"你输了"<<endl;
		}
		else
		{
			cout<<"你赢了"<<endl; 
		}
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char hum;
		while(1)
		{
			cout<<"请输入你想出的:"<<endl;
			cout<<"a.剪刀 b.石头 c.布"<<endl;
			cin>>hum;
			if (hum=='a'||hum=='b'||hum=='c')
			{
				break;
			}
			else
			{
				cout<<"输入有误，请重新输入"<<endl; 
			}
		}
		pan(hum,com());//调用函数进行比较 
	}
	return 0;
}
