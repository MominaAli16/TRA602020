#include<iostream>
#include<string>
using namespace std;
class Person 
{
private:
    string name;
    string address;
public:
    Person(string val1 = "", string val2 = "") : name(val1), address(val2) {}
	void getdata() 
	{
        cout << "Enter Name  : ";
        getline(cin, name);
        cout << "Enter Address : ";
        getline(cin, address);
    }
	void showdata() 
	{
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
    }
};
class Qualification 
{
private:
    string qualification;
public:
    Qualification(string qual = "") : qualification(qual) {}
	void getdata() {
        cout << "Enter Qualification: ";
        getline(cin, qualification);
    }
	void showdata() 
	{
        cout << "Qualification: " << qualification << endl;
    }
};
class Employee : public Person, public Qualification 
{
private:
    int empID;
public:
    Employee(string val1 = "", string val2 = "", string qual = "", int id = 0)
        : Person(val1, val2), Qualification(qual), empID(id) {}
		void getdata()
		{
        Person::getdata();
        Qualification::getdata();
        cout << "Enter Employee ID : ";
        cin >> empID;
        cin.ignore();
    }
	void showdata() 
	{
        Person::showdata();
        Qualification::showdata();
        cout << "Employee ID : " << empID << endl;
    }
};
int main()
{
    Employee emp;
    emp.getdata();
	cout << "\n===== Employee Record =====" << endl;
    emp.showdata();
	return 0;
}
