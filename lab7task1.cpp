#include<iostream>
#include<string>
using namespace std;
class Robot
{
public:
    string robotId;
    string robotType;
    int battery;
    float speed;
};
int main() 
{
    Robot r1;
    Robot r2;
    Robot r3;

    r1.robotId = "R-001";
    r1.robotType = "Picker";
    r1.battery = 90;
    r1.speed = 1.5;

    r2.robotId = "R-002";
    r2.robotType = "Scout";
    r2.battery = 55;
    r2.speed = 2.2;

    r3.robotId = "R-003";
    r3.robotType = "Carrier";
    r3.battery = 20;
    r3.speed = 0.8;

    cout << "--- Robot Fleet Status ---" << endl;

    cout << "ID: " << r1.robotId << " | Type: " << r1.robotType << " | Battery: " << r1.battery << "% | Speed: " << r1.speed << " m/s" << endl;
    cout << "ID: " << r2.robotId << " | Type: " << r2.robotType << " | Battery: " << r2.battery << "% | Speed: " << r2.speed << " m/s" << endl;
    cout << "ID: " << r3.robotId << " | Type: " << r3.robotType << " | Battery: " << r3.battery << "% | Speed: " << r3.speed << " m/s" << endl;
	return 0;
}
