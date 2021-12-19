#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <regex>
#include <tuple>
#include <fstream>
#include <vector>

using namespace std;

class Integer;
class Fraction;
class FractionToLowestTermUIConverter;
class RandomIntegerGenerator;
class RandomFractionGenerator;
class FractionToStringDataConverter;
class FractionDataReader;

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

class Fraction {
private:
	long long _num;
	long long _den;
public:
	long long Numerator() const { return _num; }
	long long Denominator() const { return _den; }

	void setNum(long long num) { _num = num; }
	void setDen(long long den) { _den = den; }

	Fraction() { _num = 0; _den = 1; }
	Fraction(long long num, long long den) { _num = num; _den = den; }

	static Fraction addTwoFractions(const Fraction& a, const Fraction& b) {
		Fraction sum;

		sum.setNum(a.Denominator() * b.Numerator() + a.Numerator() * b.Denominator());
		sum.setDen(a.Denominator() * b.Denominator());
		long long gcd = Integer::gcd(sum.Numerator(), sum.Denominator());
		sum.setNum(sum.Numerator() / gcd);
		sum.setDen(sum.Denominator() / gcd);
		return sum;
	}
};

class FractionToLowestTermUIConverter {
public:
	string Convert(const Fraction& f) {
		stringstream ss;
		long long gcd = Integer::gcd(f.Numerator(), f.Denominator());
		long long num = f.Numerator() / gcd;
		long long den = f.Denominator() / gcd;

		if (num > den) {
			long long fullNum = num / den;
			ss << fullNum << " ";
			num = num % den;
		}

		if (num > 0) {
			ss << num;

			if (den != 1) ss << "/" << den;
		}

		string ans = ss.str();
		return ans;
	}
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

class FractionToStringDataConverter {
public:
	string convert(const Fraction& f) {
		stringstream ss;
		ss << f.Numerator() << "/" << f.Denominator();
		string result = ss.str();
		return result;
	}

	bool isValidFraction(string value) {
		bool result;
		const string patterns = "\\b\\d+/[1-9][0-9]*\\b";
		regex fractionsFormat(patterns);
		result = regex_match(value, fractionsFormat);
		return result;
	}

	Fraction convertBack(string value) {
		bool isValid = isValidFraction(value);
		if (isValid) {
			int slash = value.find('/');
			string numString = value.substr(0, slash);
			string denString = value.substr(slash + 1, value.length() - slash - 1);

			long long num = stoi(numString);
			long long den = stoi(denString);

			Fraction f(num, den);
			return f;
		}
		else {
			throw runtime_error("Wrong format");
		}
	}

	bool tryConvertBack(string buffer, Fraction& f) {
		bool result = true;
		bool isValid = isValidFraction(buffer);
		if (isValid) {
			f = convertBack(buffer);
		}
		else { result = false; }
		return result;
	}
};

class FractionDataReader {
private:
	string _connectingString;
public:
	FractionDataReader(string connectingString) {
		_connectingString = connectingString;
	}

	vector<Fraction>GetAll() {
		ifstream input(_connectingString);
		vector<Fraction> f;

		while (!input.eof()) {
			string line;
			getline(input, line);
			Fraction a;
			bool checkOK;
			FractionToStringDataConverter fConvert;
			try {
				checkOK = fConvert.tryConvertBack(line, a);
			}
			catch (runtime_error e) {
				checkOK = false;
				cout << e.what() << endl;
			}
			if (checkOK) {
				f.push_back(a);
			}
		}
		input.close();
		return f;
	}
};

class FractionDataWriter {
private:
	string _connectingString;
public:
	FractionDataWriter(string connectingString) {
		_connectingString = connectingString;
	}

	void Write(const Fraction& f) {
		ofstream output(_connectingString, ios::app);
		FractionToStringDataConverter fConvert;
		string line = fConvert.convert(f);
		output << line << endl;
		output.close();
	}
};

int main() {
	FractionDataReader reader("data.txt");
	vector<Fraction> Mylist = reader.GetAll();

	FractionToStringDataConverter fts;
	FractionToLowestTermUIConverter lts;
	RandomFractionGenerator rfg;
	Fraction f;
	FractionDataWriter writer("data.txt");

	cout << "All of the fractions in the list: " << endl;
	for (int i = 0; i < Mylist.size(); i++) {
		cout << lts.Convert(Mylist[i]) << ", ";
	}

	cout << endl << "Two random fractions:" << endl;
	for (int i = 0; i < 2; i++) {
		f = rfg.next(1, 99);
		cout << fts.convert(f) << " ";
		Mylist.push_back(f);
		writer.Write(f);
	}
	Fraction sum;
	for (int i = 0; i < Mylist.size(); i++) {
		sum = Fraction::addTwoFractions(sum, Mylist[i]);
	}
	cout << endl << "The total of two fractions is: " << lts.Convert(sum) << endl;

	cout << endl << "Press any key to continue..." << endl;
	cin.get();
	return 0;
}
