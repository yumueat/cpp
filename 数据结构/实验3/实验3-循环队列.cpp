#include<iostream>
#include<string.h>
#define CAP 6
using namespace std;
class Queue//新建类用于创建队列
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
void Queue::showQueue()//输出队列的函数
{
    int i;
    if (isFull())//如果满了需要从start输入到最后，再从头输入到rear，这样可以保证队列顺序不被打乱
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
    else if (start>rear)//如果start的值小于rear的值，则输入方法和上一种一样，目的也是为了按照队列本身的顺序输出
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
    else//这种情况直接从start到rear输出就行了
    {
        for (i=start;i<rear;i++)
        {
            cout<<data[i]<<' ';

        }
        cout<<endl;
    }
}
void Queue::outQueue()//出队函数
{
    data[start]='\0';
    len--;
    start++;
    if (start>CAP-1)//起到循环作用
    {
        start=0;
    }
}
bool Queue::isEmpty()//判断队列是否为空的函数
{
    if (len==0)
    {
        return true;
    }
    return false;
}
bool Queue::isFull()//判断队列是否为满的函数
{
    if (len==CAP)
    {
        return true;
    }
    return false;
}
void Queue::initQueue(char a)//入队函数
{
    if (!isFull())
    {
        data[rear]=a;
        rear++;
        len++;
        if (rear>CAP-1)//起到循环作用
        {
            rear=0;
        }
    }
    
}

int main()
{
    Queue queue;//新建队列
    char a;
    cout<<queue.isEmpty()<<endl;//查看新建的队列是否为空，如果是则输出1，如果不是则输出0
    for (int i=0;i<CAP;i++)//入队
    {
        cin>>a;
        queue.initQueue(a);
    }
    cout<<queue.isFull()<<endl;//查看队列是否为满，如果是则输出1，不是则输出0
    queue.showQueue();//输出队列，以查看队列内元素
    return 0;
}
