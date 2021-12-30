#include<iostream>
#include "Point.h"
using namespace std;
Point::Point(int xx = 0, int yy = 0) {	//构造函数的声明 
        x = xx;
        y = yy;
    }
//对拷贝构造函数的定义 
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
