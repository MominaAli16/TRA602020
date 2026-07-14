#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
    ofstream r1("robot1_log.txt");
    r1<<"RobotID,Temperature,Battery\n";
    r1<<"1,35.2,80\n";
    r1<<"1,36.5,75\n";
    r1<<"1,37.0,70\n";
    r1<<"1,35.8,65\n";
    r1<<"1,36.1,15\n";
    r1.close();
    ofstream r2("robot2_log.txt");
    r2<<"RobotID,Temperature,Battery\n";
    r2<<"2,30.0,90\n";
    r2<<"2,31.5,85\n";
    r2<<"2,33.0,50\n";
    r2<<"2,34.0,30\n";
    r2<<"2,35.0,18\n";
    r2.close();
    ofstream r3("robot3_log.txt");
    r3<<"RobotID,Temperature,Battery\n";
    r3<<"3,28.0,60\n";
    r3<<"3,29.5,55\n";
    r3<<"3,31.0,45\n";
    r3<<"3,32.5,25\n";
    r3<<"3,34.0,10\n";
    r3.close();
    cout<<"robot log files created"<<endl;
    ofstream fleet("fleet_log.txt");
    fleet<<"RobotID,Temperature,Battery,Status\n";
    string files[] = {"robot1_log.txt", "robot2_log.txt", "robot3_log.txt"};
    for(int i = 0; i < 3; i++)
	{
        ifstream rf(files[i].c_str());
        string line;
        getline(rf, line);
        while(getline(rf, line))
		{
            int rid = atoi(line.substr(0, line.find(',')).c_str());
            line = line.substr(line.find(',') + 1);
            float temp = atof(line.substr(0, line.find(',')).c_str());
            line = line.substr(line.find(',') + 1);
            float batt = atof(line.c_str());
            string status = "OK";
            if(batt < 20) status = "CRITICAL";
            fleet << rid << "," << temp << "," << batt << "," << status << "\n";
        }
        rf.close();
    }
    fleet.close();
    cout << "fleet_log.txt created" << endl;
    remove("robot1_log.txt");
    remove("robot2_log.txt");
    remove("robot3_log.txt");
    cout << "individual files deleted" << endl;
    ifstream show("fleet_log.txt");
    string ln;
    cout << "\n--- Fleet Log ---" << endl;
    while(getline(show, ln)){
        cout << ln << endl;
    }
    show.close();
    return 0;
}
