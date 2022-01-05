/*
DISCLAIMER: THIS PROJECT IS USED VIETNAMESE NAMES SO YOUR CONSOLE MAY NOT SHOW 
            VIETNAMESE CHARACTERS WHEN YOU PRINT OUT THE RESULT
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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
        _femaleLastnames = {"Bùi", "Nguyễn", "Tôn Nữ", "Lâm", "Hồ", "Lý", "Triệu", "Lê", "Trưng"};
        _maleLastNames = {"Nguyễn", "Trần", "Lê", "Trương", "Vũ", "Đặng", "Phạm", "Ngô", "Lý",
        "Tôn Thất", "Hồ", "Mạc", "Trịnh", "Hoàng Phủ"};

        _femaleMiddleNames = {"Thị", "Hồng"};
        _maleMiddleNames = {"Quốc", "Đăng", "Phúc", "Ngọc", "Văn", "Phong", "Hữu"};

        _firstName = {"Quyền", "Quang Phục", "Bộ Lĩnh", "Hoàn", "Công Uẩn", "Thủ Độ", "Cảnh",
        "Trắc", "Chân", "Trình", "Thiên Hinh", "Ngọc Bảo", "Xuân Hương", "Mỹ Dạ", "Ánh Viên","Cẩm Vân"};
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

int32_t main() {
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

    return 0;
}
