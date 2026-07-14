#include <iostream>
#include <string>
using namespace std;
class RobotUnit
{
private:
    string robotName;
    int robotID;
    static int objectCount;
public:
    RobotUnit()
	{
        robotName = "Unknown";
        robotID = 0;
        objectCount++;
        cout << "[Default Constructor] RobotUnit '" << robotName << "' (ID: " << robotID << ") created. Count: " << objectCount << endl;
    }
    RobotUnit(string name, int id) : robotName(name), robotID(id) 
	{
        objectCount++;
        cout << "[Constructor] RobotUnit '" << robotName << "' (ID: " << robotID << ") created. Count: " << objectCount << endl;
    }
    ~RobotUnit() 
	{
        objectCount--;
        cout << "[Destructor] RobotUnit '" << robotName << "' destroyed. Count: " << objectCount << endl;
    }
    static int getCount()
	{
        return objectCount;
    }
    void display() const
	{
        cout << "Robot: " << robotName << " | ID: " << robotID << endl;
    }
};
int RobotUnit::objectCount = 0;
int main() 
{
    cout << "Objects alive: " << RobotUnit::getCount() << endl;
    {
        RobotUnit r1("Striker-X", 301);
        RobotUnit r2("Ranger-V2", 302);
        RobotUnit r3;
        cout << "Objects alive: " << RobotUnit::getCount() << endl;
        RobotUnit* heapBot = new RobotUnit("Alpha-Bot", 500);
        cout << "Objects alive: " << RobotUnit::getCount() << endl;
        delete heapBot;
        cout << "Objects alive: " << RobotUnit::getCount() << endl;
        cout << "--- Individual Robot Info ---" << endl;
        r1.display();
        r2.display();
        r3.display();
        cout << "--- End of main ---" << endl;
    }
    cout << "Final object count: " << RobotUnit::getCount() << endl;
    return 0;
}
