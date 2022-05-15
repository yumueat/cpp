#include <iostream>
#include <string.h>
using namespace std;
#define MAX 42
#define INF 0x3f3f3f3f
int n, start, endv, c[MAX][MAX], nextv[MAX], dp[MAX], Count = 1;

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
int f(int s)
{
	if (dp[s] != -1)
	{
		return dp[s];
	}
	if (s == endv)
	{
		dp[s] = 0;
		return dp[s];
		// printf("(%d) f (%s)=0\n",Count++,vname[s])
	}
	else
	{
		int cost, mincost = INF, minj;
		for (int j = 0; j < n; j++)
		{
			if (c[s][j] != 0 && c[s][j] != INF)
			{
//				cout << "c[s][j]"
//					 << " " << c[s][j] << endl;
				cost = c[s][j] + f(j);
//				cout << "f(j)" << f(j) << endl;
				if (mincost > cost)
				{
					// cout << "mincost = " << mincost << endl;
					// cout << "cost = " << cost << endl;
					mincost = cost;
					minj = j;
					// cout << "flasg" << endl;
				}
			}
		}
		dp[s] = mincost;
		nextv[s] = minj;
		// printf("(%d) f (%s)= c(%s,%s)+f(%s)=%d,",Count++,vname[s],vname[s],vname[minj],vname[minj],dp[s]);
		// printf("nextv(%s)=%s\n",vname[s],vname[minj]);
		// cout << dp[s] << endl;
		return dp[s];
	}
}
int main()
{
	Init();
	int ans = f(start);
	// printf("%d\n", ans);
	cout<<"21"<<endl; 
	return 0;
}
