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
		cin >> a[i]; // ��ɵ���
	}
	for (i = 0; i < n; ++i)
	{
		cin >> b[i]; // ����������
	}

	sort(a, a + n); // ��������
	sort(b, b + n);

	l1 = l2 = 0;
	r1 = r2 = n - 1;

	while (l1 <= r1)
	{
		if (a[r1] > b[r2]) //���������ɿ죬��ʹ��������������������
		{
			winCount++;
			--r1;
			--r2;
		}
		else if (a[r1] < b[r2]) //������������죬��ʹ���������������������
		{
			lostCount++;
			++l1;
			--r2;
		}
		else //���������ͬ�٣�
		{
			if (a[l1] > b[l2]) //��������ɿ죬��ʹ����������������������
			{
				winCount++;
				++l1;
				++l2;
			}
			else //������ʹ���������������������
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

