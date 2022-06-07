#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 105;
int graph[maxn][maxn], n, m;
void init()
{
    for (int i = 0; i <= n; i++) //初始化,只有起点终点一样时为0
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
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j])); //将弗洛伊德算法中的加换成max即可
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
            if (graph[u][v] > w) //有可能存在同一段都有值
            {
                graph[u][v] = graph[v][u] = w;
            }
        }
        cout << "Case #" << count++ << endl;
        floyd();
        while (q--)
        {
            cin >> u >> v;
            if (graph[u][v] >= INF) //超过最大值证明路不通
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
