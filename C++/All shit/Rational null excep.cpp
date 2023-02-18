#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Rational;

static int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int nok(int a, int b) { return (a * b) / gcd(a, b); }

class Rational
{
    int num;
    int den;

public:
    Rational()
    {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }

        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }

        int x = gcd(abs(numerator), denominator);
        num = numerator /= x;
        den = denominator /= x;
    }

    int Numerator() const { return num; }
    int Denominator() const { return den; }

    friend const Rational& operator/(const Rational& lhs, const Rational& rhs)
    {
        if (lhs.Denominator() * rhs.Numerator() == 0)
        {
            string s;
            stringstream stream(s);
            stream << "domain_error";
            throw domain_error(stream.str());
        }
        return Rational {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
    }
};

int main()
{
    try
    {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&)
    {
    }

    try
    {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&)
    {
    }

    cout << "OK" << endl;
    return 0;
}