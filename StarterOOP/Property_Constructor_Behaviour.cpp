#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Soldier
{
private:
	int _hitPoint;
	int _mana;

public: // Property
	int getHitPoint() { return _hitPoint; }
	int getMana() { return _mana; }

	void setHitPoint(int hitPoint) { _hitPoint = hitPoint; }
	void setMana(int mana) { _mana = mana; }

public: // Constructor
	Soldier() { _hitPoint = 0; _mana = 0; }
	Soldier(int hitPoint, int mana) { _hitPoint = hitPoint; _mana = mana; }

public: // Behaviors
	void attack()
	{
		cout << "The Soldier is attacking." << endl;
	}
	void defend()
	{
		cout << "The Soldier is defending." << endl;
	}

public:
	// Print
	string toString()
	{
		stringstream ss;
		ss << "HP: " << _hitPoint << "         Mana: " << _mana << endl;
		return ss.str();
	}
};

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	int getNumerator() { return _numerator; }
	int getDenominator() { return _denominator; }

	void setNumerator(int numerator) { _numerator = numerator; }
	void setDenominator(int denominator) { _denominator = denominator; }

public:
	Fraction() { _numerator = 0; _denominator = 0; }

	Fraction(int numerator, int denominator) { _numerator = numerator; _denominator = denominator; }

public:
	string toString()
	{
		stringstream ss;
		ss << "Numerator: " << _numerator << "         Denominator: " << _denominator << endl;
		ss << "The fraction is: " << _numerator << "/" << _denominator << endl;
		return ss.str();
	}
};

class Point
{
private:
	int _x;
	int _y;

public:
	int getX() { return _x; }
	int getY() { return _y; }

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

public:
	Point() { _x = 0; _y = 0; }
	Point(int x, int y) { _x = x; _y = y; }

public:
	string toString() {
		stringstream ss;
		ss << "X: " << _x << "            Y: " << _y << endl;
		ss << "The point is: " << "(" << _x << "," << _y << ")" << endl;
		return ss.str();
	}
};

class Line
{
private:
	Point _a;
	Point _b;

public:
	int getFirstX() { return _a.getX(); }
	int getFirstY() { return _a.getY(); }
	int getLastX() { return _b.getX(); }
	int getLastY() { return _b.getY(); }

	void setFirst(int x, int y) { _a.setX(x); _a.setY(y); }
	void setLast(int x, int y) { _b.setX(x); _b.setY(y); }
public:
	Line() 
	{
		_a.setX(0);
		_a.setY(0);
		_b.setX(0);
		_b.setY(0);
	}
	Line(int x1, int y1, int x2, int y2) {
		_a.setX(x1);
		_a.setY(y1);
		_b.setX(x2);
		_b.setY(y2);
	}

public:
	string toString() 
	{
		stringstream ss;
		ss << "The line contains: " << endl << "First point: (" << _a.getX() << ", " << _a.getY() << ")" << endl
			<< "Last point: (" << _b.getX() << ", " << _b.getY() << ")" << endl;
		return ss.str();
	}
};

int main()
{
	Soldier s(100, 100);
	cout << s.toString();
	s.attack();
	s.defend();
	cout << "---------------------------------------------" << endl;
	Fraction f(100, 100);
	cout << f.toString();
	cout << "---------------------------------------------" << endl;
	Point p(100, 100);
	cout << p.toString();
	cout << "---------------------------------------------" << endl;
	Line l(0, 0, 1, 1);
	cout << l.toString();
	return 0;
}
