#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, m, min, i, j, ask;
	cin >> n >> m;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (m--)
	{
		cin >> ask;
		min = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > ask)
			{
				break;
			}
			if (a[i] > min)
			{
				min = a[i];
			}
		}
		cout << min << endl;
	}
	return 0;
}

