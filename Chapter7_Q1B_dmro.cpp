#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

void computeCircle(double width, double length);
void computeTriangle(double width, double length);
void computeRectangle(double width, double length);

int main()
{
	int choice;
	double width, length, radius, a, b, c;
	cout << "---------------Area computation---------------\n";
	cout << "1.   Circle\n2.	Triangle\n3.	Rectangle\n";
	cout << "Enter your choice ";
	cin >> choice;
	if (choice == 1) {
		cout << "Enter radius";
		cin >> radius;
		computeCircle(radius);	// function to compute area of rectangle
	}
	else if (choice == 2) {
		cout << "Enter a, b, c";
		cin >> a >> b >> c;
		computeTriangle(width, length);	// function to compute area of rectangle
	}
	else if (choice == 3) {
		cout << "Enter width and length : ";
		cin >> width >> length;
		computeRectangle(width, length);	// function to compute area of rectangle
	}
	
	cout << "End of Program!\n";
	system("pause");
	return 0;
}

void computeCircle(double radius)
{
	const double PI = 3.141592;
	double area, radius;
	cout << "Enter radius of circle :	";
	cin >> radius;
	area = radius * radius * PI;}

void computeTriangle(double a, double b, double c)
{
	double a, b, c, area,s;
	cout << "Enter side a :";
	cin >> a;
	cout << "Enter side b : ";
	cin >> b;
	cout << "Enter side c : ";
	cin >> c;
	cout << endl;
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "The area of the triangle is " << area << endl;
}
void computeRectangle(double width, double length)
{
	double height, width, area;
	cout << "Enter width : ";
	cin >> width;
	cout << "Enter height : ";
	cin >> height;
	area = width * height;
	cout << "The area of the rectangle is " << area << endl;
}
