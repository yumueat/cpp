#include<iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU 
{
	public:
		CPU() 
		{
			cout<<"构造函数开始"<<endl;
		}
		~CPU() 
		{
			cout<<"析构函数开始"<<endl;
		}
		void run() 
		{
			cout<<"CPU开始运行"<<endl;
		}
		void stop() 
		{
			cout<<"CPU停止运行"<<endl;
		}
		void setElem(int a,double b,enum CPU_Rank c)
		{
			frequency=a;
			voltage=b;
			rank=c;
		}
		void getElem()
		{
			cout<<"frequency="<<frequency<<endl;
			cout<<"voltage="<<voltage<<endl;
			cout<<"rank="<<rank<<endl;
		}
	private:
		int frequency;
		double voltage;
		enum CPU_Rank rank;
};
int main() 
{
	CPU myCPU;
	myCPU.run();
	myCPU.stop();
	myCPU.setElem(60,120,P2);
    myCPU.getElem();
	return 0;
}
