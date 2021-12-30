#include<iostream>
#include "point.h"
using namespace std;
void fun1(Point p) {
    cout << p.getX() << endl;
}

//函数定义 
Point fun2() {
    Point a(1, 2);
    return a;
}
int main() {
    Point a(4, 5);	//实例化a为point类的对象 
    Point b = a;	//使用拷贝构造函数 
    cout << b.getX() << endl;
    fun1(b);		//调用函数查看b的值 
    b = fun2();		 
    cout << b.getX() << endl;
    return 0;
}
