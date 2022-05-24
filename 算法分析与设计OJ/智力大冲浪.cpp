#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 501
using namespace std;
#define INF 0x3f3f3f3f
struct active
{
	int time, money;
} obj[MAX];
bool cmp(active a, active b) { return a.money > b.money; }
int main()
{
	int money, n, i, j, temp, win;
	while (cin >> money)
	{
		cin >> n;
		int *flag = new int[n + 1];
		for (i = 0; i <= n; i++)
		{
			flag[i] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			cin >> obj[i].time;
		}
		for (i = 1; i <= n; i++)
		{
			cin >> obj[i].money;
		}
		sort(obj + 1, obj + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			win = 0;
			for (j = obj[i].time; j > 0; j--)
			{
				if (flag[j] == 0)
				{
					flag[j] = 1;
					win = 1;
					break;
				}
			}
			if (win == 0)
			{
				money -= obj[i].money;
			}
		}
		cout << money << endl;
	}
}

