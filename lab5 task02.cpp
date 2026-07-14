#include<iostream>
using namespace std;
struct Citizen 
{
    int cnicID;
    char name[30];
    char city[20];
    int age;
};
int main()
{
    Citizen c;
    Citizen *ptr = &c;
    cout << "Enter CNIC ID: ";
    cin >> ptr->cnicID;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(ptr->name, 30);
    cout << "Enter City: ";
    cin >> ptr->city;
    cout << "Enter Age: ";
    cin >> ptr->age;
    int choice;
    cout << "Press 1 to update city of residence, 0 to display record: ";
    cin >> choice;
    if (choice == 1)
	{
        cout << "Enter new city: ";
        cin >> ptr->city;
        cout << "\n--- Updated NADRA Record ---\n";
        cout << "CNIC ID: " << ptr->cnicID << "\n";
        cout << "Name: " << ptr->name << "\n";
        cout << "City: " << ptr->city << "\n";
        cout << "Age: " << ptr->age << endl;
    } 
	else
	{
        cout << "\n--- NADRA Record ---\n";
        cout << "CNIC ID: " << ptr->cnicID << "\n";
        cout << "Name: " << ptr->name << "\n";
        cout << "City: " << ptr->city << "\n";
        cout << "Age: " << ptr->age << endl;
    }
    return 0;
}
