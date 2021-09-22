#include<iostream>
#include<cmath>
using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point(double a, double b)
	{
		x = a;
		y = b;
	}

	double GetX()
	{
		return x;
	}

	double GetY()
	{
		return y;
	}

	double Distance(Point z)
	{
		double distance = sqrt((x-z.GetX())* (x - z.GetX()) + (y-z.GetY())* (y - z.GetY()));
		return distance;
	}
};

int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cout << A.Distance(B) << endl;
	return 0;
}