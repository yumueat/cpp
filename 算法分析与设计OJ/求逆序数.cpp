#include <bits/stdc++.h>
using namespace std;

int temp[500010];

void mergeSort(int *q, int start, int end, long long int &count)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(q, start, mid, count);
	mergeSort(q, mid + 1, end, count);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (q[i] <= q[j])
		{
			temp[k++] = q[i++];
		}

		else
		{
			temp[k++] = q[j++];
			count = count + mid - i + 1;
		}
	}
	while (i <= mid)
	{
		temp[k++] = q[i++];
	}

	while (j <= end)
	{
		temp[k++] = q[j++];
	}

	for (i = start, j = 0; i <= end; i++, j++)
	{
		q[i] = temp[j];
	}
}

int main()
{
	int n, a[500010], i;
	long long count = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergeSort(a, 0, n - 1, count);
	cout << count << endl;
}
