#include <iostream>
#include <string>
using namespace std;
float average(float* num);
int main()
{

    float* mass = new float[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Input " << i << " = ";
        cin >> mass[i];
    }
    cout << average(mass) << endl;
    system("pause");
}

float average(float* num)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += num[i];
    }
    return sum / 5;
}
