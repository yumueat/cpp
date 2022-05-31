#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	int n, l1, l2, r1, r2;
	cin >> n;
	int i, winCount = 0, lostCount = 0;
	int *a = new int[n];
	int *b = new int[n];
	for (i = 0; i < n; ++i)
	{
		cin >> a[i]; // 田忌的马
	}
	for (i = 0; i < n; ++i)
	{
		cin >> b[i]; // 齐威王的马
	}

	sort(a, a + n); // 升序排列
	sort(b, b + n);

	l1 = l2 = 0;
	r1 = r2 = n - 1;

	while (l1 <= r1)
	{
		if (a[r1] > b[r2]) //最快马。若田忌快，则使用田忌最快马对齐王最快马
		{
			winCount++;
			--r1;
			--r2;
		}
		else if (a[r1] < b[r2]) //最快马。若齐王快，则使用田忌最慢马对齐王最快马
		{
			lostCount++;
			++l1;
			--r2;
		}
		else //最快马。两者同速：
		{
			if (a[l1] > b[l2]) //最慢马田忌快，则使用田忌最慢马对齐王最慢马。
			{
				winCount++;
				++l1;
				++l2;
			}
			else //否则，则使用田忌最慢马对齐王最快马。
			{
				if (a[l1] < b[r2])
				{
					lostCount++;
				}

				++l1;
				--r2;
			}
		}
	}
	cout << (winCount - lostCount) * 200 << endl;
	return 0;
}

