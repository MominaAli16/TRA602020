#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream f("student.txt");
	if(!f)
	{
		cout<<"File could not be opened!"<<endl;
		return 1;
	}
f<<"Roll No:2301"<<endl;
f<<"Name:Ahmad"<<endl;
f<<"Section:B"<<endl;
f<<"CGPA:3.6"<<endl;
f<<"===================="<<endl;
f<<"Roll No:2302"<<endl;
f<<"Name:Dua"<<endl;
f<<"Section:A"<<endl;
f<<"=================="<<endl;
f.close();
cout<<"Data saved to file."<<endl;
string line;
ifstream rf("student.txt");
if(!rf)
{
	cout<<"========================================"<<endl;
	cout<<"       STUDENT RECORD MANAGEMENT        "<<endl;
	cout<<"========================================"<<endl;
	}
	while(getline(rf,line))
	{
		cout<<line<<endl;
	}
	rf.close();
	ofstream af("student.txt",ios::app);
	if(!af)
	{
		cout<<"Could not append to file!"<<endl;
		return 1;
	}
	af<<"Total student:2\n";
	af.close();
	cout<<"========================================"<<endl;
	cout<<"Summary added successsfully."<<endl;
	return 0;
}
