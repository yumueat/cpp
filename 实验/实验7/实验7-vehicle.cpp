#include <iostream>
using namespace std;
class vehicle{
    public:
        double MaxSpeed=100;
        double Weight=100;
        virtual void Run(){
            cout<<"The vehicle is running"<<endl;
        }
        virtual void Stop(){
            cout<<"The vehicle is stopping"<<endl;
        }
};
class bicycle : virtual public vehicle{
    public:
        void Run(){
            cout<<"The bicycle is running"<<endl;
        }
        void Stop(){
            cout<<"The bicycle is stopping"<<endl;
        }
        double Height=100;
};
class motorcar : virtual public vehicle{
    public:
        void Run(){
            cout<<"The motorcar is running"<<endl;
        }
        void Stop(){
            cout<<"The motorcar is stopping"<<endl;
        }
        double SeatNum=5;
};
class motorcycle : public bicycle, public motorcar{
    public:
        void Run(){
            cout<<"The motorcycle is running"<<endl;
        }
        void Stop(){
            cout<<"The motorcycle is stopping"<<endl;
        }
};
int main()
{
    motorcycle motorcycle1;
    motorcar motorcar1;
    bicycle bicycle1;
    vehicle vehicle1;
    vehicle1.Run();
    vehicle1.Stop();
    bicycle1.Run();
    bicycle1.Stop();
    motorcar1.Run();
    motorcar1.Stop();
    motorcycle1.Run();
    motorcycle1.Stop();
    // cout<<"Height: "<<motorcycle1.Height<<endl;
    // cout<<"SeatNum: "<<motorcycle1.SeatNum<<endl;
    // cout<<"Weight: "<<motorcycle1.Weight<<endl;
    // cout<<"MaxSpeed: "<<motorcycle1.MaxSpeed<<endl;
    return 0;
}
