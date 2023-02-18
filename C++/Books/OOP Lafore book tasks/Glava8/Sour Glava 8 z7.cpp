#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int number;
class Fraction
{
private:
    int numerator, denominator;
    char n;

public:
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
        cout << setw(5) << numerator << "/" << denominator << endl;
    }
    void getdisp() { cin >> numerator >> n >> denominator; }
    Fraction operator+(Fraction f)
    {
        Fraction temp;
        temp.numerator = temp.numerator * f.denominator + temp.denominator * f.numerator;
        temp.denominator = temp.denominator * f.denominator;
        return temp;
    }
    Fraction operator-(Fraction f)
    {
        Fraction temp;
        temp.numerator = temp.numerator * f.denominator - temp.denominator * f.numerator;
        temp.denominator = temp.denominator * f.denominator;
        return temp;
    }
    Fraction operator*(Fraction f)
    {
        Fraction temp;
        temp.numerator = temp.numerator * f.numerator;
        temp.denominator = temp.denominator * f.denominator;
        return temp;
    }
    Fraction operator/(Fraction f)
    {
        Fraction temp;
        temp.numerator = temp.numerator * f.denominator;
        temp.denominator = temp.denominator * f.numerator;
        return temp;
    }
    bool operator==(Fraction f) { return (numerator == f.numerator && denominator == f.denominator) ? true : false; }
    bool operator!=(Fraction f) { return (numerator != f.numerator || denominator != f.denominator) ? true : false; }
};
int main()
{
    Fraction fr1, fr2, fr3;
    cout << "enter denominator and numerator" << endl;
    fr1.getdisp();
    fr2.getdisp();
    cout << "fr1 = ";
    fr1.disp_fr();
    cout << "fr2 = ";
    fr2.disp_fr();
    cout << "fr1 == f2";
    if (fr1 == fr2)
    {
        cout << " true == " << endl;
    }
    else
    {
        cout << " flase == " << endl;
    }
    cout << "fr1 != f2 ";
    if (fr1 != fr2)
    {
        cout << " true != " << endl;
    }
    else
    {
        cout << " flase != " << endl;
    }

    system("pause");
    return 0;
}