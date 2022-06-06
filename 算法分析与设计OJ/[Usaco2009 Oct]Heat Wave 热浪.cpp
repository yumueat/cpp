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
    dis[start] = 0;    //��㵽�Լ�����̾���Ϊ0
    q.push(start);     //�����ѹ�����
    visit[start] = 1;  //������Ϊ�Ѿ����
    while (!q.empty()) //������в���
    {
        int now = q.front();                   //ȡ������Ԫ��
        q.pop();                               //����Ԫ�س���
        visit[now] = 0;                        //��Ǹո�ȡ���ĵ�Ϊû��������
        for (int i = head[now]; i; i = nex[i]) //̽�鵱ǰѡ�е�Ϊ���ı�
        {
            int v = to[i], w = value[i];
            if (dis[v] > dis[now] + w) //�жϵ��յ�ľ����Ƿ����
            {
                dis[v] = dis[now] + w;
                if (!visit[v]) //������̶��ұߵ��յ���û�б���������
                {
                    q.push(v);    //���յ�ѹ�����
                    visit[v] = 1; //����Ѿ���������
                }
            }
        }
    }
}

int main()
{
    int n, m, s, t; // tsΪ��㣬teΪ�ص�
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w); //��Ϊ������ͼ��������������Ҫ���
    }
    dijkstra(s);
    cout << dis[t] << endl;
    system("pause");
    return 0;
}

