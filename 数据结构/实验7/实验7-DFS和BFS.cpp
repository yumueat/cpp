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
node * createGraph()  //��ʽǰ����
{
    int n,m,i,start,end;
    cout<<"������ڵ�����";
    cin>>n;
    for (i=0;i<n;i++)
    {
        head[i] = new node ;
        head[i]->next=NULL;
    }
    cout<<"�����������";
    cin>>m;
    cout<<"������ÿ���ߵ������յ㣺"<<endl;
    for (i=0;i<m;i++)
    {
        cin>>start>>end;
        insert(head[start],end);
        insert(head[end],start);
    }
}
int visitBfs[VMAX]={0};//�����������vit����
int que[VMAX]; //�������飬��֤����˳��
void bfs(int n)// �����������
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
int visitDfs[VMAX]={0};//�����������vit����
void dfs(int n)//�����������
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
    cout<<"�����������ȱ�������㣺";
    cin>>startBfs;
    bfs(startBfs);
    cout<<endl;
    cout<<"������������ȱ�������㣺";
    cin>>startDfs;
    dfs(startDfs);
    cout<<endl;
    return 0;
}
