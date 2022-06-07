#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 105;
int graph[maxn][maxn], n, m;
void init()
{
    for (int i = 0; i <= n; i++) //��ʼ��,ֻ������յ�һ��ʱΪ0
    {
        for (int j = 0; j <= n; j++)
        {
            graph[i][j] = i == j ? 0 : INF;
        }
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j])); //�����������㷨�еļӻ���max����
            }
        }
    }
}
int main()
{
    int q, count = 1, u, v, w;
    while (cin >> n >> m >> q)
    {
        init();
        while (m--)
        {
            cin >> u >> v >> w;
            if (graph[u][v] > w) //�п��ܴ���ͬһ�ζ���ֵ
            {
                graph[u][v] = graph[v][u] = w;
            }
        }
        cout << "Case #" << count++ << endl;
        floyd();
        while (q--)
        {
            cin >> u >> v;
            if (graph[u][v] >= INF) //�������ֵ֤��·��ͨ
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << graph[u][v] << endl;
            }
        }
    }
    return 0;
}
