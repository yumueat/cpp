#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	int i, j, temp = 1, num, count = 0;
	vector<int> a;
	for (i = 1; i <= n; i++) //对每个输入进行处理
	{
		cin >> num;
		if (num == k)
		{
			while (temp * 2 <= i) //是2的幂的就记为0
			{
				temp *= 2;
			}
			a.push_back(i - temp); //不是2的幂就记录删掉所需的次数
		}
	}
	i = 0;
	for (i = 0; i < a.size(); i++)
	{
		if (count >= a[i]) //如果目前删的次数已经超过或等于预计删的次数，那么可以直接一次删除，也不用考虑位置问题，因为这是在比第i个，只要是前面的删了，当前位置都会变，前面删的是哪个其实不重要
			count++;
		else
			count = a[i] + 1; //如果删除的次数还不够直接一次删除，那么就直接让次数等于要删除的次数+1，这样也是满足前面的情况的
	}
	cout << count << endl;
}

