#include<iostream>
#include<time.h>
#include<stdlib.h> 
using namespace std;
char com()//���Գ����Ƶĺ��� 
{
	srand((unsigned)time(NULL));//������������� 
	int a=rand()%3+1;//����1-3֮������� 
	if (a==1)
	{
		cout<<"���Գ��˼���"<<' ';
		return 'a';
	}
	else if (a==2)
	{
		cout<<"���Գ���ʯͷ"<<' ';
		return 'b';
	}
	else
	{
		cout<<"���Գ��˲�"<<' ';
		return 'c';
	}
}
void pan(char hum,char com)//�ж���Ӯ�ĺ��� 
{
	if (hum=='a')
	{
		if (com=='a')
		{
			cout<<"ƽ��"<<endl;
		}
		else if (com=='b')
		{
			cout<<"������"<<endl;
		}
		else
		{
			cout<<"��Ӯ��"<<endl; 
		}
	}
	if (hum=='b')
	{
		if (com=='b')
		{
			cout<<"ƽ��"<<endl;
		}
		else if (com=='c')
		{
			cout<<"������"<<endl;
		}
		else
		{
			cout<<"��Ӯ��"<<endl; 
		}
	}
	if (hum=='c')
	{
		if (com=='c')
		{
			cout<<"ƽ��"<<endl;
		}
		else if (com=='a')
		{
			cout<<"������"<<endl;
		}
		else
		{
			cout<<"��Ӯ��"<<endl; 
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
			cout<<"�������������:"<<endl;
			cout<<"a.���� b.ʯͷ c.��"<<endl;
			cin>>hum;
			if (hum=='a'||hum=='b'||hum=='c')
			{
				break;
			}
			else
			{
				cout<<"������������������"<<endl; 
			}
		}
		pan(hum,com());//���ú������бȽ� 
	}
	return 0;
}
