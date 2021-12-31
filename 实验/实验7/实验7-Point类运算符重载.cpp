#include<iostream>
using namespace std;
class Point{
    public:
        int x, y;
        Point(int xx=10, int yy=0)
        {
            x=xx; 
            y=yy;
        }
        // Point operator+(const Point& a) 
        // {
        //     Point p;
        //     p.x=this->x+a.x;
        //     p.y=this->y+a.y;
        //     return p; 
        // }
        // Point operator-(const Point& a)
        // {
        //     Point p;
        //     p.x=this->x-a.x;
        //     p.y=this->y-a.y;
        //     return p;
        // }
        // Point operator++()
        // {
        //     return Point(++x,++y);
        // }
        // Point operator--()
        // {
        //     return Point(--x,--y);
        // }   
        // Point operator++(int )
        // {
        //     Point p(x,y);
        //     this->x++; 
        //     this->y++;
        //     return p;
        // }
        // Point operator--(int )
        // {
        //     Point p(x,y);
        //     this->x--; 
        //     this->y--;
        //     return p;
        // }
        void showPoint()
        {
            cout<<x<<","<<y<<endl;
        }
};
Point operator+(const Point& a,const Point& b) 
{
    Point p;
    p.x=a.x+b.x; 
    p.y=a.y+b.y;
    return p; 
}
Point operator-(const Point& a,const Point& b) 
{
    Point p;
    p.x=a.x-b.x;
    p.y=a.y-b.y;
    return p;
}
Point operator++(Point& a)
{
    a.x++;
    a.y++;
    return Point(a.x,a.y);
}
Point operator--(Point& a)
{
    a.x--; 
    a.y--;
    return Point(a.x,a.y);
}   
Point operator++(Point& a,int )
{
    Point p(a.x,a.y);
    a.x++; 
    a.y++;
    return p;
}
Point operator--(Point& a,int )
{
    Point p(a.x,a.y);
    a.x--; 
    a.y--;
    return p;
}
int main()
{   
    Point p1(1,1),p2(2,2),p3;
    p3=p1+p2;
    p3.showPoint();
    p3=p2-p1;
    p3.showPoint();
    ++p3;
    p3.showPoint();
    --p3;
    p3.showPoint();
    p3++;
    p3.showPoint();
    p3--;
    p3.showPoint();
    return 0;
}
