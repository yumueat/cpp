#include <iostream>
using namespace std;
class Animal{
    public:
        Animal(){
            cout<<"Animal�๹�캯������"<<endl;
        }
        ~Animal(){
            cout<<"Animal��������������"<<endl;
        }
        int age=0;
};
class dog:protected Animal{
    public:
        dog(){
            cout<<"dog�๹�캯������"<<endl;
        }
        ~dog(){
            cout<<"dog��������������"<<endl;
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
