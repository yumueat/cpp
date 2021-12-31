#include <iostream>
using namespace std;
class Animal{
    public:
        Animal(){
            cout<<"Animal类构造函数运行"<<endl;
        }
        ~Animal(){
            cout<<"Animal类析构函数运行"<<endl;
        }
        int age=0;
};
class dog:protected Animal{
    public:
        dog(){
            cout<<"dog类构造函数运行"<<endl;
        }
        ~dog(){
            cout<<"dog类析构函数运行"<<endl;
        }
        void SetAge(int n){
            age=n;  
        }
        int GetAge(){
            return age;
        }

};
int main()
{
    dog yellowdog;
    yellowdog.SetAge(3);
    cout << "Age: " << yellowdog.GetAge() << endl;
    return 0;
}
