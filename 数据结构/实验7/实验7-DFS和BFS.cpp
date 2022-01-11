#include<iostream>
#include<string>
#define VMAX 1000
using namespace std;
typedef struct Node{
    int v;
    struct Node * next;
}node;
node * head[VMAX];
void insert(node * p,int v) 
{
    node * np = new node;
    np->v=v;
    np->next=p->next;
    p->next=np;
}
node * createGraph()  //链式前向星
{
    int n,m,i,start,end;
    cout<<"请输入节点数：";
    cin>>n;
    for (i=0;i<n;i++)
    {
        head[i] = new node ;
        head[i]->next=NULL;
    }
    cout<<"请输入边数：";
    cin>>m;
    cout<<"请输入每条边的起点和终点："<<endl;
    for (i=0;i<m;i++)
    {
        cin>>start>>end;
        insert(head[start],end);
        insert(head[end],start);
    }
}
int visitBfs[VMAX]={0};//广度优先搜索vit数组
int que[VMAX]; //队列数组，保证搜索顺序
void bfs(int n)// 广度优先搜索
{
    int i=0,j=0;
    que[i++]=n;
    visitBfs[n]=1;
    while(j<i)
    {
        int u = que[j++];
        cout<<u<<" ";
        node * p = head[u]->next;
        while(p)
        {
            if (!visitBfs[p->v])
            {
                que[i++]=p->v;
                visitBfs[p->v]=1;
            }
            p=p->next;
        }

    }
}
int visitDfs[VMAX]={0};//深度优先搜索vit数组
void dfs(int n)//深度优先搜索
{
    visitDfs[n] = 1;
    cout<<n<<' ';
    node * p = head[n]->next;
    while (p)
    {
        if (!visitDfs[p->v]){
            dfs(p->v);
        }
        p=p->next;
    }
}
int main()
{
    int startBfs,startDfs;
    createGraph();
    cout<<"请输入广度优先遍历的起点：";
    cin>>startBfs;
    bfs(startBfs);
    cout<<endl;
    cout<<"请输入深度优先遍历的起点：";
    cin>>startDfs;
    dfs(startDfs);
    cout<<endl;
    return 0;
}
