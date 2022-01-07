#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

class RandomIntegerGenerator {
public:
	//RandomIntegerGenerator() { srand(time(NULL)); }
	int next() { return rand(); }
	int next(int ceiling) { return rand() % ceiling; }
	int next(int left, int right) { return rand() % (right - left + 1) + left; }
};

class DateTime {
private:
    int _day;
    int _month;
    int _year;
public:
    
    DateTime(int day, int month, int year) {
        _day = day;
        _month = month;
        _year = year;
    }

    static int currentYear() { return 2022; }

    static bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    string toString() {
        stringstream ss;
        ss << _day << "/" << _month << "/" << _year;
        string result = ss.str();
        return result;
    }

};

class BirthdayMock {
private:
    RandomIntegerGenerator _rng;
    int _maxAge;
    int _currentYear;
public:
    BirthdayMock() {
        _maxAge = 120;
        _currentYear = DateTime::currentYear();
    }
    DateTime next() {
        int year = _currentYear - _rng.next(_maxAge);
        int month = _rng.next(1, 12);

        int days[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (DateTime::isLeapYear(year)) {
            days[2] = 29;
        }

        int day = _rng.next(days[month]);
        
        DateTime dob(day, month, year);
        return dob;
    }
};


int main() {
    srand(time(NULL));

    BirthdayMock birthdayStore;

    for(int i = 1; i <= 10; i++) {
        DateTime dob = birthdayStore.next();
        cout << dob.toString() << endl;
    }
}
