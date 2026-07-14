#include<iostream>
#include<string>
using namespace std;
class Sensor
{
public:
    string sensorId;
    string sensorType;
    float reading;
    bool isActive;
};
int main()
{
    Sensor dev1;
    Sensor dev2;
    Sensor dev3;

    dev1.sensorId ="S-01";
    dev1.sensorType ="Ultrasonic";
    dev1.reading =25.4;
    dev1.isActive =true;

    dev2.sensorId ="S-02";
    dev2.sensorType ="Infrared";
    dev2.reading =10.1;
    dev2.isActive =false;

    dev3.sensorId ="S-03";
    dev3.sensorType ="Camera";
    dev3.reading =0.0;
    dev3.isActive =true;

    cout << "--- Sensor Status Report ---" << endl;
    cout << boolalpha;

    cout << "ID: " << dev1.sensorId << " | Type: " << dev1.sensorType << " | Reading: " << dev1.reading << " | Active: " << dev1.isActive << endl;
    cout << "ID: " << dev2.sensorId << " | Type: " << dev2.sensorType << " | Reading: " << dev2.reading << " | Active: " << dev2.isActive << endl;
    cout << "ID: " << dev3.sensorId << " | Type: " << dev3.sensorType << " | Reading: " << dev3.reading << " | Active: " << dev3.isActive << endl;
	return 0;
}
