#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
const double PI = M_PI;
using namespace std;

int main()
{
    float jellyBeanHeight = 0.0;
    float jellyBeanLength = 0.0;
    float jellyBeanVol = 0.0;
    int jarVolume = 0;
    int totalJellyBeans = 0;
    const float LOAD_FACTOR = 0.698;

    cout << "Let's guess how many jelly beans will fit into a jar!" << endl;

    cout << "Enter the length of one jelly bean (cm):" << endl;
    cin >> jellyBeanLength;

    cout << "Enter the height of one jelly bean (cm):" << endl;
    cin >> jellyBeanHeight;

    cout << "Enter the volume of the jar (mL):" << endl;
    cin >> jarVolume;

    jellyBeanVol = (5 * PI * (jellyBeanLength * pow(jellyBeanHeight, 2))) / 24;

    totalJellyBeans = jarVolume * LOAD_FACTOR / jellyBeanVol;

    cout << "Approximately " << totalJellyBeans << " jelly beans could fit in a jar with a volume of " << jarVolume << " mL." << endl;

    return 0;
}