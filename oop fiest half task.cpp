#include <iostream>
#include <fstream>
using namespace std;

struct SensorReading
{
    int sensorID;
    float temperature;
    float humidity;
    string timestamp;
};

int main() 
{
    SensorReading s[3];
    s[0].sensorID = 4;
    s[0].temperature = 41.2;
    s[0].humidity = 65.8;
    s[0].timestamp = "2024-03-22 09:15";
    s[1].sensorID = 5;
    s[1].temperature = 39.6;
    s[1].humidity = 70.4;
    s[1].timestamp = "2024-03-22 09:20";
    s[2].sensorID = 6;
    s[2].temperature = 37.3;
    s[2].humidity = 78.6;
    s[2].timestamp = "2024-03-22 09:25";

    ofstream outFile;
    outFile.open("sensor_log.txt");
    
    if(outFile.is_open())
    {
        cout<<"File sensor_log.txt created successfully."<<endl;
        int i = 0;
        while(i < 3)
        {
            outFile<<"--- Sensor Reading "<<i+1<<" ---"<<endl;
            outFile<<"Sensor ID   : "<<s[i].sensorID<<endl;
            outFile<<"Temperature : "<<s[i].temperature<<" C"<<endl;
            outFile<<"Humidity    : "<<s[i].humidity<<" %"<<endl;
            outFile<<"Timestamp   : "<<s[i].timestamp<<endl;
            i++;
        }
        outFile.close();
    }
    else
    {
        cout<<"Unable to open file"<<endl;
    }
    ifstream inFile;
    inFile.open("sensor_log.txt");
    string line;
    cout<<"Reading file contents:"<<endl;
    while(getline(inFile, line))
    {
        cout<<line<<endl;
    }
     inFile.close();
    return 0;
}
