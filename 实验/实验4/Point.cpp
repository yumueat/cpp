#include<iostream>
#include "Point.h"
using namespace std;
Point::Point(int xx = 0, int yy = 0) {	//���캯�������� 
        x = xx;
        y = yy;
    }
//�Կ������캯���Ķ��� 
Point::Point(Point &p) {
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}
int Point::getX() {
        return x;
    }
int Point::getY() {
    return y;
}
