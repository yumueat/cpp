#include<iostream>
using namespace std;
class Car;
class Boat
{
private:
    double weight=10;
public:
    friend void totalWeight(Boat boat,Car car);
    
};

class Car
{
private:
    double weight=30;
public:
    friend void totalWeight(Boat boat,Car car);
};
void totalWeight(Boat boat,Car car)
{
    cout<<"���ߵ�������Ϊ:"<<car.weight+boat.weight<<endl;
}   

int  main()
{
    Boat boat;
    Car car;
    totalWeight(boat,car);
    return 0;
}


