#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#define MAXN 500000
#define INF 0x7fffffff//����������
using namespace std;
// ��ʼ��
struct Node//�㼯 
{
	int num,dis;//numΪ�ڵ��ţ�disΪ���s��num����̾���
	Node(int a,int b)//��ʼ�������캯����
	{
		num=a;
		dis=b;
	}
	friend bool operator < (const Node &a,const Node &b)//������������������ȶ�������
	{
		return a.dis>b.dis;//����̵����� 
	}
};
struct Edge
{
    int to,value,nxt;//�յ㣬��Ȩ��ͬ������һ���ߵı�ţ�ͨ��һ���߱����һ���ߣ����԰����еı߶�������
}e[MAXN];//�߼�
int vs,edges;//����������ߵ�����
int Head[MAXN];//head[i],��ʾ��iΪ����һ�����ڱ߼������λ�ã���ţ���Ȼ�����nxt�ı�ǿ��Ա���ͬ�������б�
int index;//����ߵı��
int dis[MAXN];//�洢���������
bool visit[MAXN];//�洢�����̾���ĵ������
int way[MAXN];//�洢·�ߵ�����

// ��������
//������ӱߵĺ���
void Add(int u,int v,int value)
{ 
    e[++index].to=v;//��index���ߵ��յ���v
    e[index].value=value;//Ȩֵ 
    e[index].nxt=Head[u];//ͬ�����һ���ߵı��
    Head[u]=index;//�������ߵı�Ÿ��µ�Head��������
}
priority_queue <Node> q;//�½�һ���㼯�����ȶ���

// �Ͻ�˹�����㷨
void dijkstra(int s)//�������
{
	fill(dis,dis+MAXN,INF);//�Ѿ��������ÿһ�����Ϊ���ֵ
	dis[s]=0;//�����ľ�������Ϊ0
	while(!q.empty())//ֻҪ���в�Ϊ�գ�һ�����㿴��ȥ
	{
		int u=q.top().num;//uΪ����
		q.pop();//��������Ԫ��
		if(visit[u])//�ж���uΪ���ı��Ƿ񱻱���
		{
			continue;//����ѭ��
		}
		else
		{
			visit[u]=1;//���Ϊ��������Ȼ������׼����ʼ����
		}
		for(int i=Head[u];i!=0;i=e[i].nxt)//�����������Ϊ�������е�
		{
			int v=e[i].to;//��ȡ�յ�
            if(visit[v]==0&&dis[u]+e[i].value<dis[v])//����յ�û�б�����������µ�·�߱�֮ǰ��·�߸���
			{
                dis[v]=dis[u]+e[i].value;//�ͰѸ��̵�·�߼ӽ�ȥ
				way[v]=u;//��¼·��
                q.push(Node(v,dis[v]));//����������ĵ�;���ӽ�ȥ���Ӷ����Բ��ϱȽ��ҵ���̵ľ���
            }
        }
	}
}

// ���յ�ͼ���ѵص�ת��Ϊ��ŵĺ���
int placeSearch(string a,string * place)
{
	for (int i=0; i<vs;i++)
	{
		if(place[i]==a)
		{
			return i;
		}
	}
}

int main(){
	string s,a,b;//��㣬e{a,b}
	int u,v,start;//���ڼ���ĵ�(���)����Ҫͨ����������
	int value;//Ȩ��value
	cout<<"������ص��������·����������㣺";
	cin>>vs>>edges>>s; 
	cout<<"����������ص�����ƣ�����㿪ʼ��:";
	string * place = new string[vs];//��ͼ�������ڴ洢�ص�
	for(int i=0;i<vs;i++)
	{	
		cin>>place[i];
	}
	start = placeSearch(s,place);//��ȡ�����
	cout<<"����������ÿ��·������յ��Ȩֵ:";
	for(int i=0;i<edges;i++)//��������ÿ���ߵ�����յ��Ȩֵ
	{ 
		cin>>a>>b>>value;
		u=placeSearch(a,place);
		v=placeSearch(b,place);
		Add(u,v,value);//�ѱ߼��뵽������ȥ
	}
	q.push(Node(start,dis[start]));//�����ӵ���������ȥ
	dijkstra(start);//���·���㷨

	// ������·��
	string searchplace;
	cout<<"������Ҫ��ѯ���·���ĵص㣺";
	cin>>searchplace;
	int i=placeSearch(searchplace,place);
	cout<<place[0]<<"��"<<place[i]<<"����̾���Ϊ:"<<dis[i]<<"�����·����";
	int t = i ,len=0;
	int * que = new int[vs];
	while(1)
	{
		que[len++] = t;
		t = way [t];
		if (t==0)
		{
			que[len++] = t;
			break;
		}
	}
	for (int i = len - 1 ;i >=0 ; i--)
	{
		
		if (i==0)
		{
			cout<<place[que[i]]<<endl;
		}
		else
		{
			cout<<place[que[i]]<<"-->";
		}
	}

	// ����ʱ���ȫ�����·��
	// for(int i=1;i<vs;i++)//�����㵽�������̾���
	// {
	// 	cout<<place[0]<<"��"<<place[i]<<"����̾���Ϊ:"<<dis[i]<<"�����·����";
	// 	int u = i ,len=0;
	// 	int * que = new int[vs];
	// 	while(1)
	// 	{
	// 		que[len++] = u;
	// 		u = way [u];
	// 		if (u==0)
	// 		{
	// 			que[len++] = u;
	// 			break;
	// 		}
	// 	}
	// 	for (int i = len - 1 ;i >=0 ; i--)
	// 	{
			
	// 		if (i==0)
	// 		{
	// 			cout<<place[que[i]]<<endl;
	// 		}
	// 		else
	// 		{
	// 			cout<<place[que[i]]<<"-->";
	// 		}
	// 	}
		
	// }
	return 0;
}
