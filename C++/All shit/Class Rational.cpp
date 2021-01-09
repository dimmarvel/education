A#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Rational;

static int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
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
		if (denominator < 0)
		{
			denominator = -denominator;
			numerator = -numerator;
		}

		int x = gcd(abs(numerator), denominator);
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
	friend bool operator==(const Rational& lhs, const Rational& rhs)
	{
		return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
	}

	friend const Rational& operator+(const Rational& lhs, const Rational& rhs)
	{
		return Rational{
			lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
			lhs.Denominator() * rhs.Denominator() };
	}

	friend const Rational& operator-(const Rational& lhs, const Rational& rhs)
	{
		return Rational{
			lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
			lhs.Denominator() * rhs.Denominator() };
	}

	friend const Rational& operator*(const Rational& lhs, const Rational& rhs)
	{
		return Rational{
			lhs.Numerator() * rhs.Numerator(),
			 lhs.Denominator() * rhs.Denominator() };
	}

	friend const Rational& operator/(const Rational& lhs, const Rational& rhs)
	{
		return Rational{
			lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator() };
	}

	friend istream& operator>>(istream& stream, Rational& r)
	{
		stream >> r.num;
		stream.ignore(1);
		stream >> r.den;
		r = Rational{ r.num, r.den };

		return stream;
	}

	friend ostream& operator<<(ostream& stream, const Rational& r)
	{
		stream << r.num << '/' << r.den;
		return stream;
	}

	friend bool operator>(const Rational& lhs, const Rational& rhs)
	{
		return (lhs.Numerator() * rhs.Denominator()) < (lhs.Denominator() * rhs.Numerator());
	}

	friend bool operator<(const Rational& lhs, const Rational& rhs)
	{
		return (lhs.Numerator() * rhs.Denominator()) < (lhs.Denominator() * rhs.Numerator());
	}
};

int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;

		++count[{1, 2}];
		++count[{1, 2}];
		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}