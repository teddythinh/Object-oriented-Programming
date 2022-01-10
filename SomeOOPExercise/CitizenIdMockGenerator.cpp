/*
THE CITIZENID FORMAT:
FIRST 3 NUMS: BORN CITY CODE
4TH NUM: CENTURY CODE + GENDER
5TH AND 6TH NUM: LAST 2 DIGITS OF BIRTH YEAR
LAST 6 DIGITS: RANDOM FROM 000 001 TO 999 999

REFERENCE: https://luatminhkhue.vn/y-nghia-12-so-the-can-cuoc-cong-dan-la-gi--the-can-cuoc-cong-dan-nhu-the-nao-.aspx
*/

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

class CitizenIDMock {
private:
    RandomIntegerGenerator _rng;
    vector<string> _cityCodes;
    int _maxAge;
    int _currentYear;
public:
    CitizenIDMock() {
        _cityCodes = {"001", "002", "003", "004", "005", "006", "007", "008", "009", "010",
                    "011", "012", "013", "014", "015", "016", "017", "018", "019", "020"};
        _maxAge = 100;

        time_t t = time(NULL);
        tm now;
        localtime_s(&now, &t);
        _currentYear = now.tm_year + 1900;
    }

    string next() {
        stringstream writer;
        int i = _rng.next(_cityCodes.size());
        string citycode = _cityCodes[i];
        
        int century = _currentYear / 100 + 1;

        int male = _rng.next(2);
        int gender = (century - 20) * 2 + male;

        int birthYear = (_currentYear - _rng.next(_maxAge)) % 100;
        writer << citycode << birthYear;

        if(birthYear < 10) writer << "0";
        writer << birthYear;

        for(int i = 1; i <= 6; i++) {
            writer << _rng.next(10);
        }
        
        string id = writer.str();
        return id;
    }
};


int main() {
    srand(time(NULL));

    CitizenIDMock citizenIdStore;
    for(int i = 1; i <= 10; i++) {
        string citizenID = citizenIdStore.next();
        cout << citizenID << endl;
    }
}
