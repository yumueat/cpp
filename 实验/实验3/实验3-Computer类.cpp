#include<iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class RAM
{
public:
    RAM()
    {
        cout<<"RAM���캯����ʼ"<<endl;
    }
    ~RAM()
    {
        cout<<"RAM����������ʼ"<<endl;
    }
    void run()
    {
        cout<<"RAM��ʼ����"<<endl;
    }
    void stop()
    {
        cout<<"RAMֹͣ����"<<endl;
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
        cout<<"CDROM���캯����ʼ"<<endl;
    }
    ~CDROM()
    {
        cout<<"CDROM����������ʼ"<<endl;
    }
    void run()
    {
        cout<<"CDROM��ʼ����"<<endl;
    }
    void stop()
    {
        cout<<"CDROMֹͣ����"<<endl;
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
        cout<<"CPU���캯����ʼ"<<endl;
    }
    ~CPU()
    {
        cout<<"CPU����������ʼ"<<endl;
    }
    void run()
    {
        cout<<"CPU��ʼ����"<<endl;
    }
    void stop()
    {
        cout<<"CPUֹͣ����"<<endl;
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
        cout<<"Computer���캯����ʼ"<<endl;
    }
    ~Computer()
    {
        cout<<"Computer����������ʼ"<<endl;
    }
    void run()
    {
        cout<<"Computer��ʼ����"<<endl;
        cpu.run();
        ram.run();
        cdrom.run();
    }
    void stop()
    {
        cdrom.stop();
        ram.stop();
        cpu.stop();
        cout<<"Computerֹͣ����"<<endl;
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
