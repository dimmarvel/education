#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return gcd(a%b, b);
	return gcd(a, b%a);
}

int nok(int a, int b)
{
	return (a*b) / gcd(a, b);
}

class Rational {
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
		if (numerator >= 0 && denominator < 0)
		{
			denominator = -denominator;
			numerator = -numerator;
		}
		else if (numerator < 0 && denominator < 0)
		{
			numerator = abs(numerator);
			denominator = abs(denominator);
		}

		int x = gcd(numerator, denominator);
		num = numerator /= x;
		den = denominator /= x;


	}

	int Numerator() const
	{
		return num;
	}
	int Denominator() const
	{
		return den;
	}
	bool operator==(Rational r)
	{
		return r.num == this->num && r.den == this->den;
	}

	Rational operator+(Rational r)
	{
		if (r.den == this->den)
		{
			return Rational(this->num + r.num, this->den);
		}
		else
		{
			int nokcalc = nok(r.den, this->den);
			int mnojitel1 = nokcalc / r.den;
			int mnojitel2 = nokcalc / this->den;

			r.num *= mnojitel1;
			r.den *= mnojitel1;
			this->num *= mnojitel2;
			this->den *= mnojitel2;

			return Rational(this->num + r.num, this->den);
		}
	}

	Rational operator-(Rational r)
	{
		if (r.den == this->den)
		{
			return Rational(this->num - r.num, this->den);
		}
		else
		{
			int nokcalc = nok(r.den, this->den);
			int mnojitel1 = nokcalc / r.den;
			int mnojitel2 = nokcalc / this->den;

			r.num *= mnojitel1;
			r.den *= mnojitel1;
			this->num *= mnojitel2;
			this->den *= mnojitel2;

			return Rational(this->num - r.num, this->den);
		}
	}

};

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}