#include<iostream>
using namespace std;
struct Patient
{
    int patientID;
    char name[45];
    float temperature;
    int severity;
};
Patient* mostCritical(Patient arr[], int n)
{
    if (n <= 0) return NULL;
    Patient *criticalAns = &arr[0];
    for (int i = 1; i < n; i++)
	{
        if (arr[i].severity > criticalAns->severity)
		{
            criticalAns = &arr[i];
        }
    }
    return criticalAns;
}
Patient* findByID(Patient arr[], int n, int id)
{
    for (int i = 0; i < n; i++)
   {
        if (arr[i].patientID == id)
	   {
            return &arr[i];
        }
    }
    return NULL;
}
void displayPatient(Patient *p)
 {
    cout << "ID       : " << p->patientID << endl;
    cout << "Name     : " << p->name << endl;
    cout << "Temp     : " << p->temperature << " C" << endl;
    cout << "Severity : " << p->severity << "/10" << endl;
}
void inputPatient(Patient *p, int index)
 {
    cout << "Patient " << index << ":" << endl;
    cout << " ID: ";
    cin >> p->patientID;
    cout << " Name: ";
    cin >> p->name;
    cout << " Temp: ";
    cin >> p->temperature;
    cout << " Severity: ";
    cin >> p->severity;
}
int main() 
{
    int totalPatients;
    cout << "=== Lahore General Hospital - Emergency Triage ===" << endl;
    cout << "Enter number of patients: ";
    cin >> totalPatients;
    Patient patientsList[50];
    for (int i = 0; i < totalPatients; i++)
   {
        inputPatient(&patientsList[i], i + 1);
    }
    cout << "\n--- Most Critical Patient ---" << endl;
    cout << "?? ALERT: Immediate Attention Required!" << endl;
    Patient *highestCrit = mostCritical(patientsList, totalPatients);
    if (highestCrit != NULL)
	{
        displayPatient(highestCrit);
    }
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
   {
        int searchID;
        cout << "\nEnter Patient ID to update (0 to stop): ";
        cin >> searchID;
        if (searchID == 0) break;
        Patient *foundPatient = findByID(patientsList, totalPatients, searchID);
        if (foundPatient != NULL) {
            cout << "Enter new temperature: ";
            cin >> foundPatient->temperature;
            cout << "Enter new severity : ";
            cin >> foundPatient->severity;
            cout << "--- Updated Record ---" << endl;
            displayPatient(foundPatient);
            cout << "--- New Most Critical Patient ---" << endl;
            cout << "?? ALERT: Immediate Attention Required!" << endl;
            Patient *newCrit = mostCritical(patientsList, totalPatients);
            if (newCrit != NULL)
		   {
                displayPatient(newCrit);
            }
        } 
		else
	   {
            cout << "Patient not found!" << endl;
        }
        cout << "Update another patient? (y/n): ";
        cin >> choice;
    }
    cout << "\n=== Final Triage Summary ===" << endl;
    for (int i = 0; i < totalPatients; i++)
   {
        cout << "ID: " << patientsList[i].patientID 
             << " | Name: " << patientsList[i].name 
             << " | Temp: " << patientsList[i].temperature 
             << " C | Severity: " << patientsList[i].severity << endl;
    }
    return 0;
}
