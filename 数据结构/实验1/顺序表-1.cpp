#include<iostream>
using namespace std;
int main()
{
	int i;
	char flag[10]="ajcniydu";//�½�˳��� 
	for (i=0;i<=7;i++)
	{
		cout<<flag[i]<<' ';
	}//�鿴�Ƿ��½��ɹ� 
	cout<<endl; 
	for (i=9;i>=2;i--)
	{
		flag[i]=flag[i-1];
	}//������λ��ʼ�����ݺ��� 
	flag[2]='p';//�������� 
	for (i=0;i<=8;i++)
	{
		cout<<flag[i]<<' ';
	}//�鿴�����Ƿ�ɹ� 
	cout<<endl;
	for (i=2;i<=9;i++)
	{
		flag[i]=flag[i+1];
	}//�ӵ�3λ��ʼ������ǰ�ƣ�ֱ�Ӹ��ǵ�3λ�����ݣ���ɾ����Ч��
	for (i=0;i<=7;i++)
	{
		cout<<flag[i]<<' ';
	}//�鿴ɾ���Ƿ�ɹ� 
	return 0;
}
