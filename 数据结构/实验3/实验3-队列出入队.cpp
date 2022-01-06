#include<iostream>
#include<string.h>
using namespace std;

void show (char queue[])//输出队列的函数
{
    for (int i=0;i<strlen(queue);i++)
    {
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}
void outQueue(char queue[],int start,int end)//出队函数，需要输入出队的位置
{
    for (int i=end;i>=start;i--)
    {
        queue[i]='\0';
    }
}
int main()
{
    char queue[255];
    cin>>queue;//入队
    show (queue);//查看是否入队成功
    outQueue(queue,0,strlen(queue));//出队
    show (queue);//查看是否出队成功
    return 0;
}
