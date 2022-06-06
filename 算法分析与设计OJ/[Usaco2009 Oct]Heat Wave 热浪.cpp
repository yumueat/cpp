#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int maxn = 20005;
int head[maxn], nex[maxn], to[maxn], value[maxn], tot;
int dis[maxn], visit[maxn];

void add(int x, int y, int z)
{
    to[++tot] = y;
    nex[tot] = head[x];
    value[tot] = z;
    head[x] = tot;
}

void dijkstra(int start)
{
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;    //起点到自己的最短距离为0
    q.push(start);     //将起点压入队列
    visit[start] = 1;  //标记起点为已经查过
    while (!q.empty()) //如果队列不空
    {
        int now = q.front();                   //取出队首元素
        q.pop();                               //队首元素出队
        visit[now] = 0;                        //标记刚刚取出的点为没有搜索过
        for (int i = head[now]; i; i = nex[i]) //探查当前选中点为起点的边
        {
            int v = to[i], w = value[i];
            if (dis[v] > dis[now] + w) //判断到终点的距离是否更短
            {
                dis[v] = dis[now] + w;
                if (!visit[v]) //如果更短而且边的终点是没有被搜索过的
                {
                    q.push(v);    //把终点压入队列
                    visit[v] = 1; //标记已经被搜索过
                }
            }
        }
    }
}

int main()
{
    int n, m, s, t; // ts为起点，te为重点
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w); //因为是无向图，所以两个方向都要添加
    }
    dijkstra(s);
    cout << dis[t] << endl;
    system("pause");
    return 0;
}

