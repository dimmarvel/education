#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int number;
class Fraction
{
private:
public:
    int numerator, denominator;
    Fraction() : numerator(0), denominator(0) {}
    void mul_fr(Fraction f1, Fraction f2) // перемножение дробей
    {
        numerator = f1.numerator * f2.numerator;
        denominator = f1.denominator * f2.denominator;
    }
    void lowterms() // сокращение дроби
    {
        long tnum, tden, temp, gcd;
        tnum = labs(numerator);
        tden = labs(denominator);
        if (tden == 0)
        {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0)
        {
            numerator = 0;
            denominator = 1;
            return;
        }
        while (tnum != 0)
        {
            if (tnum < tden)
            {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    void disp_fr() const //отображение числителя и знаменателя
    {
        cout << setw(5) << numerator << "/" << denominator;
    }
};
int main()
{
    Fraction fr1, fr2, fr3;

    fr1.denominator = fr2.denominator = number;
    cout << "enter denominator" << endl;
    cin >> number; // знаменатель

    for (int j = 1; j < number; j++)
    {
        fr1.numerator = j;        //числитель = j
        fr1.denominator = number; //знаменатель = введенному знаменателю
        fr1.lowterms();           //сокращение дроби
        fr1.disp_fr();            //отображение
    }
    cout << endl;
    for (int i = 1; i < number; i++)
    {
        fr2.numerator = i;
        fr2.denominator = number;
        fr2.lowterms();
        fr2.disp_fr();

        for (int j = 1; j < number; j++)
        {
            fr1.numerator = j;
            fr1.denominator = number;
            fr3.mul_fr(fr1, fr2);
            fr3.lowterms();
            fr3.disp_fr();
        }
        cout << endl;
    }
    system("pause");
    return 0;
}