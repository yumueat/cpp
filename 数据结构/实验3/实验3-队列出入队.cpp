#include<iostream>
#include<string.h>
using namespace std;

void show (char queue[])//������еĺ���
{
    for (int i=0;i<strlen(queue);i++)
    {
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}
void outQueue(char queue[],int start,int end)//���Ӻ�������Ҫ������ӵ�λ��
{
    for (int i=end;i>=start;i--)
    {
        queue[i]='\0';
    }
}
int main()
{
    char queue[255];
    cin>>queue;//���
    show (queue);//�鿴�Ƿ���ӳɹ�
    outQueue(queue,0,strlen(queue));//����
    show (queue);//�鿴�Ƿ���ӳɹ�
    return 0;
}
