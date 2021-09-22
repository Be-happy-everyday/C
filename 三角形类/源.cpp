#include<iostream>
#include<cmath>
using namespace std;

class Ctriangle
{
private:
	double line_1;
	double line_2;
	double line_3;
	double perimeter;
	double area;

public:
	Ctriangle(double a, double b, double c)
	{
		line_1 = a;
		line_2 = b;
		line_3 = c;
		perimeter = a + b + c;
		double p = perimeter / 2;
		area = sqrt((p * (p - a) * (p - b) * (p - c)));
	}

	double GetPerimeter()
	{
		return perimeter;
	}

	double GetArea()
	{
		return area;
	}

	void display()
	{
		cout<<"Ctriangle:a="<<line_1<<",b="<<line_2<<",c="<<line_3 << endl;
	}
};

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	Ctriangle T(a, b, c);
	T.display();
	cout << "Perimeter:" << T.GetPerimeter() << endl;
	cout << "Area:" << T.GetArea() << endl;
	return 0;
}