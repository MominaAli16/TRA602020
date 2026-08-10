#include <iostream>
#include <string>
using namespace std;
const float PI = 3.14159f;
class Shape
{
protected:
    string shapeName;
public:
    Shape(string name) : shapeName(name) {}
	float calculateArea() 
	{
        return 0.0f;
    }
	void describe()
	{
        cout << "I am a Shape called: " << shapeName << endl;
    }
};
class Rectangle : public Shape 
{
private:
    float length;
    float width;

public:
    Rectangle(string name, float l, float w) : Shape(name), length(l), width(w) {}
	float calculateArea() 
	{
        return length * width;
    }
	void describe() 
	{
        Shape::describe();
        cout << "Type: Rectangle | Length: " << length << " | Width: " << width << endl;
    }
};
class Circle : public Shape 
{
private:
    float radius;
public:
    Circle(string name, float r) : Shape(name), radius(r) {}
	float calculateArea() 
	{
        return PI * radius * radius;
    }
	void describe() 
	{
        Shape::describe();
        cout << "Type: Circle | Radius: " << radius << endl;
    }
};
int main()
{
    Rectangle r("MyRectangle", 6.0f, 4.0f);
    Circle c("MyCircle", 5.0f);
	r.describe();
    cout << "Area: " << r.calculateArea() << endl << endl;
	c.describe();
    cout << "Area: " << c.calculateArea() << endl;
	return 0;
}
