#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Account
{
    string ownerName;
    int accNo;
    float *monthlyDeposits;
    float currentBalance;
};
int main() 
{
int n = 5;
Account *bank = new Account[n];
bank[0].ownerName = "Ahmed";  bank[0].accNo = 2301;  bank[0].currentBalance = 75000;
bank[1].ownerName = "Fatima"; bank[1].accNo = 2302;  bank[1].currentBalance = 32000;
bank[2].ownerName = "Bilal";  bank[2].accNo = 2303;  bank[2].currentBalance = 90000;
bank[3].ownerName = "Zara";   bank[3].accNo = 2304;  bank[3].currentBalance = 15000;
bank[4].ownerName = "Usman";  bank[4].accNo = 2305;  bank[4].currentBalance = 62000;
for (int i = 0; i < n; i++)
{
    bank[i].monthlyDeposits = new float[30];
     for (int d = 0; d < 30; d++) {
        bank[i].monthlyDeposits[d] = 500.0f + (i * 50) + d;
        }
    }
ofstream file("details.txt");
    if (!file) 
	{
        cout << "File could not be opened!" << endl;
        return 1;
    }
for (int i = 0; i < n; i++)
 {
        file << "Name: " << bank[i].ownerName << endl;
        file << "Acc No: " << bank[i].accNo << endl;
        file << "Balance: " << bank[i].currentBalance << endl;
        file << "First 5 Deposits: ";
        for (int d = 0; d < 5; d++)
		{
            file << bank[i].monthlyDeposits[d] << "  ";
        }
        file << endl;
        file << "---------------------------------" << endl;
    }
    file.close();
    cout << "All records saved to file." << endl;
	cout << "\n--- Accounts with Balance above 50,000 ---" << endl;
    for (int i = 0; i < n; i++) 
	{
        if (bank[i].currentBalance > 50000) 
		{
            cout << "Name    : " << bank[i].ownerName << endl;
            cout << "Acc No  : " << bank[i].accNo << endl;
            cout << "Balance : " << bank[i].currentBalance << endl;
            cout << "---------------------------------" << endl;
        }
    }
for (int i = 0; i < n; i++) 
{
        delete[] bank[i].monthlyDeposits;
    }
    delete[] bank;

    return 0;
}
