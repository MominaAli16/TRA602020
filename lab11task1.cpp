#include<iostream>
#include<string>
using namespace std;
class Person
{
protected:
    string name;
    string address;
public:
    Person(string val1, string val2) : name(val1), address(val2) {}

    void showPerson()
	{
        cout << "Name    : " << name << endl;
        cout << "Address : " << address << endl;
    }
};
class Employee : public Person 
{
protected:
    int empID;
public:
    Employee(string val1, string val2, int id) 
        : Person(val1, val2), empID(id) {}
		void showEmployee()
		{
        showPerson();
        cout << "Employee ID : " << empID << endl;
    }
};
class Manager : public Employee 
{
private:
    string qualification;
public:
    Manager(string val1, string val2, int id, string qual) 
        : Employee(val1, val2, id), qualification(qual) {}
		void showManager() 
		{
        showEmployee();
        cout << "Qualification: " << qualification << endl;
    }
};
int main() 
{
    Manager mgr("Momina Ali", "Lahore", 1042, "MBA");
    cout << "===== Manager Profile =====" << endl;
    mgr.showManager();
    cout << endl;
	Manager mgr2("Ahmad Ali", "Karachi", 2075, "PhD Computer Science");
    cout << "===== Manager Profile =====" << endl;
    mgr2.showManager();
	return 0;
}
