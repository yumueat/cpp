#include <iostream>
#include <string.h>
using namespace std;
#define MAX 42
#define INF 0x3f3f3f3f
int n, start, endv, c[MAX][MAX], nextv[MAX], dp[MAX], Count = 1;
int minNum = INF * -1;
void Init()
{
	n = 18;
	start = 0;
	endv = 17;
	memset(c, INF, sizeof(c));
	for (int i = 0; i < n; i++)
	{
		dp[i] = -1;
	}
	for (int j = 0; j < n; j++)
	{
		c[j][j] = 0;
	}
	c[0][1] = 4;
	c[0][2] = 4;
	c[0][3] = 5;
	c[0][4] = 8;

	c[1][5] = 3;
	c[1][6] = 5;
	c[1][7] = 6;
	c[1][8] = 7;
	c[2][5] = 3;
	c[2][6] = 5;
	c[2][7] = 6;
	c[3][5] = 3;
	c[3][6] = 5;
	c[4][5] = 3;

	c[5][9] = 5;
	c[5][10] = 6;
	c[5][11] = 8;
	c[5][12] = 8;
	c[6][9] = 5;
	c[6][10] = 6;
	c[6][11] = 8;
	c[7][9] = 5;
	c[7][10] = 6;
	c[8][9] = 5;

	c[9][13] = 2;
	c[9][14] = 4;
	c[9][15] = 7;
	c[9][16] = 8;
	c[10][13] = 2;
	c[10][14] = 4;
	c[10][15] = 7;
	c[11][13] = 2;
	c[11][14] = 4;
	c[12][13] = 2;

	c[13][17] = 0;
	c[14][17] = 0;
	c[15][17] = 0;
	c[16][17] = 0;
}
int f(int s, int sum, int j)
{
	if (j == 0 || j == 17)
	{
		sum += 0;
	}
	else if (j % 4 == 0)
	{
		sum += 4;
	}
	else
	{
		sum += j % 4;
	}
	if (sum > 7)
	{
		return minNum;
	}
	if (dp[s] != -1)
	{
		return dp[s];
	}
	if (s == endv)
	{
		dp[s] = 0;
		return dp[s];
	}
	else
	{
		int cost, maxcost = 0, maxj, sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (c[s][j] != 0 && c[s][j] != INF)
			{

				// cout << "c[" << s << "][" << j << "]"
				// 	 << " " << c[s][j] << endl;
				cost = c[s][j] + f(j, sum, j);
				// cout << "f(" << j << ")" << f(j, sum) << endl;
				if (maxcost < cost)
				{
					maxcost = cost;
					maxj = j;
				}
			}
		}

		dp[s] = maxcost;
		nextv[s] = maxj;
		return dp[s];
	}
}
int main()
{
	int sum = 0;
	Init();
	int ans = f(start, sum, 0);
	printf("%d\n", ans);
	// for (int j = 0; j < 4; j++)
	// {
	// 	cout << nextv[j] << " ";
	// }
	// cout << endl;
	return 0;
}
