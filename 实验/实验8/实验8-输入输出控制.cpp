#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
 
int main()
{
	double values[]={1.23,35.36,1653.7,54358.324354};
	string names[]={"Zoot","Jimmy","A1","Yehengzhou"};
	for(int i=0;i<4;i++)
	{
		cout.width(8);
		if(i==1) cout.fill('*');
		cout<<setprecision(10)<<values[i]<<endl;
	}
	cout.fill(' ');
	for(int i=0;i<4;i++)
		cout<<setiosflags(ios::left)<<setw(12)<<names[i]
		    <<resetiosflags(ios::left)<<setw(12)<<values[i]<<endl;
	return 0;
}
