#include<iostream>
using namespace std;
int main()
{
	int i,j,k;
	char foo[]="acdijtuy";
	char bar[]="cfklns";//�½�˳��� 
	for (i=0;i<8;i++)
	{
		cout<<foo[i]<<' ';
	}
	cout<<endl;
	for (i=0;i<6;i++)
	{
		cout<<bar[i]<<' ';
	}//�鿴�Ƿ񴴽��ɹ�
	cout<<endl;
	char flag[14];//�½�˳��� 
	i=j=k=0;
	while (i<14)
	{
		while(j<8&&k<6)//�Ƚ����ݴ�С���кϲ� 
		{
			if (foo[j]<=bar[k])
			{
				flag[i++]=foo[j++];
			}
			else
			{
				flag[i++]=bar[k++];
			}
		}
		if (j<8)//����ʣ������� 
		{
			flag[i++]=foo[j++];
		}
		if (k<6)
		{
			flag[i++]=bar[k++];
		}
	} //�ϲ�˳��� 
	for (i=0;i<14;i++)
	{
		cout<<flag[i]<<' ';
	}//����ϲ���� 
	return 0;
}
