#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define MAX 100000
#define INF 0x3f3f3f3f
using namespace std;
int a[MAX];
int merge(int start, int end, int ask)
{
	if (end == start + 1)
	{
		if (abs(a[start] - ask) < abs(a[end] - ask))
		{
			return start;
		}
		else if (abs(a[start] - ask) > abs(a[end] - ask))
		{
			return end;
		}
		else if (abs(a[start] - ask) == abs(a[end] - ask))
		{
			return start < end ? start : end;
		}
	}
	if (ask > a[(start + end) / 2])
	{
		merge((start + end) / 2, end, ask);
	}
	else if (ask < a[(start + end)])
	{
		merge(start, (start + end) / 2, ask);
	}
	else if (ask == a[(start + end) / 2])
	{
		return (start + end) / 2;
	}
}
int main()
{
	int n, i, j, m, flag;
	int ask, minNum;
	cin >> n;
	// long long *a = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	while (m--)
	{
		// minNum = INF;
		cin >> ask;
		minNum = merge(0, n - 1, ask);
		cout << a[minNum] << endl;
	}
}

