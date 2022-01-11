#include<iostream>
#include<string>
#define VMAX 1000
using namespace std;
typedef struct Node{
    int v,c;
    struct Node * next;
}node;
node * head[VMAX];
void insert(node * p,int v) //����ߵĺ���
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
        head[i]->c=0; //��ʼ����ɫΪ0������ʹ����ʼ�ڵ��ж�˳��
    }
    cout<<"�����������";
    cin>>m;
    cout<<"������ÿ���ߵ������յ㣺"<<endl;
    for (i=0;i<m;i++)
    {
        cin>>start>>end;
        insert(head[start],end); //��Ϊ������ͼ�����������յ�ֱ�Ҫ��������
        insert(head[end],start);
    }
}

int colors[VMAX]; //������ɫ������
bool isSame(int i) //�ж���ɫ����Ƿ����ĺ���
{
    node * p = head[i]->next;
    while(p)
    {
        if (head[p->v]->c==head[i]->c) //���ýڵ����ɫ����Χ�ڵ����ɫ�Ƿ���ͬ
        {
            // cout<<"���һ��"<<endl;
            return true;
        }
        p=p->next;
    }
    return false;
}
void colorGraph(int n)//��ͼ��ɫ�ĺ���
{
    for (int i=0;i<VMAX;i++) //��ʼ��������ɫ�ĺ���
    {
        colors[i]=i+1;
    }
    for (int i=0;i<n;i++)
    {
        int j=1;
        head[i]->c=1; //һ��ʼ�ȳ���һ����ɫ����ú���û���жϵ�
        while(isSame(i))
        {
            head[i]->c=colors[j++];
            
        }
    }
}
void showColorGraph(int n) //�����ɫ���
{
    node * sortColors[VMAX];
    for (int i=0;i<n;i++)
    {
        cout<<"��"<<i+1<<"����ɫ�ĵ��У�";
        for (int j=0;j<n;j++)
        {
            if (colors[i]==head[j]->c) //��ɫ��ͬΪһ�����
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
    cout<<"������ڵ�ĸ�����";
    cin>>n;
    createGraph(n);
    colorGraph(n);
    showColorGraph(n);
    return 0;
}
