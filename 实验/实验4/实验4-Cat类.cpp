#include<iostream>
using namespace std;
class Cat
{
private:
    static int CountOfCats;
public:
    static void GetNumOfCats();
};
int Cat::CountOfCats=20;
void Cat::GetNumOfCats()
{
    cout<<CountOfCats<<endl;
}
int main()
{
    Cat cat;
    cat.GetNumOfCats();
    return 0;
}
