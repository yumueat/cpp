#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#define MAXN 500000
#define INF 0x7fffffff//最大的整形数
using namespace std;
// 初始化
struct Node//点集 
{
	int num,dis;//num为节点编号，dis为起点s到num的最短距离
	Node(int a,int b)//初始化（构造函数）
	{
		num=a;
		dis=b;
	}
	friend bool operator < (const Node &a,const Node &b)//重载运算符，便于优先队列排序
	{
		return a.dis>b.dis;//距离短的优先 
	}
};
struct Edge
{
    int to,value,nxt;//终点，边权，同起点的另一条边的编号，通过一条边标记另一条边，可以把所有的边都记下来
}e[MAXN];//边集
int vs,edges;//点的数量，边的数量
int Head[MAXN];//head[i],表示以i为起点的一条边在边集数组的位置（编号），然后借助nxt的标记可以遍历同起点的所有边
int index;//代表边的编号
int dis[MAXN];//存储距离的数组
bool visit[MAXN];//存储算出最短距离的点的数组
int way[MAXN];//存储路线的数组

// 函数定义
//用于添加边的函数
void Add(int u,int v,int value)
{ 
    e[++index].to=v;//第index条边的终点是v
    e[index].value=value;//权值 
    e[index].nxt=Head[u];//同起点上一条边的编号
    Head[u]=index;//把这条边的编号更新到Head数组里面
}
priority_queue <Node> q;//新建一个点集的优先队列

// 迪杰斯特拉算法
void dijkstra(int s)//传入起点
{
	fill(dis,dis+MAXN,INF);//把距离数组的每一项填充为最大值
	dis[s]=0;//到起点的距离设置为0
	while(!q.empty())//只要队列不为空，一个个点看过去
	{
		int u=q.top().num;//u为队首
		q.pop();//弹出队首元素
		if(visit[u])//判断以u为起点的边是否被遍历
		{
			continue;//跳过循环
		}
		else
		{
			visit[u]=1;//标记为被遍历，然后下面准备开始遍历
		}
		for(int i=Head[u];i!=0;i=e[i].nxt)//遍历以这个点为起点的所有点
		{
			int v=e[i].to;//获取终点
            if(visit[v]==0&&dis[u]+e[i].value<dis[v])//如果终点没有被计算过，且新的路线比之前的路线更短
			{
                dis[v]=dis[u]+e[i].value;//就把更短的路线加进去
				way[v]=u;//记录路线
                q.push(Node(v,dis[v]));//把新算出来的点和距离加进去，从而可以不断比较找到最短的距离
            }
        }
	}
}

// 按照地图集把地点转换为编号的函数
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
	string s,a,b;//起点，e{a,b}
	int u,v,start;//用于计算的点(编号)，需要通过函数处理
	int value;//权重value
	cout<<"请输入地点的数量、路的数量和起点：";
	cin>>vs>>edges>>s; 
	cout<<"请依次输入地点的名称（从起点开始）:";
	string * place = new string[vs];//地图集，用于存储地点
	for(int i=0;i<vs;i++)
	{	
		cin>>place[i];
	}
	start = placeSearch(s,place);//获取起点编号
	cout<<"请依次输入每条路的起点终点和权值:";
	for(int i=0;i<edges;i++)//依次输入每条边的起点终点和权值
	{ 
		cin>>a>>b>>value;
		u=placeSearch(a,place);
		v=placeSearch(b,place);
		Add(u,v,value);//把边加入到集合中去
	}
	q.push(Node(start,dis[start]));//把起点加到队列里面去
	dijkstra(start);//最短路径算法

	// 输出最短路径
	string searchplace;
	cout<<"请输入要查询最短路径的地点：";
	cin>>searchplace;
	int i=placeSearch(searchplace,place);
	cout<<place[0]<<"到"<<place[i]<<"的最短距离为:"<<dis[i]<<"，最佳路径是";
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

	// 测试时输出全部最短路径
	// for(int i=1;i<vs;i++)//输出起点到各点的最短距离
	// {
	// 	cout<<place[0]<<"到"<<place[i]<<"的最短距离为:"<<dis[i]<<"，最佳路径是";
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
