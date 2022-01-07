/*
NOTE: THE STREET NAME I HARD CODED IS FROM: https://github.com/tranphuongdinh/HCMAddresses
        AND https://vietnam-streets.openalfa.com/ho-chi-minh-city
        PLEASE USE IT CONSIDERABLY. THANKS!
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

class Address {
private:
    string _number;
    string _street;
    string _ward;
    string _district;
    string _city;
public:
    Address(string number, string street, string ward, string district, string city) {
        _number = number;
        _street = street;
        _ward = ward;
        _district = district;
        _city = city;
    }
    string toSring() {
        stringstream builder;
        builder << _number << " " << _street << ", " << _ward << ", " << _district << ", " << _city;
        string result = builder.str();
        return result;
    }
};

class HCMAddressMock {
private:
    RandomIntegerGenerator _rng;
    vector<string> _street;
    vector<string> _ward;
    vector<string> _district;
    vector<string> _city;
public:
    HCMAddressMock() {
        _street = { "Alexandre de Rhodes",
                    "Huyen Quang",
                    "Nguyen Hau",
                    "Phan Ke Binh",
                    "Ba le Chan",
                    "Huyen Chan Cong Chua",
                    "Nguyen Hue",
                    "Phan Liem",
                    "Ben Chuong Duong",
                    "Huynh Khuong Ninh",
                    "Nguyen Huu Canh",
                    "Phan Ngu",
                    "Bui Thi Xuan",
                    "Huynh Thuc Khang",
                    "Nguyen Huu Cau",
                    "Phan Ton",
                    "Bui Vien",
                    "Khanh Hoi",
                    "Nguyen Huy Tu",
                    "Phan Van Dat",
                    "Cach Mang Thang 8",
                    "Ky Con",
                    "Nguyen Khac Nhu",
                    "Phan Van Truong",
                    "Calmette",
                    "Le Anh Xuan",
                    "Nguyen Phi Khanh",
                    "Pho Duc Chinh",
                    "Cao Ba Nha",
                    "Le Cong Kieu",
                    "Nguyen Sieu",
                    "Phung Khac Khoan" };
                    
        _ward = { "Ward 1",
                "Ward 10",
                "Ward 11",
                "Ward 12",
                "Ward 13",
                "Ward 14",
                "Ward 15",
                "Ward 16",
                "Ward 17",
                "Ward 2",
                "Ward 3",
                "Ward 4",
                "Ward 5",
                "Ward 6",
                "Ward 7",
                "Ward 8",
                "Ward 9",
                "Ben Nghe Ward",
                "Ben Thanh Ward",
                "Cau Kho Ward",
                "Cau Ong Lanh Ward",
                "Co Giang Ward",
                "Da Kao Ward",
                "Nguyen Cu Trinh Ward",
                "Nguyen Thai Binh Ward",
                "Pham Ngu Lao Ward",
                "Tan Dinh Ward" };

        _district = { "Binh Chanh District",
                    "Binh Tan District",
                    "Binh Thanh District",
                    "Can Gio District",
                    "Cu Chi District",
                    "District 1",
                    "District 11",
                    "District 12",
                    "District 3",
                    "District 4",
                    "District 5",
                    "District 6",
                    "District 7",
                    "District 8",
                    "Hoc Mon District",
                    "Nha Be District",
                    "Phu Nhuan District",
                    "Tan Binh District",
                    "Tan Phu District"};

        _city = { "Ho Chi Minh City" };
    }

    Address next() {
        string number = to_string(_rng.next(1000));
        
        int i = _rng.next(_street.size());
        string street = _street[i];
        
        i = _rng.next(_ward.size());
        string ward = _ward[i];
        
        i = _rng.next(_district.size());
        string district = _district[i];
        
        i = _rng.next(_city.size());
        string city = _city[i];

        Address address(number, street, ward, district, city);
        return address;
    }
};

int main() {
    srand(time(NULL));

    HCMAddressMock addressStore;
    for(int i = 1; i <= 10; i++) {
        Address address = addressStore.next();
        cout << address.toSring() << endl;
    }
}
