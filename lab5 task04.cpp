#include<iostream>
using namespace std;
struct Bill
{
    int accountNo;
    string ownerName;
    int unitsConsumed;
    float ratePerUnit;
    float totalBill;
};
void inputBill(Bill *b)
{
    cout << "Enter Account No : ";
    cin >> b->accountNo;
    cout << "Enter Owner Name : ";
    cin.ignore();
    getline(cin, b->ownerName);
    cout << "Units Consumed : ";
    cin >> b->unitsConsumed;
    cout << "Rate Per Unit (Rs) : ";
    cin >> b->ratePerUnit;
}
void calculateBill(Bill *b)
{
    b->totalBill = b->unitsConsumed * b->ratePerUnit;
    if (b->unitsConsumed > 300)
	{
        float extraCharge = b->totalBill * 0.15;
        b->totalBill += extraCharge;
    }
}
void displayBill(Bill *b)
{
    float base = b->unitsConsumed * b->ratePerUnit;
    cout << "========== LESCO Bill ==========" << endl;
    cout << "Account No : " << b->accountNo << endl;
    cout << "Owner Name : " << b->ownerName << endl;
    cout << "Units Used : " << b->unitsConsumed << endl;
    cout << "Rate/Unit : Rs. " << b->ratePerUnit << endl;
    cout << "Base Amount : Rs. " << base << endl;
    if (b->unitsConsumed > 300)
	{
        cout << "Surcharge 15%: Rs. " << (base * 0.15) << endl;
    } 
	else
	{
        cout << "Surcharge 15%: Rs. 0" << endl;
    }
    cout << "Total Bill : Rs. " << b->totalBill << endl;
}
int main()
{
    Bill b;
    cout << "=== LESCO Billing System ===" << endl;
    inputBill(&b);
    calculateBill(&b);
    displayBill(&b);
    return 0;
}
