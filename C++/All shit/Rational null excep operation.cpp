#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

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

    Rational(const Rational& lhs)
    {
        num = lhs.num;
        den = lhs.den;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs)
    {
        return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
    }

    const Rational operator+(const Rational& rhs)
    {
        return Rational {num * rhs.Denominator() + den * rhs.Numerator(), den * rhs.Denominator()};
    }

    const Rational operator-(const Rational& rhs)
    {
        return Rational {num * rhs.Denominator() - den * rhs.Numerator(), den * rhs.Denominator()};
    }

    const Rational operator*(const Rational& rhs) { return Rational {num * rhs.Numerator(), den * rhs.Denominator()}; }

    const Rational operator/(const Rational& rhs)
    {
        if (num * rhs.Numerator() == 0)
        {
            string s;
            stringstream stream(s);
            stream << "Division by zero";
            throw domain_error(stream.str());
        }
        return Rational {num * rhs.Denominator(), den * rhs.Numerator()};
    }

    friend istream& operator>>(istream& is, Rational& r)
    {
        int n, d;
        char c;

        if (is)
        {
            is >> n >> c >> d;
            if (is && c == '/')
            {
                r = Rational(n, d);
            }
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const Rational& r) { return os << r.Numerator() << '/' << r.Denominator(); }

    friend bool operator>(const Rational& lhs, const Rational& rhs)
    {
        return ((lhs.Numerator() * rhs.Denominator()) > (lhs.Denominator() * rhs.Numerator()));
    }

    friend bool operator<(const Rational& lhs, const Rational& rhs)
    {
        return ((lhs.Numerator() * rhs.Denominator()) < (lhs.Denominator() * rhs.Numerator()));
    }
};

int main()
{
    try
    {
        string s;
        getline(cin, s);

        istringstream input(s);
        Rational r1, r2;
        char operation;

        input >> r1;
        input.ignore(1);
        input >> operation;
        input.ignore(1);
        input >> r2;

        ostringstream output;

        switch (operation)
        {
        case '+':
            output << r1 + r2;
            cout << output.str();
            break;
        case '-':
            output << r1 - r2;
            cout << output.str();
            break;
        case '/':
            output << r1 / r2;
            cout << output.str();
            break;
        case '*':
            output << r1 * r2;
            cout << output.str();
            break;
        }
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}