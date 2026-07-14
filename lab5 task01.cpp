#include <iostream>
using namespace std;
struct Book 
{
    int id;
    float price;
    int pages;
};
int main() 
{
    Book b1, b2;
    cout << "Enter details for Book 1 (ID, Price, Pages): ";
    cin >> b1.id >> b1.price >> b1.pages;
    cout << "Enter details for Book 2 (ID, Price, Pages): ";
    cin >> b2.id >> b2.price >> b2.pages;
    int choice;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    if (choice == 1)
	{
        Book* ptr = NULL;
        if (b1.price > b2.price)
		{
            ptr = &b1;
        } 
		else
		{
            ptr = &b2;
        }
        cout << "Price of most costly book: " << ptr->price << endl;
    } 
	else if (choice == 2)
	{
        cout << "Enter details again for Book 1 (ID, Price, Pages): ";
        cin >> b1.id >> b1.price >> b1.pages;
        cout << "Enter details again for Book 2 (ID, Price, Pages): ";
        cin >> b2.id >> b2.price >> b2.pages;
        cout << "New Details of Book 1: ID=" << b1.id << ", Price=" << b1.price << ", Pages=" << b1.pages << endl;
        cout << "New Details of Book 2: ID=" << b2.id << ", Price=" << b2.price << ", Pages=" << b2.pages << endl;
    }
    return 0;
}
