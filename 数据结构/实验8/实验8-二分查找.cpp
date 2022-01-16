#include<iostream>
using namespace std;
int s[]={05,13,19,21,37,56,64,75,80,88,92};

int binarySearch(int low, int high,int k)
{
	int mid = (high + low) / 2;
	if (k == s[mid])
	{
		return mid + 1;
	}
	else if (k < s[mid])
	{
		return binarySearch(low, mid - 1,k);
	}
	else
	{
		return binarySearch(mid + 1, high,k);
	}
}
int main()
{
	int len = sizeof(s)/sizeof(s[0]);
	int k = 64,low=0,high=len-1,mid=(low+high)/2,pos;
	pos = binarySearch(low, high, k);
	cout<<"kµÄÎ»ÖÃÊÇ:"<<pos<<endl;
	// cout<<sizeof(s)/sizeof(s[0])<<endl;
	return 0; 
}

