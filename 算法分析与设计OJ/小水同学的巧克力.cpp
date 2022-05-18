#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int sum = 0;
vector<long long int> square;
void split(double a, double b)
{
	double maxNum, minNum;
	maxNum = max(a, b);
	minNum = min(a, b);
	square.push_back(minNum * minNum);
	if (maxNum != minNum)
	{
		split(minNum, maxNum - minNum);
	}
}
int main()
{
	int n, m, i;

	cin >> n >> m;
	long long int a, b;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		split(a, b);
	}
	sort(square.begin(), square.end());
	reverse(square.begin(), square.end());
	for (i = 0; i < m; i++)
	{
		sum += square[i];
	}
	cout << sum << endl;
}

