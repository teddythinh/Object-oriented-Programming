#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <vector>
#include <tuple>
#include <regex>
#include <fstream>
#include <string>
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

// Class: Fraction
// Description: This class is used to represent a fraction
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

	static Fraction sumTwoFractions(const Fraction& a, const Fraction& b) {
		Fraction sum;

		sum.setNum(a.Denominator() * b.Numerator() + a.Numerator() * b.Denominator());
		sum.setDen(a.Denominator() * b.Denominator());
		long long gcd = Integer::gcd(sum.Numerator(), sum.Denominator());
		sum.setNum(sum.Numerator() / gcd);
		sum.setDen(sum.Denominator() / gcd);
		return sum;
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

class FractionToStringUIConverter {
public:
	bool isValidFormat(string value) {
		bool isValid = true;
		// 
		const string patterns = "\\b\\d+\\/[1-9][0-9]*\\b";
		const string patterns2 = "\\b\\d+\\b";
		const string patterns3 = "\\b\\d+\\s\\d+\\/[1-9][0-9]*\\b";
		regex fractionsFormat(patterns);
		regex fractionsFormat2(patterns2);
		regex fractionsFormat3(patterns3);
		if (!regex_match(value, fractionsFormat) && !regex_match(value, fractionsFormat2) && !regex_match(value, fractionsFormat3)) {
			isValid = false;
		}
		return isValid;
	}

	string convert(const Fraction& f) {
		stringstream ss;
		ss << f.Numerator() << "/" << f.Denominator();
		string ans = ss.str();
		return ans;
	}

	Fraction convertBack(string value) {
		bool isValid = isValidFormat(value);
		Fraction f;
		if (isValid) {
			int slash = value.find('/');
			int space = value.find(' ');

			if (slash == -1 && space == -1) {
				f.setNum(stoi(value));
				f.setDen(1);
			}
			if (space == -1) {
				string n = value.substr(0, slash);
				string d = value.substr(slash + 1);
				f.setNum(stoi(n));
				f.setDen(stoi(d));
			}
			else {
				string n2 = value.substr(0, space);
				string d2 = value.substr(space + 1, slash - space - 1);
				string a = value.substr(slash + 1);
				f.setNum(stoi(n2) * stoi(a) + stoi(d2));
				f.setDen(stoi(a));
			}
		}
		else {
			throw runtime_error("Wrong format, please try again");
		}
	}

	bool tryConvertBack(string buffer, Fraction& f) {
		bool result = true;
		bool isValid = isValidFormat(buffer);
		if (isValid) { f = convertBack(buffer); }
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
			FractionToStringUIConverter fConvert;
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
		FractionToStringUIConverter fConvert;
		string line = fConvert.convert(f);
		output << line << endl;
		output.close();
	}
};

int main() {
	vector<Fraction> a;
	string s;
	RandomIntegerGenerator r;
	FractionToStringUIConverter converter;
	FractionDataWriter writer("data.txt");
	Fraction f;
	int n = r.next(5, 10);
	cout << "Please input " << n << " fractions" << endl;
	// Input n fractions from user and check if they are valid, if not, ask user to input again and 
	// write them to file
	for (int i = 0; i < n; i++) {
		cout << "Please input fraction " << i + 1 << ": ";
		getline(cin, s);
		bool checkOK;
		try {
			checkOK = converter.tryConvertBack(s, f);
		}
		catch (runtime_error e) {
			checkOK = false;
			cout << e.what() << endl;
		}
		if (checkOK) {
			a.push_back(f);
			writer.Write(f);
		}
		else {
			i--;
		}
	}

	Fraction sum;
	FractionToLowestTermUIConverter fLowConvert;

	for (int i = 0; i < a.size(); i++) {
		sum = sum.sumTwoFractions(sum, a[i]);
	}
	cout << "The total is: " << fLowConvert.Convert(sum) << endl;
}
