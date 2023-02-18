#include <cmath>
#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction() : numerator(0), denominator(0) {}
    void get_fr() //метод получания дроби
    {
        char ch;
        cout << "enter fraction" << endl;
        cin >> numerator >> ch >> denominator;
    }
    void add_fr(Fraction f1, Fraction f2) //метод сложения двух дробей
    {
        numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
        denominator = f1.denominator * f2.denominator;
    }
    void mul_fr(Fraction f1,
                int n) //метод деления суммы дробей на количество их самих (умножение знаменателя на это число)
    {
        denominator = f1.denominator * n;
    }

    void lowterms() //метод сокращения дроби
    {
        long tnum, tden, temp, gcd;
        tnum = labs(numerator);   // используем неотрицательные
        tden = labs(denominator); // значения (нужен cmath)
        if (tden == 0)            // проверка знаменателя на 0
        {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0) // проверка числителя на 0
        {
            numerator = 0;
            denominator = 1;
            return;
        }
        // нахождение наибольшего общего делителя
        while (tnum != 0)
        {
            if (tnum < tden) // если числитель больше знаменателя,
            {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }                   //меняем их местами
            tnum = tnum - tden; // вычитание
        }
        gcd = tden;                  // делим числитель и знаменатель на
        numerator = numerator / gcd; // полученный наибольший общий делитель
        denominator = denominator / gcd;
    }
    void disp_fr() const { cout << "\nthe average is " << numerator << "/" << denominator << endl; }
};
int main()
{
    Fraction fraction[100];
    Fraction frtemp, frsum;
    char ans;
    int n = 0;
    do //ввод дробей в массив
    {
        fraction[n++].get_fr();
        cout << "continue typing? (y/n)" << endl;
        cin >> ans;
    } while (ans != 'n');
    for (int j = 0; j < n; j++) //сложение дробей
    {
        frtemp.add_fr(fraction[j], fraction[j++]);
        j++;
        frsum.add_fr(frtemp, frsum);
    }
    frsum.mul_fr(frsum, n + 1); //деление на их кол-во

    frsum.disp_fr(); //вывод на экран
    system("pause");
    return 0;
}