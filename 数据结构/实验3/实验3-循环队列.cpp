#include<iostream>
#include<string.h>
#define CAP 6
using namespace std;
class Queue//�½������ڴ�������
{
public:
    char data[CAP];
    int start=0;
    int rear=0; 
    int len=0;
    void initQueue(char a);
    bool isFull();
    bool isEmpty();
    void outQueue();
    void showQueue();
};
void Queue::showQueue()//������еĺ���
{
    int i;
    if (isFull())//���������Ҫ��start���뵽����ٴ�ͷ���뵽rear���������Ա�֤����˳�򲻱�����
    {
        for (i=start;i<CAP;i++)
        {
            cout<<data[i]<<' ';
        }
        for (i=0;i<rear;i++)
        {
            cout<<data[i]<<' ';
        }
        cout<<endl;
    }
    else if (start>rear)//���start��ֵС��rear��ֵ�������뷽������һ��һ����Ŀ��Ҳ��Ϊ�˰��ն��б����˳�����
    {
        for (i=start;i<CAP;i++)
        {
            cout<<data[i]<<' ';
        }
        for (i=0;i<rear;i++)
        {
            cout<<data[i]<<' ';
        }
        cout<<endl;
    }
    else//�������ֱ�Ӵ�start��rear���������
    {
        for (i=start;i<rear;i++)
        {
            cout<<data[i]<<' ';

        }
        cout<<endl;
    }
}
void Queue::outQueue()//���Ӻ���
{
    data[start]='\0';
    len--;
    start++;
    if (start>CAP-1)//��ѭ������
    {
        start=0;
    }
}
bool Queue::isEmpty()//�ж϶����Ƿ�Ϊ�յĺ���
{
    if (len==0)
    {
        return true;
    }
    return false;
}
bool Queue::isFull()//�ж϶����Ƿ�Ϊ���ĺ���
{
    if (len==CAP)
    {
        return true;
    }
    return false;
}
void Queue::initQueue(char a)//��Ӻ���
{
    if (!isFull())
    {
        data[rear]=a;
        rear++;
        len++;
        if (rear>CAP-1)//��ѭ������
        {
            rear=0;
        }
    }
    
}

int main()
{
    Queue queue;//�½�����
    char a;
    cout<<queue.isEmpty()<<endl;//�鿴�½��Ķ����Ƿ�Ϊ�գ�����������1��������������0
    for (int i=0;i<CAP;i++)//���
    {
        cin>>a;
        queue.initQueue(a);
    }
    cout<<queue.isFull()<<endl;//�鿴�����Ƿ�Ϊ��������������1�����������0
    queue.showQueue();//������У��Բ鿴������Ԫ��
    return 0;
}
