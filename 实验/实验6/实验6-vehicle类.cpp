#include <iostream>
using namespace std;
class vehicle{
    public:
        double MaxSpeed=100;
        double Weight=100;
        void Run(){
            cout<<"The vehicle is running"<<endl;
        }
        void Stop(){
            cout<<"The vehicle is stopping"<<endl;
        }
};
class bicycle : virtual public vehicle{
    public:
        double Height=100;
};
class motorcar : virtual public vehicle{
    public:
        double SeatNum=5;
};
class motorcycle : public bicycle, public motorcar{

};
int main()
{
    motorcycle motorcycle1;
    motorcycle1.Run();
    motorcycle1.Stop();
    cout<<"Height: "<<motorcycle1.Height<<endl;
    cout<<"SeatNum: "<<motorcycle1.SeatNum<<endl;
    cout<<"Weight: "<<motorcycle1.Weight<<endl;
    cout<<"MaxSpeed: "<<motorcycle1.MaxSpeed<<endl;
    return 0;
}
