#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	int i, j, temp = 1, num, count = 0;
	vector<int> a;
	for (i = 1; i <= n; i++) //��ÿ��������д���
	{
		cin >> num;
		if (num == k)
		{
			while (temp * 2 <= i) //��2���ݵľͼ�Ϊ0
			{
				temp *= 2;
			}
			a.push_back(i - temp); //����2���ݾͼ�¼ɾ������Ĵ���
		}
	}
	i = 0;
	for (i = 0; i < a.size(); i++)
	{
		if (count >= a[i]) //���Ŀǰɾ�Ĵ����Ѿ����������Ԥ��ɾ�Ĵ�������ô����ֱ��һ��ɾ����Ҳ���ÿ���λ�����⣬��Ϊ�����ڱȵ�i����ֻҪ��ǰ���ɾ�ˣ���ǰλ�ö���䣬ǰ��ɾ�����ĸ���ʵ����Ҫ
			count++;
		else
			count = a[i] + 1; //���ɾ���Ĵ���������ֱ��һ��ɾ������ô��ֱ���ô�������Ҫɾ���Ĵ���+1������Ҳ������ǰ��������
	}
	cout << count << endl;
}

