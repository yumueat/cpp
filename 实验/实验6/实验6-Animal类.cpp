#include <iostream>
using namespace std;
class Animal{
    public:
        int age;
};
class dog:public Animal{
    public:
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
