#include<iostream>
#include "point.h"
using namespace std;
void fun1(Point p) {
    cout << p.getX() << endl;
}

//�������� 
Point fun2() {
    Point a(1, 2);
    return a;
}
int main() {
    Point a(4, 5);	//ʵ����aΪpoint��Ķ��� 
    Point b = a;	//ʹ�ÿ������캯�� 
    cout << b.getX() << endl;
    fun1(b);		//���ú����鿴b��ֵ 
    b = fun2();		 
    cout << b.getX() << endl;
    return 0;
}
