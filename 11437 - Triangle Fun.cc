#include <iostream>

struct Point
{
	double x,y;
	Point(double a=0,double b=0){x=a;y=b;}
};

typedef Point Vector;

Vector operator + (Point a,Point b)
{
	return Vector(a.x+b.x,a.y+b.y);
}

Vector operator - (Point a,Point b)
{
	return Vector(a.x-b.x,a.y-b.y);
}


double Cross(Vector a,Vector b)
{
	return a.x*b.y-b.x*a.y;
}

int main(int argc, char *argv[]) {  
	int cas;
	std::cin >> cas;
	while(cas--) {
		Point a, b, c;
		std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		std::cout << int(Cross(b-a, c-a)/14 + 0.5) << std::endl;
	}
	return 0;
}