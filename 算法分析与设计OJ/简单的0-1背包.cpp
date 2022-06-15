#include <iostream>
#include <algorithm>
#define MAXN 20
using namespace std;
int *v;
int *w;
int dp[MAXN + 1][MAXN + 1];
int n, capacity;
void init()
{
	int i, j;
	for (i = 0; i <= MAXN; i++)
	{
		for (j = 0; j <= MAXN; j++)
		{
			dp[i][j] = 0;
		}
	}
}
void DPfind()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= capacity; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i] + v[i]]);
			}
		}
	}
}
int main()
{
	int i;
	while (cin >> capacity >> n)
	{
		v = new int[n + 1];
		w = new int[n + 1];
		init();
		for (i = 1; i <= n; i++)
		{
			cin >> w[i] >> v[i];
		}
		DPfind();
		cout << dp[n][capacity] << endl;
	}
	system("pause");
	return 0;
}