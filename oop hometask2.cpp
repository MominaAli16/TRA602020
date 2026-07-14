#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct Layer
{
    int neurons;
    float weights[10];
    float bias;
};
int main()
{
    Layer* net = new Layer[3];
    net[0].neurons = 3;
    net[0].bias = 0.4;
    net[0].weights[0] = 0.1;
    net[0].weights[1] = 0.2;
    net[0].weights[2] = 0.3;
    net[0].weights[3] = 0.4;
    net[0].weights[4] = 0.5;
    net[0].weights[5] = 0.6;
    net[0].weights[6] = 0.7;
    net[0].weights[7] = 0.8;
    net[0].weights[8] = 0.9;
    net[0].weights[9] = 1.0;
    net[1].neurons = 5;
    net[1].bias = 0.3;
    net[1].weights[0] = 0.2;
    net[1].weights[1] = 0.4;
    net[1].weights[2] = 0.6;
    net[1].weights[3] = 0.8;
    net[1].weights[4] = 1.0;
    net[1].weights[5] = 1.2;
    net[1].weights[6] = 1.4;
    net[1].weights[7] = 1.6;
    net[1].weights[8] = 1.8;
    net[1].weights[9] = 2.0;
    net[2].neurons = 2;
    net[2].bias = 0.6;
    net[2].weights[0] = 0.05;
    net[2].weights[1] = 0.10;
    net[2].weights[2] = 0.15;
    net[2].weights[3] = 0.20;
    net[2].weights[4] = 0.25;
    net[2].weights[5] = 0.30;
    net[2].weights[6] = 0.35;
    net[2].weights[7] = 0.40;
    net[2].weights[8] = 0.45;
    net[2].weights[9] = 0.50;
    ofstream binout("model_weights.bin", ios::binary);
    binout.write((char*)net, sizeof(Layer) * 3);
    binout.close();
    cout << "model saved to file" << endl;
    Layer* loaded = new Layer[3];
    ifstream binin("model_weights.bin", ios::binary);
    binin.read((char*)loaded, sizeof(Layer) * 3);
    binin.close();
    cout << "\n--- Loaded Model ---" << endl;
    for(int i = 0; i < 3; i++)
	{
        cout << "Layer " << i+1 << "  neurons=" << loaded[i].neurons << "  bias=" << loaded[i].bias << endl;
        cout << "weights: ";
        for(int j = 0; j < 10; j++)
		{
            cout << loaded[i].weights[j] << " ";
        }
        cout << endl;
    }
    delete[] net;
    delete[] loaded;
    return 0;
}
