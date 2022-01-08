#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

class Fraction;
class RandomIntegerGenerator;
class RandomFractionGenerator;
class Integer;
class FractionToLowestTermUIConverter;
class FractionToDecimalUIConverter;
class FractionToPercentageUIConverter;
class FractionToStringUIConverter;

class Fraction {
private:
	long long _num;
	long long _den;

public:
	Fraction() { _num = 0; _den = 1; }
	Fraction(long long num, long long den) { _num = num; _den = den; }

public:
	long long getNum() const { return _num; }
	long long getDen() const { return _den; }
};

class RandomIntegerGenerator {
public:
	RandomIntegerGenerator() {
		srand(time(NULL));
	}
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int left, int right) { return rand() % (right - left + 1) + left; }
};

class RandomFractionGenerator {
private:
	RandomIntegerGenerator _rig;

public:
	Fraction next() {
		long long num = _rig.next();
		long long den = _rig.next();
		Fraction f(num, den);
		return f;
	}
	Fraction next(int ceiling) {
		long long num = _rig.next(ceiling);
		long long den = _rig.next(ceiling);
		Fraction f(num, den);
		return f;
	}
	Fraction next(int left, int right) {
		long long num = _rig.next(left, right);
		long long den = _rig.next(left, right);
		Fraction f(num, den);
		return f;
	}
};

class Integer {
public:
	static int gcd(int a, int b) {
		if (a == 0) return b;

		if (b == 0) return a;

		if (a == b) return a;

		if (a > b) return gcd(a - b, b);

		return gcd(a, b - a);
	}
};

class FractionToLowestTermUIConverter {
public:
	string Convert(const Fraction& f) {
		stringstream ss;
		long long gcd = Integer::gcd(f.getNum(), f.getDen());
		long long num = f.getNum() / gcd;
		long long den = f.getDen() / gcd;

		if (num > den) {
			long long fullNum = num / den;
			ss << fullNum << " ";
			num = num / den;
		}

		if (num > 0) {
			ss << num;

			if (den != 1) ss << "/" << den;
		}

		string ans = ss.str();
		return ans;
	}
};

class FractionToDecimalUIConverter {
private:
	int _precision;
	bool _isFixed;

public:
	FractionToDecimalUIConverter(int precision = 3, bool isFixed = false) {
		this->_precision = precision;
		this->_isFixed = isFixed;
	}

public:
	string Convert(const Fraction& f) {
		stringstream ss;
		float value = f.getNum() * 1.0 / f.getDen() * 1.0;

		ss << setprecision(_precision);
		if (_isFixed) ss << fixed;
		ss << value;

		string ans = ss.str();
		return ans;
	}
};

class FractionToPercentageUIConverter {
private:
	int _precision;
	bool _isFixed;

public:
	FractionToPercentageUIConverter(int precision = 3, bool isFixed = false) {
		this->_precision = precision;
		this->_isFixed = isFixed;
	}

public:
	string Convert(const Fraction& f) {
		stringstream ss;
		float value = f.getNum() * 100.0 / f.getDen();

		ss << setprecision(_precision);
		if (_isFixed) ss << fixed;
		ss << value << "%";

		string ans = ss.str();
		return ans;
	}
};

class FractionToStringUIConverter {
public:
	string Convert(const Fraction& f) {
		stringstream ss;
		ss << f.getNum() << "/" << f.getDen();
		string ans = ss.str();
		return ans;
	}
};

int main() {
	const int left = 15;
	const int right = 25;

	RandomIntegerGenerator rig;
	int n = rig.next(left, right);
	cout << "There are " << n << " fractions: " << endl;

	const int minNumDen = 1;
	const int maxNumDen = 50;
	RandomFractionGenerator rfg;

	vector<Fraction> mylist;

	for (int i = 0; i < n; i++) {
		Fraction f = rfg.next(minNumDen, maxNumDen);
		mylist.push_back(f);
	}

	FractionToStringUIConverter stringConverter;
	for (int i = 0; i < mylist.size(); i++) {
		string result = stringConverter.Convert(mylist[i]);
		cout << result << ", ";
	}
	cout << endl << endl;

	cout << "These are fractions that have been converted to the lowest term: " << endl;
	FractionToLowestTermUIConverter lowestTermConverter;
	for (int i = 0; i < mylist.size(); i++) {
		string result = lowestTermConverter.Convert(mylist[i]);
		cout << result << ", ";
	}
	cout << endl << endl;

	cout << "These are numbers that fractions have been converted to decimal: " << endl;
	int precision = 4;
	bool isFixed = true;

	FractionToDecimalUIConverter decimalConverter(precision, isFixed);
	for (int i = 0; i < mylist.size(); i++) {
		string result = decimalConverter.Convert(mylist[i]);
		cout << result << ", ";
	}
	cout << endl << endl;

	cout << "These are numbers that fractions have been converted to percentage: " << endl;
	FractionToPercentageUIConverter percentageConverter(precision, isFixed);
	for (int i = 0; i < mylist.size(); i++) {
		string result = percentageConverter.Convert(mylist[i]);
		cout << result << ", ";
	}
	cout << endl;

	cin.get();
}
