#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
    void showPerson() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};
class Student : public Person 
{
private:
    int rollNumber;
public:
    Student(string n, int a, int r) : Person(n, a), rollNumber(r) {}
    void showStudent()
	{
        showPerson();
        cout << "Roll No: " << rollNumber << endl;
    }
};
class Employee : protected Person
{
private:
    int empID;
public:
    Employee(string n, int a, int id) : Person(n, a), empID(id) {}
    void showEmployee()
	{
        showPerson();
        cout << "Emp ID : " << empID << endl;
    }
};
class Teacher : private Person 
{
private:
    string subject;
public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void showTeacher() 
	{
        showPerson();
        cout << "Subject: " << subject << endl;
    }
};
int main()
{
    cout << "===== Student =====" << endl;
    Student s1("Zara Khan", 20, 1045);
    s1.showStudent();
    cout << "Direct call ok: " << s1.getName() << endl;
    cout << endl;
    cout << "===== Employee =====" << endl;
    Employee e1("Ahmed Ali", 35, 2088);
    e1.showEmployee();
    // e1.getName(); // error: protected
    cout << "// emp.getName() --> ERROR: getName() is protected in Employee" << endl;
    cout << endl;
    cout << "===== Teacher =====" << endl;
    Teacher t1("Dr. Nadia", 42, "Robotics");
    t1.showTeacher();
    // t1.showPerson(); // error: private
    cout << "// tchr.showPerson() --> ERROR: showPerson() is private in Teacher" << endl;
    return 0;
}
