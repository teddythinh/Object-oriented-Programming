/*
DISCLAIMER: THIS PROJECT HAS A BUG THAT PEOPLE WHO HAS TWO WORDS IN THEIR FIRST NAMES
            AND THEIR LAST NAMES WILL GET AN ERROR
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

class Fullname {
private:
    string _firstName;
    string _middleName;
    string _lastName;
public: 
    string getFirstName() { return _firstName; }
    string getMiddleName() { return _middleName; }
    string getLastName() { return _lastName; }


    Fullname(string firstName, string middleName, string lastName) {
        _firstName = firstName;
        _middleName = middleName;
        _lastName = lastName;
    }

    string toString() {
        stringstream ss;
        ss << _lastName << " " << _middleName << " " << _firstName;
        string result = ss.str();
        return result;
    }
};

class FullnameMock {
private:
    RandomIntegerGenerator _rng;
    vector<string> _femaleMiddleNames;
    vector<string> _maleMiddleNames;

    vector<string> _femaleLastnames;
    vector<string> _maleLastNames;

    vector<string> _firstName;

public:
    FullnameMock() {
        _femaleLastnames = {"Bui", "Nguyen", "Ton Nu", "Lam", "Ho", "Ly", "Trieu", "Le", "Trung"};
        _maleLastNames = {"Nguyen", "Tran", "Le", "Truong", "Vu", "Đang", "Pham", "Ngo", "Ly",
        "Ton That", "Ho", "Mac", "Trinh", "Hoang Phu"};

        _femaleMiddleNames = {"Thi", "Hong"};
        _maleMiddleNames = {"Quoc", "Đang", "Phuc", "Ngoc", "Van", "Phong", "Huu"};

        _firstName = {"Quyen", "Quang Phuc", "Bo Linh", "Hoan", "Cong Uan", "Thu Đo", "Canh",
        "Trac", "Chan", "Trinh", "Thien Hinh", "Ngoc Bao", "Xuan Huong", "My Da", "Anh Vien","Cam Van"};
    }

    Fullname next(bool male) {
        int i = _rng.next(_firstName.size());
        string first = _firstName[i];
        string middle = "";
        string last = "";

        if(male) {
            i = _rng.next(_maleMiddleNames.size());
            middle = _maleMiddleNames[i];
            i = _rng.next(_maleLastNames.size());
            last = _maleLastNames[i];
        }
        else {
            i = _rng.next(_femaleMiddleNames.size());
            middle = _femaleMiddleNames[i];
            i = _rng.next(_femaleLastnames.size());
            last = _femaleLastnames[i];
        }
        Fullname result(first, middle, last);
        return result;
    }

};

class EmailMock {
private: 
    RandomIntegerGenerator _rng;
    vector<string> _domains;
    FullnameMock _nameStore;
public:
    EmailMock() {
        _domains = {"gmail.com", "yahoo.com", "hotmail.com", "outlook.com",
        "live.com", "ymail.com", "msn.com", "hcmus.edu.vn"};
    }
    string next() {
        bool male = _rng.next(2) == 1;
        Fullname name = _nameStore.next(male);
        string email = next(name);
        return email;
    }
    string next(Fullname name) {
        string first = name.getFirstName().substr(0, 1);
        string middle = name.getMiddleName().substr(0, 1);

        int i = _rng.next(_domains.size());
        string domain = _domains[i];

        stringstream writer;
        writer << first << middle << name.getLastName() << "@" << domain;

        string email = writer.str();
        return email;
    }
};

int32_t main() {
    srand(time(NULL));

    FullnameMock nameStore;
    vector<Fullname> names;
    bool male = true;

    for(int i = 1; i <= 10; i++) {
        names.push_back(nameStore.next(male));
    }
    for(int i = 1; i <= 10; i++) {
        names.push_back(nameStore.next(!male));
    }
    cout << "Name of males: " << endl;
    for(int i = 1; i <= 10; i++) {
        cout << names[i].toString() << endl;
    }
    cout << endl << "Name of females: " << endl;
    for(int i = 11; i <= 20; i++) {
        cout << names[i].toString() << endl;
    }

    // Create email from people above
    EmailMock emailStore;
    for(int i = 1; i <= 20; i++) {
        string email = emailStore.next(names[i]);
        cout << email << endl;
    }

    return 0;
}
