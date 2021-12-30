class Point {	
public:		//公有成员变量 
    Point(int, int);
    Point(Point &p);	//拷贝构造函数 
    int getX();
    int getY();
private:	//私有成员变量 
    int x, y;
};

