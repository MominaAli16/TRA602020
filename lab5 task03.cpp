#include<iostream>
using namespace std;
struct PetrolPump
{
    char stationName[35];
    float pricePerLiter;
    int availableLiters;
};
void input(PetrolPump *p) 
{
    cout << "Enter Pump Name: ";
    cin >> p->stationName;
    cout << "Enter Price per Liter: ";
    cin >> p->pricePerLiter;
    cout << "Enter Available Liters: ";
    cin >> p->availableLiters;
}
void display(PetrolPump *p) 
{
    cout << "Pump Name: " << p->stationName << endl;
    cout << "Price: " << p->pricePerLiter << endl;
    cout << "Stock: " << p->availableLiters << " liters" << endl;
}
int main()
{
    PetrolPump p;
    input(&p);
    display(&p);
    return 0;
}
