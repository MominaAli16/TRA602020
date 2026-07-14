#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    ofstream file1("path_log.csv");
    file1 << "waypoint_id,x,y,z,timestamp\n";
    float ax[] = {15, 30, 50, 70, 90, 115, 140, 95, 55, 25};
    float ay[] = {10, 25, 40, 60, 80, 100, 120, 85, 50, 20};
    float az[] = {0, 1, 0, 2, 0, 1, 0, 3, 0, 0};
    int at[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++){
        file1 << i+1 << "," << ax[i] << "," << ay[i] << "," << az[i] << "," << at[i] << "\n";
    }
    file1.close();
    cout << "waypoints saved" << endl;
    ifstream file2("path_log.csv");
    string ln;
    getline(file2, ln);
    float dist = 0;
    int cnt = 0;
    float lx = -1, ly = -1, lz = -1;
    while(getline(file2, ln))
	{
        int id = atoi(ln.substr(0, ln.find(',')).c_str());
        ln = ln.substr(ln.find(',') + 1);
        float nx = atof(ln.substr(0, ln.find(',')).c_str());
        ln = ln.substr(ln.find(',') + 1);
        float ny = atof(ln.substr(0, ln.find(',')).c_str());
        ln = ln.substr(ln.find(',') + 1);
        float nz = atof(ln.substr(0, ln.find(',')).c_str());
        cout << "point " << id << "  x=" << nx << "  y=" << ny << "  z=" << nz;
        if(nx > 100)
		{
            cout << "  [flagged]";
            cnt++;
        }
        cout << endl;
        if(lx != -1)
		{
            float d = sqrt(pow(nx-lx,2) + pow(ny-ly,2) + pow(nz-lz,2));
            dist = dist + d;
        }
        lx = nx;
        ly = ny;
        lz = nz;
    }
    file2.close();
    float avgspd = dist / 10.0;
    cout << "\ntotal distance = " << dist << endl;
    cout << "average speed  = " << avgspd << endl;
    cout << "flagged points = " << cnt << endl;
    ofstream file3("path_log.csv", ios::app);
    file3 << "\nSUMMARY\n";
    file3 << "total distance," << dist << "\n";
    file3 << "average speed," << avgspd << "\n";
    file3 << "flagged," << cnt << "\n";
    file3.close();
    cout << "summary added to file" << endl;
    return 0;
}
