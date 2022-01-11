#include<iostream>
#include<string>
#define VMAX 1000
using namespace std;
typedef struct Node{
    int v,c;
    struct Node * next;
}node;
node * head[VMAX];
void insert(node * p,int v) //插入边的函数
{
    node * np = new node;
    np->v=v;
    np->c=0;
    np->next=p->next;
    p->next=np;
}
node * createGraph(int n)
{
    int m,i,start,end;
    for (i=0;i<n;i++)
    {
        head[i] = new node ;
        head[i]->next=NULL;
        head[i]->c=0; //初始化颜色为0，可以使得起始节点判断顺利
    }
    cout<<"请输入边数：";
    cin>>m;
    cout<<"请输入每条边的起点和终点："<<endl;
    for (i=0;i<m;i++)
    {
        cin>>start>>end;
        insert(head[start],end); //因为是无向图，所以起点和终点分别要交换插入
        insert(head[end],start);
    }
}

int colors[VMAX]; //储存颜色的数组
bool isSame(int i) //判断颜色填充是否合理的函数
{
    node * p = head[i]->next;
    while(p)
    {
        if (head[p->v]->c==head[i]->c) //看该节点的颜色和周围节点的颜色是否相同
        {
            // cout<<"完成一次"<<endl;
            return true;
        }
        p=p->next;
    }
    return false;
}
void colorGraph(int n)//给图填色的函数
{
    for (int i=0;i<VMAX;i++) //初始化储存颜色的函数
    {
        colors[i]=i+1;
    }
    for (int i=0;i<n;i++)
    {
        int j=1;
        head[i]->c=1; //一开始先尝试一个颜色，免得后面没有判断的
        while(isSame(i))
        {
            head[i]->c=colors[j++];
            
        }
    }
}
void showColorGraph(int n) //输出着色结果
{
    node * sortColors[VMAX];
    for (int i=0;i<n;i++)
    {
        cout<<"第"<<i+1<<"种颜色的点有：";
        for (int j=0;j<n;j++)
        {
            if (colors[i]==head[j]->c) //颜色相同为一类输出
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }

}
int main()
{
    int startBfs,startDfs,n;
    cout<<"请输入节点的个数：";
    cin>>n;
    createGraph(n);
    colorGraph(n);
    showColorGraph(n);
    return 0;
}
