#include<iostream>
#include<string>
using namespace std;
class AIModel 
{
public:
    string modelName;
    string version;
    string algorithm;
    float accuracy;
    bool isDeployed;
};
int main()
{
    AIModel card1;
    AIModel card2;
    AIModel card3;

    card1.modelName = "ResNet-50-X";
    card1.version = "v2.1.0";
    card1.algorithm = "CNN";
    card1.accuracy = 0.92;
    card1.isDeployed = true;

    card2.modelName = "SVM-Classic";
    card2.version = "v1.0.1";
    card2.algorithm = "SVM";
    card2.accuracy = 0.76;
    card2.isDeployed = false;

    card3.modelName = "YOLOv5-Pro";
    card3.version = "v3.1";
    card3.algorithm = "CNN";
    card3.accuracy = 0.94;
    card3.isDeployed = true;

    cout << boolalpha;

    cout << "=== AI Model Card ===" << endl;
    cout << "Name      : " << card1.modelName << endl;
    cout << "Version   : " << card1.version << endl;
    cout << "Algorithm : " << card1.algorithm << endl;
    cout << "Accuracy  : " << card1.accuracy << endl;
    cout << "Deployed  : " << card1.isDeployed << endl;

    cout << "=== AI Model Card ===" << endl;
    cout << "Name      : " << card2.modelName << endl;
    cout << "Version   : " << card2.version << endl;
    cout << "Algorithm : " << card2.algorithm << endl;
    cout << "Accuracy  : " << card2.accuracy << endl;
    cout << "Deployed  : " << card2.isDeployed << endl;

    cout << "=== AI Model Card ===" << endl;
    cout << "Name      : " << card3.modelName << endl;
    cout << "Version   : " << card3.version << endl;
    cout << "Algorithm : " << card3.algorithm << endl;
    cout << "Accuracy  : " << card3.accuracy << endl;
    cout << "Deployed  : " << card3.isDeployed << endl;
	return 0;
}
