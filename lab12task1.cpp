#include<iostream>
using namespace std;
#define PI 3.14159f
class Shape
{
protected:
    float val;
public:
    Shape(float v) 
	{
        val = v;
    }
    float calculateArea()
	{
        return val * val;
    }
};
class Circle : public Shape
{
public:
    Circle(float radius) : Shape(radius) {}
    float calculateArea() 
	{
        return PI * val * val;
    }
};
class Rectangle : protected Shape
{
public:
    Rectangle(float side) : Shape(side) {}
    float calculateArea() 
	{
        return val * 2.0f * val;
    }
    float getArea()
	{
        return this->calculateArea();
    }
};
class Triangle : private Shape
{
public:
    Triangle(float side) : Shape(side) {}
    float calculateArea() 
	{
        return (val * val) / 2.0f;
    }
    float getArea() 
	{
        return calculateArea();
    }
};
int main()
{
    Circle c1(5.0f);
    Rectangle r1(4.0f);
    Triangle t1(6.0f);
	cout << "Circle Area: " << c1.calculateArea() << endl;
    // cout << r1.calculateArea(); // Error: Protected access
    cout << "Rectangle Area: " << r1.getArea() << endl;
    // cout << t1.calculateArea(); // Error: Private access
    cout << "Triangle Area: " << t1.getArea() << endl;
	cout << "\n=== Mode Observation ===" << endl;
    cout << "Public   : calculateArea() callable directly from main." << endl;
    cout << "Protected: hidden from main - accessed via getArea() wrapper." << endl;
    cout << "Private  : hidden from main - accessed via getArea() wrapper." << endl;
	return 0;
}
