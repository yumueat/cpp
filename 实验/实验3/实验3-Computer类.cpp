#include<iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class RAM
{
public:
    RAM()
    {
        cout<<"RAM构造函数开始"<<endl;
    }
    ~RAM()
    {
        cout<<"RAM析构函数开始"<<endl;
    }
    void run()
    {
        cout<<"RAM开始运行"<<endl;
    }
    void stop()
    {
        cout<<"RAM停止运行"<<endl;
    }
    void setElem(int a)
    {
        memory=a;

    }
    void getElem()
    {
        cout<<"memory="<<memory<<endl;
    }
private:
    int memory;
};
class CDROM
{
public:
    CDROM()
    {
        cout<<"CDROM构造函数开始"<<endl;
    }
    ~CDROM()
    {
        cout<<"CDROM析构函数开始"<<endl;
    }
    void run()
    {
        cout<<"CDROM开始运行"<<endl;
    }
    void stop()
    {
        cout<<"CDROM停止运行"<<endl;
    }
    void setElem(int a)
    {
        speed=a;

    }
    void getElem()
    {
        cout<<"speed="<<speed<<endl;
    }
private:
    int speed;
};
class CPU
{
public:
    CPU()
    {
        cout<<"CPU构造函数开始"<<endl;
    }
    ~CPU()
    {
        cout<<"CPU析构函数开始"<<endl;
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
class Computer
{
public:
    Computer()
    {
        cout<<"Computer构造函数开始"<<endl;
    }
    ~Computer()
    {
        cout<<"Computer析构函数开始"<<endl;
    }
    void run()
    {
        cout<<"Computer开始运行"<<endl;
        cpu.run();
        ram.run();
        cdrom.run();
    }
    void stop()
    {
        cdrom.stop();
        ram.stop();
        cpu.stop();
        cout<<"Computer停止运行"<<endl;
    }
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;

};
int main()
{
    Computer myComputer;
    myComputer.run();
    myComputer.stop();
//    myComputer.setElem(60,120,P2);
//    myComputer.getElem();
//	cout<<myCPU.voltage;
    return 0;
}
