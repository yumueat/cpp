#include<iostream>
using namespace std;
const double pi=3.14; 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cout<<"请输入要计算的图形类型:"<<endl;
		cout<<"a.圆形 b.长方形 c.正方形"<<endl;
		char shape;
		cin>>shape;
		double s;
		if (shape=='a')
		{
			cout<<"请输入半径:";
			double r; 
			cin>>r;
			s=pi*r*r;
			printf("%.2lf\n",s);
		}
		else if (shape=='b')
		{
			double l,w;
			cout<<"请输入长和宽:";
			cin>>l>>w;
			s=l*w;
			printf("%.2lf\n",s);
		}
		else if (shape=='c')
		{
			double a;
			cout<<"请输入边长:";
			cin>>a;
			s=a*a;
			printf("%.2lf\n",s);
		}
	}
	return 0;
}
