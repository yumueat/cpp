#include<iostream>
using namespace std;
const double pi=3.14; 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cout<<"������Ҫ�����ͼ������:"<<endl;
		cout<<"a.Բ�� b.������ c.������"<<endl;
		char shape;
		cin>>shape;
		double s;
		if (shape=='a')
		{
			cout<<"������뾶:";
			double r; 
			cin>>r;
			s=pi*r*r;
			printf("%.2lf\n",s);
		}
		else if (shape=='b')
		{
			double l,w;
			cout<<"�����볤�Ϳ�:";
			cin>>l>>w;
			s=l*w;
			printf("%.2lf\n",s);
		}
		else if (shape=='c')
		{
			double a;
			cout<<"������߳�:";
			cin>>a;
			s=a*a;
			printf("%.2lf\n",s);
		}
	}
	return 0;
}
