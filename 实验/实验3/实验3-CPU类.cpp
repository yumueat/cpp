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
	private:
		int frequency=0;
		double voltage=0;
		enum CPU_Rank rank;
		
};
int main() 
{
	
	CPU myCPU;
	myCPU.run();
	myCPU.stop();
//	cout<<myCPU.voltage;
	return 0;
}
