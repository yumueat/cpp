class Point {	
public:		//���г�Ա���� 
    Point(int, int);
    Point(Point &p);	//�������캯�� 
    int getX();
    int getY();
private:	//˽�г�Ա���� 
    int x, y;
};

