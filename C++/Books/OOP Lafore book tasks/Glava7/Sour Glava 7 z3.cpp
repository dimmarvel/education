#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(int ft, float in)
    {
        feet = ft;
        inches = in;
    }

    void getdata()
    {
        cout << "Input feet: ";
        cin >> feet;
        cout << "Input inches: ";
        cin >> inches;
    }
    void showdist() { cout << feet << "\'-" << inches << '\"'; }
    void add_dist(Distance, Distance);
    void div_dist(Distance, int);
};

//сложение расстояний d2 и d3
void Distance::add_dist(Distance d2, Distance d3)
{
    inches = d2.inches + d3.inches;
    feet = 0;
    if (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet + d3.feet;
}
//Деление объекта Distance на целое число
void Distance::div_dist(Distance d2, int divisor)
{
    float fltfeet = d2.feet + d2.inches / 12.0; //преобразовать в формат float
    fltfeet /= divisor;                         //деление
    feet = int(fltfeet);                        //получить футовую чать
    inches = (fltfeet - feet) * 12.0;           // дюймовую чать
}

int main()
{
    setlocale(LC_ALL, "Rus");
    Distance distarr[100]; //массив из 100 обджектов типа дистансе

    Distance total(0, 0.0), average; //прочиае расстояния
    int count = 0;                   //кол-во введенных значений
    char ch;                         //признак ответа пользователя

    do
    {
        cout << "\nInput rasstoyanie: " << endl;
        distarr[count++].getdata();
        cout << "\nContinue? (y/n)";
        cin >> ch;
    } while (ch != 'n');

    for (int j = 0; j < count; j++)
    {
        total.add_dist(total, distarr[j]);
    }

    average.div_dist(total, count);
    cout << "\nAverage:";
    average.showdist();
    cout << endl;
    system("Pause");
}